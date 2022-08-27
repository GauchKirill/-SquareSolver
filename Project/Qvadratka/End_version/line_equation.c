#include <stdio.h>

#include "approx_equal.h"
#include "SolveSquare.h"
#include "assert_or_const.h"
#include "line_equation.h"

int line_equation( const double a, const double b, double* const x)
{
    if ( approx_equal(a, 0) )
        {
            if ( approx_equal(b, 0) ) return ALL_NUMBER;
            else return 0;
        }
        else
        {
            *x = - b / a;
            return 1;
        }
}
