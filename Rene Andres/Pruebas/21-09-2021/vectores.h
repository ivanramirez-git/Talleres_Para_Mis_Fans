#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

using namespace std;

void crear_vector(vector<int> &v,int n);
void crear_vector(vector<int> &v,int n,int x);
void crear_vector(vector<double> &v,int n);
void crear_vector(vector<double> &v,int n,double x);
void impresion_vector(vector<int> v);
void impresion_vector(vector<double> v);
void impresion_vector(vector<string> v);
void ingreso_datos_vector_teclado(vector<int> & v);
void ingreso_datos_vector_teclado(vector<double> & v);
//llena el arreglo con datos en el intervalo [a,b]
void ingreso_datos_vector_aleatorios(vector<int> & v, int a, int b);

double suma(vector<double> v);
int suma(vector<int> v);
double maximo_vector(vector<double> v);
int maximo_vector(vector<int> v);
double minimo_vector(vector<double> v);
int minimo_vector(vector<int> v);

//Escriba una funcion que reciba v, x, y y retorne el vector v con los reemplazos correspondientes.
vector<int> remplazarValor(vector<int> v, int x, int y);
vector<int> vectorAleatorio(int n, int a, int b);


#include "vectores.cpp"

#endif // VECTORES_H_INCLUDED
