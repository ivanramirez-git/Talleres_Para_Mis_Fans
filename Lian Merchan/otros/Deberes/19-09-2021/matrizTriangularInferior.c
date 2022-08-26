#include <stdio.h>
//#include <stdlib.h>
#define LMAX 50 

//Funciones que debe implementar

char validar(int f, int c);
void ingresar(int df,int dc,int [df][dc]);
void verificar(int f,int c,int [f][c]);

int main()
{
   int df, dc;
   int m[LMAX][LMAX];

   //Complete el codigo de acuerdo a lo solicitado
   printf("VERIFICAR MATRIZ TRIANGULAR INFERIOR");
   printf("\nIngrese la dimension de filas y columnas: ");
   scanf("%d %d",&df,&dc);
   //Complete el codigo de acuerdo a lo solicitado
   

   if(validar(df,dc)=='s'){
      ingresar(df,dc,m);
      verificar(df,dc,m);

   }else{
      printf("Dimensiones incorrectas!!!\n");
      return 0;
   }


}

//Implemente las funciones solicitadas

char validar(int f, int c){
   if(f==c && f<50 && c<50)
      return 's';
   else
      return 'n';
}

void ingresar(int df,int dc,int m[df][dc]){
   int i, j;
   for(i = 0; i < df; i++){
      for (j = 0; j < dc; j++)
      {
         /* code */
         printf("m[%d][%d]= ",i,j);
         scanf("%d",&m[i][j]);
      }
   }
}

void verificar(int f,int c,int m[f][c]){
   int ceros[c];
   int i, j;

   for(i = 0; i < f; i++){
      for (j = 0; j < c; j++)
      {
         /* code */
         if(m[i][j]==0)
            ceros[j]++;
      //   printf("%d ",m[i][j]);
      }
      //printf("\n");
   }

   for ( j = 0; j < c; j++)
      for(i=0;i<f;i++){
      {
         if(m[i][j]==0)
            ceros[j]++;

      //   printf("%d ",m[i][j]);
      }
      //printf("\n");
   }  

   for(i=0;i<c;i++){

      //   printf("%d ",ceros[i]);
      if(ceros[i]<i){

            printf("NO es MATRIZ TRIANGULAR INFERIOR\n");
            return NULL;
      }
   }
   printf("La matriz ingresada es MATRIZ TRIANGULAR\n");
}
