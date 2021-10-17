#include<stdio.h>
#include <string.h>

#define MAX_COLUMNAS 100

void descrifrarPalabra(char *palabra, char *palabraDescifrada){
    int contador=0,i,letras=0;
    while(palabra[contador]!='\0'){
        contador++;
    }
    for(i=0;i<contador;i++){
        if(palabra[i] >= '0' && palabra[i] <= '5'){
            strcpy(&palabraDescifrada[letras],&palabra[i-1]);
            letras++;
        }
    }
    strcpy(&palabraDescifrada[letras],"\0");
}

int main(){
    char palabra[MAX_COLUMNAS], palabraDescrifrada[MAX_COLUMNAS];
    printf("Descifrar palabra\n");
    printf("Ingrese la palabra cifrada: ");
    scanf("%s", palabra);
    descrifrarPalabra(palabra, palabraDescrifrada);
    printf("Palabra descifrada: %s\n", palabraDescrifrada);
    return 0;
}
//Inserte aquí su código