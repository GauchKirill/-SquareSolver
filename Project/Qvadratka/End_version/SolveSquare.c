#include <stdio.h>
#include <math.h>
#include <cmath>

#include "approx_equal.h"
#include "SolveSquare.h"
#include "compare.h"
#include "line_equation.h"
#include "assert_or_const.h"

int SolveSquare( const double a, const double b, const double c, double* const x1, double* const x2 )
{
    ASSERT_ABORT( Isfinite(a) );
    ASSERT_ABORT( Isfinite(b) );
    ASSERT_ABORT( Isfinite(c) );

    ASSERT_ABORT( x1 != NULL );
    ASSERT_ABORT( x2 != NULL );
    ASSERT_ABORT( x1 != x2 );


    if ( approx_equal(a, 0) )
    {
        return line_equation(b, c, x1);
    }
    else
    {
        double D = 0;

        D = b*b - 4*a*c;

        if ( approx_equal(D, 0) )
        {
            *x1 = - b / (2 * a);
            return 1;
        }
        else if ( D < 0 )
        {
            return 0;
        }
        else // D > 0
        {
            const double sqrt_D = sqrt(D);

            *x1 = (-b - sqrt_D) / (2 * a);
            *x2 = (-b + sqrt_D) / (2 * a);

            return 2;
        }
    }
}
