#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

/* Autores:
Naghelly García Rojas - GRNO200401
Denisse Juliete López Mederos - LMDO200377
 */
 
struct Cliente{
	char nombre[50], clave[41], correo[33], estadoC[33];
	int fechan;
	int telefono;
	int edad;
    int credito;
	int sueldo;
};


int menu();
struct Cliente capturarCliente();
int agregarCliente(char nombreA[],struct Cliente nuevo);
int buscarNombre(char nombreA[],char nombreArt[]);
void mostrarRegistro(char nombreA[]);
int buscarclave(char nombreA[],char nombreArt[]);
int modificarRegistro(char nombreA[],struct Cliente nuevo);


int main() {
	struct Cliente auxArt;
	int cliReg=0,opc;
	char auxNombre[50];
	float desc;
	
	do
	{
		opc=menu();
		switch(opc)
		{
			case 1:
				auxArt=capturarCliente();
				if(buscarNombre("cliente.dat",auxArt.nombre)==1){
					printf("El registro ya existe\n");
				}else{
					if(agregarCliente("cliente.dat",auxArt)==1){
						printf("Cliente registrado\n");
						cliReg++;
					}
				}
				break;
			case 2:
			
				break;
			case 3:
				printf("Introduce el nombre: ");
				scanf("%[^\n]",auxArt.nombre);
				printf("Introduce la fecha de nacimiento: ");
				scanf("%d",&auxArt.fechan);
				if(modificarRegistro("cliente.dat",auxArt)==1){
					printf("Registro actualizado\n");
				}
				
				break;
				
			case 4:
				
				printf("Introduce el nombre: ");
				scanf("%[^\n]",auxNombre);
				if(buscarNombre("cliente.dat",auxNombre)==0){			
					printf("El articulo no existe\n");
		     	}
				break;
			case 5:
				break;
			case 6:
				break; 
				
			case 7:
				mostrarRegistro("cliente.dat");
				
				break;
			case 0:
				break;
				
			default:
				printf("\t\t \n Opcion no valida\n\n");
				break;
		}
		
	}while(opc!=0);  
	printf("\n");
	return 0;
}
int menu(){
	int opc;
	printf("\t\t----------------------------------------------------------------------------\n");
	printf(" \t\t \t\t UNIVERSIDAD POLITECNICA DEL ESTADO DE MORELOS \n");
	printf("\t\t  \t\t ASIGNATURA: PROGRAMACION  \t EP3 \n");
	printf("\t\t----------------------------------------------------------------------------\n\n");
	
	printf("\t\t \t\t --------MENU DE OPCIONES--------\n\n");
	printf("\t\t [1]  - Registrar cliente.\n");
	printf("\t\t [2]  - Eliminar Cliente ( De manera fisica).\n");
    printf("\t\t [3]  - Modificar registro de Informacion. \n");
    printf("\t\t [4]  - Buscar un Cliente  por medio de su nombre.\n");
    printf("\t\t [5]  - Buscar un Cliente  por medio de su clave.\n");
    printf("\t\t [6]  - Buscar Cliente segun su Mes de Nacimiento.\n");
    printf("\t\t [7]  - Listado completo de Clientes.\n");
	printf("\t\t [0]  - Salir\n\n");
	
	printf("\t\t          Que opcion decea realizar: ");
	
	scanf("%d%*c",&opc);
	return opc;
}

struct Cliente capturarCliente(){
	struct Cliente nuevo;
	printf("Introduce nombre: ");
	scanf("%[^\n]",nuevo.nombre);
	printf("Introduzca su clave:");
	scanf("%s",nuevo.clave);
	printf("Introduzca su Estado Civil:");  
	scanf("%S",nuevo.estadoC);
	printf("Introduzca su correo:");
	scanf("%S",nuevo.correo);
	printf("Introduzca su edad:");
	scanf("%d",&nuevo.edad);
	printf("Introduzca su  numero Telefonico:");
	scanf("%d",&nuevo.telefono);
	printf("Introduzca su Fecha de Nacimiento:");
	scanf("%d",&nuevo.fechan);
	printf("Introduce monto de Credito:");
	scanf("%d",&nuevo.credito);
	printf("Introduce monto de sueldo:");
	scanf("%d",&nuevo.sueldo);
	
	return nuevo;
	
}

int agregarCliente(char nombreA[],struct Cliente nuevo){
	FILE *archivo;
	
	archivo=fopen(nombreA,"ab");
	if(archivo==NULL){
		printf("No se pudo crear el archivo\n");
		return 0;
	}
	fwrite(&nuevo,sizeof(nuevo),1,archivo);
	fclose(archivo);
	return 1;
}

int buscarNombre(char nombreA[],char nombreArt[]){
	FILE *archivo;
	archivo=fopen(nombreA,"rb");
	if(archivo==NULL){
		printf("El archivo no existe\n");
		return 0;
	}
	struct Cliente aux;
	while(!feof(archivo)){
		fread(&aux,sizeof(aux),1,archivo);
		if(strcmp(nombreArt,aux.nombre)==0){
			printf("%s,%s,%s,%s, %d,%d,%d,%d,%d \n", aux.nombre,aux.clave,aux.correo,aux.estadoC,aux.fechan,aux.telefono,aux.edad,aux.credito, aux.sueldo);
			fclose(archivo);
			return 1;	
     	}
	}
	fclose(archivo);
	return 0;
}

void mostrarRegistro(char nombreA[]){
	FILE *archivo;
	archivo=fopen(nombreA,"rb");
	if(archivo==NULL){
		printf("El archivo no existe\n");
		return;
	}
	struct Cliente aux;
	fread(&aux,sizeof(aux),1,archivo);
	while(!feof(archivo)){
		printf("%s,%s,%s,%s, %d,%d,%d,%d,%d \n", aux.nombre,aux.clave,aux.correo,aux.estadoC,aux.fechan,aux.telefono,aux.edad,aux.credito, aux.sueldo);		
		fread(&aux,sizeof(aux),1,archivo);
	}
	fclose(archivo);
	return;
}

int buscarclave(char nombreA[],char nombreArt[]){
	FILE *archivo;
	archivo=fopen(nombreA,"rb");
	if(archivo==NULL){
		printf("El archivo no existe\n");
		return 0;
	}
	struct Cliente aux;
	while(!feof(archivo)){
		fread(&aux,sizeof(aux),1,archivo);
		if(strcmp(nombreArt,aux.nombre)==0){
			fclose(archivo);
			return 1;	
     	}
	}
	fclose(archivo);
	return 0;
}

int modificarRegistro(char nombreA[],struct Cliente nuevo){
	FILE *archivo;
	archivo=fopen(nombreA,"r+b");
	if(archivo==NULL){
		printf("El archivo no existe\n");
		return 0;
	}
	struct Cliente aux;
	while(!feof(archivo)){
		fread(&aux,sizeof(aux),1,archivo);
		if(strcmp(aux.nombre,nuevo.nombre)==0){
			aux.fechan=nuevo.fechan;
			fseek(archivo,ftell(archivo)-sizeof(struct Cliente),SEEK_SET);
			fwrite(&aux,sizeof(struct Cliente),1,archivo);
			fclose(archivo);
			return 1;	
     	}
	}
	fclose(archivo);
	return 0;
	 
	}  
	
	 
