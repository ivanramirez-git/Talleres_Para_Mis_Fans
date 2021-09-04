#include <iostream>
#include <vector>
#include <time.h>
#include "vectores.h"
#include "matrices.h"


using namespace std;

int main()
{
    /*
    //manejo inicial de una matriz definida con vectores
    vector< vector<int> > M; //M es un vector y M[i] también lo son
    crearMatriz_defecto(M,10,10,1);
    imprimirMatriz(M);

    //************************************************
    //Ejecuciones parciales de los ejercicio 1 y 2
    vector < vector<int> > B =MatrizInicial(6,8);
    imprimirMatriz(B);
    cout<<endl<<endl;

    intercambioFilas(B,1,6);
    imprimirMatriz(B);
    cout<<endl<<endl;

    intercambioFilas2(B,2,5);
    imprimirMatriz(B);
    cout<<endl<<endl;

    //********************Ejercicio 4
    vector< vector<int> > A =MatrizInicial(10,8);
    imprimirMatriz(A);
    cout<<endl<<endl;
    intercambioFilas2(A,1,10);
    reemplazarFilas(A,9,2,3);
    imprimirMatriz(A);
    cout<<endl<<endl;*/
    vector<int> V;
    vector<vector<int>> A,B,M, At, Bt;

    int opcion;
    cout<<"Bienvenido"<<endl;
    do{
        cout<<"1. Vector, Generar 10 vectores aleatorios."<<endl;
        cout<<"2. Matriz, comprobar propiedad."<<endl;
        cout<<"0. Salir."<<endl;

        cin>>opcion;

        switch(opcion){

            case 1:
                for(int i=0;i<10;i++){
                    V=vectorAleatorio(20,10,50);
                    V=remplazarValor(V,25,-1);
                    cout<<endl;
                    impresion_vector(V);
                    cout<<endl;
                }
            break;
            case 2:
                A=matrizAleatoria(4,3,1,10);
                B=matrizAleatoria(4,3,1,10);

                //(A+B)t
                cout<<"A:"<<endl;
                imprimirMatriz(A);
                cout<<endl;
                cout<<"B:"<<endl;
                imprimirMatriz(B);
                cout<<endl;
                M=sumaDosMatrices(A,B);
                cout<<"(A+B):"<<endl;
                imprimirMatriz(M);
                cout<<endl;
                M=transpuestaDeMatriz(M);
                cout<<"(A+B)t:"<<endl;
                imprimirMatriz(M);
                cout<<endl;
                At=transpuestaDeMatriz(A);
                cout<<"At:"<<endl;
                imprimirMatriz(At);
                cout<<endl;
                Bt=transpuestaDeMatriz(B);
                cout<<"Bt:"<<endl;
                imprimirMatriz(Bt);
                cout<<endl;
                M=sumaDosMatrices(At,Bt);
                cout<<"At+Bt:"<<endl;
                imprimirMatriz(M);
                cout<<endl;

            break;
            case 0:
                return 0;
            break;
            default:

            break;
        }
    }while(1);
}







    /*
    llenarMatriz(M,0,100);
   // imprimirMatriz(M);

llenarMatriz_ejemplo2(M,10,10);
imprimirMatriz(M);

cout<<endl<<endl<<endl;
llenarMatriz_ejemplo2(M,5,6);
imprimirMatriz(M);


   // ejercicio1(M);
/*
    cout<<"Intercambiar F2 y F3"<<endl;
    intercambioFilas(M,2,3);
    imprimirMatriz(M);
    cout<<"Reemplazar F5 por F5+F4"<<endl;
    reemplazarFilas(M,5,4,1);
    imprimirMatriz(M);
    return 0;
    */

