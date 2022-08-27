#include <stdio.h>
#include <math.h>
#include <cmath>
#include <ctype.h>
#include <string.h>

#include "assert_or_const.h"
#include "check_SolveSquare.h"
#include "SolveSquare.h"
#include "compare.h"
#include "Modes.h"


#define LINE 10


bool USUAL_MODE(void)
{

    printf( "Enter the coefficients \"a\" \"b\" \"c\" "
            "of the quadratic equation \"ax^2 + bx + c = 0\".\n"
            "Separate them with spaces.\n" );

    double  a = 0,
            b = 0,
            c = 0;

    while( true)
    {
        fflush( stdin);

        int fail = 0;
        int end_string = 0;

        if ( scanf( "%lg %lg %lg", &a, &b, &c ) == 3)
        {
            end_string = check_input( stdin, &fail);

            if ( end_string == '\n' && (fail == 0)) break;
            else printf( "Invalid input. Try again.\n" );

        } else
        {
            printf( "Invalid input. Try again.\n" );
        }

    }

    Accept_right_arg_and_solve(a, b, c);

    return true;
}


void Accept_right_arg_and_solve( const double a, const double b, const double c)
{
    double x1 = 0, x2 = 0;

    int root_num = SolveSquare( a, b, c, &x1, &x2);

    switch ( root_num ) {
        case 0:
            printf( "No solution.\n" );
            break;

        case 1:
            printf( "x = %-10.6lg\n", x1 );
            break;

        case 2:
            printf( "x1 = %-10.6lg\nx2 = %-10.6lg\n", x1, x2 );
            break;

        case ALL_NUMBER:
            printf( "X is any real number.\n" );
            break;

        default:
            printf( "ERROR in switch() in USUAL_MODE()\n"
                    "root_num = %d at a = %lg, b = %lg, c = %lg\n", root_num, a, b, c);
            return;
    }
}


int Processing_input(int argc, const char** argv)
{
    if ( argc == 1)
    {
        if( !USUAL_MODE())
        {
            printf( "Error in USUAL_MODE()\n");
        }

    } else
    if ( argc == 2)
    {
        if ( strcmp( argv[1], "-i") == 0 || strcmp( argv[1], "--interactive_mode") == 0)
        {
            if( !USUAL_MODE())
            {
                printf( "Error in USUAL_MODE()\n");
            }

        } else
        if ( strcmp( argv[1], "-f") == 0 || strcmp( argv[1], "--test_from_file")   == 0)
        {

            if ( check_SolveSquare( from_file, DEFAULT_TEST_FILE)) goto Error_arg;

        } else
        if ( strcmp( argv[1], "-p") == 0 || strcmp( argv[1], "--program_testing")  == 0)
        {

            if ( check_SolveSquare( proga, 0)) goto Error_arg;

        } else
        if ( strcmp( argv[1], "--help") == 0)
        {

            printf( "............solution of a quadratic equation............\n"
                    "One of the following switches must be given:\n"
                    "-i, --interactive_mode    switches to interactive mode\n"
                    "-f, --test_from_file      tests the system from a file\n"
                    "-p, --program_testing     tests the system from a program\n");

        } else
        {

            printf( "The arguments are not an internal command executed by the program. Try again.\n");
            goto Error_arg;

        }
    } else
    if ( argc == 3)
    {

        if ( strcmp( argv[1], "-f") == 0 || strcmp( argv[1], "--test_from_file") == 0)
        {

            if ( check_SolveSquare( from_file, argv[2]) == 0);
            else
            {
                goto Error_arg;
            }

        } else
        {

            printf( "The arguments are not an internal command executed by the program.\nTry again\n");
            goto Error_arg;

        }
    } else
    if ( argc == 4)
    {

        double  a = ATOF( argv[1]),
                b = ATOF( argv[2]),
                c = ATOF( argv[3]);

        if (a != NAN && b != NAN && c != NAN)
        {

            Accept_right_arg_and_solve(a, b, c);

        } else
        {

            printf( "Invalid input. Try again.\n");
            goto Error_arg;

        }

    } else
    {

        printf( "The arguments are not an internal command executed by the program.\nTry again\n");
        goto Error_arg;

    }

    return 0;

    Error_arg:
        return 1;
}
