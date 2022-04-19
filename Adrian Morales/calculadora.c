// Calculadora para calcular la suma, resta y multiplicacion de numeros binarios, decimal y morse.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
// Funcion para convertir un numero binario a decimal
void btod(char binario[], int decimal[1]);
// Funcion para convertir un numeros decimal a binario
void dtob(int decimal[1], char binario[]);
// Funcion para convertir un numero morse a decimal
void mtod(char morse[], int decimal[1]);
// Funcion para convertir un numero decimal a morse
void dtom(int decimal[1], char morse[]);

// Pruebas
void prueba1()
{

    int i;

    // binario a decimal
    char bin1[] = "10101010";
    char bin2[] = "10101011";
    char bin3[] = "10101000";

    int dec1[1];
    int dec2[1];
    int dec3[1];

    // binario a decimal
    btod(bin1, dec1);
    printf("bin1: %s a decimal: %d\n", bin1, dec1[0]);

    btod(bin2, dec2);
    printf("bin2: %s a decimal: %d\n", bin2, dec2[0]);

    btod(bin3, dec3);
    printf("bin3: %s a decimal: %d\n", bin3, dec3[0]);

    // decimal a binario
    dec1[0] = 10;
    dec2[0] = 23;
    dec3[0] = 1;

    char bin4[8];
    char bin5[8];
    char bin6[8];

    dtob(dec1, bin4);
    printf("dec1: %d a binario: %s\n", dec1[0], bin4);

    dtob(dec2, bin5);
    printf("dec2: %d a binario: %s\n", dec2[0], bin5);

    dtob(dec3, bin6);
    printf("dec3: %d a binario: %s\n", dec3[0], bin6);

    // morse a decimal
    char morse1[] = "-----";
    char morse2[] = "..---";
    char morse3[] = "....-...--";

    int morse1dec[1];
    int morse2dec[1];
    int morse3dec[1];

    // morse a decimal
    mtod(morse1, morse1dec);
    printf("morse1: %s a decimal: %d\n", morse1, morse1dec[0]);

    mtod(morse2, morse2dec);
    printf("morse2: %s a decimal: %d\n", morse2, morse2dec[0]);

    mtod(morse3, morse3dec);
    printf("morse3: %s a decimal: %d\n", morse3, morse3dec[0]);

    // decimal a morse
    morse1dec[0] = 10;
    morse2dec[0] = 23;
    morse3dec[0] = 1;

    char morse4[30];
    char morse5[30];
    char morse6[30];

    dtom(morse1dec, morse4);
    printf("dec1: %d a morse: %s\n", morse1dec[0], morse4);

    dtom(morse2dec, morse5);
    printf("dec2: %d a morse: %s\n", morse2dec[0], morse5);

    dtom(morse3dec, morse6);
    printf("dec3: %d a morse: %s\n", morse3dec[0], morse6);

}

// Funcion principal
int main()
{
    prueba1();
    return 0;
}

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
void dtob(int decimal[1], char binario[])
{
    int i;
    int numero;
    int longitud = 0;
    int potencia = 0;
    int suma = 0;
    int decimalAux[1];

    decimalAux[0] = decimal[0];

    while (decimalAux[0] != 0)
    {
        numero = decimalAux[0] % 2;
        suma += numero * pow(10, potencia);
        potencia++;
        decimalAux[0] = decimalAux[0] / 2;
    }
    longitud = potencia;
    potencia = longitud - 1;

    for (i = 0; i < longitud; i++)
    {
        binario[i] = suma % 10 + '0';
        suma = suma / 10;
        potencia--;
    }
    binario[longitud] = '\0';

    // invertir el orden del numero binario
    int j = 0;
    int k = longitud - 1;
    char aux;

    while (j < k)
    {
        aux = binario[j];
        binario[j] = binario[k];
        binario[k] = aux;
        j++;
        k--;
    }
}

// Funcion auxiliar para convertir un numero decimal a morse
void mdtod(char morse[], int decimal[1])
{
    
    if (strcmp(morse, "-----") == 0)
    {
        decimal[0] = 0;
    }
    else if (strcmp(morse, ".----") == 0)
    {
        decimal[0] = 1;
    }
    else if (strcmp(morse, "..---") == 0)
    {
        decimal[0] = 2;
    }
    else if (strcmp(morse, "...--") == 0)
    {
        decimal[0] = 3;
    }
    else if (strcmp(morse, "....-") == 0)
    {
        decimal[0] = 4;
    }
    else if (strcmp(morse, ".....") == 0)
    {
        decimal[0] = 5;
    }
    else if (strcmp(morse, "-....") == 0)
    {
        decimal[0] = 6;
    }
    else if (strcmp(morse, "--...") == 0)
    {
        decimal[0] = 7;
    }
    else if (strcmp(morse, "---..") == 0)
    {
        decimal[0] = 8;
    }
    else if (strcmp(morse, "----.") == 0)
    {
        decimal[0] = 9;
    }
}

// Funcion para convertir un numero morse a decimal
void mtod(char morse[], int decimal[1])
{
    int longitud = strlen(morse);
    char digito[5];
    int digitoDec[1];
    int i = 0;
    decimal[0] = 0;
    while (longitud > 0)
    {
        strncpy(digito, &morse[i], 5+i);
        mdtod(digito, digitoDec);
        decimal[0] = (decimal[0] * 10) + digitoDec[0];
        i += 5;
        longitud -= 5;      
    }
}

// Funcion auxiliar para convertir un numero decimal a morse
void ddtom(int decimal[1], char morse[])
{
    if (decimal[0] == 0)
    {
        strcpy(morse, "-----");
    }
    else if (decimal[0] == 1)
    {
        strcpy(morse, ".----");
    }
    else if (decimal[0] == 2)
    {
        strcpy(morse, "..---");
    }
    else if (decimal[0] == 3)
    {
        strcpy(morse, "...--");
    }
    else if (decimal[0] == 4)
    {
        strcpy(morse, "....-");
    }
    else if (decimal[0] == 5)
    {
        strcpy(morse, ".....");
    }
    else if (decimal[0] == 6)
    {
        strcpy(morse, "-....");
    }
    else if (decimal[0] == 7)
    {
        strcpy(morse, "--...");
    }
    else if (decimal[0] == 8)
    {
        strcpy(morse, "---..");
    }
    else if (decimal[0] == 9)
    {
        strcpy(morse, "----.");
    }
}

// Funcion para convertir un numero decimal a morse
void dtom(int d[1], char morse[])
{
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
        i+=5;
    }
    morse[i] = '\0';
}