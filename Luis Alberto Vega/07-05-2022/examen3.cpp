/*
    1.	Inicializar Vectores
    2.	Ingresar Paso Vehicular
    3.	Consulta de vehículos 
    4.	Modificar Datos Vehículos 
    5.	Eliminar Paso de Vehículo
    6.	Submenú de Reportes
        1.	Todos los Movimientos Registrados
        2.	 Movimientos por número de placa
        3.	Movimientos por número de caseta
        4.	Movimientos por Tipo de Vehículo
        5.	Regresar al Menú Principal
    7.	Salir
*/
#include <iostream>
#include "./fechahora.cpp"

// Inicializar Vectores:  esta opción deberá “limpiar” los vectores (asignar los vectores numéricos con el valor cero).
void inicializar()
{
    system("cls");
    gotoxy(20,3); printf("Inicializar....");