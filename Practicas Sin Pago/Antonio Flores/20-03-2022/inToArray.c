// En C
#include <stdio.h>
int main()
{
    int numero;
    int arreglo[10];
    int arreglo2[10];
    int i = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    while (numero > 0)
    {
        arreglo[i] = numero % 10;
        numero /= 10;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        arreglo2[j] = arreglo[i - j - 1];
    }
    printf("El numero en arreglo es: [ ");
    for (int j = 0; j < i - 1; j++)
    {
        printf("%d, ", arreglo2[j]);
    }
    printf("%d ]\n", arreglo2[i - 1]);
    return 0;
}