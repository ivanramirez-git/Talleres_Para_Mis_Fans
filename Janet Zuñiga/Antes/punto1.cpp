#include <iostream>

using namespace std;

int main()
{
    // Ingresa la edad
    int edad;
    cout << "Ingresa tu edad: ";
    cin >> edad;
    // Si edad >= 18 entonces imprime "credencial"
    if (edad >= 18)
    {
        cout << "Credencial" << endl;
    }
    return 0;
}