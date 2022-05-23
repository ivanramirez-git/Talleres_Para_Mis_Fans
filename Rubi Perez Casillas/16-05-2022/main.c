#include <stdio.h>

#define N 30                      // Valor limite de la serie
#define PI 3.14159265358979323846 // Valor de pi

double Rad(double deg)
{
    return (deg * PI / 180.0);
}

double Deg(double rad)
{
    return (rad * 180.0 / PI);
}

double potencia(double x, int n)
{
    int i;
    double pot = 1;
    for (i = 1; i <= n; i++)
    {
        pot = pot * x;
    }
    // printf("\nPotencia de %f elevado a %d es %f", x, n, pot);
    return pot;
}

double cos(double x)
{
    // Serie de Taylor
    /*
    cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + x^8/8! - x^10/10! + ... + x^(2n)/(2n)!
    */
    int i, j, expo = 0;
    double factorial = 1, signo = -1, c = 0;
    for (i = 0; i <= N; i++)
    {
        factorial = 1;
        for (j = 1; j <= expo; j++)
            factorial *= j;

        signo *= -1;
        c += signo * potencia(x, expo) / factorial;
        expo += 2;
    }
    return c;
}

double sin(double x)
{
    // Serie de Taylor
    /*
    sin(x) = x/1! - x^3/3! + x^5/5! - x^7/7! + x^9/9! - x^11/11! + ... + x^(2n+1)/(2n+1)!
    */
    int i, j, expo = 1;
    double factorial = 1, signo = -1, s = 0;
    for (i = 1; i <= N; i++)
    {
        factorial = 1;
        for (j = 1; j <= expo; j++)
            factorial *= j;

        if (i % 2 == 0)
            s -= potencia(x, expo) / factorial;
        else
            s += potencia(x, expo) / factorial;

        expo += 2;
    }
    return s;
}

int main()
{

    // Menu
    int opcion;
    double angulo = -1, resultado;

    do
    {

        printf("1. Coseno\n");
        printf("2. Seno\n");
        printf("3. Definir angulo\n");
        printf("0. Salir\n");
        printf("\n");
        printf("Ingrese una opcion: ");
        do
        {
            scanf("%d", &opcion);
            if (opcion < 0 || opcion > 3)
                printf("Opcion invalida, ingrese una opcion valida: ");
        } while (opcion < 0 || opcion > 3);

        switch (opcion)
        {
        case 1:
            if (angulo == -1)
                printf("\nNo se ha definido un angulo\n");
            else
            {
                resultado = cos(Rad(angulo));
                printf("\nEl coseno de %f es %f\n", angulo, resultado);
            }
            break;
        case 2:
            if (angulo == -1)
                printf("\nNo se ha definido un angulo\n");
            else
            {
                resultado = sin(Rad(angulo));
                printf("\nEl seno de %f es %f\n", angulo, resultado);
            }
            break;
        case 3:
            printf("\nIngrese un angulo: ");
            scanf("%lf", &angulo);
            break;
        }
    } while (opcion != 0);

    return 0;
}