#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <iomanip> // setprecision
#include <cmath> // fabs
# include <math.h>
# include<string.h>
# include<process.h>





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
getch (); 
}

void falsaposicion(){
	float f0,f1,f2;
	float x0,x1,x2;
	int itr;
	int i;
	printf("Numero Maximo de Iteracciones: ");
	scanf("%d",&itr);
	for(x1=0.0;;){
		f1=f(x1);
		if (f1>0){
			break;
		}
		 else {
		 	x1 = x1+0.1;
		 }
	}
			
	x0 = x1-0.1;
	f0 = f(x0);
	printf("\n\t\t----------------------------------------");
	printf("\n\t\t Iteraccion\t x\t\t F(X) \n");
	printf("\n\t\t----------------------------------------");
	  for(i=0;i<itr;i++){
	  	x2 = x0-((x1-x0)/(f1-f0))*f0;
	  	f2=f(x2);
	  	 if(f0*f2>0){
	  	 	x1=x2;
	  	 	f1=f2;
	  	 }
	  	   else {
	  	    	x0=x2;
	  	    	f0=f2;
	  	   }
	  	     if (fabs(f(2))>TOL){
	  	     	printf("\n\t\t%d\t%f\t%f\n",i+1,x2,f2);
	  	     }
	  }
	  printf("\t\t--------------------------------");
	  printf("\n\t\t\t Raiz= %f\n",x2);
	  printf("\t\t------------------------------");
	  getch();}



#define TOL 0.000005
#define f(x) 3*x+sin(x)-exp(x)
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
			//Metodo de Punto fijo
		  void falsaposicion();
		   void tabula(double a, double b);
double f(double x);
		   printf("\n Solucion por el metodo de Falsa posicion \n");
	printf("\n La Ecuacion a resolver es: ");
	printf("\n\t\t\t 3*x+sin(x)-exp(x)= 0 \n\n");
falsaposicion();
	system("pause");
        
		case 2:
		
		
		case 3:
		
		case 4:
		
		case 5:
		 
		case 6:
		
		case 7:
		
		case 8:
		
		case 9:
		
		case 10:
		
		case 11:
		opcion=true;
				//exit(1);
				break;
 
			default:
				system("cls");
				cout << "Opcion no valida.\a\n";
				void pausa();
				break;
		}
    }while(opcion!=true);
 
    return 0;  		
	}








	
	
