// Your C++ Program

#include <iostream>
#include <math.h>

#define PI 3.141592

using namespace std;

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

double  ramanujan(int N){
    double aproximacion=0.0;

    for (double n = 0.0; n < N; n++)
    {
        aproximacion+=(((factorial(2.0*n))*(factorial(3.0*n)))/(pow(factorial(n),5.0)))*(1.0/(pow(1458.00,n)))*((15.0*n)+2.0);
    }
    return aproximacion;
}

int main(){

    double aproximacion;
    /*
    cout<<"Ingrese en N para la aproximacion: ";
    cin>>aproximacion;
    cout<<"La aproximacion es: "<<27/(4*ramanujan(aproximacion))<endl;
    */
    for (double i = 1; i <= 15; ++i)
    {
        /* code */
        cout<<"La aproximacion cuando N es "<<i<<" es "<< 27.0/(ramanujan(i)*4.0)<<endl;
    }

    cout<<"Con la calculadora es: "<<PI<<endl;
    //cout << "Hello World!";
    return 0;
}
