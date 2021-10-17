/*****************************************************************************
 este programa permite calcular la utilidad de  una empresa agricola que pose 5 productos ;a  cad
a producto se le ingresa el va valor de venta la cantidad producida y el costo de produccion;y pre-
senta el resumen de cada producto.

autores :jonatan Alexander  Muñoz Triana ,Carlos Daniel Rincon 
fecha:07/09/2021
grupo:Lunes 


*******************************************************************************/

#include <iostream>

using namespace std;

int const num_productos=5;

string nombres[num_productos]={ "arroz","papa","yuca","platano","cebolla"};

int precios[num_productos];

int opcion;
int opcion_productos;
float iva;
float valorPagar;
float suma(float, float);   //Prototipo de la funcion



int main()
{
    do{
       cout<<"Bienvenido, escoja una opcion: "<<endl<<endl;
       cout<<"Ingresar precios ...............1"<<endl;
       cout<<"Realizar Venta..................2"<<endl;
       cout<<"Salir...........................3"<<endl;
       cin>>opcion;
       
       switch(opcion){
           case 1:
                for(int i = 0; i< num_productos; i++){
                    cout<<"Digite el precio de "<<nombres[i];
                    cin>>precios[i];
                }
                break;
           case 2:
                cout<<"***** Articulos en venta ********"<<endl<<endl;
                cout<<"arroz.................1"<<endl;
                cout<<"papa..............2"<<endl;
                cout<<"yuca..................3"<<endl;
                cout<<"platano.............4"<<endl;
                cout<<"cebolla...............5"<<endl;
                cout<<"Escoja un producto ";
                cin>>opcion_productos;
                
                cout<<"------- Recivo de Venta --------"<<endl<<endl;
                cout<<"producto:   "<<nombres[opcion_productos-1]<<endl;
                cout<<"Valor bruto........"<<precios[opcion_productos-1]<<endl;
                iva = precios[opcion_productos-1]* 0.19;
                cout<<iva<<endl;
                //valorPagar = precios[opcion_producto-1]+iva;
                valorPagar = suma(precios[opcion_productos-1], iva);
                cout<<"Valor a pagar......  $"<<valorPagar<<endl<<endl;
                
                
                break;
       }
    }
    while(opcion<3);
    

    return 0;
}


float suma(float n1, float n2){
    int solucion;
    
    solucion = n1 +n2;
    return solucion;
}

