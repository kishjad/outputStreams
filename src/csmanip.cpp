// My headers
#include "csmanip.hpp"
#include "helper_tools.hpp"

// STD headers
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <regex>
namespace outStream
{
    using namespace std::string_literals; 
    //====================================================
    //     DEFINITION OF THE "feat" FUNCTION
    //====================================================

    [[nodiscard]] std::string feat(std::initializer_list<t_ops> ops)
    {
        std::string result = "";
        for(auto op : ops)
        {
            result += (std::string(" ") + ops_array[static_cast<unsigned long>(op)]);
        }
        return result;
    }

    [[nodiscard]] std::string feat(t_ops ops)
    {
        return ops_array[static_cast<unsigned long>(ops)];
    }

    template <typename T>
    [[nodiscard]] std::string feat(t_ops ops,T num ){
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

    template<class T>
    [[nodiscard]] std::string traverse( const T x, const T y )
    {
        return "\u001b[" +
           std::to_string( x ) + ";"s+
           std::to_string( y ) + "H"s;
    }
    template std::string traverse <int>( const int x, const int y );
    template std::string traverse <unsigned int>( const unsigned int x, const unsigned int y );
    template std::string traverse <long>( const long x, const long y );
    template std::string traverse <unsigned long>( const unsigned long x, const unsigned long y );
    template std::string traverse <long long>( const long long x, const long long y );
    template std::string traverse <unsigned long long>( const unsigned long long x, const unsigned long long y );

    //====================================================
    //     DEFINITION OF THE "RGB" FUNCTION
    //====================================================
    template<class T>
    [[nodiscard]] std::string RGB( const T r, T g, const T b )
    {
        return "\x1b[38;2;" +
           std::to_string( r ) + ";"s +
           std::to_string( g ) + ";"s +
           std::to_string( b ) + "m"s;
    }
    template std::string RGB <int>( const int r, const int g, const int b );
    template std::string RGB <unsigned int>( const unsigned int r, const unsigned int g, const unsigned int b );
    template std::string RGB <long>( const long r, const long g, const long b );
    template std::string RGB <unsigned long>( const unsigned long r, const unsigned long g, const unsigned long b );
    template std::string RGB <long long>( const long long r, const long long g, const long long b );
    template std::string RGB <unsigned long long>( const unsigned long long r, const unsigned long long g, const unsigned long long b );

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

}