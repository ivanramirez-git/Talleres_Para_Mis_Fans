#include "stdio.h"

#define MAXIMO 5

int maximoComunDivisor(int a, int b) {
    int resto;
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int esPrimo(int numero) {
    int i;
    for (i = 2; i < numero; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(){
	
	int vector[MAXIMO];
	
	int nDatos;
	int i;
	
	nDatos=-1;
	
	while (nDatos<0 || nDatos>MAXIMO){
		printf("Ingrese el numero de datos: ");
		scanf("%d", &nDatos);
		if(nDatos<0 || nDatos>MAXIMO) printf("\nERROR: Debe ingresar un numero entre 1 y %d. \n", MAXIMO);
	}	

	printf("\n Usted ha ingresado %d que es menor o igual a %d", nDatos, MAXIMO);
	
	
	printf("\n Ingreso de datos");
	for (i=0;i<nDatos;i++){
		printf("\n Ingrese el dato %d: ",i+1);
        scanf("%d", &vector[i]);
	}

    // Ingrese el dividendo
    int dividendo;
    printf("\n Ingrese un numero: ");
    scanf("%d", &dividendo);

    // Los numeros que son divisores del dividendo
    int divisores[MAXIMO];
    int nDivisores = 0;
    printf("\n Los numeros los divisores son: ");
    for (i = 0; i < nDatos; i++) {
        if (vector[i] % dividendo == 0) {
            divisores[nDivisores] = vector[i];
            nDivisores++;
            printf("%d ", vector[i]);
        }
    }

    // Numeros primos en el vector[MAXIMO]
    int primos[MAXIMO];
    int nPrimos = 0;
    printf("\n Los numeros primos en el vector son: ");
    for (i = 0; i < nDatos; i++) {
        if (esPrimo(vector[i])) {
            primos[nPrimos] = vector[i];
            nPrimos++;
            printf("%d ", vector[i]);
        }
    }

    return 0;
}