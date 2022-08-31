#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct nodo
{
    int key;
    int repetidos;
    nodo *izq;
    nodo *der;
    nodo *padre;
};

nodo *insertar(nodo *arbol, int key)
{
    if (arbol == NULL)
    {
        arbol = new nodo;
        arbol->key = key;
        arbol->repetidos = 1;
        arbol->izq = NULL;
        arbol->der = NULL;
        arbol->padre = NULL;
    }
    else if (key == arbol->key)
    {
        arbol->repetidos++;
    }
    else if (key < arbol->key)
    {
        arbol->izq = insertar(arbol->izq, key);
    }
    else
    {
        arbol->der = insertar(arbol->der, key);
    }
    return arbol;
}

void reporte_ordenado(nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        reporte_ordenado(arbol->izq);
        cout << arbol->key << "  " << arbol->repetidos << endl;
        reporte_ordenado(arbol->der);
    }
}

void prueba1()
{

    nodo *arbol = NULL;
    for (int i = 0; i < 20; i++)
    {
        int a = 1 + rand() % 10;
        arbol = insertar(arbol, a);
    }
    cout << "Arbol: \n";
    reporte_ordenado(arbol);
}

int main()
{
    srand(time(NULL));
    prueba1();
    return 0;
}
