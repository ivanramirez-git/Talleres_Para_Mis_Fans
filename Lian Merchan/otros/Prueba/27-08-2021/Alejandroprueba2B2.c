#include<stdio.h>
#include <string.h>

void vocales(char cadena[]){

	int  vocal=0;

	for(int i=0; i<strlen(cadena); i++){

		if(cadena[i]=='a'&& i==0)
			vocal++;
		if(cadena[i]=='e'&& i==0)
			vocal++;
		if(cadena[i]=='i'&& i==0)
			vocal++;
		if(cadena[i]=='o'&& i==0)
			vocal++;
		if(cadena[i]=='u'&& i==0)			
			vocal++;

		if(cadena[i]==' '){
			if(cadena[i+1]=='a')
				vocal++;
			if(cadena[i+1]=='e')
				vocal++;
			if(cadena[i+1]=='i')
				vocal++;
			if(cadena[i+1]=='o')
				vocal++;
			if(cadena[i+1]=='u')			
				vocal++;
		}
	}
	printf("Numero de palabras que inician con vocal: %d", vocal);	
}

void palabras(char cadena[], int n){

	int j=0, palabra=1;

	for(int i=0; i<strlen(cadena); i++){
		if(cadena[i]!=' '){
			j++;
		}else{
			if(j>=n){
				palabra++;
			}
			j=0;
		}
	}

	printf("Numero de palabras con al menos %d letras: %d\n", n, palabra);
}

int main(){
	int n;
	char cadena[100];
	printf("Ingrese una frase (Max. 100 caracteres)");

	printf("\n");

	fgets(cadena,100,stdin);

	printf("Ingrese el tamano de la palabra");
	printf("\n");
	
	scanf("%d", &n);

	palabras(cadena,n);
	vocales(cadena);
	printf("\n");
	
}