#include <stdio.h>
//complete su codigo

struct datos{
	char nombre[4][40];
	float n1[4], n2[4];
};

struct datos leer(struct datos estudiantes){
	int contador;
	
	char nomTemporal[40];
	float n1Temporal, n2Temporal;
	
	for(contador=0;contador<4;++contador){
		
		printf("nombre[%d]:",contador);
		scanf("%s",estudiantes.nombre[contador]);
		
		printf("nota1[%d]:",contador);
		scanf("%f",&estudiantes.n1[contador]);
		
		printf("nota2[%d]:",contador);
		scanf("%f",&estudiantes.n2[contador]);
		
	//	estudiantes.nombre[contador] = nomTemporal;
	//	estudiantes.n1[contador] = n1Temporal;
	//	estudiantes.n2[contador] = n2Temporal;
		printf("\n");
		
	}
	return estudiantes;
}
void aprobados(struct datos estudiantes){
	int contador;
	float suma;
	
	for(contador=0;contador<4;++contador){
		//suma=estudiantes.n1[contador] + estudiantes.n2[contador];
		if(!((estudiantes.n1[contador] + estudiantes.n2[contador])<14)){
			printf("%s - %0.1f\n",estudiantes.nombre[contador],(estudiantes.n1[contador] + estudiantes.n2[contador]));
			
		}
	}
}

int main()
{
	struct datos estudiantes;
    //complete su codigo
    printf("Reporte de Calificaciones\n");
    printf("\nIngrese los datos de los estudiantes:\n");
    estudiantes=leer(estudiantes);
    printf("Estudiantes aprobados:\n");
    aprobados(estudiantes);

    return 0;
}

//complete su codigo
