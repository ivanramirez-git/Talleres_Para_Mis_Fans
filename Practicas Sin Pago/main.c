#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

// Funcion que genera un numero aleatorio entre 1 y 99 con semilla aleatoria


int main(){

    srand(time(NULL));

    int n;
    char opcion='a';

    // Se pide el numero de intentos
    printf("cuantos numeros aleatorios genero: ");
    scanf("%d", &n);

    //Vector de enteros para almacenar numeros aleatorios
    int *vector = (int*)malloc(n * sizeof(int));

    //Generar numeros aleatorios
    for (int i = 0; i < n; i++) {
        vector[i] = (rand() % 99) + 1;
    }
        
    // Menu que se repite switch case
    while(opcion != 'f'){
        // Imprimir menu
        printf("(a) mostrar los datos generados\n(b) numero mayor\n(c) numero menor\n(d) media aritmetica\n(e) cantidad de 1,2...10 y sus porcentajes\n(f) salir\n");
        // escanear opcion
        scanf(" %c", &opcion);
        
        switch(opcion){
            case 'a':
                printf("Los datos generados son:\n");
                //Imprimir numeros aleatorios
                for (int i = 0; i < n; i++) {
                    printf("%d\n", vector[i]);
                }   
                break;
            case 'b':
                printf("El numero mayor es:");
                //Imprimir numero mayor
                int mayor=0;
                for(int i = 0; i < n; i++){
                    if(mayor < vector[i]){
                        mayor = vector[i];
                    }
                }
                printf("%d\n", mayor);
                break;
            case 'c':
                printf("El numero menor es:");
                //Imprimir numero menor
                int menor=100;
                for(int i = 0; i < n; i++){
                    if(menor > vector[i]){
                        menor = vector[i];
                    }
                }
                printf("%d\n", menor);

                break;
            case 'd':
                printf("La media aritmetica es: ");
                //Imprimir media aritmetica
                float media = 0;
                for(int i = 0; i < n; i++){
                    media += vector[i];
                }
                media = media / n;
                printf("%f\n", media);

                break;
            case 'e':
                printf("La cantidad de 1,2...10 es: ");
                //Imprimir cantidad de 1,2...10
                int cantidad[10] = {0};
                //La cantidad de 1,2...10 es la cantidad de veces que aparece el numero en el vector
                for(int i = 0; i < n; i++){
                    if(vector[i] == 1){
                        cantidad[0]++;
                    }
                    if(vector[i] == 2){
                        cantidad[1]++;
                    }
                    if(vector[i] == 3){
                        cantidad[2]++;
                    }
                    if(vector[i] == 4){
                        cantidad[3]++;
                    }
                    if(vector[i] == 5){
                        cantidad[4]++;
                    }
                    if(vector[i] == 6){
                        cantidad[5]++;
                    }
                    if(vector[i] == 7){
                        cantidad[6]++;
                    }
                    if(vector[i] == 8){
                        cantidad[7]++;
                    }
                    if(vector[i] == 9){
                        cantidad[8]++;
                    }
                    if(vector[i] == 10){
                        cantidad[9]++;
                    }
                }
                //Imprimir cantidad de 1,2...10 con porcentaje
                printf("\n");
                for(int i = 0; i < 10; i++){
                    printf("%d: Cantidad: %d, Porcentaje: %.2f%%\n", i+1, cantidad[i], (float)cantidad[i]/n*100);
                }
                break;
            case 'f':
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    }    
    return 0;
}