#include <stdio.h>
#define MAX 100

// Ordenamiento
int ordenamiento(int vector[], int n)
{

    // Ordenamiento burbuja
    int i, j, aux, ciclos = 0;
    n = n + 1;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (vector[i] < vector[j])
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
            ciclos++;
        }
    }
    printf("Array ordenado en %d ciclos\n", ciclos);
    return ciclos;
}

// Busquedas
int busqueda_binaria(int vector[], int inicio, int fin, int valor)
{
    int medio, ciclos = ordenamiento(vector, fin);
    ciclos = 0;
    while (inicio <= fin)
    {
        ciclos++;
        medio = (inicio + fin) / 2;
        if (vector[medio] == valor)
        {
            printf("La busqueda se realizo en %d ciclos\n", ciclos);
            return medio;
        }
        else if (vector[medio] < valor)
        {
            inicio = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
    }
    printf("La busqueda no tuvo exito en %d ciclos\n", ciclos);
    return -1;
}

int busqueda_secuencial(int vector[], int valor, int tam)
{
    int i, ciclos = 0;
    for (i = 0; i < tam; i++)
    {
        ciclos++;
        if (vector[i] == valor)
        {
            printf("La busqueda se realizo en %d ciclos\n", ciclos);
            return i;
        }
    }
    printf("La busqueda no tuvo exito en %d ciclos\n", ciclos);
    return -1;
}

int busqueda_interpolacion(int vector[], int valor, int bajo, int alto)
{
    int medio, ciclos = ordenamiento(vector, alto);
    ciclos = 0;
    while (bajo <= alto)
    {
        ciclos++;
        medio = bajo + ((valor - vector[bajo]) * (alto - bajo)) / (vector[alto] - vector[bajo]);
        if (vector[medio] == valor)
        {
            printf("La busqueda se realizo en %d ciclos\n", ciclos);
            return medio;
        }
        else if (vector[medio] < valor)
        {
            bajo = medio + 1;
        }
        else
        {
            alto = medio - 1;
        }
    }
    printf("La busqueda no tuvo exito en %d ciclos\n", ciclos);
    return -1;
}

// Programa principal
int main()
{
    int vector[MAX], array[MAX], tam, valor, opcion = -1, posicion;
    printf("Ingrese el tamanio del vector: ");
    scanf("%d", &tam);
    printf("Ingrese los valores del vector \n");
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("Valor %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    while (opcion != 0)
    {

        // Copia el array
        int i;
        for (i = 0; i < tam; i++)
        {
            vector[i] = array[i];
        }

        printf("Ingrese el valor a buscar: ");
        scanf("%d", &valor);
        printf("Ingrese la opcion de busqueda\n");
        printf("1. Busqueda secuencial\n");
        printf("2. Busqueda binaria\n");
        printf("3. Busqueda interpolacion\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            posicion = busqueda_secuencial(vector, valor, tam);
            break;
        case 2:
            posicion = busqueda_binaria(vector, 0, tam - 1, valor);
            break;
        case 3:
            posicion = busqueda_interpolacion(vector, valor, 0, tam - 1);
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }

        if (posicion != -1)
        {
            // imprimir indices
            printf("i = [ ");
            int i;
            for (i = 0; i < tam - 1; i++)
            {
                printf("%d,\t", i);
            }
            printf("%d ]\n", tam - 1);

            // imprimir valores
            printf("v = [ ");            
            for (i = 0; i < tam - 1; i++)
            {
                printf("%d,\t", vector[i]);
            }
            printf("%d ]\n\n", vector[tam - 1]);

            printf("El valor se encuentra en la posicion %d\n", posicion);
        }
    }

    return 0;
}