#include <stdio.h>

int main(){
    // Imprimir un menu con dos opciones
    // 1. Solicitar un numero y generar su tabla de multiplicar
    // 2. Leer un numero de dos digitos y sumar sus DIGITOS
    int opcion;
    printf("1. Tabla de multiplicar\n");
    printf("2. Suma de digitos\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    // Repetir hasta que sea 1 o 2
    while(opcion != 1 && opcion != 2){
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
    }
    switch(opcion){
        case 1:
            printf("\nTabla de multiplicar\n");
            int numero;
            printf("Ingrese un numero: ");
            scanf("%d", &numero);
            int i;
            for(i = 1; i <= 10; i++){
                printf("%d x %d = %d\n", numero, i, numero * i);
            }
            break;
        case 2:
            printf("\nSuma de digitos\n");
            int numero2;
            printf("Ingrese un numero de dos digitos: ");
            scanf("%d", &numero2);
            int suma = 0;
            while(numero2 > 0){
                suma += numero2 % 10;
                numero2 /= 10;
            }
            printf("La suma de los digitos es: %d\n", suma);
            break;
        default:
            printf("Opcion invalida\n");
            break;
    }
}