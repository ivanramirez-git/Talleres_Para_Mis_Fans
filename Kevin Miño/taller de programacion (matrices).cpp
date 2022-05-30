// Pila
#include <iostream>

struct Nodo{
    int dato;
    Nodo *sig;
};

struct Pila{
    Nodo *tope;
};

// imprime la pila
void imprimir(Pila *pila){
    Nodo *aux = pila->tope;
    while(aux != NULL){
        std::cout << aux->dato << " ";
        aux = aux->sig;
    }
    std::cout << std::endl;
}

// push
void push(Pila &p, int x){
    // mostrar estado de la pila
    Nodo *nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->sig = p.tope;
    p.tope = nuevo;
}

// pop
void pop(Pila &p){
    if(p.tope != NULL){
        Nodo *aux = p.tope;
        p.tope = p.tope->sig;
        delete aux;
    }
}

