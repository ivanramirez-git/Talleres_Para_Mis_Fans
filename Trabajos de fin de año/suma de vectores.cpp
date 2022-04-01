#include <iostream> // Librerira para entrada y salida de datos, cin y cout
using namespace std; // Espacio de nombres estandar para usar cin y cout
int main() // Funcion principal
{ // Inicio del programa
    cout << "Ingrese el tamano del vector a: "; // Imprime en pantalla
    int n; // Declaracion de la variable n
    cin >> n; // Se lee el valor de n
    cout << "Ingrese el tamano del vector b: "; // Imprime en pantalla
    int m; // Declaracion de la variable m
    cin >> m; // Se lee el valor de m
    int a[20] = {0}, b[20] = {0}, c[20] = {0}; // Declaracion de los vectores a, b y c
    cout << "Ingrese los elementos del vector a: "; // Imprime en pantalla
    for (int i = 0; i < n; i++) // Ciclo for para ingresar los elementos del vector a
    { // Inicio del ciclo for
        cout << "a[" << i << "] = "; // Imprime en pantalla
        cin >> a[i]; // Se lee el valor de a[i]
    } // Fin del ciclo for
    cout << "Ingrese los elementos del vector b: "; // Imprime en pantalla
    for (int i = 0; i < m; i++) // Ciclo for para ingresar los elementos del vector b
    { // Inicio del ciclo for
        cout << "b[" << i << "] = "; // Imprime en pantalla
        cin >> b[i]; // Se lee el valor de b[i]
    } // Fin del ciclo for
    cout << "El vector c es: "; // Imprime en pantalla
    for (int i = 0; i < (n > m ? n : m); i++) // Ciclo for para ingresar los elementos del vector c, inicia con i = 0, termina con i = n o m, dependiendo cual sea mayor entre ellos, e i se incrementa en 1.
    { // Inicio del ciclo for
        c[i] = a[i] + b[i]; // Se suman los elementos de a y b en la posicion i del vector c
        cout << c[i] << " "; // Imprime en pantalla el valor de c[i]
    } // Fin del ciclo for 
    return 0; // Termina el programa
} // Fin del programa