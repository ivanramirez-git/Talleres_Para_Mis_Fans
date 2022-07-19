// Biblioteca
#include <stdio.h>
#include <stdlib.h>

// Libreria
#include "./polinomiosComplejos.h"

// Pruebas
void sumaDos(polinomioComplejo *p1, polinomioComplejo *p2)
{
    // Sumamos los polinomios
    polinomioComplejo *p = sumaPolinomios(p1, p2);

    // Mostramos el resultado
    printf("El resultado de la suma es: ");
    imprimirPolinomio(p);
}

void restaDos(polinomioComplejo *p1, polinomioComplejo *p2)
{
    // Restamos los polinomios
    polinomioComplejo *p = restaPolinomios(p1, p2);

    // Mostramos el resultado
    printf("El resultado de la resta es: ");
    imprimirPolinomio(p);
}

void multiplicaDos(polinomioComplejo *p1, polinomioComplejo *p2)
{
    // Multiplicamos los polinomios
    polinomioComplejo *p = multiplicacionPolinomios(p1, p2);

    // Mostramos el resultado
    printf("El resultado de la multiplicacion es: ");
    imprimirPolinomio(p);
}

void dividirDos(polinomioComplejo *p1, polinomioComplejo *p2)
{
    // Dividimos los polinomios
    polinomioComplejo *p = divisionPolinomios(p1, p2);

    // Mostramos el resultado
    printf("El resultado de la division es: ");
    imprimirPolinomio(p);
}

// Menu
int main()
{
    int opcion;
    // Pedimos los polinomios
    printf("Introduce el primer polinomio: ");
    polinomioComplejo *p1 = leerPolinomio();
    printf("Introduce el segundo polinomio: ");
    polinomioComplejo *p2 = leerPolinomio();
    printf("Polinomio 1: ");
    imprimirPolinomio(p1);
    printf("Polinomio 2: ");
    imprimirPolinomio(p2);

    do
    {
        printf("\n");
        printf("1. Sumar dos polinomios\n");
        printf("2. Restar dos polinomios\n");
        printf("3. Multiplicar dos polinomios\n");
        printf("4. Dividir dos polinomios\n");
        printf("0. Salir\n");
        printf("\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);
        printf("\n");

        printf("Polinomio 1: ");
        imprimirPolinomio(p1);
        printf("Polinomio 2: ");
        imprimirPolinomio(p2);
        switch (opcion)
        {
        case 1:
            sumaDos(p1, p2);
            break;
        case 2:
            restaDos(p1, p2);
            break;
        case 3:
            multiplicaDos(p1, p2);
            break;
        case 4:
            dividirDos(p1, p2);
            break;
        case 0:
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    } while (opcion != 0);
    return 0;
}
