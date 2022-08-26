#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define LONG_VECTOR 10

//Complete su código
void imprimirValores(double *valores,int n){
    for(int i=0; i<n; i++){
        printf("[%.2f] ", valores[i]);
    }
}

void ingresarValores(double *valores, int n){
    for(int i=0; i<n; i++){
        printf("Valor[%d]: ", i);
        scanf("%le", &valores[i]);
    }
}

char validar(int n){
    if(n>10)
        return 'n';
    if(n<0)
        return 'n';
    return 's';
}

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
double potencia(double base, double power){
    double resultado=1;
    for(int i=0; i<power; i++){
        resultado=resultado*(base);
    }
    return resultado;
}

void senoTaylorVector(double *valores,double *seno,int n,int terminos){
    for(int i = 0; i < n; i++){
        seno[i]=0.00;
        for(double j=0; j<terminos; j++){
           seno[i]=seno[i]+(potencia((-1),j)/factorial((2*j)+1))*(potencia(valores[i],((2*j)+1)));
        }
    }
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