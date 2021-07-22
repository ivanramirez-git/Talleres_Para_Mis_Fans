#include "CovidController.h"
#include "iostream";
bool CovidController::esCiCorrecto(int ci, int dia, int mes)
{
	int diaSemana1 = dia % 7;
	//cout << diaSemana1 << endl;
	int ud = ci % 10;

	if (diaSemana1 > 0 && diaSemana1 <= 5)
	{
		int pt1 = dias[diaSemana1 - 1] % 10;
		int pt2 = dias[diaSemana1 - 1] / 10;

		//cout << " dias " << pt1 << pt2 << endl;

		if (ud == pt1 || ud == pt2)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;

	


}
bool CovidController::esHoraIngresoCorrecto(int hora, int min)
{
	float hgmi = horaInicio + minInicio / 60;
	float hgmf = horaFin + minFin / 60;
	float hing = hora + min / 60;

	return (hing >= hgmi && hing <= hgmf);
}
bool CovidController::esTemperaturaCorrecto(float temp)
{
	return (temp >= tempMinima && temp <= tempMaxima);
}
void CovidController::verificarIngreso(Cliente cliente, int dia, int mes, int hora, int minutos) 
{
	bool rest1, rest2, rest3;
	rest1 = esCiCorrecto(cliente.ci, dia, mes);
	rest2 = esTemperaturaCorrecto(cliente.temperatura);
	rest3 = esHoraIngresoCorrecto(hora, minutos);
	if (rest1 && rest2 && rest3)
	{
		contadorPersonasIngresadas++;
		cout << "Bienvenido " << cliente.getNombreCompleto() << endl;
	}
	else
	{
		cout << "No puede ingresar" << endl;
		contadorPersonasRechazadas++;
		verconfiguracion();
	}


	//debe llamar a las funciones de arriba para verificar si un cliente entra o no
}

void CovidController::verEstadisticas()
{
	cout << "Cantidad Personas que ingresaron " << contadorPersonasIngresadas << endl;
	cout << "Cantidad Personas rechazadas " << contadorPersonasRechazadas << endl;

}

void CovidController::resetear()
{
	contadorPersonasIngresadas = contadorPersonasRechazadas = 0;
}
void CovidController::verconfiguracion()
{
	cout << "Temperatura aceptable : " << tempMinima << " a " << tempMaxima << endl;
	cout << "Horario de Ingreso : " << horaInicio<<":"<<minInicio << " a " << horaFin<<":"<<minFin << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Dia " << (i + 1) << " ingresan las terminaciones con " << dias[i] % 10 << " y " << dias[i] / 10 << endl;
	}
}

CovidController::CovidController()
{
	horaInicio = 7;
	horaFin = 14;
	minInicio = 30;
	minFin = 30;
	tempMinima = 36.5f;
	tempMaxima = 37.5f;
	dias[0] = 12;
	dias[1] = 34;
	dias[2] = 56;
	dias[3] = 78;
	dias[4] = 90;

	resetear();
}

///implementar el resto de los requerimientos aqui.
