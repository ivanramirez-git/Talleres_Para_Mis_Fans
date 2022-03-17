/*
Un programa cuya entrada sea una cadena s y un n cuya funsion sea generar la cadena n veces.
*/
#include <iostream>

using namespace std;

int main()
{
    string s;
    int n;
    cout << "Ingrese una cadena: ";
    cin >> s;
    cout << "Ingrese un numero: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << s << " ";
    }
    return 0;
}