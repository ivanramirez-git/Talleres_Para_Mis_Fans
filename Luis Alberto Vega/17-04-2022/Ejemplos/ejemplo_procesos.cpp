/*Leccion #8 -Primer Ejemplo utilizando el uso de la programaci�n 
estructurada basada en funciones y procedimientos*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h> //toupper, tolower
#include <windows.h> //funciones de codigo de bajo nivel

//variables de ambito global
int nplanilla=0, contadorm=0, contadorf=0;
float acumuladorm=0, acumuladorf=0;

//prototipos de las funciones y de los procedimientos
void menu();
void planilla();
void estadisticas();
int contador_planilla();
float promedio_salario_femenino();
float promedio_salario_masculino();
void color(int c);
void gotoxy(int x, int y);
 

/* atributo para el manejo de codigo de bajo nivel llamada Hadle, este atributo permite
   la invocaci�n del comando para enviar la salida del texto en diferentes colores */
   
HANDLE hConsoleHandle=GetStdHandle(STD_OUTPUT_HANDLE);
   

//funciones

//funcion para obtener el promedio de salario femenino
float promedio_salario_femenino()
{
	float p=0;
	
	if (contadorf > 0)
		p= acumuladorf / float(contadorf);
		
	return p;
	
}

//funcion para obtener el promedio de salario masculino
float promedio_salario_masculino()
{
	float p=0;
	
	if (contadorm > 0)
		p=acumuladorm / float(contadorm);
		
	return p;
}
//funcion para llevar el consecutivo autonumerico del numero de planilla
int contador_planilla()
{
	nplanilla++;
	
	return nplanilla;
	
}
//procedimientos
/*Procedimiento para controlar las columnas y las filas en pantalla a traves de un proceso
  llamado gotoxy */
  
void gotoxy(int x, int y) 
{
	COORD coord;
	
	coord.X=x;
	coord.Y=y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


//procedimiento para definir el color de texto
void color(int c)
{
	SetConsoleTextAttribute(hConsoleHandle,c);
}




//procedimiento para mostrar las estadisticas 
void estadisticas()
{
	system("cls");
	system("color 5f");
	
	gotoxy(16,2);  printf("*** Programa Calcula Salarios - Estadisticas ***");
	gotoxy(16,5);  printf("Cantidad Personas Genero Masculino: %i", contadorm);
	gotoxy(16,7);  printf("Salario Acumulado Genero Masculino: %.2f",acumuladorm);
	gotoxy(16,9);  printf("Promedio Salario  Genero Masculino: %.2f",promedio_salario_masculino());
	gotoxy(16,12); printf("Cantidad Personas Genero Femenino.: %i", contadorf);
	gotoxy(16,14); printf("Salario Acumulado Genero Femenino.: %.2f",acumuladorf);
	gotoxy(16,16); printf("Promedio Salario  Genero Femenino.: %.2f",promedio_salario_femenino());
	gotoxy(16,19); printf("*** Pulse cualquier tecla para regresar al menu ***");
	getch();	
}

//procedimiento para realiza el el ingreso de datos y proceso de la planilla
void planilla()
{
	//variables de ambito local
	int cedula, horas, pxh, codigo_genero;
	float salario;
	char continuar, nombre[30], nombre_genero[30];	
	
	do{
		//entrada de datos
		system("cls");
		system("color f5");
		printf("\n\t *** Calculo de Planilla - Ingreso de Datos ***");
		printf("\n\n Ingrese numero de cedula..............: ");
		scanf("%i",&cedula);
		
		printf("\n\n Ingrese su nombre.....................: ");
		fflush(stdin); gets(nombre);
		
		do{
			printf("\n\n Codigo de Genero [1=Masculino 2=Femenino]: ");
			scanf("%i",&codigo_genero);
			
			if (codigo_genero <1 || codigo_genero > 2)
			{
				printf("\n\n *** Error: Ingrese un valor 1 o 2 ***");
			}
		}while(codigo_genero < 1 || codigo_genero > 2);
		
		printf("\n\n Ingrese cantidad de horas laboradas.....: ");
		scanf("%i",&horas);
		
		printf("\n\n Ingrese precio por hora laborada........: ");
		scanf("%i",&pxh);
		
		//proceso
		salario= horas * pxh;
		
		if (codigo_genero == 1)
		{
			contadorm++; //contadorm=contadorm+1; contador
			acumuladorm+=salario; //acumuladorm = acumuladorm + salario; acumulador
			
			strcpy(nombre_genero,"Masculino");
		}
		else{
			contadorf++; //contadorf=contadorf+1; contador
			acumuladorf+=salario; //acumuladorf=acumulador+salario; acumulador
		
			strcpy(nombre_genero,"Femenino");
			
		}
		
		//salida de datos
		system("cls");
		printf("\n\t *** Calculo de Planilla - Salida de Datos ***");
		printf("\n\n Numero de Planilla..........: %i",contador_planilla());
		printf("\n\n Numero de Cedula............: %i",cedula);
		printf("\n\n Nombre .....................: %s",nombre);
		printf("\n\n Codigo y nombre de Genero...: %i-%s",codigo_genero,nombre_genero);
		printf("\n\n Cantidad de horas laboradas.: %i",horas);
		printf("\n\n Precio por horas laborada...: %i",pxh);
		printf("\n\n Salario calculado...........: %.2f",salario);
		
		
		printf("\n\n\n\t *** Desea registrar nueva planilla S/N? ***");
		do{
			continuar=getch();
		}while (toupper(continuar)!='S' && toupper(continuar)!='N');
		
	}while (toupper(continuar)=='S');
	
}

//procedimiento para el menu del sistema
void menu()
{//inicio del procedimiento menu
	char opcion; //variable de ambito local
	
	do{
		system("cls");
		//system("color 5f");
		
		color(5);
		gotoxy(30,4); printf("*** MENU PRINCIPAL ***");
		color(10);
		gotoxy(30,7);  printf("1-Calculo de Planilla");
		gotoxy(30,9);  printf("2-Ver Estadisticas");
		gotoxy(30,11); printf("3-Salir");
		color(4);
		gotoxy(30,13); printf("Ingrese su opcion: ");
		opcion=getch();
		
		switch(opcion)
		{
			case '1': planilla();     break;
			case '2': estadisticas(); break;
			case '3': break;
			
			default: {
				gotoxy(30,16); printf("*** Opcion Incorrecta ***");
				getch();
				break;
			}
		}
		
	}while (opcion!='3');
	
}//fin del proceidmiento menu


//cuerpo principal de programa
int main()
{
	menu(); //invocaci�n del procedimiento llamado menu
	return 0;
}

