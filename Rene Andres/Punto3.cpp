// Your C++ Program

#include <iostream>
#include <math.h>

#define PI 3.141592

using namespace std;

double factorial(double numero){
    double fact=1;
    if(numero<0) fact =0;
    else if(numero==0) fact=1;
    else{
      for (int i = 1; i <= numero; i++){
         fact = fact*i;
      }
    }
    return fact;
}

double  ramanujan(int N){
    double aproximacion=0;

    for (double n = 0; n < N; n++)
    {
        /* code */
        aproximacion+=(((factorial(2*n))*(factorial(3*n)))/(pow(factorial(n),5)))*(1/(pow(1458,n)))*((15*n)+2);
    }
    return aproximacion;
}

int main(){

    double i=27/(4*PI);
    double aproximacion;
    cout<<"Ingrese en N para la aproximacion: ";
    cin>>aproximacion;
    cout<<"La aproximacion es: "<<ramanujan(aproximacion)<<endl;
    cout<<"La calculadora es: "<<i;

    //cout << "Hello World!";
    return 0;
}
