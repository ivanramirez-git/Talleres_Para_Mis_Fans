#include <stdio.h>
int main()
{
    float a1, b1, a2, b2, x, y, c1, c2;
    printf("Ingrese los valores:\n");
    printf("a1: ");
    scanf("%f", &a1);
    printf("b1: ");
    scanf("%f", &b1);
    printf("c1: ");
    scanf("%f", &c1);
    printf("a2: ");
    scanf("%f", &a2);
    printf("b2: ");
    scanf("%f", &b2);
    printf("c2: ");
    scanf("%f", &c2);
    x = (c1*b2 - c2*b1)/(a1*b2 - a2*b1);
    y = (c2*a1 - c1*a2)/(a1*b2 - a2*b1);
    printf("x = %f\n", x);
    printf("y = %f\n", y);
    return 0;
}