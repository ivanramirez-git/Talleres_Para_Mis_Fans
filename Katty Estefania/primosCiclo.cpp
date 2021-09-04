#include <iostream>

int isPrime(int num) {
  if(num<4)
    return num-1;
  else
  {
    if(( num % 2 == 0 )||( num % 3 == 0 ))
      return 0;
    else
    {
      int i = 5;
      while(i*i <= num)
      {
        if(( num % i == 0 )||( num % (i+2) == 0 ))
          return 0;
        else
          i+=6;
      }
     return num;
    }
  }
}

int main(){

  for(int i=2;i<=1000;i++)
    if(isPrime(i)>0)
      std::cout<<i<<" es un numero primo."<<std::endl;

  return 0;
}