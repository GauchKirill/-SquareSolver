/// @file //
#ifndef SOLVE_SQUARE_H
#define SOLVE_SQUARE_H


#include "approx_equal.h"


/// @brief It's Square solution ax^2 + bx + c = 0.
/// @param [in] a
/// @param [in] b
/// @param [in] c
/// @param [out] x1
/// @param [out] x2
/// @return
///         number of roots
int SolveSquare( const double a, const double b, const double c, double* const x1, double* const x2 );

#endif // SOLVE_SQUARE_H
