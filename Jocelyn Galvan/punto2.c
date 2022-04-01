/*
Leer una matriz de 3x3, calcular la suma de los elementos que se encuentran en las mismas filas, calcular el promedio de los elementos que se encuentran en la misma coluumna, indicar cual es el mayor y el menor de los elementos de la matriz.
*/
#include <stdio.h>

// Variables globales
int matriz[3][3];

// Funciones
void leerMatriz();
void sumaFilas();
void promedioColumnas();
void mayorMenor();

// Programa Principal
int main()
{
    leerMatriz();
    sumaFilas();
    promedioColumnas();
    mayorMenor();
    return 0;
}

// Funciones
void leerMatriz()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Ingrese el elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}


void sumaFilas()
{
    int i, j, suma = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            suma += matriz[i][j];
        }
        printf("La suma de los elementos de la fila %d es: %d\n", i + 1, suma);
        suma = 0;
    }
}


void promedioColumnas()
{
    int i, j, suma = 0;
    float promedio;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            suma += matriz[j][i];
        }
        promedio = (float)suma / 3;
        printf("El promedio de los elementos de la columna %d es: %.2f\n", i + 1, promedio);
        suma = 0;
    }
}

void mayorMenor()
{
    int i, j, mayor = matriz[0][0], menor = matriz[0][0];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (matriz[i][j] > mayor)
            {
                mayor = matriz[i][j];
            }
            if (matriz[i][j] < menor)
            {
                menor = matriz[i][j];
            }
        }
    }
    printf("El mayor de los elementos de la matriz es: %d\n", mayor);
    printf("El menor de los elementos de la matriz es: %d\n", menor);
}
