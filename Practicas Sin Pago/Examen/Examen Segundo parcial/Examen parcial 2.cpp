#include <iostream>
#include "Punto_fijo.cpp"
#include "NewtonRaphson.cpp"

using namespace std;

void portada(){
cout<<"\n\n  *******************************************************************";
cout<<"\n\n  *                  INSTITUTO POLITECNICO NACIONAL                  *";         
cout<<"\n\n  *         Escuela Superior de Ingenieria Mecanica y electrica      * ";
cout<<"\n\n  *                           ESIME Zacatenco                        *";
cout<<"\n\n  *            Ingenieria en Comunicaciones y Electronica            *";
cout<<"\n\n  *                        Analisis Numerico                         *";
cout<<"\n\n  *                     Examen del Segundo parcial                   *";
cout<<"\n\n  *                        Gomez Urbano Esperanza                    *";
cout<<"\n\n  *                           Grupo : 4CV6                             *";
cout<<"\n\n  *********************************************************************";
}

int main()
{
portada();
	int opcion;
	bool repetir = true;

	do{
		system("cls");
	
	// menú de Opciones
	
	cout<<"\t\t\t-----------"<<endl;
	cout<<"\n\n\t\t\t    MENU \n"<<endl;
	cout<<"\t\t\t-----------"<<endl;
	cout<<"\n\t1. Metodo de Punto Fijo "<<endl;
    cout<<"\n\t2. Metodo de Newton-Rapson "<<endl;
    cout<<"\n\t3. Metodo de la Secante "<<endl;
	cout<<"\n\t4. Metodo de la Biseccion "<<endl;
	cout<<"\n\t5. Metodo de Interpolarizacion de Newton "<<endl;
	cout<<"\n\t6. Metodo de Integracion Numerica "<<endl;
	cout<<"\n\t7. Metodo de Gauss-Jordan "<<endl;
	cout<<"\n\t8. Metodo de Lagrange "<<endl;
	cout<<"\n\t9. Metodo de Minimos Cuadrados "<<endl;
	cout<<"\n\t10.Metodo de Simpson "<<endl;
	cout<<"\n\t11.Salir "<<endl;
	
	cout<<"\n\t Ingrasa una opcion: "<<endl;
	cin>> opcion;

	
	float resultado;
	switch(opcion){
		
		case 1:			
        	puntoFijo();
        	break;
		case 2:
			newtonRaphson();
			break;
		case 3:
			break;
		
		case 4:
			break;
		
		case 5:
			break;
		 
		case 6:
			break;
		
		case 7:
			break;
		
		case 8:
			break;
		
		case 9:
			break;
		
		case 10:
			break;
		
		case 11:
			
		repetir=false;
			break;
 
			default:
				system("cls");
				cout << "Opcion no valida.\a\n";
				void pausa();
				break;
		}
    }while(repetir);
 
    return 0;  		
}








	
	
