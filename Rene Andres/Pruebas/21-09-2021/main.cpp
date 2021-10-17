#include <iostream>
#include <vector>
//#include <time.h>
#include "global.h"


using namespace std;

int main()
{
    
    vector<vector<int>> A,B,M,At,Bt;
    vector<vector<vector<int>>> m;

    M={{7,6,6,5,8},{7,7,6,5,7},{5,5,6,5,8},{7,6,6,6,6},{7,4,6,6,8}};

    int opcion;
    cout<<"Bienvenido"<<endl;
    do{
        cout<<endl;
        cout<<"1. Doble Factorial."<<endl;
        cout<<"2. Matriz transpuesta."<<endl;
        cout<<"3. Cargar datos."<<endl;
        cout<<"0. Salir."<<endl;
        cout<<"-> ";

        cin>>opcion;

        switch(opcion){

            case 1:
                solucionDobleFactorial(5);
            break;
            case 2:

                imprimirMatriz(reemplazarValores(M,5,3));
                cout<<endl;
                imprimirMatriz(frecuenciaColumnas(M));

            break;
            case 3:
                m=cargarMatrices("datos.txt");
                A=m[0];
                B=m[1];

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
