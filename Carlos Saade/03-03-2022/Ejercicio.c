#include "pila.c"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100

// Mostrar menu
void menu()
{
    printf("Menu\n");
    printf("1. Imprimir\n");
    printf("2. Ordenar\n");
    printf("3. Busqueda\n");
    printf("4. Consultas\n");
    printf("0. Salir\n");
}

// Mostrar menu
void subMenuOrdenar()
{
    printf("Menu\n");
    printf("1. Burbuja\n");
    printf("2. Insercion\n");
    printf("3. Seleccion\n");
    printf("4. QuickSort\n");
    printf("0. Atras\n");
}

// Funcion que genera un numero aleatorio
int aleatorio(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Imprimir
void imprimir(int array[], char arrayChar[][MAX], int tam)
{
    int i;
    printf("Busquedas: \n");
    printf("[\n");
    for (i = 0; i < tam - 1; i++)
    {
        printf("%d: %s,\n", i, arrayChar[i]);
    }
    printf("%d: %s\n]", i, arrayChar[i]);
    printf("\n");

    printf("\nFrecuencias: \n");
    printf("[\n");
    for (i = 0; i < tam - 1; i++)
    {
        printf("%d: %d,\n", i, array[i]);
    }
    printf("%d: %d\n]", i, array[i]);
    printf("\n");
}

// Submenu burbuja
void burbuja(int array[], char arrayChar[][MAX], int tam)
{
    int i, j, aux, ciclos = 0;
    char auxChar[MAX];
    for (i = 0; i < tam - 1; i++)
    {
        for (j = 0; j < tam - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                strcpy(auxChar, arrayChar[j]);
                strcpy(arrayChar[j], arrayChar[j + 1]);
                strcpy(arrayChar[j + 1], auxChar);
            }
            ciclos++;
        }
    }
    // imprimir(array, arrayChar, tam);
    printf("Ciclos burbuja: %d\n", ciclos);
}

// Submenu insercion
void insercion(int array[], char arrayChar[][MAX], int tam)
{
    int i, j, aux, ciclos = 0;
    char auxChar[MAX];
    for (i = 1; i < tam; i++)
    {
        aux = array[i];
        strcpy(auxChar, arrayChar[i]);
        j = i - 1;
        while ((j >= 0) && (array[j] > aux))
        {
            array[j + 1] = array[j];
            strcpy(arrayChar[j + 1], arrayChar[j]);
            j--;
            ciclos++;
        }
        array[j + 1] = aux;
        strcpy(arrayChar[j + 1], auxChar);
    }
    // imprimir(array, arrayChar, tam);
    printf("Ciclos insercion: %d\n", ciclos);
}

// Submenu seleccion
void seleccion(int array[], char arrayChar[][MAX], int tam)
{
    int i, j, min, aux, ciclos = 0;
    char auxChar[MAX];
    for (i = 0; i < tam - 1; i++)
    {
        min = i;
        for (j = i + 1; j < tam; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
            ciclos++;
        }
        aux = array[i];
        array[i] = array[min];
        array[min] = aux;
        strcpy(auxChar, arrayChar[i]);
        strcpy(arrayChar[i], arrayChar[min]);
        strcpy(arrayChar[min], auxChar);
    }
    // imprimir(array, arrayChar, tam);
    printf("Ciclos seleccion: %d\n", ciclos);
}

// Submenu QuickSort
int quickSort(int array[], char arrayChar[][MAX], int izq, int der)
{
    int i, j, pivote, aux, ciclos = 0;
    char auxChar[MAX];
    i = izq;
    j = der;
    pivote = array[(izq + der) / 2];
    do
    {
        while (array[i] < pivote)
        {
            i++;
            ciclos++;
        }
        while (array[j] > pivote)
        {
            j--;
            ciclos++;
        }
        if (i <= j)
        {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            strcpy(auxChar, arrayChar[i]);
            strcpy(arrayChar[i], arrayChar[j]);
            strcpy(arrayChar[j], auxChar);
            i++;
            j--;
        }
    } while (i <= j);
    if (izq < j)
    {
        ciclos = ciclos + quickSort(array, arrayChar, izq, j);
    }
    if (i < der)
    {
        ciclos = ciclos + quickSort(array, arrayChar, i, der);
    }
    return ciclos;
}

