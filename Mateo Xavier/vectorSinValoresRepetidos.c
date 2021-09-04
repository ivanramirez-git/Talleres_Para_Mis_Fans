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

void ingresarValores(int valores[], int n){
    int i,j, entrada;
    for(i=0; i<n; i++){

        printf("Valor[%d]: ", i);
        scanf("%d", &valores[i]);
        for(j=0;j<i;j++){
            //printf("i %d. j %d.",i,j);
            if(valores[j]==valores[i])
                i--;
        }
    }
}

void imprimirValores(int valores[],int n){
    int i;
    for( i=0; i<n; i++){
        printf("[%d] ", valores[i]);
    }
}

int main(){
    int valores[LONG_VECTOR];
    int n, contador;
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
    printf("\n");
    
}