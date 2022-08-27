/// @file //
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <stdlib.h>

#include "SolveSquare.h"
#include "compare.h"
#include "assert_or_const.h"
#include "check_SolveSquare.h"

const int proga = 1;
const int from_file = 0;
const char* DEFAULT_TEST_FILE = "Tests.txt";

bool check_SolveSquare( bool method, const char* s)
{
    int OkTest = 0, nTest = 0, valid_test = 0;
    if ( method == from_file )
    {
        FILE *File;
        File = fopen( s, "r");

        if ( File == NULL)
        {
            printf( "\"fopen()\": file named \"%s\" not found.\nTry again.\n", s);
            return 1;

        }

        double a  = 0,
               b  = 0,
               c  = 0,
               x1 = 0,
               x2 = 0;

        int nRoots = 0;

        check_from_file( File, &OkTest, &nTest, &valid_test, &a, &b, &c, &nRoots, &x1, &x2);

        fclose( File);

    }
    else if ( method == proga )
    {
//                 a    b    c      nRoots     x1 x2
        nTest++; valid_test++;
        if( Test(  0,   0,   0, ALL_NUMBER,     0, 0))
        {
            OkTest++;
            printf( "Test number %d is passed\n", nTest);
        }

        nTest++; valid_test++;
        if( Test(  0,   0,   1,          0,     0, 0))
        {
            OkTest++;
            printf( "Test number %d is passed\n", nTest);
        }

        nTest++; valid_test++;
        if( Test(  0,   1,   0,          1,     0, 0))
        {
            OkTest++;
            printf( "Test number %d is passed\n", nTest);
        }

        nTest++; valid_test++;
        if( Test(  5,   0,   0,          1,     0, 0))
        {
            OkTest++;
            printf( "Test number %d is passed\n", nTest);
        }

        nTest++; valid_test++;
        if( Test(  0,  20,   1,          1, -0.05, 0))
        {
            OkTest++;
            printf( "Test number %d is passed\n", nTest);
        }

        nTest++; valid_test++;
        if( Test(  1,   0, -25,          2,    -5, 5))
        {
            OkTest++;
            printf( "Test number %d is passed\n", nTest);
        }

        nTest++; valid_test++;
        if( Test(-25, 150,   0,          2,     0, 6))
        {
            OkTest++;
            printf( "Test number %d is passed\n", nTest);
        }

        nTest++; valid_test++;
        if( Test(  1,   1,   1,          0,     0, 0))
        {
            OkTest++;
            printf( "Test number %d is passed\n", nTest);
        }

    }
    else
    {
        printf( "check_SolveSquare: error\n"
                "method = %d. Mast be 0 or 1", method );
        abort();
    }

    printf( "Correctly passed %d tests out of %d, invalid tests %d\n", OkTest, valid_test, (nTest - valid_test));

    return 0;
}


int Test( const double a, const double b, const double c, const int nRoots, const double solv1, const double solv2)
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
                if ( !approx_equal( MIN_BUT_NOT_DED(x1, x2), MIN_BUT_NOT_DED(solv1, solv2)) ||
                     !approx_equal( MAX_BUT_NOT_DED(x1, x2), MAX_BUT_NOT_DED(solv1, solv2)) ) goto Error;
                break;

            default:
                printf( "Test: nRoots is wrong\n" );
                break;
        }
    }

    return 1;

    Error:
        printf( "Wrong answer for {a, b, c} = {%lg, %lg, %lg}\n", a, b, c );

        PrintVerdict( verdict, &x1,    &x2,    false );
        PrintVerdict( nRoots,  &solv1, &solv2, true );

    return 0;
}

void PrintVerdict( const int verdict, const double* const x1, const double* const x2, const bool is_expected )
{
    (is_expected == false) ? printf( "FAILED:   nRoots = " ) :
                             printf( "EXPECTED: nRoots = " );

    switch( verdict )
    {
        case ALL_NUMBER:
            printf( "inf\n" );
            break;

        case 0:
            printf( "%d\n",                     verdict );
            break;

        case 1:
            printf( "%d, x1 = %lg\n",           verdict, *x1 );
            break;

        case 2:
            printf( "%d, x1 = %lg, x2 = %lg\n", verdict, *x1, *x2 );
            break;

        default:
            printf( "PrintVerdict: Error\n" );
            break;
    }
}


void check_from_file( FILE* file, int* OkTest, int* nTest, int* valid_test,
                      double* const a,      double* const b,  double* const c,
                      int*    const nRoots, double* const x1, double* const x2)
{
    int end_string = '\0';

    while( end_string != EOF)
    {
        int fail = 0;

        if ( fscanf( file, "%lg %lg %lg %d %lg %lg", a, b, c, nRoots, x1, x2) == CNT_ARG_TEST)
        {
            (*nTest)++;
            end_string = check_input( file, &fail);

            if ( (fail == 0))
            {

                (*valid_test)++;

                if( Test( *a, *b, *c, *nRoots, *x1, *x2))
                {
                    (*OkTest)++;
                    printf( "Test number %d is passed for {a, b, c} = {%lg, %lg, %lg} \n", *nTest, *a, *b, *c);

                }
            } else
            {
                printf( "Incorrect test entry number %d\n", *nTest);
            }

        } else
        {
            end_string = check_input( file, &fail);

            if (fail != 0)
            {
                (*nTest)++;
                printf( "Incorrect test entry number %d\n", *nTest);
            }

        }

    }

}