// Ordenar
void ordenar(int array[], char arrayChar[][MAX], int tam)
{
    int opcion;
    do
    {
        subMenuOrdenar();
        printf("\nOpcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            burbuja(array, arrayChar, tam);
            break;
        case 2:
            insercion(array, arrayChar, tam);
            break;
        case 3:
            seleccion(array, arrayChar, tam);
            break;
        case 4:
            quickSort(array, arrayChar, 0, tam - 1);
            break;
        case 0:
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (opcion != 0);
}

// Busqueda
void busqueda(int array[], char arrayChar[][MAX], int tam)
{
    // Copiar a pila
    int i;
    for (i = 0; i < tam; i++)
    {
        PoneInt(array[i]);
    }
    for (i = 0; i < tam; i++)
    {
        PoneChar(arrayChar[i]);
    }

    // Busqueda
    int posicion = Buscar();

    // Mostrar resultado
    if (posicion == -1)
    {
        printf("No se encontro el elemento\n");
    }
    else
    {
        ImprimirChar(posicion);
    }
}

// Consultas
void busquedaMenosSolicitada(int array[], char arrayChar[][MAX], int tam)
{
    // La primera de la lista es la menos solicitada
    printf("La busqueda menos solicitada es: %s, con una frecuencia de %d\n", arrayChar[0], array[0]);
}

void busquedaMasSolicitada(int array[], char arrayChar[][MAX], int tam)
{
    // La ultima de la lista es la mas solicitada
    printf("La busqueda mas solicitada es: %s, con una frecuencia de %d\n", arrayChar[tam - 1], array[tam - 1]);
}

int busquedasConMismaFrecuencia(int array[], char arrayChar[][MAX], int tam)
{
    int i, j, contador = 0;
    for (i = 0; i < tam; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            if (array[i] == array[j])
            {
                contador++;
            }
        }
    }
    if (contador == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void cualesTienenMismaFrecuencia(int array[], char arrayChar[][MAX], int tam)
{
    int i, j, contador = 0;
    // Comparar todos los elementos con el actual el siguiente, ya que estan ordenados
    for (i = 0; i < tam - 1; i++)
    {
        if (array[i] == array[i + 1])
        {
            printf("La busqueda '%s' y '%s' tienen la misma frecuencia de %d\n", arrayChar[i], arrayChar[i + 1], array[i]);
        }
    }
}

// Inicio de programa
void iniciar(int array[], char arrayChar[][MAX], int tam)
{

    // Variables
    int i;
    int opcionOrdenar;
    int frecuencia;
    int ciclos;
    int arrayAux[tam];
    char arrayCharAux[tam][MAX];
    int ordenado = 0;

    // menu
    int opcion;
    do
    {

        menu();
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Array original:\n");
            imprimir(array, arrayChar, tam);
            break;
        case 2:
            do
            {

                ordenado = 1;
                opcionOrdenar = 0;
                subMenuOrdenar();
                printf("Ingrese una opcion: ");
                scanf("%d", &opcionOrdenar);
                switch (opcionOrdenar)
                {
                case 1:
                    for (i = 0; i < tam; i++)
                    {
                        arrayAux[i] = array[i];
                        strcpy(arrayCharAux[i], arrayChar[i]);
                    }
                    burbuja(arrayAux, arrayCharAux, tam);
                    printf("\n");
                    imprimir(arrayAux, arrayCharAux, tam);
                    printf("\n");
                    break;
                case 2:
                    for (i = 0; i < tam; i++)
                    {
                        arrayAux[i] = array[i];
                        strcpy(arrayCharAux[i], arrayChar[i]);
                    }
                    insercion(arrayAux, arrayCharAux, tam);
                    printf("\n");
                    imprimir(arrayAux, arrayCharAux, tam);
                    printf("\n");
                    break;
                case 3:
                    for (i = 0; i < tam; i++)
                    {
                        arrayAux[i] = array[i];
                        strcpy(arrayCharAux[i], arrayChar[i]);
                    }
                    seleccion(arrayAux, arrayCharAux, tam);
                    printf("\n");
                    imprimir(arrayAux, arrayCharAux, tam);
                    printf("\n");

                    break;
                case 4:
                    for (i = 0; i < tam; i++)
                    {
                        arrayAux[i] = array[i];
                        strcpy(arrayCharAux[i], arrayChar[i]);
                    }
                    ciclos = quickSort(arrayAux, arrayCharAux, 0, tam - 1);
                    printf("Array ordenado con QUICKSORT en %d ciclos\n", ciclos);
                    imprimir(arrayAux, arrayCharAux, tam);
                    printf("\n");
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
                }
            } while (opcionOrdenar != 0);
            break;
        case 3:
            busqueda(array, arrayChar, tam);
            break;
        case 4:
            // Validar si esta ordenado
            if (ordenado == 1)
            {
                // ¿Que busqueda es la menos solicitada?
                printf("La busqueda es la menos solicitada: ");
                busquedaMenosSolicitada(arrayAux, arrayCharAux, tam);

                // ¿Que busqueda es la mas solicitada?
                printf("La busqueda es la mas solicitada: ");
                busquedaMasSolicitada(arrayAux, arrayCharAux, tam);

                // ¿Existen busquedas con la misma frecuencia?
                printf("Busquedas con la misma frecuencia: ");
                if (busquedasConMismaFrecuencia(arrayAux, arrayCharAux, tam) == 1)
                {
                    // ¿Cuales son?
                    printf("\n");
                    cualesTienenMismaFrecuencia(arrayAux, arrayCharAux, tam);
                }
                else
                {
                    printf("No hay busquedas con la misma frecuencia\n");
                }
            }
            else
            {
                printf("El array no esta ordenado\n");
            }
            break;
        case 0:
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (opcion != 0);
}

// Main
int main()
{

    // Semilla
    srand(time(NULL));

    // Busquedas
    char busquedasFrecuentes[MAX_TAM][MAX];

    strcpy(busquedasFrecuentes[0], "Hola mundo en C");
    strcpy(busquedasFrecuentes[1], "Busqueda lineal");
    strcpy(busquedasFrecuentes[2], "Busqueda binaria");
    strcpy(busquedasFrecuentes[3], "Busqueda secuencial");
    strcpy(busquedasFrecuentes[4], "Ordenamiento burbuja");
    strcpy(busquedasFrecuentes[5], "Ordenamiento por insercion");
    strcpy(busquedasFrecuentes[6], "Ordenamiento por seleccion");
    strcpy(busquedasFrecuentes[7], "Ordenamiento por mezcla");
    strcpy(busquedasFrecuentes[8], "Ordenamiento por combinacion");
    strcpy(busquedasFrecuentes[9], "Ordenamiento por heapsort");
    strcpy(busquedasFrecuentes[10], "Ordenamiento por quicksort");
    strcpy(busquedasFrecuentes[11], "Ordenamiento por shellsort");
    strcpy(busquedasFrecuentes[12], "Ordenamiento por radixsort");
    strcpy(busquedasFrecuentes[13], "Ordenamiento por combinacion");
    strcpy(busquedasFrecuentes[14], "Algoritmo Timsort");
    strcpy(busquedasFrecuentes[15], "Algoritmo Counting Sort");
    strcpy(busquedasFrecuentes[16], "Algoritmo Bucket Sort");
    strcpy(busquedasFrecuentes[17], "Algoritmo Radix Sort");
    strcpy(busquedasFrecuentes[18], "Algoritmo Heap Sort");
    strcpy(busquedasFrecuentes[19], "Algoritmo Quick Sort");

    // Numeros aleatorios en el intervalo [0,1000]
    int frecuencias[MAX_TAM];

    int i, j; // Contadores
    // Generar numeros aleatorios
    for (i = 0; i < 20; i++)
    {
        frecuencias[i] = aleatorio(0, 1000);
    }

    // Inicio del programa
    iniciar(frecuencias, busquedasFrecuentes, 20);

    // Imprimir arrays
    imprimir(frecuencias, busquedasFrecuentes, 20);

    return 0;
}