#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

int main()
{
    int numero_a_adivinar, min, max, intentos, adivinado;
    srand(time(NULL));
    cout << "Ingrese el rango de numeros a adivinar:" << endl;
    cout << "Minimo: ";
    cin >> min;
    cout << "Maximo: ";
    cin >> max;
    numero_a_adivinar = rand() % (max - min + 1) + min;
    intentos = (max - min + 1) / 10;
    if (intentos == 0)
    {
        intentos = 1;
    }
    while (intentos > 0)
    {
        cout << "Intentos restantes: " << intentos << endl;
        cout << "Ingrese un numero: ";
        cin >> adivinado;
        if (adivinado == numero_a_adivinar)
        {
            cout << "Felicidades, adivinaste el numero!" << endl;
            break;
        }
        else
        {
            cout << "Intento fallido" << endl;
            intentos--;
        }
    }
    if (intentos == 0)
    {
        cout << "Perdiste, el numero era: " << numero_a_adivinar << endl;
    }
    return 0;
}