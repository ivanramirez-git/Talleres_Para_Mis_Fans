#include <iostream>

using namespace std;

int main()
{
    // Pedir la edad de N Ninos
    int N;
    cout << "Ingrese la cantidad de ninios: ";
    cin >> N;

    // Declarar variables
    int edades[N];

    // Pedir las edades de los ninios
    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese la edad del niño " << i + 1 << ": ";
        cin >> edades[i];
    }

    // Preguntar cual edad quiere saber
    int edad;
    cout << "Ingrese el indice del ninio que quiere saber la edad: ";
    cin >> edad;

    // Mostrar la edad del ninio
    cout << "La edad del niño " << edad << " es: " << edades[edad - 1] << endl;

}