#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// leer archivo .bin
void llenar_matriz(FILE *archivo, int *n, int *m, int matriz[*n][*m])
{
    /* Estructura para leer archivo binario: Numero_de_verticesPesoPeso..
    Ejemplo: 3045478580
    lo cual indica 3 vertices y los pesos de cada relacion, por lo que la matriz quedaria asi:
        A   B   C
    A   0   4   5
    B   4   7   8
    C   5   8   0
    */
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    int i, j;
    for (i = 0; i < *n; i++)
    {
        for (j = 0; j < *m; j++)
        {
            fread(&matriz[i][j], sizeof(int), 1, archivo);
        }
    }
    fclose(archivo);
}

// menu
void menu()
{
    printf("\n");
    printf("1. Matriz de adyacencia\n");
    printf("2. Lista de adyacencia\n");
    printf("3. Matriz con pesos\n");
    printf("0. Salir\n");
    printf("\n");
}

// matriz de adyacencia
void matriz_adyacencia(int n, int m, int matriz[n][m])
{

    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (matriz[i][j] == 0)
            {
                printf("%d ", 0);
            }
            else
            {
                printf("%d ", 1);
            }
        }
        printf("\n");
    }
}

// lista de adyacencia
void lista_adyacencia(int n, int m, int matriz[n][m])
{
    // Formato:
    /*
    1: 4 5 7
    2: 5 8 7 9
    3: 8
    ...
    */
    int i, j, contador = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (matriz[i][j] != 0)
            {
                contador++;
            }
        }
        printf("%d: ", i + 1);
        for (j = 0; j < m; j++)
        {
            if (matriz[i][j] != 0)
            {
                printf("%d ", j + 1);
            }
        }
        printf("\n");
    }

}

// matriz con pesos
void matriz_pesos(int n, int m, int matriz[n][m])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// main
int main(int argc, char *argv[])
{
    // Pedir nomre de archivo
    printf("Ingrese el nombre del archivo: ");
    char nombre[100];
    scanf("%s", nombre);

    FILE *archivo;
    archivo = fopen(nombre, "rb");
    int num_vertices;
    fread(&num_vertices, sizeof(int), 1, archivo);

    int n = num_vertices;
    int m = num_vertices;
    int pesos[n][m];

    llenar_matriz(archivo, &n, &m, pesos);
    // menu
    int opcion;
    do
    {
        menu();
        printf("Opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            matriz_adyacencia(n, m, pesos);
            break;
        case 2:
            lista_adyacencia(n, m, pesos);
            break;
        case 3:
            matriz_pesos(n, m, pesos);
            break;
        case 0:
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (opcion != 0);
    return 0;
}