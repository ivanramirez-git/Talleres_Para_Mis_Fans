#include <stdio.h>
#define MAX 100
#define NUM 10

void lecturadatos(int v[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("[%d]: ",i);
        scanf("%d",&v[i]);
        // entre 0 y MAX
        if(v[i]<0 || v[i]>MAX){
            i--;
        }
    }
}

int validanumero(int n){
    // entre 0 y NUM
    if(n<0 || n>NUM){
        // si es valido retorna n
        return -1;
    } else {
        return n;
    }
}

int fibonacci(int n){
    // Si un numero esta en la serie de fibonacci retorna n
    int a=0, b=1, c=0;
    int i;
    for(i=0;i<n;i++){
        c=a+b;
        a=b;
        b=c;
        if(c==n){
            return n;
        }
    }
    return -1;
}

void ordenarvector(int v[],int n){
    int v_aux[n],i,j,k;
    // si es fibo copiar inversamente si no es fibo copiar normalmente
    for(i=0,j=n-1,k=0;i<n;i++)
    {
        if(fibonacci(v[i])!=-1){
            v_aux[j]=v[i];
            j--;
        } else {
            v_aux[k]=v[i];
            k++;
        }
    }

    // copiar en v
    for(i=0;i<n;i++){
        v[i]=v_aux[i];
    }
}

void imprimirvector(int v[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("[%d]: %d\n",i,v[i]);
    }
}

int main(){
    int v[MAX];
    int n;
    printf("Prueba 4: Nombre [num unico]\n");
    printf("Vector Fibonacci ordenado\n");
    printf("Cantidad de numero a ingresar: ");
    scanf("%d",&n);
    while(validanumero(n)==-1){
        printf("Cantidad de numero a ingresar: ");
        scanf("%d",&n);
    }
    lecturadatos(v,n);
    ordenarvector(v,n);
    printf("Vector ordenado:\n");
    imprimirvector(v,n);
    return 0;
}