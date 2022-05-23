/*
Captura un Arreglo de tamañoN
En OTRO arreglo distinto,guarda los Valores pares del primer arreglo,ymuestra la sumatoria de dicho arreglo,revisando
que el arreglo sea del tamaño de la cantidad de pares
En OTRO arreglo distinto,guarda los Valores impares del primer arregloymuestra el resultado de la multiplicación de
todos los valores de dicho arreglo.revisando que el arreglo sea del tamaño de la cantidad de impares
*/
#include <iostream>


using namespace std;


int main()
{
    // Pedir la cantidad de elementos del arreglo
    int N;
    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> N;

    // Declarar variables
    int arreglo[N];
    int suma_pares = 0;
    int suma_impares = 1;

    // Pedir los valores del arreglo
    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese el valor del arreglo " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    // Pares
    for (int i = 0; i < N; i++)
    {
        if (arreglo[i] % 2 == 0)
        {
            suma_pares += arreglo[i];
        }
    }
    cout << "La suma de los valores pares es: " << suma_pares << endl;

    // Impares
    for (int i = 0; i < N; i++)
    {
        if (arreglo[i] % 2 != 0)
        {
            suma_impares *= arreglo[i];
        }
    }
    cout << "La multiplicación de los valores impares es: " << suma_impares << endl;

    return 0;
}
