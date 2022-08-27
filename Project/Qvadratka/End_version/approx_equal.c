#include <stdio.h>
#include <cmath>
#include <ctype.h>

#include "approx_equal.h"


static const double delta = 0.00001;

bool approx_equal(const double x, const double a)
{

    if ( fabs(x - a) < delta )
    {
        return true;
    }
    else
    {
        return false;
    }
}

double ATOF ( const char* s)
{
    int sign = (*s == '-') ? -1 : 1;

    if (*s == '+' || *s == '-') s++;

    double d = 0;
    int    k = 1;

    while( isdigit(*s))
    {
        d = d * 10 + *s - '0';
        s++;
    }
    if ( *s == '.')
    {
        s++;
        while ( isdigit(*s))
        {
            d = d * 10 + *s - '0';
            k *= 10;
            s++;
        }
    }

    if (*s == '\0') return sign * d / k;
    else return NAN;

}
