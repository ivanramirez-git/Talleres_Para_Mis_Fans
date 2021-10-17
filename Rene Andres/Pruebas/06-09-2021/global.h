#ifndef GLOBAL_H
#define GLOBAL_H
#include <vector>
using namespace std;

// Funciones aqui

double norma(vector<double> v);
bool magica(vector<vector<double> > m);
bool sumaFilas(vector<vector<double> > m);
bool sumaColumnas(vector<vector<double> > m);
bool sumaDiagonales(vector<vector<double> > m);


vector<int> leerDatosPrecios(string ruta);
vector<string> leerDatosServicios(string ruta);
vector<vector<string> > leerDatosNombre(string ruta);
vector<vector<int> > leerDatosInformacionPersonal(string ruta);
vector<vector<string> > leerDatosServiciosRecibidos(string ruta);

#include "global.cpp"
#endif // VECTORES_H_INCLUDED
