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
        if (p->coeficientes[i] == 0)
        {
            continue;
        }
        else
        {
            if (p->coeficientes[i] > 0 && i != p->grado)
            {
                printf(" + ");
            }
            else if (p->coeficientes[i] < 0 && i != p->grado)
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

        if (p->coeficientesImaginarios[i] == 0)
        {
            continue;
        }
        else
        {
            if (p->coeficientesImaginarios[i] > 0)
            {
                printf(" + ");
            }
            else if (p->coeficientesImaginarios[i] < 0 && i != p->grado)
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
                printf("%.2lfix", p->coeficientesImaginarios[i]);
            }
            else
            {
                printf("%.2lfix^%d", p->coeficientesImaginarios[i], i);
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
        if (p1->grado < i)
            p->coeficientes[i] = p2->coeficientes[i];
        else if (p2->grado < i)
            p->coeficientes[i] = p1->coeficientes[i];
        else if (p1->coeficientes[i] == 0 && p2->coeficientes[i] == 0)
            p->coeficientes[i] = 0;
        else
            p->coeficientes[i] = p1->coeficientes[i] + p2->coeficientes[i];

        if (p1->grado < i)
            p->coeficientesImaginarios[i] = p2->coeficientesImaginarios[i];
        else if (p2->grado < i)
            p->coeficientesImaginarios[i] = p1->coeficientesImaginarios[i];
        else if (p1->coeficientesImaginarios[i] == 0 && p2->coeficientesImaginarios[i] == 0)
            p->coeficientesImaginarios[i] = 0;
        else
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
        if (p1->grado < i)
            p->coeficientes[i] = -1 * p2->coeficientes[i];
        else if (p2->grado < i)
            p->coeficientes[i] = -1 * p1->coeficientes[i];
        else if (p1->coeficientes[i] == 0 && p2->coeficientes[i] == 0)
            p->coeficientes[i] = 0;
        else
            p->coeficientes[i] = p1->coeficientes[i] - p2->coeficientes[i];

        if (p1->grado < i)
            p->coeficientesImaginarios[i] = -1 * p2->coeficientesImaginarios[i];
        else if (p2->grado < i)
            p->coeficientesImaginarios[i] = -1 * p1->coeficientesImaginarios[i];
        else if (p1->coeficientesImaginarios[i] == 0 && p2->coeficientesImaginarios[i] == 0)
            p->coeficientesImaginarios[i] = 0;
        else
            p->coeficientesImaginarios[i] = p1->coeficientesImaginarios[i] - p2->coeficientesImaginarios[i];
    }
    return p;
}

// Multiplica dos polinomios (4.00x^4 + 2.00ix^4) * (2.00x^2 + 1.00ix^2) = (6.00x^6 + 8.00ix^6) : (a+bi)+(c+di) = (ac-bd)+(ab+bc)i
polinomioComplejo *multiplicaPolinomios(polinomioComplejo *p1, polinomioComplejo *p2)
{
    int i, j;
    polinomioComplejo *p = crearPolinomio(p1->grado + p2->grado);
    for (i = 0; i <= p->grado; i++)
    {
        for (j = 0; j <= p->grado; j++)
        {
            if (i + j > p->grado)
                continue;
            else if (i == 0 && j == 0)
                p->coeficientes[i + j] = p1->coeficientes[i] * p2->coeficientes[j] + p1->coeficientesImaginarios[i] * p2->coeficientesImaginarios[j];
            else if (i == 0)
                p->coeficientes[i + j] += p1->coeficientes[i] * p2->coeficientes[j] + p1->coeficientesImaginarios[i] * p2->coeficientesImaginarios[j];
            else if (j == 0)
                p->coeficientes[i + j] += p1->coeficientes[i] * p2->coeficientes[j] + p1->coeficientesImaginarios[i] * p2->coeficientesImaginarios[j];
            else
                p->coeficientes[i + j] += p1->coeficientes[i] * p2->coeficientes[j] + p1->coeficientesImaginarios[i] * p2->coeficientesImaginarios[j];
        }
    }
    return p;
}
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

// Divide dos polinomios (4.00x^4 + 2.00ix^4) * (2.00x^2 + 1.00ix^2) = (2x2)
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
    printf("\nGrado: ");
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