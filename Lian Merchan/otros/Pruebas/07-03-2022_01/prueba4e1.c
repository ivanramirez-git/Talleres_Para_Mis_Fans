#include <stdio.h>

int validarnumero(int, int, int); // Funcion para validar que un numero este entre un rango
void lecturadatos(int[], int);    // Funcion para leer los datos
int fibonacci(int);               // Funcion que identifica el numero ingresado perteneciente a la serie de fibonacci, si no pertenece retorna 0, si pertenece retorna 1
void ordenarvector(int[], int);   // Funcion para ordenar el vector de mayor a menor
void imprimirvector(int[], int);  // Funcion para imprimir el vector

int main()
{

    printf("Prueba 4: Nombre [num unico]\n");
    printf("Vector Fibonacci ordenado\n");

    // tamanio
    int numero; // Numero entre 1 y 10

    // Leer numero
    do
    {
        printf("Cantidad de numeros a ingresar: ");
        scanf("%d", &numero);
    } while (validarnumero(numero, 1, 10) == 0);

    // Declarar arreglo
    int numeros[numero];

    // Ingresar datos
    lecturadatos(numeros, numero); // Los numeros deben estar entre 1 y 100

    // Ordenar vector
    ordenarvector(numeros, numero);

    // Imprimir vector
    printf("Vector ordenado: \n");
    imprimirvector(numeros, numero);

    return 0;
}

int validarnumero(int numero, int min, int max)
{
    int valido;
    if (numero >= min && numero <= max)
    {
        valido = 1;
    }
    else
    {
        valido = 0;
    }
    return valido;
}

void lecturadatos(int numeros[], int numero)
{
    int i;
    for (i = 0; i < numero; i++)
    {
        do
        {
            printf("[%d]: ", i);
            scanf("%d", &numeros[i]);
        } while (validarnumero(numeros[i], 1, 100) == 0);
    }
}

int fibonacci(int numero)
{
    int fibo, a, b, c, retorno; // Si el numero pertenece a la serie de fibonacci retorna 1, sino retorna 0
    a = 0;
    b = 1;
    c = 0;
    retorno = 0;
    while (c < numero)
    {
        c = a + b;
        a = b;
        b = c;
        if (c == numero)
        {
            retorno = 1;
        }
    }
    return retorno;
}

void ordenarvector(int numeros[], int numero)
{

    int numerosFibo[numero];
    int numerosNOFibo[numero];
    int cantidadFibo = 0;
    int cantidadNOFibo = 0;
    int i, j, aux;
    // Recorrer el vector y guardar los numeros que pertenecen a la serie de fibonacci
    for (i = 0; i < numero; i++)
    {
        if (fibonacci(numeros[i]) == 1)
        {
            numerosFibo[cantidadFibo] = numeros[i];
            cantidadFibo++;
        }
        else
        {
            numerosNOFibo[cantidadNOFibo] = numeros[i];
            cantidadNOFibo++;
        }
    }

    // Unir los dos vectores, primero no fibonacci y luego fibonacci
    for (i = 0; i < cantidadNOFibo; i++)
    {
        numeros[i] = numerosNOFibo[i];
    }
    for (i = cantidadNOFibo, j = 0; i < numero; i++, j++)
    {
        numeros[i] = numerosFibo[j];
    }
}

    void imprimirvector(int numeros[], int numero)
    {
        int i;
        for (i = 0; i < numero; i++)
        {
            printf("[%d]: %d\n", i, numeros[i]);
        }
        printf("\n");
    }
