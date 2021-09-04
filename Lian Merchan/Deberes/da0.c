#include <stdio.h>
#include <stdbool.h>

#define LONG_VECTOR 10

//Complete su código
void imprimirValores(double *valores,int n){
    for(int i=0; i<n; i++){
        printf("[%f] ", valores[i]);
    }
}

void ingresarValores(double *valores, int n){
    for(int i=0; i<n; i++){
        printf("Valor[%d]: ", i);
        scanf("%le", &valores[i]);
    }
}

char validar(int n){
    
    return 's';
}

void senoTaylorVector(double *valores,double *seno,int n,int terminos){
    
}

int main(){
    int  n, terminos;
    double seno[LONG_VECTOR], valores[LONG_VECTOR];
    printf("Ingrese la dimension: ");
    scanf("%d", &n);
    if(validar(n)=='n'){
        printf("Error: Numero no valido!\n");
        return -1;
    }
    printf("Ingreso de valores: \n");
    ingresarValores(valores, n);
    printf("Ingreso el numero de terminos: \n");
    scanf("%d", &terminos);
    printf("\nVector ingresado: \n");
    imprimirValores(valores, n);
    printf("\nVector seno Taylor: \n");
    senoTaylorVector(valores, seno, n, terminos);
    imprimirValores(seno, n);
    printf("\n");
    return 0;
}



//Complete su código