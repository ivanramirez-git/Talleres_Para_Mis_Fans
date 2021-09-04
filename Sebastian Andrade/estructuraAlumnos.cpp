#include <clocale>
#include<stdio.h>
#include <string.h>


/*
Desarrolle una estructura que guarde los datos de los n
alumnos de la materia programaciÃ³n en Lenguaje C, y los
muestres por pantalla, la estructura debe tener:

Ã¼  cedula
Ã¼  nombre y apellido
Ã¼  edad
Ã¼  profesiÃ³n
Ã¼  lugar de nacimiento
Ã¼  direcciÃ³n
Ã¼  telÃ©fono
Ã¼  promedio

Escribe la estructura de datos mÃ¡s adecuada a utilizar.
Utiliza una estructura, si desea un vector, por lo menos 
se deben utilizar dos ciclos repetitivos. El programa debe 
realizar las siguientes operaciones:

1.     Crear el archivo pidiendo los datos por teclado.
2.     Buscar un estudiante
3.     Modificar su promedio
4.     Realizar la media de todos los promedios
5.     Obtener un listado en el que aparezcan los datos de los estudiantes con la misma profesiÃ³n.
6.     Mostrar el estudiante con el mejor promedio.
7.     Mostrar el estudiante con el peor promedio.
8.     Salir

*/


struct Alumno{
	int cedula;
	char nombre_y_apellido[50];
	int  edad;
	char profesion[50];
	char lugar_de_nacimiento[50];
	char  direccion[50];
	int telefono;
	float promedio;
};

int main(){
	setlocale(LC_CTYPE,"Spanish");

	int numAlumnos, opcion,i,numero,x;
	float numeroFlotante;
	char texto[50];
	printf("Bienvenido\n");
	printf("Ingrese el número de alumnos: ");
	scanf("%d",&numAlumnos);

	Alumno alumnos[numAlumnos];
	do{
		printf("1.     Crear el archivo pidiendo los datos por teclado. \n");
		printf("2.     Buscar un estudiante. \n");
		printf("3.     Modificar su promedio. \n");
		printf("4.     Realizar la media de todos los promedios. \n");
		printf("5.     Obtener un listado en el que aparezcan los datos de los estudiantes con la misma profesión. \n");
		printf("6.     Mostrar el estudiante con el mejor promedio. \n");
		printf("7.     Mostrar el estudiante con el peor promedio. \n");
		printf("8.     Salir. \n");
		printf("-> ");
		
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				for(i=0;i<numAlumnos; i++){
					
					printf("Para el almuno %d Ingrese: \n",i+1);
					printf("Cedula: ");
					scanf("%d",&alumnos[i].cedula);
					
					
					printf("Nombre y Apellido: ");
					scanf("%[^\n]",alumnos[i].nombre_y_apellido);	
					fflush(stdin);
					
									
					
					printf("Edad: ");
					scanf("%d",&alumnos[i].edad);
					
					printf("Profesión: ");
					scanf("%s",&alumnos[i].profesion);
					
					printf("Lugar de nacimiento: ");
					scanf("%s",&alumnos[i].lugar_de_nacimiento);
					
					printf("Dirección: ");
					scanf("%s",&alumnos[i].direccion);
					
					printf("Telefono: ");
					scanf("%d",&alumnos[i].telefono);
					
					printf("Promedio: ");
					scanf("%f",&alumnos[i].promedio);
				}
			break;
			case 2:
				printf("Ingrese la cedula del alumno a buscar: ");
				scanf("%d",&numero);
				for(i=0;i<numAlumnos;i++){
					if(numero==alumnos[i].cedula){
						printf("El alumno fue encontrado.\n");
						printf("Cedula: %d\n",alumnos[i].cedula);
						printf("Nombre y Apellido: %s\n",alumnos[i].nombre_y_apellido);
						printf("Edad:  %d\n",alumnos[i].edad);
						printf("Profesión:  %s\n",alumnos[i].profesion);
						printf("Lugar de nacimiento:  %s\n",alumnos[i].lugar_de_nacimiento);
						printf("Dirección:  %s\n",alumnos[i].direccion);
						printf("Telefono:  %d\n",alumnos[i].telefono);
						printf("Promedio:  %f\n",alumnos[i].promedio);
					}else{
						printf("El alumno no fue encontrado.\n");
					}
				}
			break;
			case 3:
				printf("Ingrese la cedula del alumno a modificar su promedio: ");
				scanf("%f",&numeroFlotante);
				for(i=0;i<numAlumnos;i++){
					if(numero==alumnos[i].cedula){
						printf("El alumno fue encontrado.\n");
						printf("Ingrese el nuevo promedio: ");
						scanf("%f",&numeroFlotante);
						alumnos[i].promedio=numeroFlotante;
					}else{
						printf("El alumno no fue encontrado.\n");
					}
				}
			break;
			case 4:
				numeroFlotante=0;
				for(i=0;i<numAlumnos;i++){
					numeroFlotante=numeroFlotante+alumnos[i].promedio;
				}
				if(numAlumnos>0){
					numeroFlotante=numeroFlotante/numAlumnos;
					printf("La media del promedio de los estudiantes %f\n", numeroFlotante);
				}
				
			break;
			case 5:
				printf("Ingrese la profesión a consultar: "); 
				scanf("%s", &texto);
				for(i=0;i<numAlumnos;i++){
					if(strcmp(alumnos[i].profesion,texto)==0){
						printf("Nombre: %s Profesión: %s\n",alumnos[i].nombre_y_apellido,alumnos[i].profesion);
					}else{
						printf("No existe esa profesión.\n");
					}
				}
			break;
			case 6:
				numeroFlotante=0;
				for(i=0;i<numAlumnos;i++){
					if(alumnos[i].promedio>numeroFlotante){
						numeroFlotante=alumnos[i].promedio;
						numero=i;
					}
				}
				printf("La persona con el mejor promedio es: %s y su promedio es de: %f\n",alumnos[numero].nombre_y_apellido,alumnos[numero].promedio);
			break;
			case 7:
				numeroFlotante=100;
				for(i=0;i<numAlumnos;i++){
					if(alumnos[i].promedio<numeroFlotante){
						numeroFlotante=alumnos[i].promedio;
						numero=i;
					}
				}
				printf("La persona con el peor promedio es: %s y su promedio es de: %f\n",alumnos[numero].nombre_y_apellido,alumnos[numero].promedio);
			break;
			case 8:
				return 0; 
			break;
			default:
				printf("Ingrese un número correcto.\n");
			break;
		}
	}while(1);
}
