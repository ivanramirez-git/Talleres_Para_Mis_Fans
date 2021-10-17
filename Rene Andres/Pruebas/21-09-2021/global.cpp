#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include "vectores.h"
#include "matrices.h"
#include "global.h"

using namespace std;

double norma(vector<double> v){
	double res=0;
	for(double i=0; i<v.size();i++){
		res=(v[i]*v[i])+res;
	}
	return sqrt(res);
}

bool sumaFilas(vector<vector<double>> m){
	double contador=0;
	vector<double> v;
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			contador+=m[i][j];
		}
		v.push_back(contador);
		contador=0;
	}
	//impresion_vector(v);
	for(int i=1;i<m.size();i++){
		if(v[i-1]!=v[i])
			return false;
	}
		return true;
}

bool sumaColumnas(vector<vector<double>> m){

	double contador=0;
	vector<double> v;
	for(int j=0;j<m[0].size();j++){
		for(int i=0;i<m.size();i++){
			contador+=m[i][j];
		}
		v.push_back(contador);
		contador=0;
	}
	//impresion_vector(v);
	for(int i=1;i<m.size();i++){
		if(v[i-1]!=v[i])
			return false;
	}
		return true;
}

bool sumaDiagonales(vector<vector<double>> m){
	double contador=0;
	vector<double> v;
	for(int i=0,j=0;j<m[0].size() && i < m.size();i++, j++){
		contador+=m[i][j];
	}
	v.push_back(contador);
	contador=0;

	for(int i=0,j=m[0].size()-1; 0<=j && i<m.size() ;i++, j--){
		contador+=m[i][j];
	}

	v.push_back(contador);
	//impresion_vector(v);
	for(int i=1;i<2;i++){
		if(v[i-1]!=v[i])
			return false;
	}
		return true;
}

bool magica(vector<vector<double>> m){

	return sumaFilas(m) && sumaColumnas(m) && sumaDiagonales(m);
}

// Tomado de https://foro.elhacker.net/programacion_cc/reto_funcion_extraer_numeros_de_cadenas_cppc-t349503.0.html
unsigned int getNumbers(char* szIn, char* szOut, size_t sizeBuffer)
{
    unsigned int iRet = 0;
 
    while(*szIn)
    {
        if (sizeBuffer == 0 && szOut)
            break;
 
        if ((*szIn) >= '0' && '9' >= (*szIn) )
        {
            if (szOut)
            {
                (*szOut++) = (*szIn);
                --sizeBuffer;
            }
            iRet++;
        }
        szIn++;
    }
 
    if (szOut)
        *szOut = (char)0x0;
 
    return iRet;
}
 
vector<int> leerDatosPrecios(string ruta){
	vector<int> v;
	string szCadena;
	int precio;

	ifstream f( ruta );
	if ( f.is_open() ) {
		getline( f, szCadena );
		getline( f, szCadena );
		while( !f.eof() ) {

			getline( f, szCadena );
			char* szBuffer = NULL;
		    size_t size = getNumbers(&szCadena[0], NULL, 0); // Cuantos numeros hay?...
		 
		    if (size > 0)
		    {
		        szBuffer = (char*)malloc(size + 1);
		        getNumbers(&szCadena[0], szBuffer, size);
		        precio=atoi(szBuffer);
		        //printf("%d\n", precio);
		        v.push_back(precio);
		        free(szBuffer);
		    }
		}
	}else cerr << "Error de apertura del archivo." << endl;
	
	return v;
}

vector<string> leerDatosServicios(string ruta){
	vector<string> v;

	string szCadena, palabra;
	char texto[50];

	int contador=0;

	ifstream f( ruta );
	if ( f.is_open() ) {
		getline( f, szCadena );
		getline( f, szCadena );
		while( !f.eof() ) {
			getline( f, szCadena );
			f>>palabra;
			v.push_back(palabra);
		}
	}else cerr << "Error de apertura del archivo." << endl;

	return v;
}

