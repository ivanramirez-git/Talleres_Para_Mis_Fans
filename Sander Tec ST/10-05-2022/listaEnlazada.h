// Languaje: C++
// Lista enlazada
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>

// Clase nodo
template <class T>
class Nodo
{
public:
    T dato;
    Nodo<T> *siguiente;
    Nodo<T> *anterior;

    Nodo(T dato)
    {
        this->dato = dato;
        this->siguiente = NULL;
        this->anterior = NULL;
    }

};

// Clase lista
template <class T>
class Lista
{
private:
    Nodo<T> *cabeza;
    Nodo<T> *cola;
    int tamano;

public:
    // Metodos publicos
    void insertarPrincipio(T dato)
    {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        if (cabeza == NULL)
        {
            cabeza = nuevo;
            cola = nuevo;

            cabeza->siguiente = NULL;
            cabeza->anterior = NULL;

            cola->siguiente = NULL;
            cola->anterior = NULL;

            tamano++;

            return;
        }
        else
        {
            nuevo->siguiente = cabeza;
            cabeza->anterior = nuevo;
            cabeza = nuevo;

            tamano++;

            return;
        }
    }
    void insertarFinal(T dato)
    {
        Nodo<T> *nuevo = new Nodo<T>(dato);
        if (cabeza == NULL)
        {
            cabeza = nuevo;
            cola = nuevo;

            cabeza->siguiente = NULL;
            cabeza->anterior = NULL;

            cola->siguiente = NULL;
            cola->anterior = NULL;

            tamano++;

            return;
        }
        else
        {
            nuevo->anterior = cola;
            cola->siguiente = nuevo;

            cola = nuevo;

            tamano++;

            return;
        }
    }

    void eliminar(T dato)
    {
        Nodo<T> *actual = cabeza;
        
        while (actual != NULL)
        {
            if (actual->dato == dato)
            {
                if (actual == cabeza)
                {
                    cabeza = cabeza->siguiente;
                    cabeza->anterior = NULL;
                }
                else if (actual == cola)
                {
                    cola = cola->anterior;
                    cola->siguiente = NULL;
                }
                else
                {
                    actual->anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = actual->anterior;
                }
                tamano--;
                delete actual;
                break;
            }
            actual = actual->siguiente;
        }
    }

    void imprimir()
    {
        Nodo<T> *actual = cabeza;
        while (actual != NULL)
        {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    T getPosicion(int posicion)
    {
        Nodo<T> *actual = cabeza;
        int contador = 0;
        while (actual != NULL)
        {
            if (contador == posicion)
            {
                return actual->dato;
            }
            actual = actual->siguiente;
            contador++;
        }
        T dato;
        return dato;
    }

    Lista()
    {
        cabeza = NULL;
        cola = NULL;
        tamano = 0;
    }

    ~Lista()
    {
        Nodo<T> *actual = cabeza;
        while (actual != NULL)
        {
            cabeza = cabeza->siguiente;
            delete actual;
            actual = cabeza;
        }
        cabeza = NULL;
        cola = NULL;
        tamano = 0;
    }

    int getTamano()
    {
        return tamano;
    }

    T getCabeza()
    {
        return cabeza->dato;
    }

    T getCola()
    {
        return cola->dato;
    }
};


#endif // LISTA_H

