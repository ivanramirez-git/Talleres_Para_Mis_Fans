#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "vectores.h"

using namespace std;

//v.resize(n) crea un vector vacío de tamaño n
void crear_vector(vector<int> &v,int n)
{
    v.resize(n);
}

//v.resize(n,x) crea un vector de tamaño n en el que
//todas las casillas almacenan un valor x
void crear_vector(vector<int> &v,int n,int x)
{
    v.resize(n,x);
}

void crear_vector(vector<double> &v,int n)
{
    v.resize(n);
}

//v.resize(n,x) crea un vector de tamaño n en el que
//todas las casillas almacenan un valor x
void crear_vector(vector<double> &v,int n,double x)
{
    v.resize(n,x);
}

void impresion_vector(vector<int> v)
{
    for(long long unsigned int i=0; i<v.size(); i++)
      cout << v[i] <<" ";
    cout << endl;
}


void impresion_vector(vector<double> v)
{
    for(long long unsigned int i=0; i<v.size(); i++)
      cout << v[i] << " ";
    cout << endl;
}

void ingreso_datos_vector_teclado(vector<int> & v)
{
    for(long long unsigned int i=0;i<v.size();i++)
    {
        cout<<"Ingrese el dato "<<i+1<<endl;
        cin>>v[i];
    }
}

void ingreso_datos_vector_teclado(vector<double> & v)
{
    for(long long unsigned int i=0;i<v.size();i++)
    {
        cout<<"Ingrese el dato "<<i+1<<endl;
        cin>>v[i];
    }
}

void ingreso_datos_vector_aleatorios(vector<int> & v, int a, int b)
{
    srand(time(NULL));//genera valores aleatorios diferentes en cada ejecución
    for(long long unsigned int i=0;i<v.size();i++)
        v[i]=a + rand()%(b+1-a);
}

//crear una función para generar un vector aleatorio con datos double
//(seguir análogamente lo hecho en arreglos)

double suma(vector<double> v)
{
    double suma=0;
    for(long long unsigned int i=0;i<v.size();i++)
        suma += v[i];
    return suma;
}

int suma(vector<int> v)
{
    int suma=0;
    for(long long unsigned int i=0;i<v.size();i++)
        suma += v[i];
    return suma;
}

double maximo_vector(vector<double> v)
{
    double maximo=v[0];
    for(long long unsigned int i=1;i<v.size();i++)
        if(v[i]>maximo)
            maximo = v[i];
    return maximo;
}

int maximo_vector(vector<int> v)
{
    int maximo=v[0];
    for(long long unsigned int i=1;i<v.size();i++)
        if(v[i]>maximo)
            maximo = v[i];
    return maximo;
}

double minimo_vector(vector<double> v)
{
    double minimo=v[0];
    for(long long unsigned int i=1;i<v.size();i++)
        if(v[i]<minimo)
            minimo = v[i];
    return minimo;
}

int minimo_vector(vector<int> v)
{
    int minimo=v[0];
    for(long long unsigned int i=1;i<v.size();i++)
        if(v[i]<minimo)
            minimo = v[i];
    return minimo;
}

vector<int> remplazarValor(vector<int> v, int x, int y){
    for(int i=0; i<v.size();i++){
        if(v[i] == x){
            v[i]=y;
        }
    }
    return v;
}

vector<int> vectorAleatorio( int n, int a, int b)
{
    vector<int> V;
    srand(time(NULL)+rand());
        for(int j=0; j<n;++j)
            V.push_back(a+rand()%(b-a+1));
        return V;
}