vector<vector<string> > leerDatosNombre(string ruta){
	vector<vector<string> > m;

	string szCadena, palabra1, palabra2;
	int contador=0;

	ifstream f( ruta );
	if ( f.is_open() ) {
		getline( f, szCadena );
		getline( f, szCadena );
		while( !f.eof() ) {

			getline( f, szCadena );
			f>>palabra1;
			f>>palabra2;
			vector<string> v;
			v.push_back(palabra1);
			v.push_back(palabra2);
			//impresion_vector(v);
			m.push_back(v);
			contador++;
		}
	}else cerr << "Error de apertura del archivo." << endl;

	return m;
}


vector<vector<int> > leerDatosInformacionPersonal(string ruta){
	vector<vector<int> > m;

	string szCadena, palabra1, palabra2, palabra3;
	int contador=0;

	ifstream f( ruta );
	if ( f.is_open() ) {
		getline( f, szCadena );
		getline( f, szCadena );
		while( !f.eof() ) {

			getline( f, szCadena );
			f>>palabra1;
			f>>palabra1;
			f>>palabra1;
			f>>palabra2;
			f>>palabra3;
			vector<int> v;

			v.push_back(stoi(&palabra1[0]));
			v.push_back(stoi(&palabra2[0]));
			v.push_back(stoi(&palabra3[0]));
			//impresion_vector(v);
			m.push_back(v);
			contador++;
		}
	}else cerr << "Error de apertura del archivo." << endl;

	return m;
}

vector<vector<string> > leerDatosServiciosRecibidos(string ruta){
	vector<vector<string> > m;

	string szCadena, palabra1, palabra2;
	int contador=0;

	ifstream f( ruta );
	if ( f.is_open() ) {
		getline( f, szCadena );
		getline( f, szCadena );
		while( !f.eof() ) {

			getline( f, szCadena );
			f>>palabra1;
			f>>palabra1;
			f>>palabra1;
			f>>palabra1;
			f>>palabra1;
			f>>palabra1;
			f>>palabra2;
			vector<string> v;
			v.push_back(palabra1);
			v.push_back(palabra2);
			//impresion_vector(v);
			m.push_back(v);
			contador++;
		}
	}else cerr << "Error de apertura del archivo." << endl;

	return m;
}

double factorial(double numero){
    double fact=1.0;
    if(numero<0.0) fact = 0.0;
    else if(numero==0) fact=1.0;
    else{
      for (double i = 1.0; i <= numero; i++){
         fact = fact*i;
      }
    }
    return fact;
}

double dobleFactorial(double numero){
    double fact=1.0;
    if(numero<=0.0) fact = 1.0;
    else{
      fact = numero*factorial(factorial(numero-2));
    }
    return fact;
}

void solucionDobleFactorial(int n){
	for (double i = 0; i <= n; ++i)
	{
		cout<<" x !! = "<<dobleFactorial(i)<<endl;
	}
}

vector<int> parejaFrecuencia(vector<int> v){
	int frecuencia;
	int temp[2];

	vector<int> retornable;

	temp[0]=-1;
	temp[1]=-1;

	for (int i = 0; i < v.size(); ++i)
	{
		frecuencia=0;
		/* code */
		for (int j = 0; j < v.size(); ++j)
		{
			/* code */
			//if (i!=j && v[i]==v[j])
			if (v[i]==v[j])
			{
				/* code */
				frecuencia++;
			}
		}
		if(temp[1]<frecuencia){
			temp[0]=v[i];
			temp[1]=frecuencia;
		}
	}
	retornable.push_back(temp[0]);
	retornable.push_back(temp[1]);
	return retornable;
}


vector<vector<int>> frecuenciaColumnas(vector<vector<int>> m){

	int contador=0;
	vector<vector<int>> mRetorno;




	for(int j=0;j<m[0].size();j++){
	vector<int> v;
	vector<int> pareja;
		for(int i=0;i<m.size();i++){
			//contador+=m[i][j];
			//v.push_back(contador);
			v.push_back(m[i][j]);
		}
		mRetorno.push_back(parejaFrecuencia(v));
		//contador=0;
	}
	return mRetorno;
}

