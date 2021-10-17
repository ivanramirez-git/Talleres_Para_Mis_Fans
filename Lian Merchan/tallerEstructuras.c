#include <stdio.h>

//complete su codigo

struct ESTUDIANTE {
	char nombre[40];
	float nota1;
	float nota2;
};

void leer(struct ESTUDIANTE estudiantes[]){
	int i;
	for(i=0;i<4;i++){
		printf("nombre[%d]:",i);
		scanf("%s", estudiantes[i].nombre);
		printf("nota1[%d]:",i);
		scanf("%f", &estudiantes[i].nota1);
		printf("nota2[%d]:",i);
		scanf("%f", &estudiantes[i].nota2);
		printf("\n");

	}
}

void aprobados(struct ESTUDIANTE estudiantes[]){
	int i;
	for(i=0;i<4;i++){
		if((estudiantes[i].nota1+estudiantes[i].nota2)>=14){
			printf("%s - %.1f",estudiantes[i].nombre,estudiantes[i].nota1+estudiantes[i].nota2);
			printf("\n");
		}
	}
}

int main()
{
    //complete su codigo
    struct ESTUDIANTE estudiantes[4];
    
    printf("Reporte de Calificaciones\n");
    printf("\nIngrese los datos de los estudiantes:\n");
    leer(estudiantes);
    printf("Estudiantes aprobados:\n");
    aprobados(estudiantes);

    return 0;
}

//complete su codigo
