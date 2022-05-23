/*
Capturar un arreglo de TamañoN
Buscar un VALOR en el arregloymostrar la POSICIÓN en que se encuentra
arreglo=12 59 78679 78
buscar el 78
El 78 está en la posición2
Si el valor no existe en el arreglo,marcará errorypermitirá volveraintentar.
Sí hay mas de un valor repetido en el arreglo,solo mostrar el primero.(opcional:mostrar todosymostrar el último)
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
    int valor;
    int posicion;

    // Pedir los valores del arreglo
    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese el valor del arreglo " << i << ": ";
        cin >> arreglo[i];
    }

    // Pedir el valor a buscar
    do
    {
        cout << "Ingrese el valor a buscar: ";
        cin >> valor;

        // Buscar el valor en el arreglo
        for (int i = 0; i < N; i++)
        {
            if (arreglo[i] == valor)
            {
                posicion = i;
                break;
            }
        }

        // Mostrar la posición del valor
        if (posicion == -1)
        {
            cout << "El valor no existe en el arreglo" << endl;
        }
        else
        {
            cout << "El valor " << valor << " está en la posición " << posicion << endl;
        }
    } while (posicion == -1);

    return 0;
}