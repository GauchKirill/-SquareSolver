/// @file //
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <assert.h>
#include "approx_equal.h"

#define ALL_NUMBER -1


/// @brief It's Square solution ax^2 + bx + c = 0.
/// @param [in] a
/// @param [in] b
/// @param [in] c
/// @param [out] x1
/// @param [out] x2
/// @return
///         number of roots
int SolveSquare(const double a, const double b, const double c, double* const x1, double* const x2);
