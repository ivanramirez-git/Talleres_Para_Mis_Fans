#include <stdio.h>

int main()
{
    long long segundos;
    printf("ingrese la cantidad de segundos: ");
    scanf("%lld", &segundos);

    int a = 0;
    int d = 0;
    int h = 0;
    int m = 0;
    int s = 0;

    a = segundos / 31536000;
    d = (segundos % 31536000) / 86400;
    h = (segundos % 86400) / 3600;
    m = (segundos % 3600) / 60;
    s = segundos % 60;

    printf("%d %d %d %d %d\n", a, d, h, m, s);

    return 0;
}