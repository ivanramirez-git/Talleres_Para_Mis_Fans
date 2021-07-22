#pragma once
#include "Cliente.h"
class CovidController
{
private:
	int horaInicio;
	int horaFin;
	int minInicio;
	int minFin;
	float tempMinima;
	float tempMaxima;
	int dias[5];
	int contadorPersonasIngresadas;
	int contadorPersonasRechazadas;

	

	//debe declarar los atributos según lo especificado
	protected:
	// debe terminar el resto de las declaraciones de las funciones
		bool esCiCorrecto(int ci, int dia, int mes);
		bool esHoraIngresoCorrecto(int hora, int min);
		bool esTemperaturaCorrecto(float temp);
public:
	void verificarIngreso(Cliente cliente, int dia, int mes, int hora, int minutos);
	void resetear();
	void verconfiguracion();

	int getHoraInicio() { return horaInicio; }
	void setHoraInicio(int h) { horaInicio = h; }
	void verEstadisticas();
	CovidController();

};

