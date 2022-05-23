/*
Determinar el tamaño del arreglo definido por el usuario.
Llenar el arreglo con valores aleatoriosodefinidos por usuario
•Mostrar el arreglo
•Preguntar si se desea borraroinsertar
Si se desea borrar:
•Preguntar cuál valor se desea borrar(no posición)
•Buscar la posición de dicho valoryborrarlo.
•Recorre el arreglo hacia la izquierda,ocupando el espacio libre.EJ: 2,3,4,5,6- -->2,3,,5,6,6
Si se desea Insertar
•se insertará el valor en la última posición disponible
*/
#include <iostream>

using namespace std;

int main()
{
    // Pedir la cantidad de elementos del arreglo
    int N, n = 0, i;
    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> N;

    // Declarar variables
    int arreglo[N];

    char opcion;

    do
    {
        // Preguntar si se desea borraroinsertar
        cout << "1. Borrar\n2. Insertar\n0. Salir\nIngrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case '1':
            // Pedir el valor a borrar
            int valor;
            cout << "Ingrese el valor a borrar: ";
            cin >> valor;

            // Buscar la posición de dicho valor
            for (i = 0; i < n; i++)
            {
                if (arreglo[i] == valor)
                {
                    break;
                }
            }

            // Borrar el valor
            for (int j = i; j < n; j++)
            {
                arreglo[j] = arreglo[j + 1];
            }

            // Actualizar el tamaño del arreglo
            n--;
            break;
        case '2':
            // Pedir el valor a insertar
            int valor_insertar; 
            cout << "Ingrese el valor a insertar: ";
            cin >> valor_insertar;

            // Insertar el valor en la última posición disponible
            arreglo[n] = valor_insertar;
            n++;
            break;
        }

        // Mostrar el arreglo
        cout << "El arreglo es: ";
        for (int i = 0; i < n; i++)
        {
            cout << arreglo[i] << " ";
        }
        cout << endl;

    } while (opcion != '0');

    return 0;
}
