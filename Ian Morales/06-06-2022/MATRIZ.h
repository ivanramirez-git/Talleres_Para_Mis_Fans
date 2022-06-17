#ifndef MATRIZ_H
#define MATRIZ_H

struct matriz {
    int filas;
    int columnas;
    int **matriz;
};


struct matriz *crear_matriz(int linhas, int colunas);
void liberar_matriz(struct matriz *m);
void imprimir_matriz(struct matriz *m);
void adyacencia(struct matriz *m);
void lista_adyacencia(struct matriz *m);

#include "./MATRIZ.p"

#endif