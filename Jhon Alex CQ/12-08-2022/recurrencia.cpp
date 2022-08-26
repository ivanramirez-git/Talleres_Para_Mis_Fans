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
    string x;
    cout << "Ingrese x: ";
    cin >> x;
    string n;
    cout << "Ingrese n: ";
    cin >> n;
    int numero_x = stringToInt(x);
    int numero_n = stringToInt(n);
    cout << "El resultado es: " << relacion_recurrente_aux(numero_x, numero_n) << endl;

    return 0;
}