#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
//Completar Codigo

void primeraLetra(char frase[]){
	int i=0;
    while (frase[i] != '\0'){
    	
    	char letraActual = tolower(frase[i]);
    	
    	if(i!=0 && frase[i-1]==' '){
    		frase[i]= toupper(letraActual);
		}else if(i==0){
    		frase[i]= toupper(letraActual);
		}else{
			frase[i]=tolower(letraActual);
		}
    	
		i=i+1;  	
    }
}

int main(){
    //Completar Codigo
    char frase[50];
    
    
    printf("Conversion de primera letra: ");
    gets(frase);
    printf("\nFrase original: %s",frase);
    //Completar Codigo
    primeraLetra(frase);//fraseOriginal tiene la frase inicial, y luego los caracteres convertidos se almacenan en el mismo vector
    printf("\nFrase convertida: %s",frase);
    return 0;
}

//Completar Codigo
