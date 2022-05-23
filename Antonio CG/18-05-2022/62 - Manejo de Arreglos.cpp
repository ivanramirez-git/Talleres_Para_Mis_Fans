/*
Capturar un arreglo de 20 valores aleatoriosymostrar en pantalla lo siguiente con base en los valores capturados:
-Mostrar todo el arreglo
-Cantidad de elementos pares del arreglo
-Cantidad de elementos impares del arreglo
-Suma de todos los Pares
-Suma de todos los Impares
-Posiciónyvalor del Mayor número Par
-Posiciónyvalor del Menor número impar
*/
#include <iostream>
#define N 20

using namespace std;

int main()
{
    // Declarar variables
    int arreglo[N];
    int canti_pares = 0;
    int canti_impares = 0;
    int suma_pares = 0;
    int suma_impares = 0;
    int mayor_par = 0;
    int menor_impar = 0;
    int pos_mayor_par = 0;
    int pos_menor_impar = 0;

    // Pedir los valores del arreglo
    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese el valor del arreglo " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    // Mostrar todo el arreglo
    cout << "El arreglo es: ";
    for (int i = 0; i < N; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    mayor_par = arreglo[0];
    menor_impar = arreglo[0];
    
    for (int i = 0; i < N; i++)
    {
        // Pares
        if (arreglo[i] % 2 == 0)
        {
            canti_pares++;
            suma_pares += arreglo[i];
            if (arreglo[i] > mayor_par)
            {
                mayor_par = arreglo[i];
                pos_mayor_par = i;
            }
        }
        // Impares
        else
        {
            canti_impares++;
            suma_impares += arreglo[i];
            if (arreglo[i] < menor_impar)
            {
                menor_impar = arreglo[i];
                pos_menor_impar = i;
            }
        }
    }

    // Pares
    cout << "La cantidad de elementos pares es: " << canti_pares << endl;
    cout << "La suma de los valores pares es: " << suma_pares << endl;
    cout << "El valor del mayor número par es: " << mayor_par << " en la posición " << pos_mayor_par << endl;

    // Impares
    cout << "La cantidad de elementos impares es: " << canti_impares << endl;
    cout << "La suma de los valores impares es: " << suma_impares << endl;
    cout << "El valor del menor número impar es: " << menor_impar << " en la posición " << pos_menor_impar << endl;

    return 0;
}
