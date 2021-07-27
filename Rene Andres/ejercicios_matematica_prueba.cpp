#include <iostream>
#include <math.h>

using namespace std;

int menu()
{
    int opcion;
    cout<<"*********************************"<<endl;
    cout<<".:: BIENVENIDX ::."<<endl;
    cout<<"Elija el punto de la prueba"<<endl;
    cout<<"1. Punto 1: raices "<<endl;
    cout<<"2. Punto 2: aproximacion n! "<<endl;
    cout<<"3. Punto 3: ventas "<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"*********************************"<<endl;
    cout<<endl;
    cin>>opcion;
    return opcion;
}

int aleatorio_entre(int a, int b)
{
    
    int x=a+rand()%(b+1-a);
    return x;
}

void raices(int a, int b, int c)
{
    cout<<"polinomio: "<<endl<<a<<"x^2"<<endl<<b<<"x"<<endl<<c<<endl;

    float cero_a=(-b+sqrt(((b*b)-(4*a*c))))/(2*a);
    float cero_b=(-b-sqrt(((b*b)-(4*a*c))))/(2*a);

    cout<<"x1= "<<cero_a<<endl<<"x2= "<<cero_b<<endl;

}

void ejercicio1()
{
    // Codigo

    //srand(1); //semilla
    int a=aleatorio_entre(-100,100);
    //srand(2); //semilla
    int b=aleatorio_entre(-100,100);
    //srand(3); //semilla
    int c=aleatorio_entre(-100,100);

    raices(a,b,c);

}

#define PI 3.14159

double factorial(int a)
{
    double f=1;
    if(a!=0 && a!=1)
       for(int i=1;i<=a;i++)
          f*=i;
    return f;
}

double eAproximacion(){
    double e;
    for(int k=0;k<100;k++){
        e=e+((k+1)/(factorial(k)));
    }
    return e/2;
}

double Stirling(int n){

    return sqrt(2*PI*n)*pow((n/eAproximacion()),n);
}

void ejercicio2()
{
    // Codigo
    cout<<"n! formula de clase | n! aproximacion"<<endl;

    for(int i=10;i<=100;i=i+10){
        cout<<"n= "<<i <<" :    "<<factorial(i)<<"         |         "<<Stirling(i)<<endl;
    }
}

int menu_ventas()
{

    //Leche $1, Queso $2.30, Galletas $1.5, Pan $0.40.
    int opcion;
    cout<<"*********************************"<<endl;
    cout<<".:: VENTAS ::."<<endl;
    cout<<"Elija el producto y la cantidad que desea comprar"<<endl;
    cout<<"1. Leche         $1 "<<endl;
    cout<<"2. Queso         $2.30 "<<endl;
    cout<<"3. Galletas      $1.5 "<<endl;
    cout<<"4. Pan           $0.40"<<endl;
    cout<<"0. Finalizar la compra"<<endl;
    cout<<"*********************************"<<endl;
    cout<<endl;
    cin>>opcion;
    return opcion;
}

double valorCompra(int num_leche,int num_queso,int num_galletas,int num_pan){

    return (num_leche*1)+(num_queso*2.30)+(num_galletas*1.5)+(num_pan*0.40);
}

void ejercicio3()
{
    // Codigo
    int cantidad=0, num_leche=0,num_queso=0,num_galletas=0,num_pan=0;
    string nombre, telefono;
    double compra=0;

    int opcion;
    do{
        opcion=menu_ventas();
        switch(opcion)
        {
            case 1:

                cout<<"Ingrese la cantidad de leche: ";
                cin>>cantidad;
                num_leche=num_leche+cantidad;

            break;
            case 2:

                cout<<"Ingrese la cantidad de queso: ";
                cin>>cantidad;
                num_queso=num_queso+cantidad;
                
            break;
            case 3:
                
                cout<<"Ingrese la cantidad Galletas: ";
                cin>>cantidad;
                num_galletas=num_galletas+cantidad;

            break;
            case 4:

                cout<<"Ingrese la cantidad Pan: ";
                cin>>cantidad;
                num_pan=num_pan+cantidad;

            break;
            case 0:
                cout<<"Datos de facturacion"<<endl;

                cout<<"Ingrese su nombre: ";
                cin>>nombre;

                cout<<"Ingrese su telefono: ";
                cin>>telefono;


                cout<<endl<<"FACTURA"<<endl;

                cout<<"Nombre:      "<<nombre<<"    ";
                cout<<"Telefono:    "<<telefono<<endl;

                compra=valorCompra(num_leche,num_queso,num_galletas,num_pan);

                cout<<"Valor de compra:         "<<compra<<endl;
                cout<<"IVA:                     0.6"<<endl;
                cout<<"Total:                   "<<compra*1.12<<endl;                

            break;
            default: cout<<"No ha seleccionado una opcion correcta"<<endl;
        }
    }
    while(opcion!=0);


}


int main()
{
    int opcion;
    do{
        opcion=menu();
        switch(opcion)
        {
            case 1:
                ejercicio1();
            break;
            case 2:
                ejercicio2();
            break;
            case 3:
                ejercicio3();
            break;
            case 0: cout<<"Fin del programa"<<endl;
            break;
            default: cout<<"No ha seleccionado una opcion correcta"<<endl;
        }
    }
    while(opcion!=0);
    return 0;
}
