#include<stdio.h>

char validarClave(char *clave){
	
	int contador=0;
	
	while(clave[contador]!='\0'){
		contador++;
		//printf("%c . ",clave[contador]);
	}
	
	if(contador<8){
		printf("La clave debe tener al menos 8 caracteres\n");
		return 'n';
	}
	
	int i, mayuscula=0, minuscula=0, numero=0, simbolo=0, espacio=0;
	char letra;
	
	for(i=0;i<contador;i++){
		letra = clave[i];
		if(letra >= 'a' && letra <= 'z')
        	minuscula++;
    	else if(letra >= 'A' && letra <= 'Z')
        	mayuscula++;
        else if(letra >= '0' && letra <= '9')
        	numero++;
    	else if(letra == ' ')
    		espacio++;
    	else{
    		if(letra!='\n')
    			simbolo++;
    	}
	}

	letra = 's';
	if(mayuscula<1){
		printf("La clave debe tener al menos una mayuscula\n");
		letra = 'n';
	}
	if(minuscula<1){
		printf("La clave debe tener al menos una minuscula\n");
		letra = 'n';
	}
	if(numero<1){
		printf("La clave debe tener al menos un numero\n");
		letra = 'n';
	}
	if(simbolo<1){
		printf("La clave debe tener al menos un simbolo\n");
		letra = 'n';
	}
	if(espacio>0){
		printf("La clave no debe tener espacios\n");
		letra = 'n';
	}
	if(letra == 's'){
		printf("Clave correcta\n");
	}
		return letra;
}

int main(){
	char clave, paralela[50];
	while(1){
		printf("Ingrese la clave: ");		
		fgets(paralela,101,stdin);
		//scanf("%s",paralela);
		if(validarClave(paralela)=='s')
			break;
		printf("\n");
	}
	return 0;	
}

