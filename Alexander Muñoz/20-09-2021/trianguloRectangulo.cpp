#include <iostream>
#include <math.h>

using namespace std;

int main(){
	float hipotenusa, angulo;
	
	cout<<"Triangulo rectangulo"<<endl;
	cout<<"Digite el valor de la hipotenusa: ";
	cin>>hipotenusa;
	cout<<"Digite el valor del angulo en grados: ";
	cin>>angulo;				
	cout<<"CA: "<< sqrt(pow(hipotenusa*cos(angulo*M_PI/180),2)) <<endl;
	cout<<"CO: "<< sqrt(pow(hipotenusa*sin(angulo*M_PI/180),2)) <<endl;
	
	return 0;
}
