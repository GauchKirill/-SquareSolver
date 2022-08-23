#include <stdio.h>
#include <math.h>
#include <cmath>
#include <assert.h>


#define min(a, b) (a < b) ? a : b
#define max(a, b) (a > b) ? a : b


const int All_number = 3;
const double delta = 0.00001;


//-----------------------------------------------------------------------------------------------------
/**
* @brief It's Square solution ax^2 + bx + c = 0.
* @param [in] a – coeficient at x^2
* @param [in] b – coeficient at x
* @param [in] c – free coefficient
* @param [out] x1 – first of two solutions
* @param [out] x2 – second of two solutions
* @return
*         number of roots
* @note
*         Good job
*/
//-----------------------------------------------------------------------------------------------------


int SolveSquare(const double a, const double b, const double c, double* const x1, double* const x2);
int approx_equal (const double x, const double a);
void check_SolveSquare(void);


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
            case All_number:
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
            if (approx_equal(c, 0)) return All_number;
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
            double SQRT_D = sqrt(D);

            *x1 = (-b - SQRT_D) / (2 * a);
            *x2 = (-b + SQRT_D) / (2 * a);

            return 2;
        }
    }
}


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


void check_SolveSquare(void)
{
    double x1 = 0, x2 = 0;
    int mis = 0;

    if (SolveSquare(0, 0, 0, &x1, &x2) != All_number) mis++;

    if (SolveSquare(0, 0, 1, &x1, &x2) != 0) mis++;

    if (SolveSquare(0, 1, 0, &x1, &x2) != 1 ||
        !approx_equal(x1, 0)) mis++;

    if (SolveSquare(5, 0, 0, &x1, &x2) != 1 ||
        !approx_equal(x1, 0)) mis++;

    if (SolveSquare(0, 20, 1, &x1, &x2) != 1 ||
        !approx_equal(x1,-0.05)) mis++;

    if (SolveSquare(1, 0, -25, &x1, &x2) != 2 ||
        !approx_equal(min(x1, x2), -5) ||
        !approx_equal(max(x1, x2), 5)) mis++;

    if (SolveSquare(-25, 150, 0, &x1, &x2) != 2 ||
        !approx_equal(min(x1, x2), 0) ||
        !approx_equal(max(x1, x2), 6)) mis++;

    if (SolveSquare(1, 1, 1, &x1, &x2) != 0) mis++;

    printf("Number of validation errors: %d\n", mis);
}

