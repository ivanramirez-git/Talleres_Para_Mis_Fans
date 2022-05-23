/*
Práctica 55-Arreglo invertido

-Capturar un arreglo de tamaño N
-Invertir los valores en un ARREGLO NUEVO
Ejemplo
Captura el Arreglo(a)
a[5] = 10 12 33 24 13
El arreglo invertido en el NUEVO ARREGLO(b)
b[5] = 13 24 33 12 10
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
    int arreglo_invertido[N];

    // Pedir los valores del arreglo
    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese el valor del arreglo " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    // Invertir los valores del arreglo
    for (int i = 0; i < N; i++)
    {
        arreglo_invertido[i] = arreglo[N - i - 1];
    }

    // Mostrar los valores del arreglo invertido
    cout << "El arreglo invertido es: ";
    for (int i = 0; i < N; i++)
    {
        cout << arreglo_invertido[i] << " ";
    }
    cout << endl;

    return 0;
}