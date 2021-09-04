#include <iostream>
#include <stdlib.h> 

using namespace std;

bool isPrime(int num) {
  if(num<4)
    return (num>1);
  else
  {
    if(( num % 2 == 0 )||( num % 3 == 0 ))
      return false;
    else
    {
      int i = 5;
      while(i*i <= num)
      {
        if(( num % i == 0 )||( num % (i+2) == 0 ))
          return false;
        else
          i+=6;
      }
     return true;
    }
  }
}

int aleatorio_entre(int a, int b)
{
    int x=a+rand()%(b+1-a);
    return x;
}
int main(){
    int N;
    cout<<"Ingrese un N para generar numeros primos de forma aleatoria: ";
    cin>>N;
    int i=0,temp=0;
    while(i<N){
        temp=aleatorio_entre(1,1000);
        if(isPrime(temp)){
            cout<<i+1<<" Es un numero primo generado aleatoriamente es: "<<temp<<endl;
            i++;
        }
    }
    return 0;
}

