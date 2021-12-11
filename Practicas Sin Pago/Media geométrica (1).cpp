#include <iostream>
#include <cmath>
using namespace std;
/*
Calcular la media geométrica de varios números
x es un número
n, es un contador de números. También es el total de números a promediar
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
	
	cout<<"Calcular la media geométrica de varios números"<<endl;
	cout<<"Para calcular la media, ingrese los números o 0 para finalizar: ";
	cin>>x;
	while(x!=0){
		n = n + 1;
		a = a * x;
		cout<<"Ingrese otro número o 0 para finalizar: ";
		cin>>x;
	};
	if(n!=0){
		cout<<"La media geométrica es: "<<pow(a,1/n)<<endl;
	}
	return 0;
}


