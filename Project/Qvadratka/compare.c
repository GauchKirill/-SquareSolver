#include <stdio.h>

double MAX( const double a, const double b )
{
    return (a > b) ? a : b;
}

double MIN( const double a, const double b )
{
    return (a < b) ? a : b;
}

bool Isfinite( int x )
{
    x << 1;
    x >> 24;
    if ( x == 011111111 || x == 000000000)
    {
        return false;
    }
    return true;
}
