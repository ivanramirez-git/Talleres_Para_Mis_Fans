/*
Construya una libreria en lenguaje C para realizar operaciones sobre poli-
nomios de numeros complejos.
Los coeficientes nulos de los polinomios no deben ser almacenados.
Aparte de implementar las operaciones aritmeticas se deben considerar fun-
ciones que permitan leer los polinomios a manipular e imprimir los resultados.
*/
#include <stdio.h>
#include <stdlib.h>

// Polinomio
typedef struct {
    int grado;
    double *coeficientes;
} polinomio;

// Crea un polinomio con grado dado
polinomio *crearPolinomio(int grado);

// Libera la memoria ocupada por un polinomio
void liberarPolinomio(polinomio *p);

// Imprime un polinomio
void imprimirPolinomio(polinomio *p);

// Suma dos polinomios
polinomio *sumaPolinomios(polinomio *p1, polinomio *p2);

// Resta dos polinomios
polinomio *restaPolinomios(polinomio *p1, polinomio *p2);

// Multiplica dos polinomios
polinomio *multiplicaPolinomios(polinomio *p1, polinomio *p2);

// Divide dos polinomios
polinomio *dividePolinomios(polinomio *p1, polinomio *p2);

// Funciones para leer polinomios
polinomio *leerPolinomio();


// Implementacion de las funciones
polinomio *crearPolinomio(int grado) {
    polinomio *p = malloc(sizeof(polinomio));
    p->grado = grado;
    p->coeficientes = malloc(sizeof(double) * (grado + 1));
    return p;
}


void liberarPolinomio(polinomio *p) {
    free(p->coeficientes);
    free(p);
}


void imprimirPolinomio(polinomio *p) {
    int i;
    for (i = p->grado; i >= 0; i--) {
        if (p->coeficientes[i] != 0) {
            if (i == 0) {
                printf("%.2lf", p->coeficientes[i]);
            } else if (i == 1) {
                printf("%.2lfx", p->coeficientes[i]);
            } else {
                printf("%.2lfx^%d", p->coeficientes[i], i);
            }
            if (i > 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}


polinomio *sumaPolinomios(polinomio *p1, polinomio *p2) {
    int i;
    polinomio *p = crearPolinomio(p1->grado > p2->grado ? p1->grado : p2->grado);
    for (i = 0; i <= p->grado; i++) {
        p->coeficientes[i] = p1->coeficientes[i] + p2->coeficientes[i];
    }
    return p;
}


polinomio *restaPolinomios(polinomio *p1, polinomio *p2) {
    int i;
    polinomio *p = crearPolinomio(p1->grado > p2->grado ? p1->grado : p2->grado);
    for (i = 0; i <= p->grado; i++) {
        p->coeficientes[i] = p1->coeficientes[i] - p2->coeficientes[i];
    }
    return p;
}


polinomio *multiplicaPolinomios(polinomio *p1, polinomio *p2) {
    int i, j;
    polinomio *p = crearPolinomio(p1->grado + p2->grado);
    for (i = 0; i <= p->grado; i++) {
        p->coeficientes[i] = 0;
        for (j = 0; j <= i; j++) {
            p->coeficientes[i] += p1->coeficientes[j] * p2->coeficientes[i - j];
        }
    }
    return p;
}


polinomio *dividePolinomios(polinomio *p1, polinomio *p2) {
    int i, j;
    polinomio *p = crearPolinomio(p1->grado - p2->grado);
    for (i = p->grado; i >= 0; i--) {
        p->coeficientes[i] = p1->coeficientes[i + p2->grado];
        for (j = 0; j <= p2->grado; j++) {
            p->coeficientes[i] -= p2->coeficientes[j] * p->coeficientes[i + j];
        }
        p->coeficientes[i] /= p2->coeficientes[p2->grado];
    }
    return p;
}


polinomio *leerPolinomio() {
    int grado;
    printf("Grado: ");
    scanf("%d", &grado);
    polinomio *p = crearPolinomio(grado);
    int i;
    for (i = 0; i <= grado; i++) {
        printf("Coeficiente %d: ", i);
        scanf("%lf", &p->coeficientes[i]);
    }
    return p;
}
