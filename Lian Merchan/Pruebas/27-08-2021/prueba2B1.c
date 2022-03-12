#include<stdio.h>
#include <string.h>

#define LONG_VECTOR 10
#define LONG_CADENA 100

void menu(){
	printf("1. Minimo Comun Divisor\n");
	printf("2. Palabras\n");
	printf("Ingrese opcion: ");
}

char validar(int n){
    if(n>LONG_VECTOR)
        return 'n';
    if(n<0)
        return 'n';
    return 's';
}

void imprimirValores(int valores[],int n){
    for(int i=0; i<n; i++){
        printf("%d\n", valores[i]);
    }
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
	char texto[LONG_CADENA];

	menu();
	scanf("%d", &opcion);
	switch(opcion){
		case 1:
			do{
				printf("Cuantos datos desea ingresar?: ");
			    scanf("%d", &n);
			    
			}while(validar(n)=='n' || (n%2!= 0));

		    ingresarValores(vector,n);
		    generarPares(vector,n);

		break;
		case 2:
			printf("Ingrese clave: ");
			scanf("%s", texto);

			if(strlen(texto)>7){
				printf("clave valida de longitud %ld\n", strlen(texto));
			}else{
				printf("clave muy corta de longitud %ld\n", strlen(texto));
			}

		break;
		default:
		printf("Opcion no valida.");
		break;
	}

}