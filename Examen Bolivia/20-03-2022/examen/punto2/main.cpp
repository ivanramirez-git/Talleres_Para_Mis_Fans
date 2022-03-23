#include <stdio.h>
#include <iostream>
#include <string.h>
#include "CADENAS.h"
using namespace std;
// protoripo de funciones
bool EsCapicua(char texto[]);
void InvertirCadena(char texto[]);

int main()
{
    char texto[255];
    int vocales[6];
    cout << "Escriba una Frase: ";
    fflush(stdin);
    gets(texto);
    fflush(stdin);
    if (EsCapicua(texto))
    {
    cout << "EL TEXTO ES CAPICUA!!!" << endl;
    cout << "______________________" << endl;
    cout << "LA CANTIDAD DE PALABAS DEL TEXTO ES: " << contarPalabras(texto) << endl;
    }
    else
    {
    cout << "EL TEXTO NO ES CAPICUA!!" << endl;
    cout << "________________________" << endl;
    cout << "EL TEXTO INVERTIDO ES: ";
    cout << "________________________" << endl;
    InvertirCadena(texto);
    }
    return 0;

}


bool EsCapicua(char texto[])
{
    char aux[255];
    strcpy(aux, texto);
    InvertirCadena(aux);
    for (int i = 0, j = strlen(aux) - 1; i < strlen(aux); i++, j--)
    {
        if (aux[i] != texto[j])
        {
            return false;
        }
    }
    return true;
}

void InvertirCadena(char texto[])
{
    int i = 0;
    int j = strlen(texto) - 1;
    char aux;
    while (i < j)
    {
        aux = texto[i];
        texto[i] = texto[j];
        texto[j] = aux;
        i++;
        j--;
    }
    cout << texto << endl;
}