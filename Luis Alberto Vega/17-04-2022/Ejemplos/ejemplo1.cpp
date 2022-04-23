/* Programa ejemplo procedimientos y funciones*/

//bibliotecas
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  //toupper=convierte temporalmente en mayuscula , tolower convierte temporalmente en minuscula
#include <windows.h>

//variables globales
int cedula,nota1,nota2,contador1=0,contador2=0,contador3=0;
int acumulador1=0,acumulador2=0,acumulador3=0;
float promedio,pro1=0,pro2=0,pro3=0;
char nombre[30],condicion[20];

//prototipos de las funciones y de los procedimientos
void gotoxy(int x,int y);
void menu();
void cuadro(int x1, int y1, int x2, int y2); 
void ingresar();
void estadisticas(); 
void ver_grafico();
void hacer_grafico(int cantidad,int fila); 
//funciones


//procedimientos
//procedimiento Gotoxy para posicionar el curso en las coordenadas X y Y
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);	
}
//procedimiento para crear un cuadro
void cuadro(int x1, int y1, int x2, int y2)
{
	int i;  //contador para controlar el ciclo for
	//for (i=5; i<=15; i++)
	for(i=x1; i<=x2; i++)
	{
		gotoxy(i,y1); printf("%c",205); 
		gotoxy(i,y2); printf("%c",205); 
	}
	
	for(i=y1; i<=y2; i++)
	{
		gotoxy(x1,i); printf("%c",186); 
		gotoxy(x2,i); printf("%c",186); 
	}
	
	gotoxy(x1,y1); printf("%c",201);
	gotoxy(x1,y2); printf("%c",200);
	gotoxy(x2,y1); printf("%c",187);
	gotoxy(x2,y2); printf("%c",188);
}
//procedimiento hacer grafic
void hacer_grafico(int cantidad,int fila)
{
	int i,columna=20;
	
	for (i=1; i<=cantidad; i++)
	{
		gotoxy(columna,fila); printf("%c",178);
		columna++;
	}
}
//procedimiento ver grafico
void ver_grafico()
{
	system("cls");
	system("color 5f");
	gotoxy(13,3); printf("*** Grafico Cantidad de Estudiantes por Condicion ***");
	gotoxy(5,8);  printf("APROBADOS");
	gotoxy(5,10); printf("APLAZADOS");
	gotoxy(5,12); printf("REPROBADOS");
	hacer_grafico(contador1,8);  //hace la grafico de aprobados
	hacer_grafico(contador2,10); //hace la grafica de aplazados
	hacer_grafico(contador3,12); //hacer la grafica de reprobados
	gotoxy(13,17);printf("*** Pulse cualquier <tecla> para regresar al menu ***");	
	getch();
	
}
//procedimiento para ver las estadisticas
void estadisticas()
{ 
	system("cls");
	system("color 5f");
	cuadro(20,2,60,4);
	cuadro(10,8,70,15);
	cuadro(20,19,60,21);
	gotoxy(29,3); printf("[ Proceso Estadisticas ]");
	gotoxy(30,10); printf("APROBADOS");
	gotoxy(42,10); printf("APLAZADOS");
	gotoxy(54,10); printf("REPROBADOS");
	gotoxy(29,11); printf("====================================");
	gotoxy(13,12); printf("Cantidad");
	gotoxy(13,14); printf("Promedio Notas");
	gotoxy(34,12); printf("%i",contador1);
	gotoxy(46,12); printf("%i",contador2);
	gotoxy(58,12); printf("%i",contador3);
	gotoxy(33,14); printf("%.2f",pro1);
	gotoxy(45,14); printf("%.2f",pro2);
	gotoxy(57,14); printf("%.2f",pro3);
    gotoxy(25,20); printf("[Pulse <tecla> para ir al menu]");
    getch();
}

//procedimiento para ingresar datos
void ingresar()
{
	char continuar;
	
	do{
		system("cls");
		system("color 5f");
		cuadro(20,2,60,4);
		cuadro(10,7,70,11);
		cuadro(10,13,70,17);
		gotoxy(25,3); printf("*** Proceso Ingreso de Datos ***");
		gotoxy(13,8); printf("Numero de Cedula.....: ");
		scanf("%i",&cedula);
		
		gotoxy(13,10);printf("Nombre del estudiante: ");
		fflush(stdin); gets(nombre);
		
		gotoxy(13,14);printf("Ingrese Nota 1er. Examen: ");
		scanf("%i",&nota1);
		
		gotoxy(13,16);printf("Ingrese Nota 2do. Examen: ");
		scanf("%i",&nota2);
		
		promedio=float((nota1+nota2))/2;
		
		if (promedio >= 70)
		{
			strcpy(condicion,"Aprobado");
			contador1++;
			acumulador1+=promedio;
			pro1=float(acumulador1)/float(contador1);
		}
		else if (promedio >=60 && promedio <70)
		{
			strcpy(condicion,"Aplazado");
			contador2++;
			acumulador2+=promedio;
			pro2=float(acumulador2)/float(contador2);
		}
		else{
			strcpy(condicion,"Reprobado");
			contador3++;
			acumulador3+=promedio;
			pro3=float(acumulador3)/float(contador3);
		}
		
		system("cls");
		cuadro(20,2,60,4);
		cuadro(10,7,70,11);
		cuadro(10,13,70,17);
		cuadro(20,20,60,22);
		
		gotoxy(23,3); printf("*** Resultados Calculo de Notas ***");
		gotoxy(13,8); printf("Cedula.........: %i",cedula);
		gotoxy(13,10);printf("Nombre.........: %s",nombre);
		gotoxy(13,14);printf("Nota 1er.Examen: %i",nota1);
		gotoxy(13,16);printf("Nota 2do.Examen: %i",nota2);
		gotoxy(48,14);printf("Promedio.: %.2f",promedio);
		gotoxy(48,16);printf("Condicion: %s",condicion);
		gotoxy(25,21);printf("Desea ingresar nuevo dato S/N?");
		do{
			continuar=getch();
		}while(toupper(continuar)!='S' && toupper(continuar)!='N');
			
	}while (toupper(continuar)=='S');
	
}
//procedimiento para crear un menu de opciones
void menu()
{
	char opcion;
	
	do{
		system("cls");
		system("color f5");
		cuadro(22,3,58,5);
		cuadro(18,7,62,15);
		cuadro(22,17,58,19);
		gotoxy(30,4);  printf("*** MENU PRINCIPAL ***");
		gotoxy(31,8);  printf("1-Ingresar Datos");
		gotoxy(31,10);  printf("2-Ver Estadisticas");
		gotoxy(31,12); printf("3-Ver Grafico");
		gotoxy(31,14); printf("4-Salir");
		gotoxy(30,18); printf("Ingrese su opcion: ");
		opcion=getch();
		
		switch(opcion) 
		{
			case '1':	ingresar();     break;
			case '2':   estadisticas(); break;
			case '3':   ver_grafico();  break;
			case '4':   break;
			
			default: {
				gotoxy(28,21); printf("Error: Opcion Invalida");
				Sleep(2000); //espera de tiempo cada 1000 es un segundo
				break;	
			}
		}
		
	}while (opcion!='4');
}
//cuerpo principal del programa
int main()
{
	menu();
	return 0;
}

