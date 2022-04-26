// Biblioteca
#include <stdio.h>
#include <stdlib.h>

// Libreria
#include "./polinomiosComplejos.h"

// Pruebas
void sumaDos(){
    // Pedimos los polinomios
    printf("Introduce el primer polinomio: ");
    polinomioComplejo *p1 = leerPolinomio();
    printf("Polinomio 1: ");
    imprimirPolinomio(p1);
    printf("Introduce el segundo polinomio: ");
    polinomioComplejo *p2 = leerPolinomio();
    printf("Polinomio 2: ");
    imprimirPolinomio(p2);

    // Sumamos los polinomios
    polinomioComplejo *p = sumaPolinomios(p1, p2);

    // Mostramos el resultado
    printf("El resultado de la suma es: ");
    imprimirPolinomio(p);

}

void restaDos(){
    // Pedimos los polinomios
    printf("Introduce el primer polinomio: ");
    polinomioComplejo *p1 = leerPolinomio();
    printf("Polinomio 1: ");
    imprimirPolinomio(p1);
    printf("Introduce el segundo polinomio: ");
    polinomioComplejo *p2 = leerPolinomio();
    printf("Polinomio 2: ");
    imprimirPolinomio(p2);

    // Restamos los polinomios
    polinomioComplejo *p = restaPolinomios(p1, p2);

    // Mostramos el resultado
    printf("El resultado de la resta es: ");
    imprimirPolinomio(p);

}

void multiplicaDos(){
    // Pedimos los polinomios
    printf("Introduce el primer polinomio: ");
    polinomioComplejo *p1 = leerPolinomio();
    printf("Polinomio 1: ");
    imprimirPolinomio(p1);
    printf("Introduce el segundo polinomio: ");
    polinomioComplejo *p2 = leerPolinomio();
    printf("Polinomio 2: ");
    imprimirPolinomio(p2);

    // Multiplicamos los polinomios
    polinomioComplejo *p = multiplicacionPolinomios(p1, p2);

    // Mostramos el resultado
    printf("El resultado de la multiplicacion es: ");
    imprimirPolinomio(p);
    
}

void dividirDos(){
    // Pedimos los polinomios
    printf("Introduce el primer polinomio: ");
    polinomioComplejo *p1 = leerPolinomio();
    printf("Polinomio 1: ");
    imprimirPolinomio(p1);
    printf("Introduce el segundo polinomio: ");
    polinomioComplejo *p2 = leerPolinomio();
    printf("Polinomio 2: ");
    imprimirPolinomio(p2);

    // Dividimos los polinomios
    polinomioComplejo *p = divisionPolinomios(p1, p2);

    // Mostramos el resultado
    printf("El resultado de la division es: ");
    imprimirPolinomio(p);

}


// Menu
int main() {
    int opcion;
    do {
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
        switch (opcion) {
            case 1:
                sumaDos();
                break;
            case 2:
                restaDos();
                break;
            case 3:
                multiplicaDos();
                break;
            case 4:
                dividirDos();
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


