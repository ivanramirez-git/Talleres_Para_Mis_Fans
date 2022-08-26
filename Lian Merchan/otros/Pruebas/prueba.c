#include<stdio.h>
#include <string.h>

#define LONG_VECTOR 10
#define LONG_CADENA 50

void menu(){
	printf("1. Suma de vectores\n");
	printf("2. Longitud de clave\n");
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

void ingresarValores(int valores[], int n, char texto[]){
    for(int i=0; i<n; i++){
        printf("%s[%d] = ", texto,i);
        scanf("%d", &valores[i]);
    }
}

void sumaDeVectores(int vector1[], int vector2[], int n){
	int i, resultado[LONG_VECTOR];
	for(i=0;i<n;i++){
		if(vector1[i]%2!=0 && vector2[i]%2!=0){
			resultado[i]=vector1[i]+vector2[i];
		}else{
			resultado[i]=0;
		}
	}
	imprimirValores(resultado,n);
}

int main(){
	int n, opcion, vector1[LONG_VECTOR], vector2[LONG_VECTOR];
	char texto[LONG_CADENA];

	menu();
	scanf("%d", &opcion);
	switch(opcion){
		case 1:
			printf("Ingrese longitud de vectores: ");
		    scanf("%d", &n);
		    if(validar(n)=='n'){
		        printf("longitud invalida\n");
		        return -1;
		    }
		    ingresarValores(vector1,n,"vector1");
		    ingresarValores(vector2,n,"vector2");
			sumaDeVectores(vector1,vector2,n);
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