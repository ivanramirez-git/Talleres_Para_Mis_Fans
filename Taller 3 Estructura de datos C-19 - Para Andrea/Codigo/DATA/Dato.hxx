#include "Dato.h"

#include <iostream>
#include <sstream>

Dato::Dato(string no, int ed, string ru, bool va, bool en) {
	this->nombre = no;
	this->edad = ed;
	this->rut = ru;
	this->vacunado = va;
	this->enfermedad = en;
	this->vacio = false;
}

Dato::Dato() {
	this->vacio=true;
}

void Dato::setNombre(string n) {
	this->nombre = n;
}

void Dato::setEdad(int e ) {
	this->edad = e;
}

void Dato::setRut(string r ) {
	this->rut = r;
}

void Dato::setVacunado(bool v ) {
	this->vacunado = v;
}

void Dato::setEnfermedad(bool e ) {
	this->enfermedad = e;
}

void Dato::setVacio(bool v) {
	this->vacio = v;
}

string Dato::getNombre() {
	return this->nombre;
}

int Dato::getEdad() {
	return this->edad;
}

string Dato::getRut() {
	return this->rut;
}

bool Dato::getVacunado() {
	return this->vacunado;
}

bool Dato::getEnfermedad() {
	return this->enfermedad;
}

bool Dato::isEqualDato(Dato d) {
	return this->nombre==d.getNombre() && this->edad==d.getEdad() && this->rut==d.getRut() && this->vacunado==d.getVacunado() && this->enfermedad==d.getEnfermedad();
}

bool Dato::isVacio() {
	return this->vacio;
}

void Dato::imprimirDato() {
	if(vacio){
		cout<<"El dato esta vacio.";
	} else if(vacunado && enfermedad) {
		cout<<"{ Nombre: "<<this->nombre<<", Edad: "<<this->edad<<", Rut: "<<this->rut<<", Vacunado: Si, Enfermo: Si }"<<endl;
	} else if(this->vacunado && !this->enfermedad) {
		cout<<"{ Nombre: "<<this->nombre<<", Edad: "<<this->edad<<", Rut: "<<this->rut<<", Vacunado: Si, Enfermo: No }"<<endl;
	} else if(!this->vacunado && this->enfermedad) {
		cout<<"{ Nombre: "<<this->nombre<<", Edad: "<<this->edad<<", Rut: "<<this->rut<<", Vacunado: No, Enfermo: Si }"<<endl;	
	} else if(!this->vacunado && !this->enfermedad) {
		cout<<"{ Nombre: "<<this->nombre<<", Edad: "<<this->edad<<", Rut: "<<this->rut<<", Vacunado: No, Enfermo: No }"<<endl;	
	} else {
		cout<<"Error al imprimir el dato."<<endl;
	}
}

string Dato::toString() {
	string texto,str;
	stringstream ss;  
  	ss << this->edad;  
  	ss >> str; 
	
	if(vacio){
		cout<<"El dato esta vacio.";
	} else if(vacunado && enfermedad) {
		texto=this->nombre+","+str+","+this->rut+",S,S";
	} else if(this->vacunado && !this->enfermedad) {
		texto=this->nombre+","+str+","+this->rut+",S,N";
	} else if(!this->vacunado && this->enfermedad) {
		texto=this->nombre+","+str+","+this->rut+",N,S";
	} else if(!this->vacunado && !this->enfermedad) {
		texto=this->nombre+","+str+","+this->rut+",N,N";
	} else {
		cout<<"Error al guardar el dato."<<endl;
	}
	
	return texto;
}
