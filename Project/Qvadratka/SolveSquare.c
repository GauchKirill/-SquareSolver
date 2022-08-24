#include <stdio.h>
#include <math.h>
#include <cmath>
#include <assert.h>
#include "approx_equal.h"
#include "SolveSquare.h"


int SolveSquare(const double a, const double b, const double c, double* const x1, double* const x2)
{
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);


    if (approx_equal(a, 0))
    {
        if (approx_equal(b, 0))
        {
            if (approx_equal(c, 0)) return ALL_NUMBER;
            else return 0;
        }
        else
        {
            *x1 = - c / b;
            return 1;
        }
    }
    else
    {
        double D = 0;

        D = b*b - 4*a*c;

        if (approx_equal(D, 0))
        {
            *x1 = - b / (2 * a);
            return 1;
        }
        else if (D < 0)
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
