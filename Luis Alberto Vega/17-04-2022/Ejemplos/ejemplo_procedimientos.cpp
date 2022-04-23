/*Leccion #7 -Primer Ejemplo utilizando el uso de la programación 
estructurada basada en funciones y procedimientos*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h> //toupper, tolower

//variables de ambito global
int nplanilla=1, contadorm=0, contadorf=0;
float acumuladorm=0, acumuladorf=0, promediom=0, promediof=0;

//prototipos de las funciones y de los procedimientos
void menu();
void planilla();


//funciones

//procedimientos

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
			promediom= acumuladorm / float(contadorm); //promedio
			strcpy(nombre_genero,"Masculino");
		}
		else{
			contadorf++; //contadorf=contadorf+1; contador
			acumuladorf+=salario; //acumuladorf=acumulador+salario; acumulador
			promediof=acumuladorf / float(contadorf); //promedio
			strcpy(nombre_genero,"Femenino");
			
		}
		
		//salida de datos
		system("cls");
		printf("\n\t *** Calculo de Planilla - Salida de Datos ***");
		printf("\n\n Numero de Planilla..........: %i",nplanilla);
		printf("\n\n Numero de Cedula............: %i",cedula);
		printf("\n\n Nombre .....................: %s",nombre);
		printf("\n\n Codigo y nombre de Genero...: %i-%s",codigo_genero,nombre_genero);
		printf("\n\n Cantidad de horas laboradas.: %i",horas);
		printf("\n\n Precio por horas laborada...: %i",pxh);
		printf("\n\n Salario calculado...........: %.2f",salario);
		
		nplanilla++; //nplanilla= nplanilla+1; aumentar el contador autonumerico
		
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
		system("color 5f");
		
		printf("\n\t *** MENU PRINCIPAL ***");
		printf("\n\n 1-Calculo de Planilla");
		printf("\n\n 2-Ver Estadisticas");
		printf("\n\n 3-Salir");
		printf("\n\n\n Ingrese su opcion: ");
		opcion=getch();
		
		switch(opcion)
		{
			case '1': planilla(); break;
			case '2': break;
			case '3': break;
			
			default: {
				printf("\n\n\n\t *** Opcion Incorrecta ***");
				getch();
				break;
			}
		}
		
	}while (opcion!='3');
	
}//fin del proceidmiento menu


//cuerpo principal de programa
int main()
{
	menu(); //invocación del procedimiento llamado menu
	return 0;
}

