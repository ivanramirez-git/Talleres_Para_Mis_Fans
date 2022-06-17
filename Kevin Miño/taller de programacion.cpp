#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIN 1
#define MAX 9
#define TAMANIO 5

using namespace std;

// Aleatorio entre MIN y MAX
int aleatorio()
{
    return MIN + rand() % (MAX - MIN + 1);
}

// Pila
struct pilaType
{
    int pila[TAMANIO];
    int tope;

    pilaType()
    {
        tope = -1;
    }

    void push(int valor)
    {
        tope++;
        pila[tope] = valor;
    }

    int pop()
    {
        int valor = pila[tope];
        tope--;
        return valor;
    }

    int top()
    {
        return pila[tope];
    }

    bool isEmptyPila()
    {
        return tope == -1;
    }

    bool isFullPila()
    {
        return tope == 99;
    }

    void print()
    {
        cout << endl;
        for (int i = TAMANIO; i >= 0; i--)
        {
            if (i > tope)
            {
                cout << "|   |" << endl;
            }
            else
            {
                cout << "| " << pila[i] << " |" << endl;
            }
        }
        cout << endl;
    }

    // popxnum(n): elimina n elementos de la pila, si n es mayor a la cantidad de elementos de la pila, no se modifica y se muestra un mensaje de error
    void popxnum(int n)
    {
        if (n > tope + 1)
        {
            cout << "Error: No hay suficientes elementos en la pila" << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                pop();
            }
        }
    }

    // pushxnum(n): agrega n elementos a la pila, si n supera el limite de la pila, no se modifica y se muestra un mensaje de error
    void pushxnum(int n)
    {
        if (n > TAMANIO - tope)
        {
            cout << "Error: No hay suficientes espacio en la pila" << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                push(aleatorio());
            }
        }
    }
};

// pruebas
void prueba1()
{
    cout << "Prueba 1: " << endl;
    pilaType pila;
    // agegando 2 8 7 4
    pila.push(2);
    pila.push(8);
    pila.push(7);
    pila.push(4);
    pila.print();

    pila.popxnum(3);
    pila.print();

    pila.push(8);
    pila.push(7);
    pila.push(4);

    pila.popxnum(2);
    pila.print();

    pila.push(7);
    pila.push(4);

    pila.popxnum(6);
    pila.print();

    cout << "Fin de la prueba 1" << endl;
}

void prueba2()
{
    cout << "Prueba 2: " << endl;
    pilaType pila;
    // agegando 2
    pila.push(2);
    pila.print();

    // pushear 3 veces
    pila.pushxnum(3);
    pila.print();

    // pushear 1 veces
    pila.pushxnum(1);
    pila.print();

    // pushear 2 veces
    pila.pushxnum(2);
    pila.print();

    cout << "Fin de la prueba 2" << endl;
}

/*
Escriba un algoritmo en C++ tal que, mediante el uso de una pila, invierta una cadena de
n-bits.
Ejemplo -----→ Entrada: 0010100110 Salida: 0110010100
*/
void prueba3()
{
    cout << "Prueba 3: " << endl;
    pilaType pila;
    int n;
    do
    {
        cout << "Ingrese el numero de bits (1-"<< TAMANIO << "): ";
        cin >> n;
    } while (n < 1 || n > TAMANIO);
    cout << "Ingrese los bits separados por un espacio: ";
    for (int i = 0; i < n; i++)
    {
        int valor;
        cin >> valor;
        pila.push(valor);
    }
    cout << "Los bits invertidos son: ";
    for (int i = 0; i < n; i++)
    {
        cout << pila.pop();
    }
    cout << endl;
    cout << "Fin de la prueba 3" << endl;
}

void prueba4()
{
    cout << "Prueba 4: " << endl;
    pilaType pila;               // creando la pila
    int x, y;                    // variables para guardar los valores de x y y
    x = 4;                       // asignando valor 4 a x
    y = 0;                       // asignando valor 0 a y
    pila.push(7);                // agregando los valores a la pila => [7]
    pila.push(x);                // agregando el valor de x a la pila que es 4 => [4 7]
    pila.push(x + 5);            // agregando el valor de x + 5 a la pila que es 9 => [9 4 7]
    y = pila.top();              // guardando el valor de la cima de la pila en la variable y que debe ser 9 => [9 4 7]
    pila.pop();                  // eliminando el valor de la cima de la pila => [4 7]
    pila.push(x + y);            // agregando el valor de x + y a la pila que debe ser 13 => [13 4 7]
    pila.push(y - 2);            // agregando el valor de y - 2 a la pila que debe ser 7 => [7 13 4 7]
    pila.push(3);                // agregando el valor de 3 a la pila que debe ser 3 => [3 7 13 4 7]
    x = pila.top();              // guardando el valor de la cima de la pila en la variable x que debe ser 3 => [3 7 13 4 7]
    pila.pop();                  // eliminando el valor de la cima de la pila => [7 13 4 7]
    cout << "x = " << x << endl; // imprimiendo el valor de x que debe ser 3 => [7 13 4 7]
    cout << "y = " << y << endl; // imprimiendo el valor de y que debe ser 9 => [7 13 4 7]
    while (!pila.isEmptyPila())  // mientras la pila no este vacia 
    {                           // imprimiendo los valores de la pila
        cout << pila.top() << endl; // imprimiendo el valor de la cima de la pila que debe ser => [7 13 4 7]
        pila.pop();                 // eliminando el valor de la cima de la pila
    }                              // fin del while
    cout << "Fin de la prueba 4" << endl;
} 

// funcion principal
int main()
{
    srand(time(NULL));
    prueba1();
    cout << endl;
    prueba2();
    cout << endl;
    prueba3();
    cout << endl;
    prueba4();

    return 0;
}