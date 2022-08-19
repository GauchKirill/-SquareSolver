#include <stdio.h>
#include <math.h>
#include <ctype.h>

enum {openfunk, closefunk, op, SQRT, digit, x, x2, equals, END};

typedef struct coeff {
    double a;
    double b;
    double c;
} CF;

void Solv(double *a, double *b, double *c);
void getcf(CF *);
int getop(char c);
int getch(void);
void ungetch(int);

int main () {
    printf("Enter the monomials of the equation in this form \"ax^2\", \"bx\", \"c\", where a, b, c is numeric expressions.\n");
    CF left;
    left.a = left.b = left.c = 0.0;
    CF right;
    right.a = right.b = right.c = 0.0;

    getcf(&left);

    double a = 0, b = 0, c = 0;
    a = left.a - right.a;
    b = left.b - right.b;
    c = left.c - right.c;
    Solv(&a, &b, &c);
    return 0;
}
void getcf(CF *d) {
    char c;
    switch (getop(c)) {
        case openfunk:
            ;
        case closefunk:
            ;
        case op:
            ;
        case digit:
            ;
        case SQRT:
            ;
        case x:
            ;
        case x2:
            ;
        default:
            ;
    }
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
int getop(char c) {
    while((c = getch()) == ' ');
    if (c == '(') return openfunk;
    if (c == '*' || c == '/' || c == '+' || c == '-') {
        if (!isdigit(c = getch())) {
            return op;
        }
        ungetch(c);
    }
    if (c == ')') return closefunk;
    if (c == 's') {
        if((c = getch()) == 'q') {
            if((c = getch()) == 'r') {
                if((c = getch()) == 't') {
                    if((c = getch()) == '(') {
                        return SQRT;
                    }
                }
            }
        }
    }
    if (isdigit(c) || c == '+' || c == '-' || tolower(c) == 'x') {
        ungetch(c);
        return digit;
    }
    if (c == '=') return equals;
    if (c == '\n') return END;
    return EOF;
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
