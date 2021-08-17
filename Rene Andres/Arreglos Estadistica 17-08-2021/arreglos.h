#ifndef ARREGLOS_H_INCLUDED
#define ARREGLOS_H_INCLUDED

#include "arreglos.cpp"

void ingreso_datos_arreglo_teclado(double A[],int n);
void ingreso_datos_arreglo_teclado(int A[],int n);
void ingreso_datos_arreglo_aleatorios(int A[],int n, int a, int b);
void ingreso_datos_arreglo_aleatorios_semilla(int A[],int n, int a, int b, int semilla);
//llena el arreglo con datos en el intervalo [a,b]
void ingreso_datos_notas_aleatorias_ej2(double A[],int n);
double suma(double arreglo[],int n);
int suma(int arreglo[],int n);
double maximo_arreglo(double arreglo[],int n);
int maximo_arreglo(int arreglo[],int n);
double minimo_arreglo(double arreglo[],int n);
int minimo_arreglo(int arreglo[],int n);
void impresion_arreglo(double arreglo[], int n);
void impresion_arreglo(int arreglo[], int n);
void impresion_arreglo_reversa(double arreglo[], int n);
void impresion_arreglo_reversa(int arreglo[], int n);
double promedio_arreglo(double arreglo[],int n);
double promedio_arreglo(int arreglo[],int n);
void reporte(double arreglo[], int n, double promedio);
void reporte_ej3(int datos[], int n);
void ordenar_acendente(int arreglo[], int n);
void ordenar_descendente(int arreglo[], int n);
int encontrar_moda(int arreglo[], int n);
int encontrar_mediana(int arreglo[],int n);
void estadistica_descriptiva(int arreglo[], int n);
double encontrar_varianza(int arreglo[],int n);
double encontrar_desviacion(int arreglo[],int n);

#endif // ARREGLOS_H_INCLUDED


