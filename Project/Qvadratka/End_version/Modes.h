/// @file //
#ifndef MADES_H
#define MADES_H

/// @brief Include interactive mode
bool USUAL_MODE( void);

/// @brief Solves the equation with transformed coefficients
/// @param [in] a - coefficient
/// @param [in] b - coefficient
/// @param [in] c - coefficient
void Accept_right_arg_and_solve( const double a, const double b, const double c);

/// @brief Parses input
/// @param [in] argc - number of arguments
/// @param [in] argv - arguments
int Processing_input( int argc, const char** argv);

#endif // MADES_H
