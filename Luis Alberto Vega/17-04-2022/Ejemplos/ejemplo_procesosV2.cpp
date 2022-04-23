/*Leccion #9 -Primer Ejemplo utilizando el uso de la programación 
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
void cuadro(int x1, int y1, int x2, int y2);
void estadisticas2();
void encabezado_grafico();
void grafico(int cantidad, int x, int y, int tiempo);
void inicio();

/* atributo para el manejo de codigo de bajo nivel llamada Hadle, este atributo permite
   la invocación del comando para enviar la salida del texto en diferentes colores */
   
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
/*procedimiento para realizar un cuadro segun las coordenadas que se indiquen*/
/*
	cuadro(20,5,60,15);
	x1=20;
	y1=5;
	x2=60;
	y2=15;
	
	i=20;
   
*/
void cuadro(int x1, int y1, int x2, int y2)
{
	int i;
	
	for (i=x1; i<=x2; i++)  //horizontales
	{
		gotoxy(i,y1); printf("%c",205); 
		gotoxy(i,y2); printf("%c",205);  
	}
	
	for (i=y1; i<=y2; i++)  //verticales
	{
		gotoxy(x1,i); printf("%c",186); 
		gotoxy(x2,i); printf("%c",186); 
	}
	
	//generan las esquinas
	gotoxy(x1,y1); printf("%c",201); //superior-izquierda
	gotoxy(x1,y2); printf("%c",200); //inferior-izquierda
	gotoxy(x2,y1); printf("%c",187); //superior-derecha
	gotoxy(x2,y2); printf("%c",188); //inferior-derecha
}

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

//procedimiento inicio
void inicio()
{
	system("cls");
	gotoxy(20,5);  printf("*** Programa Calculo de Planilla ***");
	gotoxy(20,10); printf("          < Iniciando... >");
	grafico(36,20,12,100);
	gotoxy(20,10); printf("          < Cargado..... >");
	Sleep(3000); //espera de tiempo donde cada 1000 es un segundo
		
}
//procedimiento para realizar el grafico
void grafico(int cantidad, int x, int y, int tiempo)
{
	int i;
	
	for (i=1; i<=cantidad; i++)
	{
		gotoxy(x,y); printf("%c",219);
		x++; //x=x+1;
		Sleep(tiempo); //espera de tiempo
	}
}

//procedimiento para ejecutar el encabezado del grafico
void encabezado_grafico()
{
	system("cls");
	cuadro(15,2,65,4);
	cuadro(15,17,65,19);
	cuadro(2,7,15,9);
	cuadro(2,12,15,14);
	cuadro(16,7,78,9);
	cuadro(16,12,78,14);
	
	gotoxy(17,3); printf("*** Grafico Cantidad de Personas por Genero ***");
	gotoxy(4,8);  printf("Masculino");
	grafico(contadorm,17,8,0);
	
	gotoxy(4,13); printf("Femenino");
	grafico(contadorf,17,13,0);
	gotoxy(17,18);printf("**** Pulse cualquier tecla para ir al menu ****");
	getch();

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

void estadisticas2()
{
	system("cls");
	system("color 5f");
	cuadro(14,2,66,4); //cuadro del titulo
	cuadro(2,8,39,14); //cuadro izquierdo para los datos de masculino
	cuadro(41,8,78,14); //cuadro derecho para los datos de femenino
	cuadro(14,18,66,20); //cuadro para texto regresar al menu
	
	gotoxy(16,3);  printf("*** Programa Calcula Salarios - Estadisticas ***");
	
	gotoxy(4,9);   printf("* Estadisticas Genero Masculino *");
	gotoxy(4,11);  printf("Cantidad      Salario     Promedio");
	gotoxy(4,12);  printf("==================================");
	gotoxy(7,13);  printf("%i",contadorm);
	gotoxy(16,13); printf("%.2f",acumuladorm);
	gotoxy(30,13); printf("%.2f",promedio_salario_masculino());
		
	gotoxy(43,9);  printf("* Estadisticas Genero Femenino *");
	gotoxy(43,11); printf("Cantidad      Salario     Promedio");
	gotoxy(43,12); printf("==================================");
	gotoxy(46,13); printf("%i",contadorf);
	gotoxy(54,13); printf("%.2f",acumuladorf);
	gotoxy(67,13); printf("%.2f",promedio_salario_femenino()); 

	gotoxy(16,19); printf("** Pulse cualquier tecla para regresar al menu **");
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
		gotoxy(20,3); printf(" *** Calculo de Planilla - Ingreso de Datos ***");
		gotoxy(15,5); printf("Ingrese numero de cedula..............: ");
		scanf("%i",&cedula);
		
		gotoxy(15,7); printf("Ingrese su nombre.....................: ");
		fflush(stdin); gets(nombre);
		
		do{
			gotoxy(15,9); printf("Codigo de Genero [1=Masculino 2=Femenino]: ");
			scanf("%i",&codigo_genero);
			
			if (codigo_genero <1 || codigo_genero > 2)
			{
				gotoxy(15,10); printf("*** Error: Ingrese un valor 1 o 2 ***");
				Sleep(2000);
				gotoxy(15,10); printf("                                      ");
			}
		}while(codigo_genero < 1 || codigo_genero > 2);
		
		gotoxy(15,11); printf("Ingrese cantidad de horas laboradas.....: ");
		scanf("%i",&horas);
		
		gotoxy(15,13); printf("Ingrese precio por hora laborada........: ");
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
	
	
	inicio();
	do{
		system("cls");
		//system("color 5f");
		cuadro(27,2,53,4);
		cuadro(27,6,53,14);
		cuadro(27,16,53,18);
		
		color(5);
		gotoxy(30,3); printf("*** MENU PRINCIPAL ***");
		color(10);
		gotoxy(30,7);  printf("1-Calculo de Planilla");
		gotoxy(30,9);  printf("2-Ver Estadisticas");
		gotoxy(30,11); printf("3-Ver Grafico");
		gotoxy(30,13); printf("4-Salir");
		
		color(4);
		gotoxy(30,17); printf("Ingrese su opcion: ");
		opcion=getch();
		
		switch(opcion)
		{
			case '1': planilla();           break;
			case '2': estadisticas2();      break;
			case '3': encabezado_grafico(); break;
			case '4': break;
			
			default: {
				gotoxy(30,17); printf("* Opcion Incorrecta *");
				Sleep(2000);
				gotoxy(30,17); printf("                     ");
				break;
			}
		}
		
	}while (opcion!='4');
	
}//fin del proceidmiento menu


//cuerpo principal de programa
int main()
{
	menu(); //invocación del procedimiento llamado menu
	return 0;
}

