// Your C++ Program

#include <iostream>
#include "Cabecera.h"

using namespace std;

Lista agenda;

void insertar(string nombre, string telefono){
	Contacto temporal;
	
	temporal.nombre = nombre;
	temporal.telefono = telefono;
	
	agenda.insertarCabeza(temporal);
	
	agenda.imprimir();
}
/*
void actualizar(){
	cout<<"Que elemento desea actualizar"<<endl;
}

void buscarNombre(char nombre[]){
	char buscador[20];
	cout<<"Indique el nombre: ";
	scanf("%s",&buscador);
}

void buscarTelefono(char telefono[]){
	
}
*/

int main() {
	string nombre;
	string telefono;	
	
	nombre="Ivan";
	telefono="3122760392";
	
	insertar(nombre,telefono);
	
	nombre="Monica";
	telefono="3135046963";
	
	insertar(nombre,telefono);
	
	nombre="Katerin";
	telefono="3123456789";
	
	insertar(nombre,telefono);
	
	
    return 0;
}
