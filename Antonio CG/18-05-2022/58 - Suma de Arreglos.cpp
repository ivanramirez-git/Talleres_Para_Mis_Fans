/*
Crear2arreglos de tamaño definido por usuario
Llenarlos de manera aleatoria(Usando RAND()y
-Guardar la suma de los arreglos en un TERCER
-mostrar los3arreglos en pantalla.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));

    // Pedir la cantidad de elementos del arreglo
    int N;
    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> N;

    // Declarar variables
    int arreglo1[N];
    int arreglo2[N];
    int arreglo3[N];

    // Generar los valores aleatorios
    for (int i = 0; i < N; i++)
    {
        arreglo1[i] = rand() % 100;
        arreglo2[i] = rand() % 100;
    }

    // Sumar los valores de los arreglos
    for (int i = 0; i < N; i++)
    {
        arreglo3[i] = arreglo1[i] + arreglo2[i];
    }

    // Mostrar los valores de los arreglos
    cout << "El arreglo 1 es: ";
    for (int i = 0; i < N; i++)
    {
        cout << arreglo1[i] << " ";
    }
    cout << endl;

    cout << "El arreglo 2 es: ";
    for (int i = 0; i < N; i++)
    {
        cout << arreglo2[i] << " ";
    }
    cout << endl;

    cout << "El arreglo 3 es: ";
    for (int i = 0; i < N; i++)
    {
        cout << arreglo3[i] << " ";
    }
    cout << endl;

    return 0;
}
