#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "vectores.h"
#include "matrices.h"

using namespace std;

void crearMatriz(vector<vector<int> > & M, int n, int m)
{//crea la cuadrícula vacía de datos o tabla o matriz
    M.resize(n); // crea un vector M de tamaño n, en donde cada casilla almacenará a un vector
    for(unsigned int i=0; i<M.size();++i)//recorre cada casilla del vector M
        M[i].resize(m); //cada vector almacenado en la casilla i del vector M se define de tamaño m
}

void crearMatriz_defecto(vector< vector<int> > & M, int n, int m, int k)
{//crea la cuadrícula o tabla o matriz  con todos los datos igual a k
    M.resize(n); // crea un vector M de tamaño n, en donde cada casilla almacenará a un vector
    for(unsigned int i=0; i<M.size();++i)//recorre cada casilla del vector M
        M[i].resize(m,k); //cada vector almacenado en la casilla i del vector M se define de tamaño m
}

void imprimirMatriz(vector< vector<int> > M)
{
    for(unsigned int i=0; i<M.size();++i)
    {
        for(unsigned int j=0; j<M[0].size();++j)
            cout<<M[i][j]<<" \t";
        cout<<endl;
    }
}

void imprimirMatriz(vector< vector<double> > M)
{
    for(unsigned int i=0; i<M.size();++i)
    {
        for(unsigned int j=0; j<M[0].size();++j)
            cout<<M[i][j]<<" \t";
        cout<<endl;
    }
}


void imprimirMatriz(vector< vector<string> > M){
    for(unsigned int i=0; i<M.size();++i)
    {
        for(unsigned int j=0; j<M[0].size();++j)
            cout<<M[i][j]<<" \t";
        cout<<endl;
    }
}

void MatrizAleatoria(vector< vector<int> > & M, int a, int b)
{
    srand(time(NULL));
    for(unsigned int i=0; i<M.size();++i)
        for(unsigned int j=0; j<M[0].size();++j)
            M[i][j]=a+rand()%(b-a+1);
}

vector< vector<int> > MatrizInicial(int n, int m)
{
    vector< vector<int> > A; //declara la matria
    crearMatriz(A,n,m); //crea la matriz vacía

    for(unsigned int i=0; i<A.size();++i) //con el doble se recorre y se llena cada casilla de la matriz
        for(unsigned int j=0; j<A[0].size();++j)
                A[i][j]=i+j+2;

    return A;
}

void intercambioFilas(vector< vector<int> > & M,int k, int l)
{
  if(k!=l)
      for(unsigned int j=0;j<M[0].size();++j)
      {
            int aux=M[k-1][j];
            M[k-1][j]=M[l-1][j];
            M[l-1][j]=aux;
      }
   //existe un método swap para vectores que intercambia dos elementos
   //   swap(M[k-1][j],M[l-1][j]);
}

void intercambioFilas2(vector< vector<int> > & M,int k, int l)
{
  if(k!=l)
  {
      vector<int> aux=M[k-1];
      M[k-1]=M[l-1];
      M[l-1]=aux;
  }
}


void reemplazarFilas(vector< vector<int> > & M,int k, int l, double c)
{
  if(k!=l)
      for(unsigned int j=0;j<M[0].size();++j)
        M[k-1][j]=M[k-1][j]+c*M[l-1][j];
}

vector< vector<int> > sumaDosMatrices(vector< vector<int> > A, vector< vector<int> > B)
{
    /*
    cout<<"A: "<<A.size()<<" B: "<<B.size()<<endl;
    cout<<"A[]: "<<A[0].size()<<" B[]: "<<B[0].size()<<endl;
    */
    if(A.size()==B.size()){
        if(A[0].size()==B[0].size()){

            vector< vector<int> > V;
            crearMatriz(V,A.size(),A[0].size());

            for(int i=0; i<A.size();i++){

                for(int j=0;j<A[0].size();j++){
                    V[i][j]=A[i][j]+B[i][j];
                    //cout<<".";
                }

            }
        return V;
        }
    }
    cout<<"No se puede sumar las matrices"<<endl;
    return A;
}

vector<vector<int> > matrizAleatoria( int x, int y, int a, int b)
{
    vector<vector<int> > M;
    crearMatriz(M,x,y);
    srand(time(NULL)+rand());
    for (int i = 0; i < M.size(); ++i)
    {
       for(int j=0; j<M[0].size();++j)
            M[i][j]=(a+rand()%(b-a+1));
    }
        return M;
}

vector<vector<int> > transpuestaDeMatriz(vector<vector<int> > M){
    vector<vector<int> > V;
    crearMatriz(V,M[0].size(),M.size());
    for(int i=0; i<M.size();i++){
        for(int j=0;j<M[0].size();j++){
            V[j][i]=M[i][j];
        }
    }
    return V;
}

vector<vector<int> > reemplazarValores(vector<vector<int> > m,int x, int y){
    for (int i = 0; i < m.size(); ++i)
    {
        for (int j = 0; j < m[0].size(); ++j)
        {
            /* code */
            if(m[i][j]==x)
                m[i][j]=y;
        }
    }
    return m;
}

vector<vector<vector<int>>> cargarMatrices(string ruta){
    
    vector<vector<vector<int>>> M;

    string texto, numero;

    ifstream f( ruta );

    if ( f.is_open() ) {
        getline( f, texto );

        while( !f.eof() ) {


            //cout<<texto<<endl;
            vector<vector<int>> ma;
            //cout<<"Bandera 1"<<endl;
            //getline( f, texto );
            for (int i = 0; /*texto!="Matriz B"*/i<5; ++i)
            {
                //cout<<texto<<endl;
                /* code */
                vector<int> mini;
                f>>numero;
                for (int j = 0; /*numero[0]!='\0'*/j<5; ++j)
                {
                    //cout<<numero<<endl;
                    mini.push_back(atoi(&numero[0]));
                    f>>numero;
                }
                ma.push_back(mini);
                getline( f, texto );
            }
            M.push_back(ma);



            getline( f, texto );
            cout<<texto<<endl;
            vector<vector<int>> mb;
            for (int i = 0; /*!f.eof()*/i<5; ++i)
            {
                /* code */
                vector<int> mini;
                f>>numero;
                for (int j = 0; /*numero[0]!='\0'*/j<5; ++j)
                {
                    cout<<numero<<endl;
                    mini.push_back(atoi(&numero[0]));
                    f>>numero;
                }
                mb.push_back(mini);
                getline( f, texto );
            }
            M.push_back(mb);
        }
    }else cerr << "Error de apertura del archivo." << endl;

    return M;
}

