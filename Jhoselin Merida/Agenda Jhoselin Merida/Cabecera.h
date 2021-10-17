#ifndef CABECERA_H
#define CABECERA_H
#include <iostream>


struct Contacto {

  std::string nombre;
  std::string telefono;

  bool esIgual(Contacto);
  std::string toString();

};

bool Contacto::esIgual(Contacto temporal){
  if(this->nombre == temporal.nombre && this->telefono == temporal.telefono)
    return true;
  return false;
}


std::string Contacto::toString(){

  std::string nombreTemporal(this->nombre), telefonoTemporal(this->telefono);
  return "{ Nombre: "+nombreTemporal+", Telefono: "+ telefonoTemporal+" }";
}

struct Nodo {
  
  Contacto dato;
  Nodo *siguiente;

};

struct Lista {

  Nodo *cabeza;

  void listaVacia();
  bool esVacia();
  void insertar(Contacto dato, Nodo *pos);
  void insertarCabeza(Contacto dato);
  void insertarCola(Contacto dato);
  Nodo* localizar(Contacto dato);
  void eliminar(Contacto dato);
  Nodo* anterior(Nodo *pos);
  Nodo* cabezaL();
  void limpiar();
  int longitud();
  void imprimir();

};

#include "Cabecera.hxx"

#endif
