#include <stdlib.h>
#include <stdio.h>


int main(){
    int matriz[8][8] = {0};

    char cadena[100];
    int a, b;
    int suma = 0;
    
    printf("Ingrese una cadena de la forma \"a+b\" donde a y b son numeros: ");
    fgets(cadena, 100, stdin);

    while(sscanf(cadena, "%d+%d", &a, &b) != 2){
        printf("Error, ingrese una cadena de la forma \"a+b\" donde a y b son numeros: ");
        fgets(cadena, 100, stdin);
    }

    suma = a + b;

    printf("La suma de los numeros ingresados es: %d\n", suma);
    
    return 0;
}