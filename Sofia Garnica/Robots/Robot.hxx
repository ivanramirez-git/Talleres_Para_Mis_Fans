//#include "Robot.h"
//#include <iostream>

//using namespace std;

Robot::Robot(string codigo,int cedula,char tipo,int modelo,float precio){
	this->codigo=codigo;
	this->cedula=cedula;
	this->tipo=tipo;
	this->modelo=modelo;
	this->precio=precio;
}

void Robot::setCodigo(char c[]){codigo=c;}
void Robot::setCedula(int c){cedula=c;}
void Robot::setTipo(char c){tipo=c;}
void Robot::setModelo(int c){modelo=c;}
void Robot::setPrecio(float c){precio=c;}

char Robot::getCodigo(){return codigo;}
int Robot::getCedula(){return cedula;}
char Robot::getTipo(){return tipo;}
int Robot::getModelo(){return modelo;}
float Robot::getPrecio(){return precio;}
