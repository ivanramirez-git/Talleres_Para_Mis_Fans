#include <iostream>
#include <cmath>
using namespace std;
/*
Calcular la media geom�trica de varios n�meros
x es un n�mero
n, es un contador de n�meros. Tambi�n es el total de n�meros a promediar
a, es un acumulador del producto de x
Autor:
*/

float x;
int   n;
float a;
int l;

int main() {
	n = 0;
	a = 1;
	
	cout<<"Calcular la media geom�trica de varios n�meros"<<endl;
	cout<<"Para calcular la media, ingrese los n�meros o 0 para finalizar: ";
	cin>>x;
	while(x!=0){
		n = n + 1;
		a = a * x;
		cout<<"Ingrese otro n�mero o 0 para finalizar: ";
		cin>>x;
	};
	if(n!=0){
		cout<<"La media geom�trica es: "<<pow(a,1/n)<<endl;
	}
	return 0;
}


