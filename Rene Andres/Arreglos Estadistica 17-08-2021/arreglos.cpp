#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "arreglos.h"

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

void ingreso_datos_arreglo_aleatorios(int A[],int n, int a, int b)
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
        A[i]=a + rand()%(b+1-a);
}

void ingreso_datos_arreglo_aleatorios_semilla(int A[],int n, int a, int b, int semilla)
{
    srand(semilla);
    for(int i=0;i<n;i++)
        A[i]=a + rand()%(b+1-a);
}

void ingreso_datos_notas_aleatorias_ej2(double A[],int n)
{
    srand(time(NULL));
    for(int i=0;i<n;i++)
        A[i]=rand()%(100+1)/10; //generar enteros entre [0,100] y luego dividir para 10
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

double maximo_arreglo(double arreglo[],int n)
{
    double maximo=arreglo[0];
    for(int i=1;i<n;i++)
        if(arreglo[i]>maximo)
            maximo = arreglo[i];
    return maximo;
}

int maximo_arreglo(int arreglo[],int n)
{
    int maximo=arreglo[0];
    for(int i=1;i<n;i++)
        if(arreglo[i]>maximo)
            maximo = arreglo[i];
    return maximo;
}

double minimo_arreglo(double arreglo[],int n)
{
    double minimo=arreglo[0];
    for(int i=1;i<n;i++)
        if(arreglo[i]<minimo)
            minimo = arreglo[i];
    return minimo;
}

int minimo_arreglo(int arreglo[],int n)
{
    int minimo=arreglo[0];
    for(int i=1;i<n;i++)
        if(arreglo[i]<minimo)
            minimo = arreglo[i];
    return minimo;
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

void impresion_arreglo_reversa(double arreglo[], int n)
{
    for(int i=n-1; i>=0; i--)
      cout << arreglo[i] << " "; //se muestra cada elemento del array
    cout << endl;
}

void impresion_arreglo_reversa(int arreglo[], int n)
{
    for(int i=(n-1); i>=0; i--)
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
    ofstream f;
    f.open("Reporte.txt");
    f<<"El promedio de notas es: "<<promedio<<endl;
    f<<"Las notas sobre el promedio son:"<<endl;
    cout<<"El promedio de notas es: "<<promedio<<endl;
    cout<<"Las notas sobre el promedio son:"<<endl;

    for(int i=0; i<n; i++)
        if(arreglo[i]>promedio)
        {
            cout<<" Alumno "<<i+1<<" Nota: "<<arreglo[i]<<endl;
            f<<" Alumno "<<i+1<<" Nota: "<<arreglo[i]<<endl;
        }
    f.close();
}

void reporte_ej3(int datos[], int n)
{
    impresion_arreglo(datos,n); //se imprime el arreglo
    cout<<"Suma: "<<suma(datos,n)<<endl; //se suman los elementos del arreglo
    cout<<"Promedio: "<<promedio_arreglo(datos,n)<<endl;
    cout<<"Maximo: "<<maximo_arreglo(datos,n)<<endl;
    cout<<"Minimo: "<<minimo_arreglo(datos,n)<<endl;
    impresion_arreglo_reversa(datos,n);

    ofstream f;
    f.open("Reporte.txt",ios::app);
    //impresión de datos
    for(int i=0; i<n; i++)
      f << datos[i] << " "; //se muestra cada elemento del array
    f << endl;
    f<<"Suma: "<<suma(datos,n)<<endl; //se suman los elementos del arreglo
    f<<"Promedio: "<<promedio_arreglo(datos,n)<<endl;
    f<<"Maximo: "<<maximo_arreglo(datos,n)<<endl;
    f<<"Minimo: "<<minimo_arreglo(datos,n)<<endl;

    //impresión en reversa
    for(int i=(n-1); i>=0; i--)
        f << datos[i] << " ";
    f << endl;

    f.close();
}

void ordenar_ascendente(int arreglo[], int n)
{
    int aux;
    for(int i=0;i<n;i++) 
        for(int j=0; j<n-1; j++)
            if (arreglo[j] > arreglo[j+1] && i!=j)
            {
                aux = arreglo[j];
                arreglo[j]= arreglo[j+1];
                arreglo[j+1]= aux;
           }
}

void ordenar_descendente(int arreglo[], int n)
{
   int aux;
    for(int i=0;i<n;i++) 
        for(int j=0; j<n-1; j++)
            if (arreglo[j] < arreglo[j+1] && i!=j)
            {
                aux = arreglo[j];
                arreglo[j]= arreglo[j+1];
                arreglo[j+1]= aux;
            }
}

int encontrar_moda(int arreglo[], int n)
{
    int indice=0, contador=0, actual=0;

    for(int i=0;i<n;i++){
        contador=0;
        for(int j=0;j<n;j++){
            if(arreglo[i]==arreglo[j] && i!=j){
                contador=contador+1;
            }               
        }
        if(contador>=actual){
            actual=contador; //guardamos el mayor por el momento
            indice=i;    
        }
    }
    return arreglo[indice];
    //cout<<"La moda es: "<<arreglo[indice]<<" y tiene "<<actual+1<<" repeticiones"<<endl;
}

int encontrar_mediana(int arreglo[],int n)
{
    double mediana;
    ordenar_ascendente(arreglo,n);
    if(n%2==0){
        mediana=(((double)arreglo[((n/2)-1)]+(double)arreglo[(n/2)])/2.0);
    }else{
        mediana=arreglo[(n/2)];
    }
    return mediana;
    //cout<<"La mediana es: "<<mediana<<endl;
}

double encontrar_varianza(int arreglo[],int n)
{
    double media=promedio_arreglo(arreglo,n);
    double varianza=0;
    for(int i=0;i<n;i++){
        varianza+=pow(arreglo[i] - media, 2);
    }
    if(n!=0)
        varianza = varianza/n;
    return varianza;
}

double encontrar_desviacion(int arreglo[],int n)
{
    return sqrt(encontrar_varianza(arreglo,n));
}

void estadistica_descriptiva(int arreglo[], int n)
{
    cout<<"Suma: "<< suma(arreglo,n)<<endl;
    cout<<"Promedio: "<< promedio_arreglo(arreglo,n)<<endl;
    cout<<"Valor maximo: "<< maximo_arreglo(arreglo,n)<<endl;
    cout<<"Valor minimo: "<< minimo_arreglo(arreglo,n)<<endl;
    cout<<"Moda: "<< encontrar_moda(arreglo,n)<<endl;
    cout<<"Mediana: "<< encontrar_mediana(arreglo,n)<<endl;
    cout<<"Varianza: "<< encontrar_varianza(arreglo,n)<<endl;
    cout<<"Desviacion estandar: "<< encontrar_desviacion(arreglo,n)<<endl;



}