/// @file //

#ifndef COMPARE_H
#define COMPARE_H

/// @brief Returns the maximum value
/// @param [in] a - comparable number
/// @param [in] b - comparable number
/// @return
///         max(a, b)
double MAX_BUT_NOT_DED( const double a, const double b );

/// @brief Returns the minimum value
/// @param [in] a - comparable number
/// @param [in] b - comparable number
/// @return
///         min(a, b)
double MIN_BUT_NOT_DED( const double a, const double b );

/// @brief Is it a real number?
/// @param [in] x
/// @return
///         1 - is a real number
///         0 - is a real number
bool Isfinite( double x );

/// @brief Ñhecks for correct input
/// @param [in] file - stream
/// @return
///         1 - correct input
///         0 - invalid input
int check_input( FILE* file, int* fail);
#endif
