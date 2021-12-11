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

// Funcion raiz n de m
float raiz(float m, int n)
{
	float r;
	r = pow(m, 1.0/n);
	return r;
}


int main() {
	n = 0;
	a = 1;
	
	cout<<"Calcular la media geom�trica de varios n�meros"<<endl;
	cout<<"Para calcular la media, ingrese los n�meros o 0 para finalizar: ";
	cin>>x;

	while (x != 0) {
		n++;
		a = a * x;
		cout<<"Para calcular la media, ingrese los n�meros o 0 para finalizar: ";
		cin>>x;
	}
	cout << a << endl;
	cout << n << endl;
	// Calculo de la media geometrica = 
	if (n != 0) {
		
		cout<<"La media geom�trica de los n�meros ingresados es: "<<raiz(a,n)<<endl;
	}
	else {
		cout<<"No se ingresaron n�meros"<<endl;
	}
	return 0;
}