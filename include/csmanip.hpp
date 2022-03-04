#ifndef CSMANIP_HPP
#define CSMANIP_HPP

// STD headers
#include <iostream>
#include <string>
#include <map>
#include <set>

#include "termDefs.hpp"
namespace outStream
{
    //====================================================
    //     USING ALIASES
    //====================================================
    using string_pair_map = std::map<std::string, std::pair<std::string, std::string>>;
    using string_set_map = std::map<std::string, std::set<std::string>>;

    //====================================================
    //     ENUM CLASSES
    //====================================================
    enum class CURSOR
    {
        ON,
        OFF
    };

    //====================================================
    //     FUNCTIONS DECLARATION
    //====================================================
    extern std::string feat(const std::initializer_list<t_ops> ops);
    extern std::string feat(const t_ops ops);
    
    template <typename T>
    extern std::string feat(const t_ops ops,const T num );
    
    extern std::string reset( const std::string & reset_string );
    
    template<class T>
    extern std::string traverse( const T x, const T y );
    
    template<class T>
    extern std::string RGB( const T r, T g, const T b );

    //====================================================
    //     TEMPLATE FUNCTIONS DECLARATION
    //====================================================
    void CursorOpt( const CURSOR & opt ) noexcept;

    //====================================================
    //     TEMPLATE "printf" FUNCTIONS DEFINITION
    //====================================================
    template <typename... Args>
    inline void print( std::ostream & os, const Args &... args )
    {
        if( &os == &std::cerr )
            os << feat( t_ops::red ) << feat( t_ops::bold );
        else if( &os == &std::clog )
            os << feat( t_ops::lt_blue ) << feat( t_ops::bold );

        ( os << ... << args ) << "\n";

        if( &os == &std::cerr || &os == &std::clog || &os == &std::cout ) os << feat( t_ops::rst_all );
    }

    template <typename... Args>
    inline void print( Args &... args )
    {
        ( std::cout << ... << args ) << "\n"
                                     << feat( t_ops::rst_all );
    }
}      // namespace outStream

#endif