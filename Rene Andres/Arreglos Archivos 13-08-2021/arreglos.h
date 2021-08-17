#ifndef ARREGLOS_H_INCLUDED
#define ARREGLOS_H_INCLUDED

void ingreso_datos_arreglo_teclado(double A[],int n);
void ingreso_datos_arreglo_teclado(int A[],int n);
double suma(double arreglo[],int n);
int suma(int arreglo[],int n);
void impresion_arreglo(double arreglo[], int n);
void impresion_arreglo(int arreglo[], int n);
double promedio_arreglo(double arreglo[],int n);
double promedio_arreglo(int arreglo[],int n);
void reporte(double arreglo[], int n, double promedio);

#include "arreglos.cpp"

#endif // ARREGLOS_H_INCLUDED
