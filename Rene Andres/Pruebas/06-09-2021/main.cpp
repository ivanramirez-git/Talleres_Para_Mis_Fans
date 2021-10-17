#include <iostream>
#include <vector>
#include <time.h>
#include "global.h"


using namespace std;

int main()
{
    
    vector<double> V={1,5,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81,85,89,93,97,101};
    vector<vector<double>> M1,M2;

    M1={{2,3,5},{13,17,19},{31,37,41}};
    M2={{2,7,6},{9,5,1},{4,3,8}};

    vector<vector<string> > Nombre;
    vector<vector<string> > ServiciosRecibidos;
    vector<vector<int> > InfoPersonal;

    int opcion;
    cout<<"Bienvenido"<<endl;
    do{
        cout<<endl;
        cout<<"1. Norma de vector."<<endl;
        cout<<"2. Matriz magica."<<endl;
        cout<<"3. Cargar datos."<<endl;

        cout<<"0. Salir."<<endl;

        cin>>opcion;

        switch(opcion){

            case 1:
                cout<<"La norma del vector v=(1,5,9,13,17,21,25,29,33,37,41,45,49,53,57,61,65,69,73,77,81,85,89,93,97,101) es: "<<norma(V)<<endl;
                cout<<endl;
            break;
            case 2:
                imprimirMatriz(M1);
                if(magica(M1)){
                    cout<<"M1 es una matriz magica"<<endl;
                }else{
                    cout<<"M1 NO es una matriz magica"<<endl;
                }

                imprimirMatriz(M2);
                if(magica(M2)){
                    cout<<"M2 es una matriz magica"<<endl;
                }else{
                    cout<<"M2 NO es una matriz magica"<<endl;
                }

            break;
            case 3:
                cout<<endl<<"Precios: (vector)"<<endl;
                impresion_vector(leerDatosPrecios("infoServiciosDentalesPrecios.txt"));
                cout<<endl<<"Servicios: (vector)"<<endl;
                impresion_vector(leerDatosServicios("infoServiciosDentalesPrecios.txt"));
                cout<<endl<<"Nombre: (matriz)"<<endl;
                imprimirMatriz(leerDatosNombre("infoClientesDentista.txt"));
                cout<<endl<<"Informacion Personal: (matriz)"<<endl;
                imprimirMatriz(leerDatosInformacionPersonal("infoClientesDentista.txt"));
                cout<<endl<<"Servicios Recibidos: (matriz)"<<endl;
                imprimirMatriz(leerDatosServiciosRecibidos("infoClientesDentista.txt"));


            break;
            case 0:
                return 0;
            break;
            default:

            break;
        }
    }while(1);
}
