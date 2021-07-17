#include <iostream>

using namespace std;

int cantEmpleados(int anosServicio[]){
	int contador=0;
	for(int i=0;i<sizeof(anosServicio)/sizeof(*anosServicio);i++){
		if(anosServicio[i]>=4 && anosServicio[i]<=6)
			contador++;
	}
	return contador;
}

int main(){

	string entrada, texto;
	int numeroEntero;
	char caracter;
	float numeroFlotante;
	int numempleados;
	do{
		cout<<".:: Menu ::."<<endl;
		cout<<"0. Iniciar"<<endl;
		cout<<"1. Salir"<<endl;
		cin>>entrada;
		numeroEntero=atoi(&entrada[0]);
		switch(numeroEntero){
			case 0:
				//cout<<0;
				cout<<"Cantidad de empleados: ";
					cin>>entrada;


					numempleados=atoi(&entrada[0]);
					
					if(numempleados>0){

						string nombresApellidos[numempleados];
						int anosServicio[numempleados];
						float sueldosBase[numempleados];

						for(int i = 0; i < numempleados; i++){
							cout<<"Por favor ingrese el nombre del "<<i+1<<" empleado: ";
							cin>>entrada;
							texto=entrada;

							cout<<"Por favor ingrese el apellido del "<<i+1<<" empleado: ";
							cin>>entrada;

							texto=texto+" "+entrada;

							cout<<"Ingrese los años de servicio de "<<texto<<":";
							cin>>entrada;

							numeroEntero=atoi(&entrada[0]);

							if(numeroEntero>=0 && numeroEntero <=8){
								caracter=numeroEntero+48;
								//cout<<caracter;
								switch(caracter){
									case '0'...'2':
									// S 950
									nombresApellidos[i]=texto;
									anosServicio[i]=numeroEntero;
									sueldosBase[i]=950;

									break;
									case '3'...'4':
									//	1150
									nombresApellidos[i]=texto;
									anosServicio[i]=numeroEntero;
									sueldosBase[i]=1150;
									
									break;
									case '5'...'6':
									// 1550
									nombresApellidos[i]=texto;
									anosServicio[i]=numeroEntero;
									sueldosBase[i]=1550;

									break;
									case '7'...'8':
									// 1800
									nombresApellidos[i]=texto;
									anosServicio[i]=numeroEntero;
									sueldosBase[i]=1800;

									break;
								}
							}

							cout<<"El empleado No "<<i+1<<". "<<endl;
							cout<<nombresApellidos[i]<<endl;
							cout<<anosServicio[i]<<endl;
							cout<<sueldosBase[i]<<endl;
							cout<<endl;


						}
						cout<< cantEmpleados(anosServicio)<<endl;
					}

			break;

			case 1:
				//cout<<1;
				return 0;
			break;
		}

	}while(true);
	
}