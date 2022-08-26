#include <stdio.h>

void generacionDatos(int vector[], int inicial, int paso, int cantidad);
int validacion(int inicial, int paso, int cantidad);
int generacionPrimos(int numero);
int primoCercano(int numero);
void imprimirVector(int vector[], int tam);

int main()
{
    int n = -1;
    printf("Prueba 3:\n");
    printf("Primos cercanos\n");
    int inicial, paso, cantidad;

    //Lectura de numero
    do{
        printf("Ingrese numero inicial: ");
        scanf("%d", &inicial);
        printf("Ingrese paso: ");
        scanf("%d", &paso);
        printf("Ingrese cantidad de numeros: ");
        scanf("%d", &cantidad);
    }while(validacion(inicial, paso, cantidad) == 0);

    //Lectura de datos
    int vector[cantidad];
    int vectorPrimos[cantidad];
    generacionDatos(vector, inicial, paso, cantidad);

    //Primos cercanos
    for(int i = 0; i < cantidad; i++)
    {
        vectorPrimos[i] = primoCercano(vector[i]);
    }

    //Impresion de datos
    printf("Vector datos: ");
    imprimirVector(vector, cantidad);

    printf("\nVector primos: ");
    imprimirVector(vectorPrimos, cantidad);

    return 0;
}

// Lectura de datos
void generacionDatos(int vector[], int inicial, int paso, int cantidad)
{
    for(int i = 0; i < cantidad; i++)
    {
        vector[i] = inicial + (i * paso);
    }
}

// Validacion de numero
int validacion(int inicial, int paso, int cantidad)
{
    if(inicial > 2 && paso > 0 && cantidad < 11)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Primo
int generacionPrimos(int numero)
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
int primoCercano(int numero)
{
    int contador = 0;
    int numeroCercanoArriba = numero;
    int numeroCercanoAbajo = numero;

    while(generacionPrimos(numeroCercanoArriba) == 0)
    {
        numeroCercanoArriba++;
    }

    while(generacionPrimos(numeroCercanoAbajo) == 0)
    {
        numeroCercanoAbajo--;
    }

    if(numeroCercanoArriba - numero > numero - numeroCercanoAbajo)
    {
        return numeroCercanoArriba;
    }
    else
    {
        return numeroCercanoAbajo;
    }
}

// Imprimir vector
void imprimirVector(int vector[], int tam)
{
    printf("[ ");
    for(int i = 0; i < tam-1; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("%d ]", vector[tam-1]);
}

