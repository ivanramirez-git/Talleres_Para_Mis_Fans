#include <iostream>

using namespace std;

int main()
{
    // Ciclo
    while (true)
    {
        int numero;
        cout << "Ingrese un numero: ";
        cin >> numero;
        // Validar que tenga 3 cifras
        if (numero >= 100 && numero <= 600)
        {
            // Validar que no contenga 5
            if (numero % 10 != 5 && (numero / 10) % 10 != 5 && (numero / 100) % 10 != 5)
            {
                // Validar que no contenga ningun digito repetido
                if (numero / 100 != numero / 10 % 10 && numero / 10 % 10 != numero % 10 && numero % 10 != numero / 100)
                {
                    cout << "El numero es valido" << endl;
                    break;
                }
                else
                {
                    cout << "El numero no es valido" << endl;
                }
            }
            else
            {
                cout << "El numero no es valido" << endl;
            }
        }
        else
        {
            cout << "El numero no es valido" << endl;
        }
    }
    return 0;
}