#include <iostream>

using namespace std;

int main()
{
    string palabra;
    cout << "Para el numero: ";
    cin >> palabra;
    int numeros[palabra.length()];
    int suma = 0;
    for (int i = 0; i < palabra.length(); i++)
    {
        numeros[i] = palabra[i] - '0';
        suma += numeros[i];
    }
    cout << "La salida es: ";
    bool impar = palabra.length() % 2 == 1;
    if (impar)
    {
        for (int i = 0; i < (palabra.length() - 1) / 2; i++)
        {
            cout << numeros[i] << "+" << numeros[palabra.length() - 1 - i] << "=" << numeros[i] + numeros[palabra.length() - 1 - i] << ", ";
        }
        cout << numeros[(palabra.length() - 1) / 2] << endl;
    }
    else
    {
        for (int i = 0; i < palabra.length() / 2; i++)
        {
            if (i == palabra.length() / 2 - 1)
            {
                cout << numeros[i] << "+" << numeros[palabra.length() - 1 - i] << "=" << numeros[i] + numeros[palabra.length() - 1 - i] << endl;
            }
            else
            {
                cout << numeros[i] << "+" << numeros[palabra.length() - 1 - i] << "=" << numeros[i] + numeros[palabra.length() - 1 - i] << ", ";
            }
        }
    }
    return 0;
}