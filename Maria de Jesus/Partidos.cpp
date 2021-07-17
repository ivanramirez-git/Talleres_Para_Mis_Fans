#include <iostream>

#include <stdio.h>
#include <stdlib.h>


using namespace std;

struct partido
{
   char local[20];
   int gloc;
   char visit[20];
   int gvis;
};

int proceso(partido P[100], int np, char E[20])
{

   int contador=0;
   for(int i=0; i<np; i++)
   {
      if(P[i].local[0] == E[0])
      {
         if(P[i].gloc<P[i].gvis)
         {
            contador++;
         }
      }else if(P[i].visit[0] == E[0])
      {
         if(P[i].gvis<P[i].gloc)
         {
            contador++;
         }
      }
   }
   return contador;
}
/*
int proceso(partido P[100], int np, char E[20]){

   int contador=0;
   for(int i=0; i<np; i++){
      if(P[i].local == E){
         if(P[i].gloc<P[i].gvis){
            contador++;
         }
      }else if(P[i].visit == E){
         if(P[i].gvis<P[i].gloc){
            contador++;
         }
      }
   }
   return contador;
}
*/

int main()
{
   partido P[6];
   char E[20];

   //Equipo A vs B


   E[0]='A';
   P[0].local[0] = *E;
   P[0].gloc  = 2;

   E[0]='B';
   P[0].visit[0] = *E;
   P[0].gvis  = 1;


   //Equipo A vs C
   E[0]='A';
   P[1].local[0] = *E;
   P[1].gloc  = 3;

   E[0]='C';
   P[1].visit[0] = *E;
   P[1].gvis  = 3;

   //Equipo A vs D
   E[0]='A';
   P[2].local[0] = *E;
   P[2].gloc  = 2;

   E[0]='D';
   P[2].visit[0] = *E;
   P[2].gvis  = 4;

   //Equipo B vs C
   E[0]='B';
   P[3].local[0] = *E;
   P[3].gloc  = 0;

   E[0]='C';
   P[3].visit[0] = *E;
   P[3].gvis  = 3;

   //Equipo B vs D
   E[0]='B';
   P[4].local[0] = *E;
   P[4].gloc  = 2;

   E[0]='D';
   P[4].visit[0] = *E;
   P[4].gvis  = 5;

   //Equipo C vs D
   E[0]='C';
   P[5].local[0] = *E;
   P[5].gloc  = 6;
   
   E[0]='D';
   P[5].visit[0] = *E;
   P[5].gvis  = 3;

   E[0]='D';
   cout<<"Los partidos perdidos por el Team "<< E[0] <<" son: "<<proceso(P,6,E)<<" partidos."<<endl;

	cout<<"Hola mundo";
	return 0;
}