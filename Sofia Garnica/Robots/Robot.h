#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>

using namespace std;

class Robot{
	private:
		string codigo;
		int cedula;
		char tipo;
		int modelo;
		float precio;
	public:
		/*
		Robot(string,int,char,int,float);
		
		void setCodigo(string);
		void setCedula(int);
		void setTipo(char);
		void setModelo(int);
		void setPrecio(float);
		
		char getCodigo();
		int getCedula();
		char getTipo();
		int getModelo();
		float getPrecio();
		*/
		Robot(string codigo,int cedula,char tipo,int modelo,float precio){
			this->codigo=codigo;
			this->cedula=cedula;
			this->tipo=tipo;
			this->modelo=modelo;
			this->precio=precio;
		}
		
		void setCodigo(string c){codigo=c;}
		void setCedula(int c){cedula=c;}
		void setTipo(char c){tipo=c;}
		void setModelo(int c){modelo=c;}
		void setPrecio(float c){precio=c;}
		
		string getCodigo(){return codigo;}
		int getCedula(){return cedula;}
		char getTipo(){return tipo;}
		int getModelo(){return modelo;}
		float getPrecio(){return precio;}
};

//#include "Robot.hxx"

#endif
