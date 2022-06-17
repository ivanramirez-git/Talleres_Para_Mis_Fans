// Crea una matriz segun numero de filas y columnas
struct matriz *crear_matriz(int filas, int columnas)
{
    struct matriz *matriz = malloc(sizeof(struct matriz));
    matriz->filas = filas;
    matriz->columnas = columnas;
    matriz->matriz = malloc(filas * sizeof(int *));
    int i;
    for (i = 0; i < filas; i++)
    {
        matriz->matriz[i] = malloc(columnas * sizeof(int));
    }
    return matriz;
}

// Libera la memoria de una matriz
void liberar_matriz(struct matriz *matriz)
{
	int i;
    for (i = 0; i < matriz->filas; i++)
    {
        free(matriz->matriz[i]);
    }
    free(matriz->matriz);
    free(matriz);
}

// Imprime una matriz
void imprimir_matriz(struct matriz *matriz)
{
	int i;
    for (i = 0; i < matriz->filas; i++)
    {
    	int j;
        for (j = 0; j < matriz->columnas; j++)
        {
            printf("%d ", matriz->matriz[i][j]);
        }
        printf("\n");
    }
}

// adyacencia
void adyacencia(struct matriz *matriz)
{
	int i;
    for (i = 0; i < matriz->filas; i++)
    {
    	int j;
        for (j = 0; j < matriz->columnas; j++)
        {
            if (i == j)
            {
                printf("0 ");
            }
            else
            {
                if (matriz->matriz[i][j] != 0)
                {
                    printf("1 ");
                }
                else
                {
                    printf("0 ");
                }
            }
        }
        printf("\n");
    }
}

// lista adyacencia
void lista_adyacencia(struct matriz *matriz)
{
	int i;
    for (i = 0; i < matriz->filas; i++)
    {
        printf("%d: ", i+1); 
        int j;
        for (j = 0; j < matriz->columnas; j++)
        {
            if (matriz->matriz[i][j] != 0)
            {
                printf("%d ", j+1);
            }
        }
        printf("\n");
    }
}
