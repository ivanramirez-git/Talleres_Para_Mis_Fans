/*
Construya una libreria en lenguaje C para realizar operaciones sobre poli-
nomios de numeros complejos.
Los coeficientes nulos de los polinomios no deben ser almacenados.
Aparte de implementar las operaciones aritmeticas se deben considerar fun-
ciones que permitan leer los polinomios a manipular e imprimir los resultados.
*/
#include <stdio.h>
#include <stdlib.h>

// Polinomio Complejo
typedef struct
{
    int grado;
    double *coeficientes;
    double *coeficientesImaginarios;
} polinomioComplejo;

// Crea un polinomio con grado dado
polinomioComplejo *crearPolinomio(int grado);

// Libera la memoria ocupada por un polinomio
void liberarPolinomio(polinomioComplejo *p);

// Imprime un polinomio
void imprimirPolinomio(polinomioComplejo *p);

// Suma dos polinomios
polinomioComplejo *sumaPolinomios(polinomioComplejo *p1, polinomioComplejo *p2);

// Resta dos polinomios
polinomioComplejo *restaPolinomios(polinomioComplejo *p1, polinomioComplejo *p2);

// Multiplica dos polinomios
polinomioComplejo *multiplicacionPolinomios(polinomioComplejo *p1, polinomioComplejo *p2);

// Divide dos polinomios
polinomioComplejo *divisionPolinomios(polinomioComplejo *p1, polinomioComplejo *p2);

// Funciones para leer polinomios
polinomioComplejo *leerPolinomio();

// Implementacion de las funciones

// Crea un polinomio con grado dado
polinomioComplejo *crearPolinomio(int grado)
{
    polinomioComplejo *p = malloc(sizeof(polinomioComplejo));
    p->grado = grado;
    p->coeficientes = malloc(sizeof(double) * (grado + 1));
    p->coeficientesImaginarios = malloc(sizeof(double) * (grado + 1));
    return p;
}

// Libera la memoria ocupada por un polinomio
void liberarPolinomio(polinomioComplejo *p)
{
    free(p->coeficientes);
    free(p->coeficientesImaginarios);
    free(p);
}

// Imprime un polinomio
void imprimirPolinomio(polinomioComplejo *p)
{
    int i;
    for (i = p->grado; i >= 0; i--)
    {

        if (p->coeficientes[i] != 0)
        {
            if (p->coeficientes[i] > 0 && i != p->grado)
            {
                printf(" + ");
            } else if (p->coeficientes[i] < 0 && i != p->grado)
            {
                printf(" ");
            }
            // Imprime el coeficiente
            if (i == 0)
            {
                printf("%.2lf", p->coeficientes[i]);
            }
            else if (i == 1)
            {
                printf("%.2lfx", p->coeficientes[i]);
            }
            else
            {
                printf("%.2lfx^%d", p->coeficientes[i], i);
            }
        }

        if (p->coeficientesImaginarios[i] != 0)
        {
            if (p->coeficientesImaginarios[i] > 0 )
            {
                printf(" + ");
            } else if (p->coeficientesImaginarios[i] < 0 && i != p->grado)
            {
                printf(" ");
            }
            // Imprime el coeficiente imaginario
            if (i == 0)
            {
                printf("%.2lfi", p->coeficientesImaginarios[i]);
            }
            else if (i == 1)
            {
                printf("%.2lfxi", p->coeficientesImaginarios[i]);
            }
            else
            {
                printf("%.2lfx^%di", p->coeficientesImaginarios[i], i);
            }
        }
    }
    printf("\n");
}

// Suma dos polinomios
polinomioComplejo *sumaPolinomios(polinomioComplejo *p1, polinomioComplejo *p2)
{
    int i;
    polinomioComplejo *p = crearPolinomio(p1->grado > p2->grado ? p1->grado : p2->grado);
    for (i = 0; i <= p->grado; i++)
    {
        p->coeficientes[i] = p1->coeficientes[i] + p2->coeficientes[i];
        p->coeficientesImaginarios[i] = p1->coeficientesImaginarios[i] + p2->coeficientesImaginarios[i];
    }
    return p;
}

// Resta dos polinomios
polinomioComplejo *restaPolinomios(polinomioComplejo *p1, polinomioComplejo *p2)
{
    int i;
    polinomioComplejo *p = crearPolinomio(p1->grado > p2->grado ? p1->grado : p2->grado);
    for (i = 0; i <= p->grado; i++)
    {
        p->coeficientes[i] = p1->coeficientes[i] - p2->coeficientes[i];
        p->coeficientesImaginarios[i] = p1->coeficientesImaginarios[i] - p2->coeficientesImaginarios[i];
    }
    return p;
}

// Multiplica dos polinomios
polinomioComplejo *multiplicacionPolinomios(polinomioComplejo *p1, polinomioComplejo *p2)
{
    int i, j;
    polinomioComplejo *p = crearPolinomio(p1->grado + p2->grado);
    for (i = 0; i <= p->grado; i++)
    {
        p->coeficientes[i] = 0;
        p->coeficientesImaginarios[i] = 0;
    }
    for (i = 0; i <= p1->grado; i++)
    {
        for (j = 0; j <= p2->grado; j++)
        {
            p->coeficientes[i + j] += p1->coeficientes[i] * p2->coeficientes[j];
            p->coeficientesImaginarios[i + j] += p1->coeficientesImaginarios[i] * p2->coeficientesImaginarios[j];
        }
    }
    return p;
}

// Divide dos polinomios
polinomioComplejo *divisionPolinomios(polinomioComplejo *p1, polinomioComplejo *p2)
{
    int i, j;
    polinomioComplejo *p = crearPolinomio(p1->grado - p2->grado);
    for (i = 0; i <= p->grado; i++)
    {
        p->coeficientes[i] = 0;
        p->coeficientesImaginarios[i] = 0;
    }
    for (i = 0; i <= p1->grado; i++)
    {
        for (j = 0; j <= p2->grado; j++)
        {
            p->coeficientes[i - j] += p1->coeficientes[i] * p2->coeficientes[j];
            p->coeficientesImaginarios[i - j] += p1->coeficientesImaginarios[i] * p2->coeficientesImaginarios[j];
        }
    }
    return p;
}

// Funciones para leer polinomios
polinomioComplejo *leerPolinomio()
{
    int grado;
    printf("Grado: ");
    scanf("%d", &grado);
    polinomioComplejo *p = crearPolinomio(grado);
    int i;
    for (i = 0; i <= grado; i++)
    {
        printf("Coeficiente %d: ", i);
        scanf("%lf", &p->coeficientes[i]);
        printf("Coeficiente imaginario %d: ", i);
        scanf("%lf", &p->coeficientesImaginarios[i]);
    }
    return p;
}