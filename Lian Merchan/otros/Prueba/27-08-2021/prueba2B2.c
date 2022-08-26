#include<stdio.h>
#include <string.h>
#define LONG_CADENA 100

void contarPalabras(char frase[], int tamano){
	char palabra[LONG_CADENA];
	int contador=0, contadorPalabras=0, contadorVocales=0;
	int i=0;

	
	if(frase[0]=='a'||frase[0]=='e'||frase[0]=='i'||frase[0]=='o'||frase[0]=='u')
		contadorVocales=contadorVocales+1;

	contador=0;

	for(i=0; i<strlen(frase); i++){
		if(i==0)
			contadorPalabras=contadorPalabras+1;

		if(frase[i]==' '){
			if(contador>=tamano)
				contadorPalabras=contadorPalabras+1;
			if(frase[i+1]=='a'||frase[i+1]=='e'||frase[i+1]=='i'||frase[i+1]=='o'||frase[i+1]=='u')
				contadorVocales=contadorVocales+1;
			contador=0;
		}else{
			contador=contador+1;
		}
	}
	printf("Numero de palabras con al menos %d letras: %d\n", tamano, contadorPalabras);
	printf("Numero de palabras que inician con vocal: %d\n", contadorVocales);
	
}

void contarVocales(){

}

int main(){
	char cadenaOriginal[100];
	int tamano;
	printf("Ingrese una frase (Max. 100 caracteres)\n");
	fgets(cadenaOriginal,101,stdin);

	printf("Ingrse el tamano de la palabra\n");
	scanf("%d", &tamano);
	contarPalabras(cadenaOriginal,tamano);

}