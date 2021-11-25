/* 2) Realiza un programa que defina una matriz de 2x2 y escriba un ciclo para que muestre la diagonal principal de la matriz.*/
// C++

#include <iostream>

using namespace std;

int main()
{
    int matriz[2][2];
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << "Ingrese el valor de la posicion [" << i << "," << j << "]: ";
            cin >> matriz[i][j];
        }
    }
    cout << "\nLa diagonal principal de la matriz es: ";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (i == j)
            {
                cout << matriz[i][j] << " ";
            }
        }
    }
    cout << endl;
    cout << "\nLa diagonal secundaria de la matriz es: ";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if(i+j == 1)
            {
                cout << matriz[i][j] << " ";
            }
        }
    }
    return 0;
}