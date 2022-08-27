#include <stdio.h>
#include <inttypes.h>

#include "compare.h"


double MAX_BUT_NOT_DED( const double a, const double b )
{
    return (a > b) ? a : b;
}

double MIN_BUT_NOT_DED( const double a, const double b )
{
    return (a < b) ? a : b;
}

bool Isfinite( double x )
{
    uint64_t n = *( uint64_t*) &x;

    n <<= 1;
    n >>= 53;

    return ( n != 0x7ff );
}

int check_input( FILE* file, int* fail)
{
    *fail = 0;
    int c = 0;

    while ( (c = getc( file)) != '\n' && c != EOF)
    {
        if (c != ' ' && c != '\t') (*fail)++;
    }

    return c;
}
