#include <stdio.h>

void lecturadatos(int vector[], int tam);
int fibonacci(int numero);
void subvectorfibo(int vector[], int tam, int subvector[], int subtam);
void ordenarvector(int vector[], int tam);
void imprimirvector(int vector[], int tam);

int main(){
    
    int n = -1;
    printf("Prueba 3: Nombre [num unico]\n");
    printf("Vector Fibonacci ordenado\n");

    //Lectura de numero entre 1 y 10
    while(n < 0)
    {
        printf("Cantidad de numeros a ingresar: ");
        scanf("%d", &n);

        if(n < 0 || n > 10)
        {
            n = -1;
        }
    }

    //Lectura de datos
    int vector[n];
    lecturadatos(vector, n);

    //Contar cuantos numeros fibonacci hay
    int contador = 0;
    for(int i = 0; i < n; i++)
    {
        if(fibonacci(vector[i]) == 1)
        {
            contador++;
        }
    }

    //Crear subvector de numeros fibonacci
    int subvector[contador];
    subvectorfibo(vector, n, subvector, contador);

    //Imprimir subvector
    printf("Vector Fibo:\n");
    imprimirvector(subvector, contador);

    //Ordenar subvector
    ordenarvector(subvector, contador);

    //Imprimir subvector ordenado
    printf("Vector Fibo ordenado:\n");
    imprimirvector(subvector, contador);

    return 0;
}

// Lectura de datos
void lecturadatos(int vector[], int tam)
{
    int dato;
    for(int i = 0; i < tam; i++)
    {
        printf("[%d]: ", i);
        scanf("%d", &dato);
        vector[i] = dato;
    }
}

// Fibonacci, 1 si es fibonacci, 0 si no
int fibonacci(int numero)
{
    int a = 0;
    int b = 1;
    int c = 0;

    for(int i = 0; i <= numero; i++)
    {
        c = a + b;
        a = b;
        b = c;
        if(c == numero)
        {
            return 1;
        }
    }
    return 0;
}

// Crear subvector de numeros fibonacci
void subvectorfibo(int vector[], int tam, int subvector[], int subtam)
{
    int contador = 0;
    for(int i = 0; i < tam; i++)
    {
        if(fibonacci(vector[i]) == 1)
        {
            subvector[contador] = vector[i];
            contador++;
        }
    }
}

// Ordenar subvector
void ordenarvector(int vector[], int tam)
{
    int aux;
    for(int i = 0; i < tam; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(vector[i] > vector[j])
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

// Imprimir vector
void imprimirvector(int vector[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        printf("[%d]: %d\n",i, vector[i]);
    }
}