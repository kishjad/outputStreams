// My headers
#include "helper_tools.hpp"

// STD headers
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <type_traits>
#include <stdexcept>
#include <cmath>

namespace osm
{
    //====================================================
    //     GLOBAL VARIABLES DECLARATION
    //       (in implementation file)
    //====================================================
    std::string output, error;

    //====================================================
    //     OPERATOR * REDEFINITIONS
    // (to multiply strings by an integer)
    //====================================================
    std::string operator*( const std::string & generic_string, unsigned int integer )
    {
        output = "";
        while( integer-- )
        {
            output += generic_string;
        }
        return output;
    }

    std::string operator*( unsigned int integer, const std::string & generic_string )
    {
        return generic_string * integer;
    }

    //====================================================
    //     FUNCTION FOR CUSTOMIZED RUNTIME ERROR
    //====================================================
    template <typename T>
    std::runtime_error runtime_error_func( const std::string & beg, T variable, const std::string & end )
    {
        error = beg +
           static_cast<std::string>( " \"" ) +
           static_cast<std::string>( variable ) +
           static_cast<std::string>( "\" " ) +
           end +
           "\n";
        return std::runtime_error( error );
    }

    template std::runtime_error runtime_error_func<std::string>( const std::string & beg, std::string variable, const std::string & end );
    template std::runtime_error runtime_error_func<const char *>( const std::string & beg, const char * variable, const std::string & end );

    //====================================================
    //     FUNCTION TO CHECK IF A CONDITION IS VERIFIED
    //     AND IN POSITIVE CASE RETURN IT
    //====================================================
    template <typename T>
    T check_condition( const std::function<bool()> & condition, const T & return_it, const T & return_false )
    {
        if( condition() )
            return return_it;
        else
            return return_false;
    }

    template int check_condition<int>( const std::function<bool()> & condition, const int & return_it, const int & return_false );
    template long check_condition<long>( const std::function<bool()> & condition, const long & return_it, const long & return_false );
    template long long check_condition<long long>( const std::function<bool()> & condition, const long long & return_it, const long long & return_false );
    template long double check_condition<long double>( const std::function<bool()> & condition, const long double & return_it, const long double & return_false );
    template float check_condition<float>( const std::function<bool()> & condition, const float & return_it, const float & return_false );
    template double check_condition<double>( const std::function<bool()> & condition, const double & return_it, const double & return_false );
    template std::string check_condition<std::string>( const std::function<bool()> & condition, const std::string & return_it, const std::string & return_false );

    //====================================================
    //     FUNCTION TO CHECK IF EXPRESSION TYPE IS
    //     FLOATING POINT
    //====================================================
    template <typename T>
    bool isFloatingPoint( const T & expression )
    {
        return std::is_floating_point<T>::value;
    }

    // Explicit instantiations:
    template bool isFloatingPoint<int>( const int & expression );
    template bool isFloatingPoint<long>( const long & expression );
    template bool isFloatingPoint<long long>( const long long & expression );
    template bool isFloatingPoint<float>( const float & expression );
    template bool isFloatingPoint<double>( const double & expression );
    template bool isFloatingPoint<long double>( const long double & expression );

    //====================================================
    //     FUNCTION TO ROUND A FLOATING POINT TO N
    //     DECIMAL PLACES
    //====================================================
    template <typename T>
    extern T roundoff( const T & value, const unsigned char prec )
    {
        T pow_10 = pow( 10.0f, static_cast<T>( prec ) );
        return round( value * pow_10 ) / pow_10;
    }

    // Explicit instantiations:
    template int roundoff<int>( const int & value, const unsigned char prec );
    template double roundoff<double>( const double & value, const unsigned char prec );
    template long double roundoff<long double>( const long double & value, const unsigned char prec );
    template long roundoff<long>( const long & value, const unsigned char prec );
    template long long roundoff<long long>( const long long & value, const unsigned char prec );
    template float roundoff<float>( const float & value, const unsigned char prec );

    //====================================================
    //     FUNCTION TO CHECK IF A NUMBER LIE IN A
    //     CERTAIN BOUND
    //====================================================
    template <typename T>
    bool IsInBounds( const T & value, const T & low, const T & high )
    {
        return !( value < low ) && ( value < high );
    }

    // Explicit instantiations:
    template bool IsInBounds<int>( const int & value, const int & low, const int & high );
    template bool IsInBounds<double>( const double & value, const double & low, const double & high );
    template bool IsInBounds<long double>( const long double & value, const long double & low, const long double & high );
    template bool IsInBounds<long>( const long & value, const long & low, const long & high );
    template bool IsInBounds<long long>( const long long & value, const long long & low, const long long & high );
    template bool IsInBounds<float>( const float & value, const float & low, const float & high );
}      // namespace osm