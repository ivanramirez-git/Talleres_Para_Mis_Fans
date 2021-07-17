#include <iostream>
#include <math.h>

using namespace std;

float V0;
float theta;
float g=9.8;


void ingresarDatos(){
   string texto;
   cout<<"Por favor ingrese la velocidad inicial: ";
   cin>>texto;

   V0=stof(&texto[0]);

   cout<<"Por favor ingrese el angulo de disparo: ";
   cin>>texto;
   theta=stof(&texto[0]);
}

float Form_esp(char opcion){

   switch(opcion){
         case 1:
            return (2*V0*sin(theta))/g;
         break;
         case 2:
            return (V0*V0*sin(theta)*sin(theta))/(2*g);
         break;
         case 3:
            return (V0*V0*sin(2*theta))/g;
         break;
      }
      return 0;
}

int main(){
   ingresarDatos();
   cout<<"Tv: "<<Form_esp(1)<<endl;
   cout<<"Hm: "<<Form_esp(2)<<endl;
   cout<<"Dm: "<<Form_esp(3)<<endl;

	return 0;
}