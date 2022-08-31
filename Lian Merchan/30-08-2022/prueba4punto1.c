#include <stdio.h>

int pedirAltura();
void imprimirTrianguloSuperior(int altura);
void imprimirTrianguloInferior(int altura);
void imprimirTriangulo(int altura);

int main()
{
    printf("Prueba 4: Triangulo\n");
    int altura = pedirAltura();
    imprimirTriangulo(altura);
    return 0;
}

int pedirAltura()
{
    int altura;
    do
    {
        printf("Ingrese altura del triangulo: ");
        scanf("%d", &altura);
    } while (altura <= 0 || altura % 2 == 0);
    return altura;
}

void imprimirTriangulo(int altura)
{
    imprimirTrianguloSuperior(altura);
    int i = 0;
    for (i = 0; i < altura; i++)
    {
        printf("*");
    }
    printf("\n");
    imprimirTrianguloInferior(altura);
}

void imprimirTrianguloSuperior(int altura)
{
    int i = 0;
    for (i = altura - 1; i >= 0; i--)
    {
        for (int j = 0; j < altura; j++)
        {
            if (j < altura - i)
            {
                printf("*");
            }
            else
            {
                printf("O");
            }
        }
        printf("\n");
    }
}

void imprimirTrianguloInferior(int altura)
{
    int i = 0;
    for (i = 0; i < altura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            if (j < altura - i)
            {
                printf("*");
            }
            else
            {
                printf("O");
            }
        }
        printf("\n");
    }
}