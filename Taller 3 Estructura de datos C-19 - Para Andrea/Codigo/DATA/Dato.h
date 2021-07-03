#ifndef DATO_H
#define DATO_H

using namespace std;

struct Dato {
	
	private:
		// Dato que contiene los datos de una persona
		string nombre;
		int edad;
		string rut;
		bool vacunado;
		bool enfermedad;
		bool vacio;
	public:
		
		// Constructor
		Dato();
		Dato(string no, int ed, string ru, bool va, bool en);

		//setters
		void setNombre(string n);
		void setEdad(int e);
		void setRut(string r);
		void setVacunado(bool v);
		void setEnfermedad(bool e);
		void setVacio(bool v);

		//getters
		string getNombre();
		int getEdad();
		string getRut();
		bool getVacunado();
		bool getEnfermedad();
		bool isVacio();
		bool isEqualDato(Dato d);
		
		//metodos
		void imprimirDato();
		string toString();
		

};

#include "Dato.hxx"

#endif
