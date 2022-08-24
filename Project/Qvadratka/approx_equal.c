#include <stdio.h>
#include <cmath>

static const double delta = 0.00001;

int approx_equal(const double x, const double a)
{

    if (fabs(x - a) < delta)
    {
        return true;
    }
    else
    {
        return false;
    }
}

