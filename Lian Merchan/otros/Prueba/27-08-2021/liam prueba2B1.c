#include<stdio.h>
#define LONG_VECTOR 10
#define LONG_CADENA 100

char validar(int n){
    if(n>LONG_VECTOR)
        return 'n';
    if(n<0)
        return 'n';
    return 's';
}

void ingresarValores(int valores[], int n){
    for(int i=0; i<n; i++){
        printf("[%d] = ", i);
        scanf("%d", &valores[i]);
    }
}

void MaximoCD(int num1, int num2){
	printf("El MCD de %d y %d",num1, num2);
	int temporal;
    while (num2 != 0) {
        temporal = num2;
        num2 = num1 % num2;
        num1 = temporal;
    }
    printf(" es: %d", num1);
}

void generarPares(int vector[], int n){
	int num1, num2, i, j;

	for(i=0;i<n/2;i++){
			num1=vector[i];
			num2=vector[n-i-1];
			MaximoCD(num1, num2);
			printf("\n");
	}
}
int main(){
	int n, opcion, vector[LONG_VECTOR];
	do{
		printf("Cuantos datos desea guardar?: ");
	    scanf("%d", &n);
	    
	}while(validar(n)=='n' || (n%2!= 0));
	printf("Ingrese datos: \n");
	ingresarValores(vector,n);
	generarPares(vector,n);
}