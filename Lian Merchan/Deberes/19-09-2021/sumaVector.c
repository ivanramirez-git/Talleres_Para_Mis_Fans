//COMPLETAR CODIGO
#include <stdio.h>

void leer(int *);
void sumar(int *,int *,int *);
void imprimir(int *);

int main(){
    int A[5],B[5],C[5],i;
    printf("Ingrese datos del primer vector\n");
    leer(A);
    printf("Ingrese datos del segundo vector\n");
    leer(B);
    sumar(A,B,C);
    printf("Resultado:\n");
    imprimir(C);
    return 0;
}
void leer(int *pdato){
    //COMPLETAR CODIGO
    int i;
    for ( i = 0; i < 5; ++i)
    {
        /* code */
        printf("[%d]:",i);
        scanf("%d",&*pdato);
        *pdato++;
    }
    //COMPLETAR CODIGO    
}

void sumar(int *A,int *B,int *C){
    int i;
    for ( i = 0; i < 5; ++i)
    {
        /* code */
        *C=*A+*B;
        *A++;
        *B++;
        *C++;
    }
}

void imprimir(int *pdato){
    //COMPLETAR CODIGO

    int i,*j;
    for ( i = 0; i < 5; ++i)
    {
        
        printf("[%d]:%d\n",i,*pdato);
        *pdato++;        
    }

    //COMPLETAR CODIGO  
}
//COMPLETAR CODIGO