#include <iostream>

using namespace std;

void imprimirArreglo(int A[], int n){
		cout<<"{ ";
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if((i+1)<n){
			cout<<A[i]<<", ";
		}else{
			cout<<A[i]<<" }"<<endl;
		}
	}
}

void imprimirArregloAtras(int A[], int n){
		cout<<"{ ";
	for (int i = n-1; i > 0; --i)
	{
		/* code */
		if((i-1) > 0){
			cout<<A[i]<<", ";
		}else{
			cout<<A[i]<<" }"<<endl;
		}
	}
}

void ingresarDatos(int A[], int n){
	
	for (int i = 0; i < n; i++)
	{
		while(A [i]<1 || A[i]>10){
			cout<<"["<<i<<"]: ";
			cin>>A[i];
		}
	}
}

void duplicarArreglo(int A[],int n){
	for (int i = 0; i < n; ++i)
	{
		A[i]=A[i]+A[i];
	}
}

void triplicarArreglo(int A[], int B[], int n){
	for (int i = 0; i < n; ++i)
	{
		B[i]=A[i]+A[i]+A[i];
	}
}

int main(){

//	int A[7]={0};
//	int B[7]={0};
	int A[7];
	int B[7];

	ingresarDatos(A,7);
	cout<<"A: ";
	imprimirArreglo(A,7);

	duplicarArreglo(A,7);
	cout<<"A (Duplicado): ";
	imprimirArreglo(A,7);

	triplicarArreglo(A,B,7);
	cout<<"B = A(Duplicado)(Triple): ";
	imprimirArreglo(B,7);

	cout<<"A(Duplicado Inverso): ";
	imprimirArregloAtras(A,7);

	cout<<"B(Duplicado Inverso): ";
	imprimirArregloAtras(B,7);

	return 0;
}
