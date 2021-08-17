#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "arreglos.h"
#include <string>
#include <vector>

using namespace std;

void ingreso_datos_arreglo_teclado(double A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Ingrese el dato "<<i+1<<endl;
        cin>>A[i];
    }
}

void ingreso_datos_arreglo_teclado(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Ingrese el dato "<<i+1<<endl;
        cin>>A[i];
    }
}

double suma(double arreglo[],int n)
{
    double suma=0.0;
    for(int i=0; i<n; i++)
        suma += arreglo[i];
    return suma;
}

int suma(int arreglo[],int n)
{
    int suma=0;
    for(int i=0; i<n; i++)
        suma += arreglo[i];
    return suma;
}

void impresion_arreglo(double arreglo[], int n)
{
    for(int i=0; i<n; i++)
      cout << arreglo[i] << " "; //se muestra cada elemento del array
    cout << endl;
}

void impresion_arreglo(int arreglo[], int n)
{
    for(int i=0; i<n; i++)
      cout << arreglo[i] << " "; //se muestra cada elemento del array
    cout << endl;
}

double promedio_arreglo(double arreglo[],int n)
{
    double promedio= suma(arreglo,n)/n;
    return promedio;
}

double promedio_arreglo(int arreglo[],int n)
{
    double promedio= (1.0*suma(arreglo,n))/n;
    return promedio;
}

void reporte(double arreglo[], int n, double promedio)
{
    double contador=0;

    for(double i = 1; i<= n ;i++){
        contador=contador + arreglo[i];
        promedio=contador/i;

    }
}
