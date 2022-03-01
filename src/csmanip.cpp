// My headers
#include "csmanip.hpp"
#include "helper_tools.hpp"

// STD headers
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <regex>
namespace osm
{

    //====================================================
    //     DEFINITION OF THE "feat" FUNCTION
    //====================================================

    std::string feat(std::initializer_list<t_ops> ops)
    {
        std::string result = "";
        for(auto op : ops)
        {
            result += (std::string(" ") + ops_array[static_cast<unsigned long>(op)]);
        }
        return result;
    }

    std::string feat(t_ops ops)
    {
        return ops_array[static_cast<unsigned long>(ops)];
    }

    template <typename T>
    std::string feat(t_ops ops,T num ){
        if( (num < 0) || (std::string(ops_array[static_cast<unsigned long>(ops)]).find("%d") == std::string::npos) ){
            return "";
        }
        std::string result = ops_array[static_cast<unsigned long>(ops)];
        result = std::regex_replace(result, std::regex("%d"), std::to_string(num));
        return result;
    }

    template std::string feat <int>(t_ops ops,int num );
    template std::string feat <unsigned int>(t_ops ops,unsigned int num );
    template std::string feat <long>(t_ops ops,long num );
    template std::string feat <unsigned long>(t_ops ops,unsigned long num );
    template std::string feat <long long> (t_ops ops,long long num );
    template std::string feat <unsigned long long>(t_ops ops,unsigned long long num );

    //====================================================
    //     DEFINITION OF THE "go_to" FUNCTION
    //====================================================
    std::string go_to( const int & x, const int & y )
    {
        return "\u001b[" +
           std::to_string( x ) +
           static_cast<std::string>( ";" ) +
           std::to_string( y ) +
           static_cast<std::string>( "H" );
    }

    //====================================================
    //     DEFINITION OF THE "RGB" FUNCTION
    //====================================================
    std::string RGB( const int & r, const int & g, const int & b )
    {
        return "\x1b[38;2;" +
           std::to_string( r ) +
           static_cast<std::string>( ";" ) +
           std::to_string( g ) +
           static_cast<std::string>( ";" ) +
           std::to_string( b ) +
           static_cast<std::string>( "m" );
    }

    //====================================================
    //     DEFINITION OF THE "CursorOpt" FUNCTION
    //====================================================
    void CursorOpt( const CURSOR & opt ) noexcept
    {
        if( opt == CURSOR::OFF )
            std::cout << feat( t_ops::hide_cursor );
        else if( opt == CURSOR::ON )
            std::cout << feat( t_ops::show_cursor );
        else   // Default
            std::cout << "Invalid cursor CursorOpt, set to default!" << feat( t_ops::show_cursor ) << "\n";
    }

}      // namespace osm