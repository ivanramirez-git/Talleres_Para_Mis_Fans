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

// funcion principal
int main()
{
    srand(time(NULL));
    cout << endl;
    prueba1();

    return 0;
}