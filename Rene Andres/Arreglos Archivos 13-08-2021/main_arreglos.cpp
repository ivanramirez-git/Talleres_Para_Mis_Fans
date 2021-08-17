#include <iostream>
#include "arreglos.h"

using namespace std;

int main()
{
    int op;
    cout<<"Elija el ejercicio que desea resolver"<<endl;
    cout<<"1. Operaciones basicas con arreglos"<<endl;
    cout<<"2. Reporte de estudiantes con notas sobre el promedio. Debe ingresar manualmente 7 notas."<<endl;
    cout<<"3. Arreglo aleatorio. Reporte de suma, max, min, promedio e impresion de arreglos."<<endl;
    cin>>op;

    switch(op)
    {
    case 1:
        {
            //Ejemplo 1: declaración del arreglo y operaciones básicas
            int n, m = 5;

            int a[]={2,8,3,0,4}; //se declara un array de 5 elementos de tipo
                         //int con esos valores iniciales
            cout << a[0]<<" "<< a[1]<< " "<< a[2]<< " "<< a[3]<< " "<< a[4]<<endl<<endl;

            n = a[0];       //n = 2
            cout << a[0]<<" "<< a[1]<< " "<< a[2]<< " "<< a[3]<< " "<< a[4]<<endl<<endl;

            a[0]=a[1]+a[2]; //a[0]= 8 + 3 = 11
            cout << a[0]<<" "<< a[1]<< " "<< a[2]<< " "<< a[3]<< " "<< a[4]<<endl<<endl;

            a[1]++;         //a[1]= 9
            cout << a[0]<<" "<< a[1]<< " "<< a[2]<< " "<< a[3]<< " "<< a[4]<<endl<<endl;

            a[n]=m+10;      //a[2]= 15
            cout << a[0]<<" "<< a[1]<< " "<< a[2]<< " "<< a[3]<< " "<< a[4]<<endl<<endl;

            a[n+1]=7;       //a[3]= 7
            cout << a[0]<<" "<< a[1]<< " "<< a[2]<< " "<< a[3]<< " "<< a[4]<<endl<<endl;

            if(a[0]>=a[1])  //if(11 >= 9)
            a[4]=a[0];   //   a[4]= 11

            cout << a[0]<<" "<< a[1]<< " "<< a[2]<< " "<< a[3]<< " "<< a[4];
            cout<< endl;

            //Ejemplo 2, recorrer un arreglo
            double notas[]={2.3,8.5,3.2,9.5,4,5.5,7.0}; //declaración de un arreglo con 7 valore inciiales
            cout<<"El arreglo notas es: "<<endl;

            //imprimir los datos del arreglo en pantalla
            for(int i=0; i<7; i++)
                cout << notas[i] << " "; //se muestra cada elemento del array
            cout << endl;

            //calcular el promedio de los datos que están en el arreglo
            double suma=0.0;
            for(int i=0; i<7; i++)
                suma = suma +a[i];
            cout<<"El promedio es: "<<suma/7;


        }
        break;

    case 2:
        {
            //Ejemplo 3:
            double notas1[7];
            ingreso_datos_arreglo_teclado(notas1,7);
            double promedio = promedio_arreglo(notas1,7);
            reporte(notas1,7,promedio);
        }
        break;
    case 3:
        {
            
        }
        break;
    default: cout<<"Ingrese una opcion valida"<<endl;
    }//end switch
}
