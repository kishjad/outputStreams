
/*
 * This file is part of outputStream
 * Licensed under the MIT License 
 * Copyright (c) 2022 Kshitej Jadhav
 */
// My headers
#include "canvas.hpp"
#include "csmanip.hpp"

// STD headers
#include <sstream>
#include <iostream>

namespace outStream
{
    //====================================================
    //     CONSTRUCTORS AND DESTRUCTORS DEFINITION
    //====================================================
    Canvas::Canvas( unsigned int width, unsigned int height )
    {
        already_drawn_ = false;
        width_ = width;
        height_ = height;
        bg_char_ = ' ';
        bg_feat_ = "";
        frame_enabled_ = false;
        resizeCanvas();
        clear();
    }

    //====================================================
    //     SETTERS DEFINITION
    //====================================================
    void Canvas::setBackground( char c, const std::string & feat )
    {
        bg_char_ = c;
        bg_feat_ = feat;
    }

    void Canvas::enableFrame( bool frame_enabled )
    {
        frame_enabled_ = frame_enabled;
    }

    void Canvas::setFrame( FrameStyle fs, const std::string & feat )
    {
        frame_style_ = fs;
        frame_feat_ = feat;
    }

    void Canvas::setWidth( unsigned int width )
    {
        width_ = width;
        resizeCanvas();
    }

    void Canvas::setHeight( unsigned int height )
    {
        height_ = height;
        resizeCanvas();
    }

    //====================================================
    //     GETTERS DEFINITION
    //====================================================
    unsigned int Canvas::getWidth() const
    {
        return width_;
    }

    unsigned int Canvas::getHeight() const
    {
        return height_;
    }

    char Canvas::getBackground() const
    {
        return bg_char_;
    }

    std::string Canvas::getBackgroundFeat() const
    {
        return bg_feat_;
    }

    bool Canvas::isFrameEnabled() const
    {
        return frame_enabled_;
    }

    std::string Canvas::getFrameFeat() const
    {
        return frame_feat_;
    }

    FrameStyle Canvas::getFrameStyle() const
    {
        return frame_style_;
    }

    //====================================================
    //     CLEAR METHOD DEFINITION
    //====================================================
    void Canvas::clear()
    {
        char_buffer_.assign( width_ * height_, bg_char_ );
        feat_buffer_.assign( width_ * height_, bg_feat_ );
    }

    //====================================================
    //     PUT METHOD DEFINITION
    //====================================================
    void Canvas::put( unsigned int x, unsigned int y, char c, const std::string & feat )
    {
        char_buffer_.at( y * width_ + x ) = c;
        feat_buffer_.at( y * width_ + x ) = feat;
    }

    //====================================================
    //     REFRESH METHOD DEFINITION
    //====================================================
    void Canvas::refresh()
    {
        static const std::vector<std::vector<std::string>> frames = {
            //   TL,  T,   TR,  L,   R,   BL,  B,   BR
            { " ", " ", " ", " ", " ", " ", " ", " " },
            { "+", "-", "+", "|", "|", "+", "-", "+" },
            { "\u250c", "\u2500", "\u2510", "\u2502", "\u2502", "\u2514", "\u2500", "\u2518" }
        };

        if( already_drawn_ )
        {
            for( unsigned int i = 0; i < height_; i++ )
            {
                std::cout << feat( t_ops::cursor_up, 1 );
            }
        }

        unsigned int y = 0;

        const auto & frame = [ & ]( unsigned int fi ) -> std::string
        {
            return frame_feat_ + frames[ frame_style_ ][ fi ] + feat( t_ops::rst_all );
        };

        std::stringstream ss;

        if( frame_enabled_ )
        {
            ss << frame( 0 );

            for( unsigned int i = 2; i < width_; i++ )
            {
                ss << frame( 1 );
            }

            ss << frame( 2 ) << std::endl;
            y++;
        }

        for( ; y < height_; y++ )
        {
            if( y == height_ - 1 && frame_enabled_ )
            {
                ss << frame( 5 );

                for( unsigned int i = 2; i < width_; i++ )
                {
                    ss << frame( 6 );
                }

                ss << frame( 7 ) << std::endl;
                continue;
            }

            for( unsigned int x = 0; x < width_; x++ )
            {
                if( x == 0 && frame_enabled_ )
                {
                    ss << frame( 3 );
                    continue;
                }

                if( x == width_ - 1 && frame_enabled_ )
                {
                    ss << frame( 4 );
                    continue;
                }

                unsigned int p = y * width_ + x;

                ss << feat_buffer_[ p ]
                   << char_buffer_[ p ]
                   << feat( t_ops::rst_all );
            }
            ss << std::endl;
        }
        std::cout << ss.str();
        already_drawn_ = true;
    }

    //====================================================
    //     RESIZECANVAS METHOD DEFINITION
    //====================================================
    void Canvas::resizeCanvas()
    {
        char_buffer_.resize( width_ * height_ );
        feat_buffer_.resize( width_ * height_ );
    }
}      // namespace outStream