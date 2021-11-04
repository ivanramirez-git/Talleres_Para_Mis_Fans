#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f (double x)
{
    return x*x*x + 2.0*x*x + 10.0*x - 20;
}

const int ITERACIONES_MAXIMAS = 100;
const double TOLERANCIA = 0;

int main (void)
{
    double x0, x1, temp, err;
    int n = 1;
    printf ("M\202todo de la Secante para el c\240lculo de la funci\242n: f(x)=x\374+2x\375+10x-20");
    printf ("\n\nIngrese la aproximaci\242n inicial x0: ");
    scanf  ("%lf", &x0);
    printf ("Ingrese la aproximaci\242n inicial x1: ");
    scanf  ("%lf", &x1);
    printf ("\n%-20s%-20s%-20s\n", "n", "Xn", "Error");
    printf ("0                   %g\n", x0);
    do {
        err = fabs(x0-x1);
        printf ("%-20d%-20g%-20g\n", n, x1, err);
        if (err!=0)
        {
            temp = x1;
            x1 = x1 - (x1 - x0) * f(x1) / (f(x1) - f(x0));
            x0 = temp;
        }
        n++;
    } while (err>TOLERANCIA && n<=ITERACIONES_MAXIMAS);
    putchar ('\n');
    if (n<ITERACIONES_MAXIMAS)
        printf ("La soluci\242n es: %g", x1);
    else
        printf ("No se encontr\242 la ra\241z: cambiar aproximaciones iniciales o aumentar ITERACIONES_MAXIMAS");
    printf ("\n\n");
    system ("pause");
    return EXIT_SUCCESS;
}
