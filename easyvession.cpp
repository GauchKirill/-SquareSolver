#include <stdio.h>
#include <math.h>
#include <ctype.h>
enum {right = 1, error = 2};

void Solv(double *a, double *b, double *c);
char getdigit(double *x);
int getch(void);
void ungetch(int c);

int main() {
    printf("%s", "Enter the coefficients \"a\" \"b\" \"c\" of the quadratic equation \"ax^2 + bx + c = 0\".\nSeparate them with spaces.\n");
    double a, b, c;
    a = 0.0;
    b = 0.0;
    c = 0.0;
    if (getdigit(&a) == ' ') {
        if (getdigit(&b) == ' ') {
            if(getdigit(&c) == '\n') {
                Solv(&a, &b, &c);
            } else {
                printf("Invalid input.\n");
            }
        } else {
            printf("Invalid input.\n");
        }
    } else {
        printf("Invalid input.\n");
    }
    return 0;
}
char getdigit(double *x) {
    char c = 0;
    while((c = getch()) == ' ' || c == '\t');
    int sign;
    sign = 1;
    sign = (c == '-') ? -1 : 1;
    if (c != '+' && c != '-') ungetch(c);
    int n1, n2;
    double n;
    n1 = error;
    n2 = right;
    int k = 1;
    n = 0;
    while(isdigit(c = getch())) {
        n  = 10 * n + c - '0';
        n1 = right;
    }
    if (c == '.') {
        n2 = error;
        while (isdigit(c = getch())) {
            n2 = right;
            k *= 10;
            n = 10 * n + c - '0';
        }
    }
    if (n1 == right && n2 == right) {
        *x = sign * n / k;
        if (c == ' ') {
            return ' ';
        } else if (c == '\n') {
            return '\n';
        }
    }
    return EOF;
}
void Solv(double *a, double *b, double *c) {
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
            double x1 = 0.0, x2 = 0.0;
            x1 = (- (*b) - sqrt(D)) / (2 * (*a));
            x2 = (- (*b) + sqrt(D)) / (2 * (*a));
            printf("X1 = %-6.4lf\nX2 = %-6.4lf\n", x1, x2);
        }
    }
}
#define BUFSIZE 100
char buf[BUFSIZE];

int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch(): I'm full!!!\n");
    } else {
        buf[bufp++] = c;
    }
}
