#include <iostream>
#include <math.h>

using namespace std;

int punto2(int previo)
{
    // numero entero positivo distinto de cero impar
    int numero;
    do
    {
        cout << "Ingrese un numero entero positivo distinto de cero impar: ";
        cin >> numero;
    } while (numero == 0 || numero % 2 == 0 || numero < 0);

    // remplazar el ultimo digito del numero con previo
    int cifras = 0;
    int aux = numero;
    while (aux > 0)
    {
        aux /= 10;
        cifras++;
    }

    int ultimo = numero % 10;
    int penultimo = numero / (int)pow(10, cifras - 1);
    int nuevo = penultimo * 10 + previo;
    int resultado = nuevo * (int)pow(10, cifras - 1) + ultimo;

    return resultado;
}

void punto1()
{
    int numero1;
    int numero2;
    do
    {
        cout << "Ingrese un numero1 entero positivo distinto de cero: ";
        cin >> numero1;
    } while (numero1 == 0 || numero1 < 0);

    do
    {
        cout << "Ingrese un numero2 entero positivo distinto de cero: ";
        cin >> numero2;
    } while (numero2 == 0 || numero2 < 0);

    // determinar si tienen la misma cantidad de digitos
    int cifras1 = 0;
    int aux1 = numero1;
    while (aux1 > 0)
    {
        aux1 /= 10;
        cifras1++;
    }

    int cifras2 = 0;
    int aux2 = numero2;
    while (aux2 > 0)
    {
        aux2 /= 10;
        cifras2++;
    }

    if (cifras1 == cifras2)
    {
        // determinar si sus ultimos digitos son divisibles entre si
        int ultimo1 = numero1 % 10;
        int penultimo1 = numero1 / (int)pow(10, cifras1 - 1);
        int ultimo2 = numero2 % 10;
        int penultimo2 = numero2 / (int)pow(10, cifras2 - 1);

        if (ultimo1 % ultimo2 == 0 && penultimo1 % penultimo2 == 0)
        {
            cout << "Los numeros " << numero1 << " y " << numero2 << " son divisibles entre si." << endl;
        }
        else
        {
            cout << "Los numeros " << numero1 << " y " << numero2 << " no son divisibles entre si." << endl;
        }
    }
    else
    {
        // si tienen almenos dos digitos, determinar si los dos ultimos digitos de cada numero son iguales los 4
        int ultimo1 = numero1 % 10;
        int penultimo1 = numero1 / (int)pow(10, cifras1 - 1);
        int ultimo2 = numero2 % 10;
        int penultimo2 = numero2 / (int)pow(10, cifras2 - 1);

        if (ultimo1 == ultimo2 && penultimo1 == penultimo2)
        {
            cout << "Los ultimos dos digitos de los numeros " << numero1 << " y " << numero2 << " son iguales: " << ultimo1 << endl;
        }
        else
        {
            // sumar los 4 valones
            cout << "Los ultimos dos digitos de los numeros " << numero1 << " y " << numero2 << " no son iguales, la suma de los valones es: " << ultimo1 + penultimo1 + ultimo2 + penultimo2 << endl;
        }
    }
}

int main()
{
    int previo;
    do
    {
        cout << "Ingrese un numero entero positivo distinto de cero de un solo digito: ";
        cin >> previo;
    } while (previo == 0 || previo < 0 || previo > 9);

    punto1();
    int resultado = punto2(previo);
    cout << "El resultado es: " << resultado << endl;
}
