#include<stdio.h>
#include<string.h>

struct ESTUDIANTE
{
	char nombre[40];
	float notas[3];
	float promedio;
};

void menu0(){
	printf("ESTUDIANTES DE REALIDAD NACIONAL\n");
	printf("Ingrese el numero de estudiantes : ");	
}

void menu1(){
	printf("Seleccione lo que desea listar\n");
	printf("a. Todos los registros\n");
	printf("b. Estudiantes aprobados\n");	
	printf("c. Estudiantes suspensos\n");	
	printf("d. Estudiantes reprobados\n");	
	printf("e. Salir\n");	
}

// Saca el promedio de todos los estudiantes del arreglo
void promediar(struct ESTUDIANTE estudiantes[], int numeroEstudiantes){
	for (int i = 0; i < numeroEstudiantes; ++i)
	{
		float suma=0;
		// Suma las 3 notas
		for (int j=0;j<3;++j)
			suma=suma+estudiantes[i].notas[j];

		// Se asigna el promedio en el arreglo
		estudiantes[i].promedio=(suma/3);
	}
}

void ingresoInicial(struct ESTUDIANTE estudiantes[]){

	strcpy(estudiantes[0].nombre,"Juan");	
	estudiantes[0].notas[0]=9.30;
	estudiantes[0].notas[1]=8.70;
	estudiantes[0].notas[2]=5.00;

	strcpy(estudiantes[1].nombre,"Pedro");	
	estudiantes[1].notas[0]=5.30;
	estudiantes[1].notas[1]=6.70;
	estudiantes[1].notas[2]=7.00;

	strcpy(estudiantes[2].nombre,"Luis");	
	estudiantes[2].notas[0]=4.10;
	estudiantes[2].notas[1]=2.50;
	estudiantes[2].notas[2]=3.00;

}

void impimirUnEstudiante(struct ESTUDIANTE estudiantes[], int i){
	printf("%s\t\t%.2f\t%.2f\t%.2f\t%.2f\n",estudiantes[i].nombre,estudiantes[i].notas[0],estudiantes[i].notas[1],estudiantes[i].notas[2],estudiantes[i].promedio);
}

void imprimirTodos(struct ESTUDIANTE estudiantes[], int numeroEstudiantes){
	printf("Nombre\t\tNota 1\tNota 2\tNota 3\tProm.\n");
	printf("-----------------------------------------------\n");
	
	for (int i = 0; i < numeroEstudiantes; ++i)
	{
		impimirUnEstudiante(estudiantes,i);
	}
}

void imprimirAprobados(struct ESTUDIANTE estudiantes[], int numeroEstudiantes){
	printf("Nombre\t\tNota 1\tNota 2\tNota 3\tProm.\n");
	printf("-----------------------------------------------\n");
	
	for (int i = 0; i < numeroEstudiantes; ++i)
	{
		if(estudiantes[i].promedio>=7)
			impimirUnEstudiante(estudiantes,i);		
	}
}

void imprimirSuspenso(struct ESTUDIANTE estudiantes[], int numeroEstudiantes){
	printf("Nombre\t\tNota 1\tNota 2\tNota 3\tProm.\n");
	printf("-----------------------------------------------\n");
	
	for (int i = 0; i < numeroEstudiantes; ++i)
	{
		if(estudiantes[i].promedio>=5 && estudiantes[i].promedio<7)
			impimirUnEstudiante(estudiantes,i);		
	}
}

void imprimirReprobado(struct ESTUDIANTE estudiantes[], int numeroEstudiantes){
	printf("Nombre\t\tNota 1\tNota 2\tNota 3\tProm.\n");
	printf("-----------------------------------------------\n");
	
	for (int i = 0; i < numeroEstudiantes; ++i)
	{
		if(estudiantes[i].promedio<5)
			impimirUnEstudiante(estudiantes,i);		
	}
}

// Funcion que añade nuevos estudiantes al arreglo
void nuevosEstudiantes(struct ESTUDIANTE estudiantes[], int numeroEstudiantes, int anadirEstudiantes){
	// Ciclo desde el numero de estuantes actual estudiantes[3]
	for(int i=numeroEstudiantes;i<(numeroEstudiantes+anadirEstudiantes);i++){
		printf("Nombre [%d] : ",i);
		scanf("%s",estudiantes[i].nombre);
		printf("Nota [0] : ");
		scanf("%f",&estudiantes[i].notas[0]);
		printf("Nota [1] : ");
		scanf("%f",&estudiantes[i].notas[1]);
		printf("Nota [2] : ");
		scanf("%f",&estudiantes[i].notas[2]);
	}
}

int main(){
	// Variable para el switch
	char opcion;
	
	// Lista de estudiantes
	struct ESTUDIANTE estudiantes[20];

	// Numero de estudiantes en el arreglo, y numero de estudiantes para añadir a el arreglo
	int numeroEstudiantes=0, anadirEstudiantes=0;

	// Ingresar los 3 estudiantes del ejemplo, Juan, Pedro y Luis
	ingresoInicial(estudiantes);

	// Numero de estudiantes = 3, porque en el arreglo hay 3 estudiantes
	numeroEstudiantes=3;

	// Funcion que saca el promedio de todos los estudiantes del arreglo
	promediar(estudiantes,numeroEstudiantes);

	// Funcion que imprime el menu 0 donde podemos añadir nuevos estudiantes
	menu0();

	// Se escanea cuantos estudiantes nuevos se van añador
	scanf("%d",&anadirEstudiantes);

	// 
	if(anadirEstudiantes>0){

		// Funcion que añade nuevos estudiantes al arreglo
		nuevosEstudiantes(estudiantes,numeroEstudiantes,anadirEstudiantes);
		numeroEstudiantes=numeroEstudiantes+anadirEstudiantes;
		promediar(estudiantes,numeroEstudiantes);
	}

	while(1){		

		printf("\n");		
		menu1();
		scanf("%c",&opcion);
		scanf("%c",&opcion);


		switch(opcion){
			case 'a':
				printf("\n");
				imprimirTodos(estudiantes,numeroEstudiantes);
			break;
			case 'b':
				printf("\n");
				imprimirAprobados(estudiantes,numeroEstudiantes);
			break;
			case 'c':
				printf("\n");
				imprimirSuspenso(estudiantes,numeroEstudiantes);
			break;
			case 'd':
				printf("\n");
				imprimirReprobado(estudiantes,numeroEstudiantes);
			break;
			case 'e':
				return 0;
			break;
			default:
				printf("\n\tSeleccione una opcion valida!!!\n");
			break;
		}
	}
}