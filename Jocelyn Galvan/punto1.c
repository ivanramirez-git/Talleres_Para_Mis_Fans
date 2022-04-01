/*
Leer los datos de doce personas como son: nombre, edad, estatura, peso. Posteriormente indicar cual es el nombre de la persona con menor edad, el promedio de las estaturas y el de los pesos.
*/
#include <stdio.h>
#include <string.h>

// Variables globales
int edad[12];
float estatura[12];
float peso[12];
char nombre[12][20];

// Funciones
void leerDatos();
void mostrarDatos();
void mostrarMenorEdad();
void mostrarPromedioEstatura();
void mostrarPromedioPeso();
void datosPruebas();

// Programa principal
int main()
{
    datosPruebas();
    //leerDatos();
    mostrarDatos();
    mostrarMenorEdad();
    mostrarPromedioEstatura();
    mostrarPromedioPeso();
    return 0;
}


// Funcion para llenar los datos con datos de prueba
void datosPruebas()
{
    strcpy(nombre[0], "Juan");
    strcpy(nombre[1], "Pedro");
    strcpy(nombre[2], "Maria");
    strcpy(nombre[3], "Jose");
    strcpy(nombre[4], "Luis");
    strcpy(nombre[5], "Ana");
    strcpy(nombre[6], "Maria");
    strcpy(nombre[7], "Juan");
    strcpy(nombre[8], "Pedro");
    strcpy(nombre[9], "Maria");
    strcpy(nombre[10], "Jose");
    strcpy(nombre[11], "Luis");

    edad[0] = 20;
    edad[1] = 30;
    edad[2] = 18;
    edad[3] = 25;
    edad[4] = 15;
    edad[5] = 35;
    edad[6] = 20;
    edad[7] = 30;
    edad[8] = 18;
    edad[9] = 25;
    edad[10] = 15;
    edad[11] = 35;

    estatura[0] = 1.70;
    estatura[1] = 1.80;
    estatura[2] = 1.60;
    estatura[3] = 1.75;
    estatura[4] = 1.50;
    estatura[5] = 1.85;
    estatura[6] = 1.70;
    estatura[7] = 1.80;
    estatura[8] = 1.60;
    estatura[9] = 1.75;
    estatura[10] = 1.50;
    estatura[11] = 1.85;

    peso[0] = 70;
    peso[1] = 80;
    peso[2] = 60;
    peso[3] = 75;
    peso[4] = 50;
    peso[5] = 85.7;
    peso[6] = 70.9;
    peso[7] = 80.4;
    peso[8] = 60.33333;
    peso[9] = 75.4;
    peso[10] = 50;
    peso[11] = 200;
}

// Funciones
void leerDatos()
{
    int i;
    for (i = 0; i < 12; i++)
    {
        printf("Ingrese el nombre de la persona %d: ", i + 1);
        scanf("%s", nombre[i]);
        printf("Ingrese la edad de la persona %d: ", i + 1);
        scanf("%d", &edad[i]);
        printf("Ingrese la estatura de la persona %d: ", i + 1);
        scanf("%f", &estatura[i]);
        printf("Ingrese el peso de la persona %d: ", i + 1);
        scanf("%f", &peso[i]);
    }
}


void mostrarDatos()
{
    int i;
    for (i = 0; i < 12; i++)
    {
        printf("\nNombre: %s", nombre[i]);
        printf("\nEdad: %d", edad[i]);
        printf("\nEstatura: %.2f", estatura[i]);
        printf("\nPeso: %.2f", peso[i]);
    }
}


void mostrarMenorEdad()
{
    int i;
    int menorEdad = edad[0];
    char nombreMenorEdad[20];
    strcpy(nombreMenorEdad, nombre[0]);
    for (i = 0; i < 12; i++)
    {
        if (edad[i] < menorEdad)
        {
            menorEdad = edad[i];
            strcpy(nombreMenorEdad, nombre[i]);
        }
    }
    printf("\nLa menor edad es de %d años y el nombre es %s", menorEdad, nombreMenorEdad);
}


void mostrarPromedioEstatura()
{
    int i;
    float promedio = 0;
    for (i = 0; i < 12; i++)
    {
        promedio += estatura[i];
    }
    promedio = promedio / 12;
    printf("\nEl promedio de las estaturas es %.2f", promedio);
}


void mostrarPromedioPeso()
{
    int i;
    float promedio = 0;
    for (i = 0; i < 12; i++)
    {
        promedio += peso[i];
    }
    promedio = promedio / 12;
    printf("\nEl promedio de los pesos es %.2f", promedio);
}


// Fin del programa