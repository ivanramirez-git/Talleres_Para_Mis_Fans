#include <iostream>

using namespace std;

int navidad(int n1, int n2)
{
   int aux;
   if (n1==1)
   {
      aux = n2;
   } //Caso Base
   else
   {
      aux=navidad(n1/2, n2*2);  // Caso Recursivo
      if ((n1%2) != 0)
      {
          aux = aux + n2;
      }
   		return aux;
	}
}

int main(){

	cout<<navidad(1,6);
	
	cout<<"Hola mundo";
	return 0;
}