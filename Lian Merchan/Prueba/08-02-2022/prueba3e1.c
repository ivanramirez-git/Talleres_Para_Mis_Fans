#include <stdio.h>

void lecturadatos(int vector[], int tam);
int validacionnumero(int numero, int min, int max);
int primo(int numero);
int primocercano(int numero);
void imprimirvector(int vector[], int tam);

int main()
{
    int n = -1;
    printf("Prueba 3: Nombre [num unico]\n");
    printf("Primos cercanos\n");

    //Lectura de numero
    while(validacionnumero(n,1,6) < 0)
    {
        printf("Cantidad de numeros a ingresar: ");
        scanf("%d", &n);
    }

    //Lectura de datos
    int vector[n];
    int vectorPrimos[n];
    lecturadatos(vector, n);

    //Primos cercanos
    for(int i = 0; i < n; i++)
    {
        vectorPrimos[i] = primocercano(vector[i]);
    }

    //Impresion de datos
    printf("Vector original:\n");
    imprimirvector(vector, n);

    printf("Vector primos cercanos:\n");
    imprimirvector(vectorPrimos, n);

    return 0;
}

// Lectura de datos
void lecturadatos(int vector[], int tam)
{
    int dato;
    for(int i = 0; i < tam; i++)
    {
        printf("[%d]: ", i);
        scanf("%d", &dato);

        while(validacionnumero(dato,2,50) < 0)
        {
            printf("[%d]: ", i);
            scanf("%d", &dato);
        }

        vector[i] = dato;
    }
}

// Validacion de numero
int validacionnumero(int numero, int min, int max)
{
    if(numero < min || numero > max)
    {
        return -1;
    }
    else
    {
        return numero;
    }
}

// Primo
int primo(int numero)
{
    int contador = 0;
    for(int i = 1; i <= numero; i++)
    {
        if(numero % i == 0)
        {
            contador++;
        }
    }
    if(contador == 2)
    {
        return 1;
    }
    return 0;
}

// Primo cercano
int primocercano(int numero)
{
    int contador = 0;
    int numeroCercanoArriba = numero;
    int numeroCercanoAbajo = numero;

    while(primo(numeroCercanoArriba) == 0)
    {
        numeroCercanoArriba++;
    }

    while(primo(numeroCercanoAbajo) == 0)
    {
        numeroCercanoAbajo--;
    }

    if(numeroCercanoArriba - numero < numero - numeroCercanoAbajo)
    {
        return numeroCercanoAbajo;
    }
    else
    {
        return numeroCercanoArriba;
    }
}

// Imprimir vector
void imprimirvector(int vector[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("[%d]: %d\n",i, vector[i]);
    }
}

