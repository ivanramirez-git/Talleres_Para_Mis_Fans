#include <stdio.h>
#include <stdlib.h>

int * sumaBinaria(int a[], int b[], int a_tamanio, int b_tamanio);

// Programa principal
int main(){
    // ingrese su primer binario
    int primerBinarioEntero;
    printf("Ingrese su primer binario: ");
    scanf("%d", &primerBinarioEntero);
    // ingrese su segundo binario
    int segundoBinarioEntero;
    printf("Ingrese su segundo binario: ");
    scanf("%d", &segundoBinarioEntero);
    // convertir los enteros a arreglos
    int primerBinario[32];
    int segundoBinario[32];
    int i=0, j=0;
    while(primerBinarioEntero > 0){
        primerBinario[i] = primerBinarioEntero % 2;
        primerBinarioEntero = primerBinarioEntero / 10;
        i++;
    }

    while(segundoBinarioEntero > 0){
        segundoBinario[j] = segundoBinarioEntero % 2;
        segundoBinarioEntero = segundoBinarioEntero / 10;
        j++;
    }

    // sumar los arreglos
    int * suma = sumaBinaria(primerBinario, segundoBinario, i, j);

    // imprimir el resultado
    printf("El resultado es: ");
    for(int k=0; k<i+j; k++){
        printf("%d", suma[k]);
    }
