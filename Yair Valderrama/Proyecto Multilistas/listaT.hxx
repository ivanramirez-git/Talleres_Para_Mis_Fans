#include <iostream>
#include "listaT.h"

using namespace std;

template <class T>
void Lista<T>::listaVacia() {
  cabeza = NULL;
}

template <class T>
bool Lista<T>::esVacia() {
  return (cabeza == NULL);
}

template <class T>
void Lista<T>::insertar(T dato, Nodo<T> *pos) {
  Nodo<T> *nuevo = new Nodo<T>;
  nuevo->dato = dato;
  if (cabeza == NULL) {
    //insertar en lista vacía
    nuevo->siguiente = NULL;
    cabeza = nuevo;
  } else {
    //insertar en algun punto interno de la lista
    nuevo->siguiente = pos->siguiente;
    pos->siguiente = nuevo;
  }
}

template <class T>
void Lista<T>::insertarCabeza(T dato) {
  Nodo<T> *nuevo = new Nodo<T>;
  nuevo->dato = dato;
  nuevo->siguiente = cabeza;
  cabeza = nuevo;
}

template <class T>
void Lista<T>::insertarCola(T dato) {
  Nodo<T> *loc = cabeza;
  while (loc->siguiente != NULL) {
    loc = loc->siguiente;
  }
  insertar(dato, loc);
}

template <class T>
Nodo<T>* Lista<T>::localizar(T dato) {
  Nodo<T> *loc = cabeza;
  bool encontrado = false;
  while (loc != NULL && !encontrado) {
    if (loc->dato == dato)
      encontrado = true;
    else
      loc = loc->siguiente;
  }
  return loc;
}

template <class T>
void Lista<T>::eliminar(T dato) {
  Nodo<T> *act = localizar(dato);
  Nodo<T> *ant = anterior(act);
  if (act != NULL) {
    if (act == cabeza) {
      cabeza = act->siguiente;
    } else {
      ant->siguiente = act->siguiente;
    }
    delete act;
  }
}

template <class T>
Nodo<T>* Lista<T>::anterior(Nodo<T> *pos) {
  Nodo<T> *loc = cabeza;
  bool encontrado = false;
  while (loc != NULL && !encontrado) {
    if (loc->siguiente == pos)
      encontrado = true;
    else
      loc = loc->siguiente;
  }
  return loc;
}

template <class T>
Nodo<T>* Lista<T>::cabezaL() {
  return cabeza;
}

template <class T>
void Lista<T>::limpiar() {
  Nodo<T> *temp;
  while (cabeza != NULL) {
    temp = cabeza->siguiente;
    delete cabeza;
    cabeza = temp;
  }
}

template <class T>
int Lista<T>::longitud() {
  Nodo<T> *loc = cabeza;
  int longi = 0;
  while (loc != NULL) {
    longi = longi + 1;
    loc = loc->siguiente;
  }
  return longi;
}

template <class T>
void Lista<T>::imprimir() {
  Nodo<T> *loc = cabeza;
  while (loc != NULL) {
    cout<<loc->dato<<" ";
    loc = loc->siguiente;
  }
  cout<<endl;
}

