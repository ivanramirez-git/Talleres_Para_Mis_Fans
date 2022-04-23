#include <iostream>

using namespace std;

// Pila
struct pila
{
    int dato;
    pila *sig;
};

// Insertar un elemento en la pila
void insertar(pila **p, int dato)
{
    pila *nuevo = new pila;
    nuevo->dato = dato;
    nuevo->sig = *p;
    *p = nuevo;
}

// Eliminar un elemento de la pila
void eliminar(pila **p)
{
    pila *aux = *p;
    *p = (*p)->sig;
    delete aux;
}

// Mostrar la pila
void mostrar(pila *p)
{
    while (p != NULL)
    {
        cout << p->dato << " ";
        p = p->sig;
    }
    cout << endl;
}

// Funcion que recibe una pila y dos enteros, nuevo y viejo, si el viejo esta en la pila, lo reemplaza por el nuevo
void reemplazar(pila *&p, int nuevo, int viejo)
{
    pila *aux = p;
    while (aux != NULL)
    {
        if (aux->dato == viejo)
        {
            aux->dato = nuevo;
        }
        aux = aux->sig;
    }
}

// Funcion que suma los elementos de una pila
int suma(pila *p)
{
    int suma = 0;
    while (p != NULL)
    {
        suma += p->dato;
        p = p->sig;
    }
    return suma;
}

// Pruebas
void prueba1()
{
    cout << "Prueba 1" << endl;
    pila *p = NULL;
    int numero = 0;
    do
    {
        cout << "Ingrese un numero (-1 para terminar): ";
        cin >> numero;
        if (numero != -1)
        {
            insertar(&p, numero);
        }
    } while (numero != -1);
    mostrar(p);
    cout << "Nuevo: ";
    int nuevo = 0;
    cin >> nuevo;
    cout << "Viejo: ";
    int viejo = 0;
    cin >> viejo;
    cout << "Reemplazando " << viejo << " por " << nuevo << endl;
    reemplazar(p, nuevo, viejo);
    mostrar(p);
    cout << "Suma: " << suma(p) << endl;
}

// Programa principal
int main()
{
    prueba1();
    return 0;
}
