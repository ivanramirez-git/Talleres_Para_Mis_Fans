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

// funcion principal
int main()
{
    srand(time(NULL));
    cout << endl;
    prueba2();

    return 0;
}