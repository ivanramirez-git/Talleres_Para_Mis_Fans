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

int main()
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
            return 1;
        }
    }
    // convertir el numero a base 10
    int numero_base_10 = 0;
    for (int i = 0; i < numero.length(); i++)
    {
        numero_base_10 += (numero[i] - '0') * relacion_recurrente_aux(numero_base, numero.length() - 1 - i);
    }
    cout << "El numero en base 10 es: " << numero_base_10 << endl;
    return 0;
}