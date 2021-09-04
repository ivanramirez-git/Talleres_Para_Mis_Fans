//Complete su código
#include <stdio.h>
#define LONG_VECTOR 10

char validar(int n){
    if(n>LONG_VECTOR)
        return 'n';
    if(n<0)
        return 'n';
    return 's';
}

void ingresarValores(float *valores, int n){
    for(int i=0; i<n; i++){
        printf("Valor[%d]: ", i);
        scanf("%f", &valores[i]);
    }
}

void imprimirValores(float *valores,int n){
    for(int i=0; i<n; i++){
        printf("[%.2f] ", valores[i]);
    }
}

void ordenarValores(float *valores, int n){
	
	int i,j;
	float temp=0;
	for (i=1;i<n;i++)
	{
       for (j=0; j <n-i ;j++) // for(j=0; j < Nelementos-i; j++) es menor y no menor igual
       {
          if (valores[j] > valores[j+1])//Condicion mayor-menor
          {
            temp=valores[j];
            valores[j]=valores[j+1];
            valores[j+1]=temp;
          }
       }
	}
}

int main(){
    float valores[LONG_VECTOR];
    int n;
    printf("Ingrese la dimension: ");
    scanf("%d", &n);
    if(validar(n)=='n'){
        printf("Error: Numero no valido!");
        return -1;
    }
    
    printf("Ingreso de valores: \n");
    ingresarValores(valores, n);
    
    printf("\nVector ingresado: \n");
    imprimirValores(valores, n);
    
    printf("\nVector ordenado: \n");
    ordenarValores(valores, n);
    imprimirValores(valores, n);

}

//Complete su código
