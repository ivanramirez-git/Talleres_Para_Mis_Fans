// pila y cola
#include <iostream>

using namespace std;

// pila
struct nodo
{
    int dato;
    nodo *sig;
};

// agregar un elemento a la pila
void push_p(nodo *&p, int x)
{
    nodo *nuevo = new nodo;
    nuevo->dato = x;
    nuevo->sig = p;
    p = nuevo;
}

// eliminar un elemento de la pila
int pop_p(nodo *&p)
{
    int x = p->dato;
    nodo *aux = p;
    p = p->sig;
    delete aux;
    return x;
}

// mostrar la pila
void print_p(nodo *p)
{
    cout << "[";
    while (p)
    {
        cout << p->dato;
        p = p->sig;
        if (p)
            cout << ", ";
    }
    cout << "]" << endl;
}

// cola
struct nodo2
{
    int dato;
    nodo2 *sig;
};

// agregar un elemento a la cola
void push_c(nodo2 *&p, int x)
{
    nodo2 *nuevo = new nodo2;
    nuevo->dato = x;
    nuevo->sig = NULL;
    if (p == NULL)
    {
        p = nuevo;
    }
    else
    {
        nodo2 *aux = p;
        while (aux->sig)
            aux = aux->sig;
        aux->sig = nuevo;
    }
}

// eliminar un elemento de la cola
int pop_c(nodo2 *&p)
{
    int x = p->dato;
    nodo2 *aux = p;
    p = p->sig;
    delete aux;
    return x;
}

// mostrar la cola
void print_c(nodo2 *p)
{
    cout << "[";
    while (p)
    {
        cout << p->dato;
        p = p->sig;
        if (p)
            cout << ", ";
    }
    cout << "]" << endl;
}

// palindromo
bool palindromo(nodo *p, nodo2 *q)
{
    while (p && q)
    {
        if (p->dato != q->dato)
            return false;
        p = p->sig;
        q = q->sig;
    }

    return true;
}

int main()
{
    // Menu de Opciones
    // 1. Palindromo
    // 2. Borrar dato de pila
    // 3. Borrar dato de cola
    // 0. Salir

    int opcion;
    int num1, num2;
    nodo *p = NULL;
    nodo2 *c = NULL;

    // Ingreso de dato
    do
    {
        cout << "Ingrese un numero (-1 para salir): ";
        cin >> num1;
        if (num1 != -1)
        {
            push_p(p, num1);
            push_c(c, num1);
        }
    } while (num1 != -1);

    do
    {
        cout << "Menu de Opciones" << endl;
        cout << "1. Palindromo" << endl;
        cout << "2. Borrar dato" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion)
        {
        case 1:
            if (palindromo(p, c))
                cout << "Es palindromo" << endl;
            else
                cout << "No es palindromo" << endl;
            break;
        case 2:
            if (p && c)
            {
                pop_p(p);
                pop_c(c);
            }
            else
                cout << "No hay datos" << endl;
            break;
        case 3:
            opcion = 0;
            break;
        default:
            cout << "Opcion no valida" << endl;
            opcion = -1;
            break;
        }
        cout << "P: ";
        print_p(p);
        cout << "C: ";
        print_c(c);
    } while (opcion);

    return 0;
}