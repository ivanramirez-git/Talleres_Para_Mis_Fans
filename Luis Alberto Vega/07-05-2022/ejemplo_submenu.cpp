/* ejemplo programa con submenu de opciones */

#include <mibiblioteca.h>

//prototipos
void menu();
void inicializar();
void ingresar();
void consulta();
void submenu();
void reporte1();
void reporte2();
void reporte3();

//funciones


//procedimientos
void reporte3()
{
	system("cls");
	gotoxy(20,3); printf("Reporte 3...");
	getch();
}
void reporte2()
{
	system("cls");
	gotoxy(20,3); printf("Reporte 2...");
	getch();
}

void reporte1()
{
	system("cls");
	gotoxy(20,3); printf("Reporte 1...");
	getch();
}

void consulta()
{
	system("cls");
	gotoxy(20,3); printf("Consultar Datos...");
	getch();
}

void ingresar()
{
	system("cls");
	gotoxy(20,3); printf("Ingresar Datos...");
	getch();
	
}

void inicializar()
{
	system("cls");
	gotoxy(20,3); printf("Inicializar....");
	getch();
}

//procedimiento submenu para los reportes
void submenu()
{
	char opcions;
	
	do{
		system("cls");
		system("color f5");
		
		gotoxy(20,5);  printf("*** SUBMENU DE REPORTES ***");
		gotoxy(20,8);  printf("1-Reporte #1");
		gotoxy(20,10); printf("2-Reporte #2");
		gotoxy(20,12); printf("3-Reporte #3");
		gotoxy(20,14); printf("4-Regresar al Menu");
		opcions=getch();
		
		switch(opcions)
		{
			case '1': reporte1(); break;
			case '2': reporte2(); break;
			case '3': reporte3(); break;
			case '4': break;
			
			default: {
				gotoxy(39,14); printf("Error: opcion invalida");
				Sleep(2000);
				break;
			}
		}
		
	}while (opcions!='4');
}

//procedimiento menu principal
void menu()
{
	char opcion;
	
	do{
		system("cls");
		system("color 5f");
		
		gotoxy(20,5);  printf("*** MENU PRINCIPAL ***");
		gotoxy(20,8);  printf("1-Inicializar Vectores");
		gotoxy(20,10); printf("2-Ingresar Datos");
		gotoxy(20,12); printf("3-Consultar Datos");
		gotoxy(20,14); printf("4-Submenu de Reportes");
		gotoxy(20,16); printf("5-Salir");
		gotoxy(20,19); printf("Ingrese su opcion: ");
		opcion=getch();
		
		switch(opcion)
		{
			case '1': inicializar(); break;
			case '2': ingresar();    break;
			case '3': consulta();    break; 
			case '4': submenu();     break;
			case '5': break;
			
			default: {
				gotoxy(39,19); printf("Error: Opcion invalida");
				Sleep(2000);
				break;
			}
		}
		
	}while (opcion !='5');
}


//cuerpo principal
int main()
{
	menu();
	return 0;	
}
