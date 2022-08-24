#include <stdio.h>
#include <math.h>
#include <cmath>
#include "check_SolveSquare.h"
#include "SolveSquare.h"

int main()
{
    check_SolveSquare();

    printf("%s", "Enter the coefficients \"a\" \"b\" \"c\" of the quadratic equation \"ax^2 + bx + c = 0\".\nSeparate them with spaces.\n");

    double  a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    if ( scanf("%lg %lg %lg", &a, &b, &c) == 3 )
    {
        int temp = SolveSquare(a, b, c, &x1, &x2);
        switch ( temp ) {
            case 0:
                printf("No solution.");
                break;
            case 1:
                printf("x = %-10.6lg", x1);
                break;
            case 2:
                printf("x1 = %-10.6lg\nx2 = %-10.6lg", x1, x2);
                break;
            case ALL_NUMBER:
                printf("X is any real number.");
            default:
                printf("ERROR in main()");
                return 1;
        }
    }
    else
    {
        printf("Invalid input.");
        return 1;
    }

    return 0;
}

