#include<stdio.h>
#include <stdbool.h>

void ordenarNombres(char primer[],char segundo[]){
	
	int i=0;
	bool salir=true;
	
	while (primer[i] != '\0' || segundo[i] != '\0' && salir){
	
		if(primer[i]<segundo[i]){			
			salir=false;
		}else if(primer[i]>segundo[i]){
			char *texto=primer;
			primer=segundo;
			segundo=texto;
			salir=false;
		}
			i=i+1;
	}
	
	printf("%s\n", primer);
	printf("%s\n", segundo);
}

int main(){
    //COMPLETE SU CODIGO
    printf("Ordenamiento de 2 cadenas");
    printf("\nIngrese primer nombre: ");
    char primer[30], segundo[30];
    scanf("%s",primer);
    //COMPLETE SU CODIGO
    printf("Ingrese segundo nombre: ");
    scanf("%s",segundo);
    
    //COMPLETE SU CODIGO    
    ordenarNombres(primer,segundo);//La funcion garantiza que luego de su uso, se tendra primer y segundo ordenados.
    /*
	printf("Primer: %s\n", primer);
    printf("Segundo: %s", segundo);
	*/
    
    
    return 0;
}
