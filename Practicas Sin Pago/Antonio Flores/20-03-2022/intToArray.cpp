// Convertir un numero a un arreglo de digitos
#include <iostream>
using namespace std;
int main()
{
    int numero;
    int arreglo[10];
    int arreglo2[10];
    int i = 0;
    cout << "Ingrese un numero: ";
    cin >> numero;
    while (numero > 0)
    {
        arreglo[i] = numero % 10;
        numero /= 10;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        arreglo2[j] = arreglo[i - j - 1];
    }
    cout << "El numero en arreglo es: [ ";
    for (int j = 0; j < i - 1; j++)
    {
        cout << arreglo2[j] << ", ";
    }
    cout << arreglo2[i - 1] << " ]" << endl;
    cout << endl;
    return 0;
}

