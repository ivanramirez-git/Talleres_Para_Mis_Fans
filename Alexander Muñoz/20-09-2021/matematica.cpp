#include <iostream>
#include <math.h>


using namespace std;

int main(){
	int opcion;
	float radio, hipotenusa, angulo;
	
	while(true){
		cout<<"1. Area de circulo"<<endl;
		cout<<"2. Triangulo rectangulo"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"-> ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"Ingrese el radio del circulo: ";
				cin>>radio;
				cout<<"El area del circulo es: "<<M_PI*pow(radio,2);
			break;
			case 2:
				cout<<"Digite el valor de la hipotenusa: ";
				cin>>hipotenusa;
				cout<<"Digite el valor del angulo en grados: ";
				cin>>angulo;				
				cout<<"CA: "<< sqrt(pow(hipotenusa*cos(angulo*M_PI/180),2)) <<endl;
				cout<<"CO: "<< sqrt(pow(hipotenusa*sin(angulo*M_PI/180),2)) <<endl;
			break;
			case 0:
				return 0;
			break;
			default:
				cout<<"Ingrese una opcion valida!!!"<<endl;
			break;
		}
		
	}
}
