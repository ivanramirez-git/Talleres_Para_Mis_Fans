#include <iostream>

using namespace std;

/*

Se requiere crear un software que permita calcular la utilidad de
una empresa agrícola que posee 5 productos; a cada producto se le
debe ingresar el valor de venta, la cantidad producida y el costo
de producción; se debe presentar el resumen de cada producto.

*/

	string nombreProducto[5];
	float valorVenta[5];
	float costoProduccion[5];
	int cantidadProducida[5];
	int unidadesVendidas[5];
	

int main(){
	
	string nombreProducto[5];
	float valorVenta[5];
	float costoProduccion[5];
	int cantidadProducida[5];
	int unidadesVendidas[5];
	
	int opcion;
	
	nombreProducto[0]="Arroz";
	nombreProducto[1]="Papa";
	nombreProducto[2]="Yuca";
	nombreProducto[3]="Platano";
	nombreProducto[4]="Cebolla";
	
	cout<<"Bienvenido"<<endl;
	while(true){
		
		cout<<"1. Ingresar precios "<<endl;
		cout<<"2. Resumen de cada producto"<<endl;
		cout<<"3. Salir"<<endl;
		
		cin>>opcion;
		
		switch(opcion){
			case 1:
				for(int i=0; i<5; i++){		
					cout<<"\nIngrese datos de "<<nombreProducto[i]<<endl;
					cout<<"\tCosto de produccion: ";
					cin>>costoProduccion[i]; 
					cout<<"\tPrecio de venta: ";
					cin>>valorVenta[i]; 
					cout<<"\tCantidad producida (Ventas): ";
					cin>>cantidadProducida[i]; 
				}
			break;
			case 2:
				float utilidades[5], totalUtilidades;
				totalUtilidades=0;
				for(int i=0; i<5; i++){		
					utilidades[i]=(cantidadProducida[i]+0.00000)*(valorVenta[i]-costoProduccion[i]);	
					totalUtilidades+=(cantidadProducida[i]+0.00000)*(valorVenta[i]-costoProduccion[i]);
				}
				
				//Resumen
				
				for(int i=0; i<5; i++){
					cout<<"\n"<<i+1<<". "<<nombreProducto[i]<<
					" con valor de venta de "<<valorVenta[i]<<
					", un costo de produccion de "<<costoProduccion[i]<<
					" y una cantidad de "<<cantidadProducida[i]<<
					" tuvo unas utilidades de "<<utilidades[i]<<"."<<endl;
				}
				cout<<"El total de las utilidades es: "<<totalUtilidades<<"."<<endl;
			break;
			case 3:
				cout<<"Muchas gracias por utilizar nuestros servicios."<<endl;
				return 0;
			break;
		}	
	}
	
	//Utilidad
	
	
	
	return 0;
}
