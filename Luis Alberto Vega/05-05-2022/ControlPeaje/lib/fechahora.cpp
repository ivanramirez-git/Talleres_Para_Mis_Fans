#include <ctime>
#include <stdio.h>
#include <string.h>
#include <conio.h>

// funcion que retorna la fecha actual
char* darFechaActual()
{
	time_t current_time;  // declaracion de una estructura time
	struct tm *time_info; // asignaci�n de la estructura time

	char* fecha;
	char aux[15];
	time(&current_time);
	time_info = localtime(&current_time);

	fecha = asctime(time_info);

	// Formatear dd/mm/aaaa
	strftime(aux, sizeof(aux), "%d/%m/%Y", time_info);

	strcpy(fecha, aux);

	return fecha;
}

// funcion que retorna la hora actual
char* darHoraActual()
{
	time_t current_time;  // declaracion de una estructura time
	struct tm *time_info; // asignaci�n de la estructura time

	char* hora;
	char aux[15];
	time(&current_time);
	time_info = localtime(&current_time);

	hora = asctime(time_info);

	// Formatear hh:mm:ss
	strftime(aux, sizeof(aux), "%H:%M:%S", time_info);

	strcpy(hora, aux);

	return hora;
}
/* 
// main
int main()
{

	char fecha[15];
	char hora[15];

	strcpy(fecha, fechaActual());
	strcpy(hora, horaActual());

	// imprimir la fecha y hora actual
	printf("Fecha: %s\n", fecha);
	printf("Hora: %s\n", hora);

	return 0;
}
*/