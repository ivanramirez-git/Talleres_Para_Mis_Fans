#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// Elaborar un programa orientado a objetos que permita determinar los valosres que menos digitos repetidos tiene entre varios numeros ingresados por el usuario.
struct Numero
{
    vector<int> digitos;
    bool negativo;

    Numero() { }

    void insertar(int numero)
    {
        // numeros positivos y negativos
        if (numero < 0)
        {
            numero *= -1;
            negativo = true;
        }
        else
        {
            negativo = false;
        }

        // insertar digitos
        while (numero > 0)
        {
            digitos.push_back(numero % 10);
            numero /= 10;
        }
    }

    int valor(){
        int valor = 0;
        for (int i = 0; i < digitos.size(); i++)
        {
            valor += digitos[i] * pow(10, digitos.size() - i - 1);
        }
        if (negativo)
        {
            valor *= -1;
        }
        return valor;
    }

    int cantidadDigitosRepetidos()
    {
        int cantidad = 0;
        int cantidadRepetidos = 0;
        int numeroRepetido = 0;

        
        vector<int> digitos = this->digitos;

        // ordenar digitos
        sort(digitos.begin(), digitos.end());

        // contar digitos repetidos
        for (int i = 0; i < digitos.size(); i++)
        {
            if (digitos[i] == numeroRepetido)
            {
                cantidadRepetidos++;
            }
            else
            {
                cantidadRepetidos = 1;
            }

            numeroRepetido = digitos[i];
            cantidad = max(cantidad, cantidadRepetidos);
        }
        cout << "Numero: " << valor() << " - Cantidad de digitos repetidos: " << cantidad << endl;
        return cantidad;
    }

};

// pruebas
void prueba1(){
    cout << "N: ";
    int n;
    cin >> n;

    Numero numeros[n];

    for(int i = 0; i < n; i++){
        int aux;
        cout << "Numero " << i + 1 << ": ";
        cin >> aux;
        numeros[i].insertar(aux);
    }

    int menor = numeros[0].cantidadDigitosRepetidos();
    int posicion = 0;

    for(int i = 0; i < n; i++){
        int aux = numeros[i].cantidadDigitosRepetidos();
        if(aux < menor){
            menor = aux;
            posicion = i;
        }
    }

    cout << "Respuesta: " << numeros[posicion].valor() << " con " << numeros[posicion].cantidadDigitosRepetidos() << " digitos repetidos, en la posicion " << posicion  << endl;
}

// main
int main(){
    prueba1();
    return 0;
}