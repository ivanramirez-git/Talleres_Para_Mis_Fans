// Ivan Ramirez
#ifndef LISTAT_H
#define LISTAT_H

template <class T>
struct Nodo{
  T dato;
  Nodo<T> *siguiente;
};

template <class T>
struct Lista {
  Nodo<T> *cabeza;

  void listaVacia();
  bool esVacia();
  void insertar(T dato, Nodo<T> *pos);
  void insertarCabeza(T dato);
  void insertarCola(T dato);
  Nodo<T>* localizar(T dato);
  void eliminar(T dato);
  Nodo<T>* anterior(Nodo<T> *pos);
  Nodo<T>* cabezaL();
  void limpiar();
  int longitud();
  void imprimir();
};

#include "listaT.hxx"

#endif
