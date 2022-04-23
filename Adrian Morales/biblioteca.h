#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Funcion para convertir un numero binario a decimal
void btod(char binario[], int decimal[1])
{
    int i;
    int longitud = strlen(binario);
    int potencia = longitud - 1;
    int suma = 0;
    int numero;

    for (i = 0; i < longitud; i++)
    {
        numero = binario[i] - '0';
        suma += numero * pow(2, potencia);
        potencia--;
    }
    decimal[0] = suma;
}

// Funcion para convertir un numeros decimal a binario
void dtob(int d[1], char binario[])
{


    if(d[0]==0)
    {
        binario[0]='0';
        binario[1]='\0';
        return;
    }

    if(d[0]<0)
    {
        printf("Error: El numero no puede ser negativo\n");
    }

    int i;
    int longitud = 0;
    int numero;
    int resto;
    int decimal[1];
    decimal[0] = d[0];

    while (decimal[0] != 0)
    {
        numero = decimal[0] / 2;
        resto = decimal[0] % 2;
        binario[longitud] = resto + '0';
        decimal[0] = numero;
        longitud++;
    }
    binario[longitud] = '\0';
    for (i = 0; i < longitud / 2; i++)
    {
        char aux = binario[i];
        binario[i] = binario[longitud - i - 1];
        binario[longitud - i - 1] = aux;
    }
}

// Funcion auxiliar para convertir un numero morse a decimal
void mdtod(char morse[], int decimal[1])
{

    if (strcmp(morse, "_____") == 0)
    {
        decimal[0] = 0;
    }
    else if (strcmp(morse, ".____") == 0)
    {
        decimal[0] = 1;
    }
    else if (strcmp(morse, "..___") == 0)
    {
        decimal[0] = 2;
    }
    else if (strcmp(morse, "...__") == 0)
    {
        decimal[0] = 3;
    }
    else if (strcmp(morse, "...._") == 0)
    {
        decimal[0] = 4;
    }
    else if (strcmp(morse, ".....") == 0)
    {
        decimal[0] = 5;
    }
    else if (strcmp(morse, "_....") == 0)
    {
        decimal[0] = 6;
    }
    else if (strcmp(morse, "__...") == 0)
    {
        decimal[0] = 7;
    }
    else if (strcmp(morse, "___..") == 0)
    {
        decimal[0] = 8;
    }
    else if (strcmp(morse, "____.") == 0)
    {
        decimal[0] = 9;
    }
    else{
        printf("Error: Numero no valido\n");
    }
}

// Funcion para convertir un numero morse a decimal
void mtod(char morse[], int decimal[1])
{
    char digito[6];
    int digitoDec[1];
    int i = 0;
    decimal[0] = 0;

    for (i = 0; i < strlen(morse) / 5; i++)
    {
        strncpy(digito, &morse[i * 5], 5);
        digito[5] = '\0';
        mdtod(digito, digitoDec);
        decimal[0] = decimal[0] * 10 + digitoDec[0];
    }
}

// Funcion auxiliar para convertir un numero decimal a morse
void ddtom(int decimal[1], char morse[])
{
    if (decimal[0] == 0)
    {
        strcpy(morse, "_____");
    }
    else if (decimal[0] == 1)
    {
        strcpy(morse, ".____");
    }
    else if (decimal[0] == 2)
    {
        strcpy(morse, "..___");
    }
    else if (decimal[0] == 3)
    {
        strcpy(morse, "...__");
    }
    else if (decimal[0] == 4)
    {
        strcpy(morse, "...._");
    }
    else if (decimal[0] == 5)
    {
        strcpy(morse, ".....");
    }
    else if (decimal[0] == 6)
    {
        strcpy(morse, "_....");
    }
    else if (decimal[0] == 7)
    {
        strcpy(morse, "__...");
    }
    else if (decimal[0] == 8)
    {
        strcpy(morse, "___..");
    }
    else if (decimal[0] == 9)
    {
        strcpy(morse, "____.");
    }
    else{
        printf("Error: Numero no valido\n");
    }
}

// Funcion para convertir un numero decimal a morse
void dtom(int d[1], char morse[])
{
    if (d[0] == 0)
    {
        strcpy(morse, "_____");
        return;
    }

    if (d[0] < 0)
    {
        printf("Error: Numero no valido\n");
        return;
    }

    int longitud = 0;
    int i = 0;
    int digitoDec[1];
    char digito[5];
    int decimal[1];
    decimal[0] = d[0];
    char aux[30];

    while (decimal[0] != 0)
    {
        digitoDec[0] = decimal[0] % 10;
        ddtom(digitoDec, digito);
        // concatenar el digito a la cadena al principio
        strcpy(aux, digito);
        strcpy(&aux[5], morse);
        strcpy(morse, aux);
        decimal[0] = decimal[0] / 10;
        i += 5;
    }
    morse[i] = '\0';
}

// Funcion para convertir un numero morse a binario
void mtob(char morse[], char binario[])
{
    int decimal[1];
    // morse a decimal
    mtod(morse, decimal);
    // decimal a binario
    dtob(decimal, binario);
}

// Funcion para convertir un numero binario a morse
void btom(char binario[], char morse[])
{
    int decimal[1];
    // binario a decimal
    btod(binario, decimal);
    // decimal a morse
    dtom(decimal, morse);
}

// Funcion para convertir un numero decimal a decimal
void dtod(char decimal[], int decimal2[1])
{
    int i = 0;
    decimal2[0] = 0;
    for (i = 0; i < strlen(decimal); i++)
    {
        decimal2[0] = decimal2[0] * 10 + decimal[i] - '0';
    }
}