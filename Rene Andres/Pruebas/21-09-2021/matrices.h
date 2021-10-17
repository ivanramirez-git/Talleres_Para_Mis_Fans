#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
#include <vector>
using namespace std;

void crearMatriz(vector< vector<int> > & M, int n, int m);
void crearMatriz_defecto(vector< vector<int> > & M, int n, int m, int k);
void imprimirMatriz(vector< vector<int> > M);
void imprimirMatriz(vector< vector<double> > M);
void imprimirMatriz(vector< vector<string> > M);

void MatrizAleatoria(vector< vector<int> > & M, int a, int b);
vector< vector<int> > MatrizInicial(int n, int m);
void intercambioFilas(vector< vector<int> > & M,int k, int l);
void intercambioFilas2(vector< vector<int> > & M,int k, int l);
void reemplazarFilas(vector< vector<int> > & M,int k, int l, double c);
// (A+B)t=At+Bt
vector< vector<int> > sumaDosMatrices(vector< vector<int> > A, vector< vector<int> > B);
vector<vector<int> > matrizAleatoria( int x, int y, int a, int b);
vector<vector<int> > transpuestaDeMatriz(vector<vector<int> > M);

vector<vector<int> > reemplazarValores(vector<vector<int> > m,int x, int y);
vector<vector<vector<int>>> cargarMatrices(string ruta);


#include "matrices.cpp"
#endif // MATRICES_H_INCLUDED
