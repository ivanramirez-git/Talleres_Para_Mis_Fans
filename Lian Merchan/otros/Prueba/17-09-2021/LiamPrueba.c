#include<stdio.h>

struct PRODUCTO{
	char Codigo[5];
	float Precio;
	char Iva;
	char Registro;
	char Nombre[40];
	int cantidad;
};

void crearEstructura(struct PRODUCTO productos[]){
	
	strcpy(productos[0].Codigo,"P001");
	productos[0].Precio = 1.58;	
	productos[0].Iva = 's';
	productos[0].Registro = 'n';
	strcpy(productos[0].Nombre,"Atun");
	
	
	
	strcpy(productos[1].Codigo,"P002");
	productos[1].Precio = 0.58;	
	productos[1].Iva = 'n';
	productos[1].Registro = 'n';
	strcpy(productos[1].Nombre,"Panela");
	
	strcpy(productos[2].Codigo,"P003");
	productos[2].Precio = 0.85;	
	productos[2].Iva = 'n';
	productos[2].Registro = 'n';
	strcpy(productos[2].Nombre,"Avena");
	
	strcpy(productos[3].Codigo,"P004");
	productos[3].Precio = 1.10;	
	productos[3].Iva = 'n';
	productos[3].Registro = 'n';
	strcpy(productos[3].Nombre,"Sal");
	
	strcpy(productos[4].Codigo,"P005");
	productos[4].Precio = 1.50;	
	productos[4].Iva = 'n';
	productos[4].Registro = 'n';
	strcpy(productos[4].Nombre,"Gelatina");
	
	productos[0].cantidad = 0;
	productos[1].cantidad = 0;	
	productos[2].cantidad = 0;	
	productos[3].cantidad = 0;
	productos[4].cantidad = 0;
	
	
	
}

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
    	else
    		simbolo++;
	}
	letra = 's';
	if(mayuscula<1){
		printf("La clave debe tener al menos una mayuscula\n");
		letra = 'n';
	}
	if(numero<1){
		printf("La clave debe tener al menos un numero\n");
		letra = 'n';
	}
	if(minuscula<1){
		printf("La clave debe tener al menos una minuscula\n");
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

void imrpimirEstructura(struct PRODUCTO productos[]){
	printf("Codigo\tNombre\tPrecio\tIVA\t\n");
	int i;
	for(i=0;i<5;i++){
		printf("%s\t%s\t%0.2f\t%c\t\n",productos[i].Codigo,productos[i].Nombre,productos[i].Precio,productos[i].Iva);
	}
}

void buscador(struct PRODUCTO productos[], char texto[]){

	int i;
	for(i=0;i<5;i++){
		if(strcmp(productos[i].Nombre,texto) == 0){
			
			printf("Ingrese la cantidad: ");
		}
	}
}

int main(){
	char *clave, paralela[50];
	int opcion;
	char letra;
	struct PRODUCTO productos[5];
	do{
		//printf("1. Claves\n2. Productos\n0. Salir\n-> ");
		//scanf("%d", &opcion);
		opcion=2;
		switch(opcion){
			case 1:
				while(1){
					printf("Ingrese la clave: ");
					scanf("%s",paralela);
					if(validarClave(paralela)=='s')
						break;
				}
			break;
			case 2:
				crearEstructura(productos);
				while(1){
					imrpimirEstructura(productos);
					printf("Ingrese el codigo de producto: ");
					scanf("%s",paralela);
					
					buscador(productos, paralela);				
					
					
					//validarProducto()
					
					if(letra=='n')
						break;
				}
				
			break;		
			case 0:
				return 0;
			break;
			default:
				printf("Opcion no valida.");
			break;
		}
	}while(1);

}
