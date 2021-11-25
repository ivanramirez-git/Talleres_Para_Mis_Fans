#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

struct azar{
    int numeros[50];
    int contador;
};

void imprimir(azar a);
azar llenar(azar a);

void desvia(azar a);
void media(azar a);
void mayor(azar a);
void menor(azar a);
void prom(azar a);

int main(){

    char respuesta;
    azar a;
    int opcion;

    for(int i = 0; i < 50; i++){
        a.numeros[i] = 0;
    }
    a.contador = 50;

    cout<<".:: Bienvenido ::."<<endl;
    cout<<"\n";
    while(true){
        cout<<"Desea generar nuevos datos al azar? (s/n)"<<endl;
        cin>>respuesta;

        if(respuesta=='s'){

            a=llenar(a);

            imprimir(a);

            cout<<"\n";
            cout<<"Parametros estadisticos ";
            cout<<"\n";
            cout<<"a) Desviacion estandar ";
            desvia(a);
            cout<<"b) Media ";
            media(a);
            cout<<"c) Mayor ";
            mayor(a);
            cout<<"d) Menor ";
            menor(a);
            cout<<"e) Promedio ";
            prom(a);
            cout<<"\n";

        }else{

            cout<<"\n";
            cout<<"Gracias por usar el programa"<<endl;
            break;
        }
    }    
    
    return 0;
}

void imprimir(azar a){
    for(int i=0; i<a.contador; i++){
        cout << a.numeros[i] << " ";
    }
    cout << endl;
}

azar llenar(azar a){
    srand(time(NULL));
    for(int i=0; i<a.contador; i++){
        a.numeros[i] = rand() % 500 + 1;
    }
    return a;
}

void desvia(azar a){
    float suma = 0;
    float promedio = 0;
    float desviacion = 0;
    for(int i=0; i<a.contador; i++){
        suma += a.numeros[i];
    }
    promedio = suma / a.contador;
    for(int i=0; i<a.contador; i++){
        desviacion += pow(a.numeros[i] - promedio, 2);
    }
    desviacion = sqrt(desviacion / a.contador);
    cout << desviacion << endl;
}

void media(azar a){
    float suma = 0;
    float promedio = 0;
    for(int i=0; i<a.contador; i++){
        suma += a.numeros[i];
    }
    promedio = suma / a.contador;
    cout << promedio << endl;
}

void mayor(azar a){
    int mayor = a.numeros[0];
    for(int i=0; i<a.contador; i++){
        if(a.numeros[i] > mayor){
            mayor = a.numeros[i];
        }
    }
    cout << mayor << endl;
}

void menor(azar a){
    int menor = a.numeros[0];
    for(int i=0; i<a.contador; i++){
        if(a.numeros[i] < menor){
            menor = a.numeros[i];
        }
    }
    cout << menor << endl;
}

void prom(azar a){
    float suma = 0;
    float promedio = 0;
    for(int i=0; i<a.contador; i++){
        suma += a.numeros[i];
    }
    promedio = suma / a.contador;
    cout << promedio << endl;
}
