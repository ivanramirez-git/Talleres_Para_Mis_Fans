#include<stdio.h>
#include <string.h>

struct producto
{
	char codigo[30];
	char nombre[30];
	float costo;
	float venta;
	int cantidad;
};

int main()
{
	
	producto datos[4];
	int opc;
	char codigo[30];
	int i;
	float precio;
	
	do{
		printf("1. Crear el archivo pidiendo los datos por teclado\n");
		printf("2. Buscar un producto.\n");
		printf("3. Dar de alta un producto\n");
		printf("4. Modificar el precio de un producto dado\n");
		printf("5. Mostrar el producto con el precio mas alto\n");
		printf("6. Mostrar el producto con el precio mas bajo\n");
		printf("7. Salir.\n");		
		scanf("%d",&opc);
		switch(opc){
			case 1:
				for(i=0;i<4; i++){					
					printf("%d Producto: \n",i+1);
					printf("Ingrese el codigo: ");
					scanf("%s",&datos[i].codigo);
					printf("Ingrese el nombre del producto: ");
					scanf("%s",&datos[i].nombre);
					printf("Ingrese el precio del costo: ");
					scanf("%f",&datos[i].costo);
					printf("Ingrese el precio de venta: ");
					scanf("%f",&datos[i].venta);
					datos[i].cantidad=0;					
				}
			break;
			case 2:
				printf("Para buscar ingrese el codigo del producto: ");
				scanf("%s",&codigo);
				for(i=0;i<4;i++){
					if(!strcmp(datos[i].codigo,codigo)){
						printf("El producto con codigo [%s] es [%s] con un precio de venta de [%f] y un costo de [%f], la cantidad vendida es de [%d] unidades \n",datos[i].codigo,datos[i].nombre,datos[i].venta,datos[i].costo,datos[i].cantidad);
					}
				}
			break;
			case 3:
				printf("Para vender un producto, ingrese el codigo: ");
				scanf("%s",&codigo);
				for(i=0;i<4;i++){
					if(!strcmp(datos[i].codigo,codigo)){
						datos[i].cantidad=datos[i].cantidad+1;
					}
				}
			break;
			case 4:
				printf("Para modificar los precios de un producto, ingrese el codigo: ");
				scanf("%s",&codigo);
				for(i=0;i<4;i++){
					if(!strcmp(datos[i].codigo,codigo)){
						printf("Ingrese el nuevo costo del producto [%s]: ",datos[i].nombre);
						scanf("%f",&datos[i].costo);
						printf("Ingrese el nuevo precio de venta del producto [%s]: ",datos[i].nombre);
						scanf("%f",&datos[i].venta);
					}
				}				
			break;
			case 5:
				precio=0;
				for(i=0;i<4;i++){
					if(datos[i].venta>precio){
						precio=datos[i].venta;
					}
				}
				for(i=0;i<4;i++){
					if(datos[i].venta==precio){
						printf("El precio mas alto es [%f]\n",datos[i].venta);
					}
				}			
			break;
			case 6:
				precio=1000000;
				for(i=0;i<4;i++){
					if(datos[i].venta<precio){
						precio=datos[i].venta;
					}
				}
				for(i=0;i<4;i++){
					if(datos[i].venta==precio){
						printf("El precio mas bajo es [%f]\n",datos[i].venta);
					}
				}
			break;
		}
	}while(opc!=7);
}
