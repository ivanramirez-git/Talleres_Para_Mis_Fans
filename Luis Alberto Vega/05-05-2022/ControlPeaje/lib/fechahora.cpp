
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <conio.h>

const int t=5; //declaracion de constante
 
time_t current_time; //declaracion de una estructura time
struct tm * time_info; //asignación de la estructura time

char timeString[t][9]; //creación del vector para almacenar la hora del sistema


//variable global para el manejo de las posiciones del vector
int p=0; 
 
 
 void datos()
 {
 	time(&current_time);
	time_info = localtime(&current_time);
 
 	
 
   	strftime(timeString[p], sizeof(timeString[p]), "%H:%M:%S", time_info);
   	printf("%s", timeString[p]); //mostrando el vecto timeString en la posicion p
     
   getch();
 }
 
 
int main ()
{
 	datos();
   	return 0;
}
