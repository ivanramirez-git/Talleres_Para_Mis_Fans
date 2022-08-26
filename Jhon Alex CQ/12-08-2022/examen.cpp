#include <iostream>

using namespace std;

int stringToInt(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        n = n * 10 + (s[i] - '0');
    }
    return n;
}

void sumas()
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
}

int relacion_recurrente_aux(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n > 0)
    {
        return x * relacion_recurrente_aux(x, n - 1);
    }
    else
    {
        return (relacion_recurrente_aux(x, n + 1) + 1) / x;
    }
}

void convertir_a_base_10()
{
    // pedir numero de base
    string base;
    cout << "Ingrese la base: ";
    cin >> base;
    int numero_base = stringToInt(base);
    // pedir numero a convertir
    string numero;
    cout << "Ingrese el numero: ";
    cin >> numero;
    // validar que todo el numero sea valido
    for (int i = 0; i < numero.length(); i++)
    {
        if (numero[i] < '0' || numero[i] >= (numero_base + '0'))
        {
            cout << "El numero no es valido" << endl;
            return;
        }
    }
    // convertir el numero a base 10
    int numero_base_10 = 0;
    for (int i = 0; i < numero.length(); i++)
    {
        numero_base_10 += (numero[i] - '0') * relacion_recurrente_aux(numero_base, numero.length() - 1 - i);
    }
    cout << "El numero en base 10 es: " << numero_base_10 << endl;
}

void relacion_recurrente()
{
    string x;
    cout << "Ingrese x: ";
    cin >> x;
    string n;
    cout << "Ingrese n: ";
    cin >> n;
    int numero_x = stringToInt(x);
    int numero_n = stringToInt(n);
    cout << "El resultado es: " << relacion_recurrente_aux(numero_x, numero_n) << endl;
}

void menu()
{
    int opcion;
    do
    {
        cout << "1. Sumas" << endl;
        cout << "2. Convertir a base 10" << endl;
        cout << "3. Relacion recurrente" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            sumas();
            break;
        case 2:
            convertir_a_base_10();
            break;
        case 3:
            relacion_recurrente();
            break;
        case 0:
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != 0);
}

int main()
{
    menu();
    return 0;
}