#include <stdio.h>
#include <math.h>

double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

void Solv(double *a, double *b, double *c);

int main () {
    printf("Enter the monomials of the equation in this form \"a*x^2\", \"b*x\", \"c\", where a, b, c is numeric expressions.\n");

    double a = 0, b = 0, c = 0;
    scanf("%lf%lf%lf", &a, &b, &c);
    /*a = a1 - a2;
    b = b1 - b2;
    c = c1 - c2;*/
    Solv(&a, &b, &c);
    return 0;
    error: printf("Invalid input.");
}
void Solv(double *a, double *b, double *c) { //Вычисляем решение по коэффициэнтам
    if (*a == 0.0) {
        if (*b == 0.0) {
            if (*c == 0) {
                printf("x is any real number.\n");
            } else {
                printf("The equation has no solutions.\n");
            }
        } else {
            printf("x = %-6.4lf\n", (*c) / (*b));
        }
    } else {
        double D = 0;
        D = (*b) * (*b) - 4 * (*a) * (*c);
        if (D < 0) {
            printf("The equation has no solutions.\n");
        } else if (D == 0) {
            printf("x = %-6.4lf\n", (- *b) / (2 * (*a)));
        } else {
            double x1 = 0, x2 = 0;
            x1 = (- (*b) - sqrt(D)) / (2 * (*a));
            x2 = (- (*b) + sqrt(D)) / (2 * (*a));
            printf("X1 = %-6.4lf\nX2 = %-6.4lf\n", x1, x2);
        }
    }
}
#define MAXCNT 100
double SUM[MAXCNT];
double *p; //указатель на свободную ячейку
p = &SUM;
void operation(double &a, double &b, double &c) {

}
