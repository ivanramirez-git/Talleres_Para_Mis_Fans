// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h> //toupper, tolower
#include <windows.h> //funciones de codigo de bajo nivel
// manejo de consola
HANDLE hConsoleHandle=GetStdHandle(STD_OUTPUT_HANDLE);

// procedimiento para controlar las columnas y las filas en pantalla a traves de un proceso llamado gotoxy
  
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

// funcion que permite convertir un char[] a un int
int ctoi(char cadena[])
{
    int i=0, numero=0;
    
    while (cadena[i] != '\0')
    {
        numero = numero * 10 + cadena[i] - '0';
        i++;
    }
    
    return numero;
}

// funcion que permite convertir un char[] a un float
float ctof(char cadena[])
{
    int i=0, numero=0;
    float fnumero=0;
    
    while (cadena[i] != '\0')
    {
        numero = numero * 10 + cadena[i] - '0';
        i++;
    }
    
    fnumero = numero;
    
    return fnumero;
}
