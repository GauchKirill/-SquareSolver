#include <stdio.h>
#include <math.h>
#include <cmath>
#include "SolveSquare.h"

#define min(a, b) (a < b) ? a : b
#define max(a, b) (a > b) ? a : b


void Test(double a, double b, double c, int nRoots, double solv1, double solv2);
void PrintVerdict(int verdict, double* x1, double* x2, int state);


void check_SolveSquare(void)
{
 //        a    b    c      nRoots     x1 x2
    Test(  0,   0,   0, ALL_NUMBER,     0, 0);
    Test(  0,   0,   1,          0,     0, 0);
    Test(  0,   1,   0,          1,     0, 0);
    Test(  5,   0,   0,          1,     0, 0);
    Test(  0,  20,   1,          1, -0.05, 0);
    Test(  1,   0, -25,          2,    -5, 5);
    Test(-25, 150,   0,          2,     0, 6);
    Test(  1,   1,   1,          0,     0, 0);
}


void Test(double a, double b, double c, int nRoots, double solv1, double solv2)
{
    double x1 = 0, x2 = 0;
    int verdict = 0;

    if ( ( verdict = SolveSquare( a, b, c, &x1, &x2 ) ) != nRoots ) goto Error;
    else
    {
        switch( nRoots )
        {
            case ALL_NUMBER:
                break;

            case 0:
                break;

            case 1:
                if ( !approx_equal(x1, solv1) ) goto Error;
                break;

            case 2:
                if ( !approx_equal( min(x1, x2), solv1 ) || !approx_equal(max(x1, x2), solv2) ) goto Error;
                break;

            default:
                printf("Test: nRoots is wrong\n");
                break;
        }
    }

    return;

    Error:
        printf( "Wrong answer for {a, b, c} = {%lg, %lg, %lg}\n", a, b, c);

        PrintVerdict(verdict, &x1,    &x2,    false);
        PrintVerdict(nRoots,  &solv1, &solv2, true);
}

void PrintVerdict(int verdict, double* x1, double* x2, int state)
{
    (state == false) ? printf("FAILED: nRoots = ") : printf("EXPECTED: nRoots = ");

    switch( verdict )
    {
        case ALL_NUMBER:
            printf("inf\n");
            break;

        case 0:
            printf("%d\n", verdict);
            break;

        case 1:
            printf("%d, x1 = %lg\n", verdict, *x1);
            break;

        case 2:
            printf("%d, x1 = %lg, x2 = %lg\n", verdict, *x1, *x2);
            break;

        default:
            printf("PrintVerdict: Error\n");
            break;
    }
}

