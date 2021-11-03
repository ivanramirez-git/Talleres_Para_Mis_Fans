#include <iostream>
#include<math.h>
using namespace std;
int *num();


void cuadrado(int *n);
void funcion2(int *n);
void sumatoria(int *n);
void promedio();
void resultados();

int vector[4];

int main() {
	int *n;
	do{
		n = num();
		cuadrado(n);
		funcion2(n);
		sumatoria(n);
		promedio();
		resultados();
	}while(*n!=20);
	delete n;
	
	return 0;
}

int *num() {
	int *e = new int;
	do{
		cout<<"Ingrese numero: "<<endl;
		cin>>*e;
		if(*e<0 || *e>20)
			cout<<"Error... ";		
	}while(*e<0 || *e>20);
	return e;
}
	
void cuadrado (int *n){
	int cuad;
	cuad = pow(*n,2);
	vector[0]=cuad;	
	
	cout<<"El cuadrado es: "<<cuad<<endl;
	
}

void funcion2(int *n){
	int p,i,y;
  
	if (*n%2==0){
	
		p = 20 - *n;
		//p=y;
		vector[1]=p;
		cout<<"El numero es par y esta a "<<p<<" unidades de 20"<<endl;
	}
	else{
		i = 10 - *n;
    	//i=y;
		vector[1]=i;
		cout<<"El numero es impar y esta a "<<i<<" unidades de 10"<<endl;
	}
	
	

}

void sumatoria(int *n){
	int s=0;
	for(int i=1;i<=*n;i++){
		s=s+i;
	}
	
	vector[2]=s;
	cout<<"La sumatoria es igual a: "<<s<<endl;

}

void promedio(){
	int prom=0;
	
	for(int i = 0; i<3; i++){
	    prom= prom+ vector[i];
	  
	}
	cout<<"El promedio es: "<<prom/3<<endl;
	vector[3]=prom/3;
}

void resultados(){
	
	for(int i = 0; i<4; i++){
	    cout<<i<<" "<<vector[i]<<endl;
	   
	}
}