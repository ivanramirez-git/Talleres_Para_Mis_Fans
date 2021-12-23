
// Language: c
// Path: Jocelyn Nery/3punto.c

#include <stdio.h>

// funcion que captura un mensaje de hasta 130 caracteres
char* capturarMensaje(char* mensaje){
    printf("Ingrese el mensaje: ");
    scanf("%s", mensaje);
    return mensaje;
}

// a) Que porcentaje utiliza consonantes
void porcentajeConsonantes(char* mensaje){
    int cantidadConsonantes = 0;
    int cantidadLetras = 0;
    for(int i = 0; i < strlen(mensaje); i++){
        if(mensaje[i] == 'a' || mensaje[i] == 'e' || mensaje[i] == 'i' || mensaje[i] == 'o' || mensaje[i] == 'u'){
            cantidadConsonantes++;
        }
        cantidadLetras++;
    }
    printf("El porcentaje de consonantes es: %.2f%%\n", (cantidadConsonantes * 100) / cantidadLetras);
}

// b) Ordenar los caracteres de mayor a menor alfabeticamente en una cadena auxiliar
void ordenarCaracteres(char* mensaje){
    char aux[130];
    for(int i = 0; i < strlen(mensaje); i++){
        aux[i] = mensaje[i];
    }
    for(int i = 0; i < strlen(mensaje); i++){
        for(int j = 0; j < strlen(mensaje); j++){
            if(aux[i] < aux[j]){
                char aux2 = aux[i];
                aux[i] = aux[j];
                aux[j] = aux2;
            }
        }
    }
    for(int i = 0; i < strlen(mensaje); i++){
        mensaje[i] = aux[i];
    }
    printf("El mensaje ordenado es: %s\n", mensaje);
}

// c) Cuantas palabras del mensaje inician y terminan con consonante
void cuantasPalabras(char* mensaje){
    int cantidadPalabras = 0;
    int contador;
    char consonantes[21];
    consonantes[0] = 'b';
    consonantes[1] = 'c';
    consonantes[2] = 'd';
    consonantes[3] = 'f';
    consonantes[4] = 'g';
    consonantes[5] = 'h';
    consonantes[6] = 'j';
    consonantes[7] = 'k';
    consonantes[8] = 'l';
    consonantes[9] = 'm';
    consonantes[10] = 'n';
    consonantes[11] = 'p';
    consonantes[12] = 'q';
    consonantes[13] = 'r';
    consonantes[14] = 's';
    consonantes[15] = 't';
    consonantes[16] = 'v';
    consonantes[17] = 'w';
    consonantes[18] = 'x';
    consonantes[19] = 'y';
    consonantes[20] = 'z';
    // Separar las palabras del mensaje
    char* palabras = strtok(mensaje, " ");
    while(palabras != NULL){
        contador = 0;
        for(int i = 0; i < strlen(palabras); i++){
            for(int j = 0; j < 21; j++){
                if(palabras[i] == consonantes[j]){
                    if(i == 0 || i == strlen(palabras) - 1){
                        contador++;
                    }
                }
            }
        }
        if(contador == 2){
            cantidadPalabras++;
        }
        palabras = strtok(NULL, " ");
    }
    printf("La cantidad de palabras que inician y terminan con consonante es: %d\n", cantidadPalabras);
}

int main(){
    char mensaje[130];
    capturarMensaje(mensaje);
    porcentajeConsonantes(mensaje);
    ordenarCaracteres(mensaje);
    cuantasPalabras(mensaje);
    return 0;
}