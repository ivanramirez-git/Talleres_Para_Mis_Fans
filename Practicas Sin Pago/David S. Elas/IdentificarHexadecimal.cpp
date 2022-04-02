#include <iostream>
#include <string>
using namespace std;
int main()
{
    string numero;
    cout << "Introduce un numero hexadecimal: ";
    cin >> numero;
    int i = 0;
    bool esHexadecimal = true;
    while (i < numero.length() && esHexadecimal)
    {
        if (numero[i] >= '0' && numero[i] <= '9')
        {
            i++;
        }
        else if (numero[i] >= 'A' && numero[i] <= 'F')
        {
            i++;
        }
        else
        {
            esHexadecimal = false;
        }
    }
    if (esHexadecimal)
    {
        cout << "El numero es hexadecimal" << endl;
    }
    else
    {
        cout << "El numero no es hexadecimal" << endl;
    }
    return 0;
}