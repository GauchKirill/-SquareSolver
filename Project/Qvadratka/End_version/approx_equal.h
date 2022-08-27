/// @file //
#ifndef APPROX_EQUAL_H
#define APPROX_EQUAL_H


/// @brief It determines the approximate equality of two numbers
/// @param [in] x
/// @param [in] a
/// @return
///         x is approximately equal a?  true/false
bool approx_equal( const double x, const double a );

/// @brief Converts the string to double
/// @param [in] s - convertible string
/// @return double number
/// @note
///         Returns NAN if the string is not convertible
double ATOF ( const char *s);

#endif //APPROX_EQUAL_H
