#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME "ESTUDI"
#define MAX_REGISTROS 100
#define MAX_NAME_LENGTH 25
#define MAX_DATE_LENGTH 11
#define MAX_NUM_LENGTH 7

// Variables Globales
FILE *pFile; // Puntero al archivo
char nombre[MAX_NAME_LENGTH]; // Nombre del estudiante
char fecha[MAX_DATE_LENGTH]; // Fecha de nacimiento
int numero; // Numero de estudiante

// Funcion que busca un registro en el archivo, devuelve la posicion del registro, o -1 si no lo encuentra
int buscarRegistro(int numero)
{
    int i; // Contador
    int aux; // Variable auxiliar
    int posicion = -1; // Variable que almacena la posicion del registro
    rewind(pFile); // Se posiciona al principio del archivo
    fscanf(pFile, "%*[^\n]\n"); // Saltar la linea de cabecera
    for (i = 0; i < MAX_REGISTROS; i++) // Recorrer el archivo
    {
        fscanf(pFile, "%d %s %s\n", &aux, nombre, fecha); // Leer el registro
        if (aux == numero) // Si el numero coincide
        {
            posicion = i; // Guardar la posicion
            break; // Salir del bucle
        }
    }
    return posicion; // Devolver la posicion
}

// Funcion que agrega un registro al final del archivo si no existe
void agregarRegistro(int numero2, char nombre2[], char fecha2[])
{
    int posicion = buscarRegistro(numero2);
    if (posicion == -1)
    {
        fprintf(pFile, "\n%d %s %s", numero2, nombre2, fecha2);
    }
}

// Imprimir un registro
void imprimirRegistro(int numero)
{
    int posicion = buscarRegistro(numero);
    if (posicion != -1)
    {
        fseek(pFile, posicion * sizeof(char) * MAX_NAME_LENGTH * MAX_DATE_LENGTH, SEEK_SET);
        fscanf(pFile, "%d %s %s\n", &numero, nombre, fecha);
        printf("%d %s %s\n", numero, nombre, fecha);
    }
}

// Imprimir todos los registros
void imprimirTodos()
{
    int i;
    rewind(pFile);
    // Impresion de cabecera
    char nom[MAX_NAME_LENGTH] = "Nombre";
    char fec[MAX_DATE_LENGTH] = "Fecha";
    char num[MAX_DATE_LENGTH] = "Numero";
    
    printf("%s", num);
    for (i = 0; i < MAX_NUM_LENGTH - strlen(num); i++)
    {
        printf(" ");
    }
    printf("%s", nom);
    for (i = 0; i < MAX_NAME_LENGTH - strlen(nom); i++)
    {
        printf(" ");
    }
    printf("%s\n", fec);

    // Saltar 1 linea de cabecera
    fscanf(pFile, "%*[^\n]\n");
    while (!feof(pFile))
    {
        fscanf(pFile, "%d %s %s\n", &numero, nombre, fecha);
        printf("%d", numero);
        // Imprimir espacios en blanco
        int espacios = 0;
        int num2 = numero;
        while (num2>0)
        {
            num2 = num2 / 10;            
            espacios++;
        }
        for (i = 0; i < MAX_NUM_LENGTH - espacios; i++)
        {
            printf(" ");
        }
        printf("%s", nombre);
        for (i = 0; i < MAX_NAME_LENGTH - strlen(nombre); i++)
        {
            printf(" ");
        }
        printf("%s\n", fecha);

    }
}

// Ciclo
void ciclo()
{

    while (numero != 0)
    {
        printf("Ingrese el numero de estudiante: ");
        scanf("%d", &numero);
        if (numero == 0)
        {
            break;
        }
        else
        {
            // Validar que sea un numero entero positivo
            if (numero < 0)
            {
                printf("Error: Numero de estudiante invalido\n");
                continue;
            }
        }
        int posicion = buscarRegistro(numero);
        if (posicion != -1)
        {
            fseek(pFile, posicion * sizeof(char) * MAX_NAME_LENGTH * MAX_DATE_LENGTH, SEEK_SET);
            fscanf(pFile, "%d %s %s\n", &numero, nombre, fecha);
            printf("%d %s %s\n", numero, nombre, fecha);
        }
        else
        {
            char nombre2[MAX_NAME_LENGTH];
            char fecha2[MAX_DATE_LENGTH];
            printf("Ingrese el nombre: ");
            scanf("%s", nombre2);
            printf("Ingrese la fecha de nacimiento: ");
            scanf("%s", fecha2);
            agregarRegistro(numero, nombre2, fecha2);
        }
    }
}

// Funcion principal
int main()
{
    // Apertura del archivo
    pFile = fopen(FILENAME, "r+");
    if (pFile == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    // Numero
    numero = -1;
    // Ciclo
    ciclo();
    // Imprimir todos los registros
    imprimirTodos();
    // Cierre del archivo
    fclose(pFile);
    return 0;
}
