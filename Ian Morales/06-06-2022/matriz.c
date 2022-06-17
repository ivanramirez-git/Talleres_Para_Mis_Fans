#include <stdio.h>
#include <stdlib.h>
#include "./MATRIZ.h"

int main()
{
    FILE *f = fopen("grafo.bin", "r");
    int n;
    fread(&n, sizeof(int), 1, f);
    struct matriz *m = crear_matriz(n, n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fread(&m->matriz[i][j], sizeof(int), 1, f);
        }
    }
    printf("Matriz:\n");
    imprimir_matriz(m);
    int opcion = -1;

    while(opcion!=0){
        printf("\n\n1. Adyacencia\n2. Lista de adyacencia\n0. Salir\n");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                adyacencia(m);
                break;
            case 2:
                lista_adyacencia(m);
                break;
            case 0:
                break;
            default:
                printf("Opcion no valida\n");
        }
    }
    return 0;
}

