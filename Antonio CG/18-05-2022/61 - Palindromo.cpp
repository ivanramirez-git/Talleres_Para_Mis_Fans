/*
Capturar una cadena de caracteres de tamaño definido por el usuario
Detectar si es palíndromo o no
*/

#include <iostream>


using namespace std;


int main()
{
    // Pedir la cantidad de caracteres de la cadena
    string cadena;
    cout << "Ingrese la cadena de caracteres: ";
    cin >> cadena;

    // Detectar si es palíndromo o no
    int i = 0, j = cadena.length() - 1;
    bool es_palindromo = true;
    while (i < j)
    {
        if (cadena[i] != cadena[j])
        {
            es_palindromo = false;
            break;
        }
        i++;
        j--;
    }

    // Mostrar si es palíndromo o no
    if (es_palindromo)
    {
        cout << "La cadena es palíndromo" << endl;
    }
    else
    {
        cout << "La cadena no es palíndromo" << endl;
    }

    return 0;
}