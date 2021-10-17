#include <iostream>
#include "Cabecera.h"

using namespace std;


void Lista::listaVacia() {
  cabeza = NULL;
}


bool Lista::esVacia() {
  return (cabeza == NULL);
}


void Lista::insertar(Contacto dato, Nodo *pos) {
  Nodo *nuevo = new Nodo;
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


void Lista::insertarCabeza(Contacto dato) {
  Nodo *nuevo = new Nodo;
  nuevo->dato = dato;
  nuevo->siguiente = cabeza;
  cabeza = nuevo;
}


void Lista::insertarCola(Contacto dato) {
  Nodo *loc = cabeza;
  while (loc->siguiente != NULL) {
    loc = loc->siguiente;
  }
  insertar(dato, loc);
}


Nodo* Lista::localizar(Contacto dato) {
  Nodo *loc = cabeza;
  bool encontrado = false;
  while (loc != NULL && !encontrado) {
    if (loc->dato.esIgual(dato))
      encontrado = true;
    else
      loc = loc->siguiente;
  }
  return loc;
}


void Lista::eliminar(Contacto dato) {
  Nodo *act = localizar(dato);
  Nodo *ant = anterior(act);
  if (act != NULL) {
    if (act == cabeza) {
      cabeza = act->siguiente;
    } else {
      ant->siguiente = act->siguiente;
    }
    delete act;
  }
}


Nodo* Lista::anterior(Nodo *pos) {
  Nodo *loc = cabeza;
  bool encontrado = false;
  while (loc != NULL && !encontrado) {
    if (loc->siguiente == pos)
      encontrado = true;
    else
      loc = loc->siguiente;
  }
  return loc;
}


Nodo* Lista::cabezaL() {
  return cabeza;
}


void Lista::limpiar() {
  Nodo *temp;
  while (cabeza != NULL) {
    temp = cabeza->siguiente;
    delete cabeza;
    cabeza = temp;
  }
}


int Lista::longitud() {
  Nodo *loc = cabeza;
  int longi = 0;
  while (loc != NULL) {
    longi = longi + 1;
    loc = loc->siguiente;
  }
  return longi;
}


void Lista::imprimir() {
  Nodo *loc = cabeza;
  cout<<"{ ";
  while (loc != NULL) {
    cout<<loc->dato.toString()<<" ";
    loc = loc->siguiente;
    if(loc != NULL){
		cout<<", ";
	}
  }
  cout<<"}";
  cout<<endl;
}


