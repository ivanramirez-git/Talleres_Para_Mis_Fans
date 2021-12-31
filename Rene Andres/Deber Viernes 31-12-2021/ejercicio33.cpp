#include <iostream>
// stl
#include <vector>

using namespace std;

// Funcion que reciba un numero n >= 2 y devuelva un vector con la descomposicion en factores primos de n
vector<int> factoresPrimos(int n) {
    vector<int> factores;
    int i = 2;
    while (n > 1) {
        if (n % i == 0) {
            factores.push_back(i);
            n /= i;
        } else {
            i++;
        }
    }
    return factores;
}

// Funcion que reciba un vector x y un entero positivo p, retornar el numero de repeticiones de p en x
int repeticionesVector(vector<int> x, int p) {
    int contador = 0;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == p) {
            contador++;
        }
    }
    return contador;
}

// Funcion que recibe un vector x y retorna un vector z con zi = repeticiones de i en x
vector<int> repeticionesIndices(vector<int> x) {
    vector<int> z;
    for (int i = 0; i < x.size(); i++) {
        z.push_back(repeticionesVector(x, i));
    }
    return z;
}

// Puntos
void punto1(){
    // Factores primos de 24
    vector<int> primos = factoresPrimos(24);
    cout << "Punto 1: " << endl;
    cout << "Factores primos de 24: ";
    cout << "{ ";
    for (int i = 0; i < primos.size() - 1; i++) {
        cout << primos[i] << ", ";
    }
    cout << primos[primos.size() - 1] << " }" << endl;
}

void punto2(){
    // Repeticiones de p en x
    vector<int> x;
    x.push_back(2);
    x.push_back(2);
    x.push_back(2);
    x.push_back(3);
    cout << "Punto 2: " << endl;
    cout << "Repeticiones de 2 en x: " << repeticionesVector(x, 2) << endl;
}

void punto3(){
    // Repeticiones de i en x
    vector<int> x;
    x.push_back(2);
    x.push_back(2);
    x.push_back(2);
    x.push_back(3);
    cout << "Punto 3: " << endl;
    cout << "Repeticiones de indices en x: ";
    cout << "{ ";
    vector<int> z = repeticionesIndices(x);
    for (int i = 0; i < z.size() - 1; i++) {
        cout << z[i] << ", ";
    }
    cout << z[z.size() - 1] << " }" << endl;
}

// Programa Principal
int main() {
    cout << "Ejercicio 33" << endl;
    punto1();
    cout << endl;
    punto2();
    cout << endl;
    punto3();
    return 0;
}
