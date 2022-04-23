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

// Buscar numero mayor
int buscarMayor(pila *p)
{
    int mayor = p->dato;
    while (p != NULL)
    {
        if (p->dato > mayor)
            mayor = p->dato;
        p = p->sig;
    }
    return mayor;
}

// Buscar numero menor
int buscarMenor(pila *p)
{
    int menor = p->dato;
    while (p != NULL)
    {
        if (p->dato < menor)
            menor = p->dato;
        p = p->sig;
    }
    return menor;
}

// Ordenar la pila mayor a menor
void ordenarMm(pila **p)
{
    int dato_aux;
    pila *p1 = *p;
    pila *p2 = *p;
    while (p1 != NULL)
    {
        while (p2 != NULL)
        {
            if (p1->dato > p2->dato)
            {
                dato_aux = p1->dato;
                p1->dato = p2->dato;
                p2->dato = dato_aux;
            }
            p2 = p2->sig;
        }
        p1 = p1->sig;
        p2 = *p;
    }
}

// Ordenar la pila menor a mayor
void ordenarmM(pila **p)
{
    int dato_aux;
    pila *p1 = *p;
    pila *p2 = *p;
    while (p1 != NULL)
    {
        while (p2 != NULL)
        {
            if (p1->dato < p2->dato)
            {
                dato_aux = p1->dato;
                p1->dato = p2->dato;
                p2->dato = dato_aux;
            }
            p2 = p2->sig;
        }
        p1 = p1->sig;
        p2 = *p;
    }
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
    
    // Mostrar la pila
    cout << "Pila: ";
    mostrar(p);

    // Buscar numero mayor
    cout << "Numero mayor: " << buscarMayor(p) << endl;

    // Mostrar la pila
    cout << "Pila desordenada: "; 
    mostrar(p);

    // Ordenar la pila mayor a menor
    ordenarMm(&p);

    // Mostrar la pila
    cout << "Pila ordenada mayor a menor: ";
    mostrar(p);

    // Ordenar la pila menor a mayor
    ordenarmM(&p);

    // Mostrar la pila
    cout << "Pila ordenada menor a mayor: ";
    mostrar(p);

}

// Programa principal
int main()
{
    prueba1();
    return 0;
}
