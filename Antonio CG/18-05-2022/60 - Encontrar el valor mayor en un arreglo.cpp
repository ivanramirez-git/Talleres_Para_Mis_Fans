/*
Genera un arreglo entero de tamañoN(Aleatorioopor Consola)
Una vez que el arreglo esté lleno con sus valores correspondientes.Determinar cuál es el valor mayor.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    // Pedir la cantidad de elementos del arreglo
    int N;
    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> N;

    // Declarar variables
    int arreglo[N];
    int mayor = 0;

    // Generar los valores del arreglo
    for (int i = 0; i < N; i++)
    {
        arreglo[i] = rand() % 100;
    }

    // Mostrar los valores del arreglo
    cout << "El arreglo es: ";
    for (int i = 0; i < N; i++)
    {
        cout << arreglo[i] << " ";
    }

    // Buscar el valor mayor
    mayor = arreglo[0];
    for (int i = 0; i < N; i++)
    {
        if (arreglo[i] > mayor)
        {
            mayor = arreglo[i];
        }
    }

    // Mostrar el valor mayor
    cout << endl << "El valor mayor es: " << mayor << endl;

    return 0;
}