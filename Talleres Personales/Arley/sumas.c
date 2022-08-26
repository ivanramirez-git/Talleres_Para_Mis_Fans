#include <stdio.h>

int main()
{
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    int suma = 0;
    while (n > 9)
    {
        while (n > 0)
        {
            suma += n % 10;
            n /= 10;
        }
        n = suma;
        suma = 0;
    }
    printf("El n es %d\n", n-1);

    return 0;
}