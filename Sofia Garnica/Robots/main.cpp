#include <iostream>
#include <vector>
#include "Robot.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


//	Robot(string codigo,int cedula,char tipo,int modelo,float precio)
Robot ingresarRobot(){
	
	string codigo;
	int cedula;
	char tipo;
	int modelo;
	float precio;	
	
	cout<<"Ingrese el codigo: ";
	cin>>codigo;
	
	cout<<"Ingrese la cedula: ";
	cin>>cedula;
	
	cout<<"Ingrese el tipo: ";
	cin>>tipo;
	
	cout<<"Ingrese el modelo: ";
	cin>>modelo;
	
	cout<<"Ingrese el precio: ";
	cin>>precio;
	
	Robot r(codigo,cedula,tipo,modelo,precio);	
	return r;
}

int main(int argc, char** argv) {
	vector<Robot> bots;
	
	//Robot r("iBOT",1116,'A',1998,200.3);
	
	bots.push_back(ingresarRobot());	
	cout<<"Robot: "<<bots[0].getCodigo()<<endl;
	
	
	
	return 0;
}
