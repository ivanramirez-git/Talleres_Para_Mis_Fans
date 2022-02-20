#include <iostream> // cin, cout
#include <stack> // pilas

using namespace std; // libreria estandar de C++

// Programa que dice si una palabra es palindromo o no usando una pila
int main() {
    string palabra; // palabra a evaluar
    stack<char> pila; // pila de caracteres
    cout << "Ingrese una palabra: "; // pedimos la palabra
    cin >> palabra; // la guardamos en la variable
    for (int i = 0; i < palabra.length(); i++) { // recorremos la palabra
        pila.push(palabra[i]); // la metemos en la pila
    } // fin del for
    for (int i = 0; i < palabra.length(); i++) { // recorremos la palabra
        if (pila.top() != palabra[i]) { // si el caracter de la pila es diferente al de la palabra
            cout << "No es palindromo" << endl; // no es palindromo
            return 0; // terminamos el programa
        } // fin del if
        pila.pop(); // sacamos el caracter de la pila
    } // fin del for
    cout << "Es palindromo" << endl; // es palindromo
    return 0; // terminamos el programa
} // fin de main