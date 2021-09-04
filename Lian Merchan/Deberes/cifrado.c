#include<stdio.h>
#include <ctype.h>

#define TAMANO 30
//Complete su codigo

int main(){
	
	char cadenaOriginal[TAMANO];
	int clave;
	
	printf("Cifrado de Cesar");
	printf("\nCadena original: ");
	fgets(cadenaOriginal,51,stdin);
	printf("clave: ");
	scanf("%d",&clave);
	
	int i = 0;
	char suma;
    while(cadenaOriginal[i])
    {   	
    	
    	if(cadenaOriginal[i]==' '){
			tolower(cadenaOriginal[i]);		
		}else if((toupper(cadenaOriginal[i])+clave)>'Z'){
    		cadenaOriginal[i]=toupper(cadenaOriginal[i])+clave-26;
    		
		}else{
			cadenaOriginal[i]=toupper(cadenaOriginal[i])+clave;
			
		}
		if(cadenaOriginal[i+1]!='\0'){
			putchar(cadenaOriginal[i]);
		}
        i++;
    }
    printf("\n");
    //printf("%s",cadenaOriginal);
	
    return 0;    
}

//Complete su codigo
