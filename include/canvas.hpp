#ifndef OUTSTREAM_CANVAS_HPP
#define OUTSTREAM_CANVAS_HPP

// STD headers
#include <vector>
#include <string>

namespace outStream
{
    //====================================================
    //     FRAMESTYLE ENUM CLASS
    //====================================================
    typedef enum
    {
        EMPTY = 0,
        ASCII = 1,
        BOX = 2
    } FrameStyle;

    //====================================================
    //     CANVAS CLASS
    //====================================================
    class Canvas
    {
    public:
        //====================================================
        //     CONSTRUCTORS AND DESTRUCTORS DECLARATION
        //====================================================
        Canvas( unsigned int width, unsigned int height );

        //====================================================
        //     SETTERS DECLARATION
        //====================================================
        void enableFrame( bool frame_enabled );
        void setFrame( FrameStyle, const std::string & feat = "" );
        void setBackground( char c, const std::string & feat = "" );
        void setWidth( unsigned int width );
        void setHeight( unsigned int height );

        //====================================================
        //     GETTERS DECLARATION
        //====================================================
        char getBackground() const;
        std::string getBackgroundFeat() const;
        bool isFrameEnabled() const;
        std::string getFrameFeat() const;
        FrameStyle getFrameStyle() const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;

        //====================================================
        //     OTHER METHODS DECLARATION
        //====================================================
        void clear();
        void put( unsigned int x, unsigned int y, char c, const std::string & feat = "" );
        void refresh();

    private:
        //====================================================
        //     PRIVATE ATTRIBUTES DECLARATION
        //====================================================
        bool frame_enabled_;
        FrameStyle frame_style_;
        std::string frame_feat_;
        char bg_char_;
        std::string bg_feat_;
        std::vector<char> char_buffer_;
        std::vector<std::string> feat_buffer_;
        bool already_drawn_;

        //====================================================
        //     PRIVATE METHODS DECLARATION
        //====================================================
        void resizeCanvas();

   protected:
        //====================================================
        //     PROTECTED ATTRIBUTES DECLARATION
        //====================================================
        unsigned int width_, height_;
    };
}      // namespace outStream

#endif
