#include <iostream>
#include "./lib/fechahora.cpp"
#include "./lib/biblioteca.h"

// Datos
int numerosFactura[15];    // Autogerado por el sistema
char numeroPlaca[15][15];  // Numero de placa, se le pide al usuario
char fechaActual[15][15];  // Fecha actual, desde la funcion darFechaActual
char horaActual[15][15];   // Hora actual, desde la funcion darHoraActual
int tipoVehiculo[15];      // 1= Moto ,2= Vehiculo Liviano, 3 =Camion o Pesado, 4=Autobus
int numeroCaseta[15];      // 1,2,3
double montoPagar[15];     // Ver tabla de precios, este valor lo asigna el sistema segun el tipo de vehiculo
double pagaCon[15];        // Debe validar que el monto con el que paga sea igual o mayor al monto a pagar si es menor debe repetir el ingreso de este capo
double vuelto[15];         // Monto a pagar – paga con
int numeroDeRegistros; // Numero de registros de la planilla

// Inicializar Vectores:  esta opcion debera “limpiar” los vectores (asignar los vectores numericos con el valor cero).
void inicializarVectores()
{
    for (int i = 0; i < 15; i++)
    {
        numerosFactura[i] = 0;
        strcpy(numeroPlaca[i], "");
        strcpy(fechaActual[i], "");
        strcpy(horaActual[i], "");
        tipoVehiculo[i] = 0;
        numeroCaseta[i] = 0;
        montoPagar[i] = 0;
        pagaCon[i] = 0;
        vuelto[i] = 0;
    }
    numeroDeRegistros = 0;
}

/*
Para el pago debe tomar el valor de la siguiente tabla de precios:

Vehiculo liviano paga	¢700
Camion o Pesado paga	¢2700
Motocicleta paga	    ¢500
Autobus paga	        ¢3700
*/
double calcularMontoPagar(int tipoVehiculo)
{
    double montoPagar;
    switch (tipoVehiculo)
    {
    case 1:
        montoPagar = 700;
        break;
    case 2:
        montoPagar = 2700;
        break;
    case 3:
        montoPagar = 3700;
        break;
    case 4:
        montoPagar = 3700;
        break;
    default:
        montoPagar = 0;
        break;
    }
    return montoPagar;
}

// Ingresar Datos: la informacion debera guardarse en vectores.  Los datos que se deben leer son los siguientes: numero factura (auto numerico debera ser asignado por el sistema), numero de placa, fecha actual, hora actual, tipo de vehiculo (1= Moto ,2= Vehiculo Liviano, 3 =Camion o Pesado, 4=Autobus), numero de caseta (1,2,3), monto a pagar (ver tabla de precios, este valor lo asigna el sistema segun el tipo de vehiculo), paga con (debe validar que el monto con el que paga sea igual o mayor al monto a pagar si es menor debe repetir el ingreso de este capo) y vuelto (monto a pagar – paga con).  Debe controlar que el procedimiento no ingrese mas datos de los que permite el vector.
void ingresarPasoVehicular()
{
    /*
    Ejemplo:				REGISTRAR FLUJO VEHICULAR

    Numero Factura;
    Numero PLACA:
    Fecha actual:
    Hora actual:
            Tipo de vehiculo:   1
            [1= Moto	2= Vehiculo Liviano          3=Camion o Pesado		4=Autobus]

            Numero caseta
            [1= caseta 1  	2=caseta 2    	                3=caseta 3]

            Monto a pagar:
            Paga con:
            Vuelto:

    Desea continuar S/N?

    */
    system("cls");
    system("color 0F");

    // Titulo
    gotoxy(10, 5);
    printf("REGISTRAR FLUJO VEHICULAR");
    // Numero Factura
    gotoxy(10, 7);
    numerosFactura[numeroDeRegistros] = numeroDeRegistros;
    printf("Numero Factura: %d", numerosFactura[numeroDeRegistros]);
    // Numero de placa
    do
    {
        gotoxy(10, 9);
        printf("Numero PLACA: ");
        scanf("%s", numeroPlaca[numeroDeRegistros]);
    } while (strlen(numeroPlaca[numeroDeRegistros]) < 3);
    // Fecha actual
    gotoxy(10, 11);
    strcpy(fechaActual[numeroDeRegistros], darFechaActual());
    printf("Fecha actual: %s", fechaActual[numeroDeRegistros]);
    // Hora actual
    gotoxy(10, 13);
    strcpy(horaActual[numeroDeRegistros], darHoraActual());
    printf("Hora actual: %s", horaActual[numeroDeRegistros]);
    // Tipo de vehiculo
    gotoxy(10, 16);
    printf("[1= Moto	2= Vehiculo Liviano          3=Camion o Pesado		4=Autobus]");
    do
    {
        gotoxy(10, 15);
        printf("Tipo de vehiculo: ");
        scanf("%d", &tipoVehiculo[numeroDeRegistros]);
    } while (tipoVehiculo[numeroDeRegistros] < 1 || tipoVehiculo[numeroDeRegistros] > 4);
    // Numero de caseta
    gotoxy(10, 19);
    printf("[1= caseta 1  	2=caseta 2  	3=caseta 3]");
    do
    {
        gotoxy(10, 18);
        printf("Numero caseta: ");
        scanf("%d", &numeroCaseta[numeroDeRegistros]);
    } while (numeroCaseta[numeroDeRegistros] < 1 || numeroCaseta[numeroDeRegistros] > 3);
    // Monto a pagar
    gotoxy(10, 21);
    montoPagar[numeroDeRegistros] = calcularMontoPagar(tipoVehiculo[numeroDeRegistros]);
    printf("Monto a pagar: %.2f", montoPagar[numeroDeRegistros]);
    // Paga con
    do
    {
        gotoxy(10, 23);
        printf("Paga con: ");
        scanf("%lf", &pagaCon[numeroDeRegistros]);
    } while (pagaCon[numeroDeRegistros] < montoPagar[numeroDeRegistros]);
    // Vuelto
    gotoxy(10, 25);
    vuelto[numeroDeRegistros] = pagaCon[numeroDeRegistros] - montoPagar[numeroDeRegistros];
    printf("Vuelto: %.2f", vuelto[numeroDeRegistros]);
    // Desea continuar
    gotoxy(10, 27);
    printf("Desea continuar S/N? ");
    char deseaContinuar;
    scanf("%s", &deseaContinuar);
    if (deseaContinuar == 'S' || deseaContinuar == 's')
    {
        // Incrementar el numero de registros
        numeroDeRegistros++;
        // Llamar a la funcion de ingresar paso vehicular
        ingresarPasoVehicular();
    }
    else
    {
        // Incrementar el numero de registros
        numeroDeRegistros++;
    }
}

// En la opcion de consulta de vehiculos, debera consultar los datos segun numero de factura, mostrar todos los datos que se ingresaron y obtuvieron en el proceso de ingresar Paso Vehicular asociado a ese numero de factura.   Si el numero de factura no fue encontrado debera mostrar el mensaje: “Numero de Factura no Existe”.
void consultarDeVehiculos()
{
    system("cls");
    system("color 0F");

    // Titulo
    gotoxy(10, 5);
    printf("CONSULTAR VEHICULOS");
    // Numero de factura
    gotoxy(10, 7);
    printf("Numero de factura: ");
    int numeroFactura;
    scanf("%d", &numeroFactura);
    // Buscar el numero de factura
    int i;
    for (i = 0; i < numeroDeRegistros; i++)
    {
        if (numerosFactura[i] == numeroFactura)
        {
            // Mostrar los datos
            gotoxy(10, 9);
            printf("Numero Factura: %d", numerosFactura[i]);
            gotoxy(10, 11);
            printf("Numero PLACA: %s", numeroPlaca[i]);
            gotoxy(10, 13);
            printf("Fecha actual: %s", fechaActual[i]);
            gotoxy(10, 15);
            printf("Hora actual: %s", horaActual[i]);
            gotoxy(10, 17);
            printf("Tipo de vehiculo: %d", tipoVehiculo[i]);
            gotoxy(10, 19);
            printf("Numero caseta: %d", numeroCaseta[i]);
            gotoxy(10, 21);
            printf("Monto a pagar: %.2f", montoPagar[i]);
            gotoxy(10, 23);
            printf("Paga con: %.2f", pagaCon[i]);
            gotoxy(10, 25);
            printf("Vuelto: %.2f", vuelto[i]);
            // Pausa
            gotoxy(10, 27);
            printf("Presione una tecla para continuar...");
            getch();
            return;
        }
    }
    // Mensaje de error
    gotoxy(10, 9);
    printf("Numero Factura no existe");
    // Pausa
    gotoxy(10, 11);
    printf("Presione una tecla para continuar...");
    getch();
}

// En la opcion de modificar, debe primero realizar una consulta por numero de factura, luego, mostrar todos los datos que se ingresaron y obtuvieron en el proceso de ingresar Paso Vehicular asociado a ese numero de factura.  Realizar un menu de opciones con los datos mostrados, para que el usuario pueda seleccionar cual dato quiere modificar.  (recordar no todos los datos se pueden modificar y al modificar algunos datos debera recalcular los procesos).  Si el numero de factura no fue encontrado debera mostrar el mensaje: “Numero de Factura no Existe”.
void modificarDatosVehiculos()
{
    system("cls");
    system("color 0F");

    // Titulo
    gotoxy(10, 5);
    printf("MODIFICAR DATOS VEHICULOS");
    // Numero de factura
    gotoxy(10, 7);
    printf("Numero de factura: ");
    int numero;
    scanf("%d", &numero);
    // Buscar el numero de factura
    int i;
    for (i = 0; i < numeroDeRegistros; i++)
    {
        if (numerosFactura[i] == numero)
        {
            // Mostrar los datos
            gotoxy(10, 9);
            printf("Numero Factura: %d", numerosFactura[i]);
            gotoxy(10, 11);
            printf("1. Numero PLACA: %s", numeroPlaca[i]);
            gotoxy(10, 13);
            printf("2. Fecha actual: %s", fechaActual[i]);
            gotoxy(10, 15);
            printf("3. Hora actual: %s", horaActual[i]);
            gotoxy(10, 17);
            printf("4. Tipo de vehiculo: %d", tipoVehiculo[i]);
            gotoxy(10, 19);
            printf("5. Numero caseta: %d", numeroCaseta[i]);
            gotoxy(10, 21);
            printf("Monto a pagar: %.2f", montoPagar[i]);
            gotoxy(10, 23);
            printf("Paga con: %.2f", pagaCon[i]);
            gotoxy(10, 25);
            printf("Vuelto: %.2f", vuelto[i]);
            // Pedir opcion
            gotoxy(10, 27);
            printf("Seleccione una opcion: ");
            int opcion;
            scanf("%d", &opcion);
            // Modificar datos
            switch (opcion)
            {
            case 1:
                // Numero de placa
                do
                {
                    gotoxy(10, 29);
                    printf("Numero PLACA: ");
                    scanf("%s", numeroPlaca[numero]);
                } while (strlen(numeroPlaca[numero]) < 3);
                break;
            case 2:
                // Fecha actual
                gotoxy(10, 29);
                strcpy(fechaActual[numero], darFechaActual());
                printf("Fecha actual: %s", fechaActual[numero]);
                break;
            case 3:
                // Hora actual
                gotoxy(10, 29);
                strcpy(horaActual[numero], darHoraActual());
                printf("Hora actual: %s", horaActual[numero]);
                break;
            case 4:
                // Tipo de vehiculo
                gotoxy(10, 30);
                printf("[1= Moto	2= Vehiculo Liviano          3=Camion o Pesado		4=Autobus]");
                do
                {
                    gotoxy(10, 29);
                    printf("Tipo de vehiculo: ");
                    scanf("%d", &tipoVehiculo[numero]);
                } while (tipoVehiculo[numero] < 1 || tipoVehiculo[numero] > 4);
                // Monto a pagar
                gotoxy(10, 32);
                montoPagar[numero] = calcularMontoPagar(tipoVehiculo[numero]);
                printf("Monto a pagar: %.2f", montoPagar[numero]);
                // Paga con
                do
                {
                    gotoxy(10, 34);
                    printf("Paga con: ");
                    scanf("%lf", &pagaCon[numero]);
                } while (pagaCon[numero] < montoPagar[numero]);
                // Vuelto
                gotoxy(10, 36);
                vuelto[numero] = pagaCon[numero] - montoPagar[numero];
                printf("Vuelto: %.2f", vuelto[numero]);
                break;
            case 5:
                // Numero de caseta
                gotoxy(10, 30);
                printf("[1= caseta 1  	2=caseta 2  	3=caseta 3]");
                do
                {
                    gotoxy(10, 29);
                    printf("Numero caseta: ");
                    scanf("%d", &numeroCaseta[numero]);
                } while (numeroCaseta[numero] < 1 || numeroCaseta[numero] > 3);
                break;
            default:
                break;
            }
            // Pausa
            gotoxy(10, 38);
            printf("Presione una tecla para continuar...");
            getch();
            return;
        }
    }
    // Numero de factura no existe
    gotoxy(10, 9);
    printf("Numero de factura no existe");
    // Pausa
    printf("Presione una tecla para continuar...");
    getch();
}

// En la opcion de eliminar, debe primero realizar una consulta por numero de factura, luego, mostrar todos los datos que se ingresaron y obtuvieron en el proceso de ingresar Paso Vehicular asociado a ese numero de factura.  Solicitar la confirmacion para la eliminacion del dato, si la confirmacion es afirmativa proceder con el proceso de eliminar de forma logica el dato, si la confirmacion no es afirmativa enviar el mensaje: “El dato no sera eliminado”.   Finalmente, si el numero de factura no fue encontrado debera mostrar el mensaje: “Numero de Factura no Existe”.
void eliminarPasoDeVehicular()
{
    system("cls");
    system("color 0F");

    // Titulo
    gotoxy(10, 5);
    printf("ELIMINAR PASO DE VEHICULO");

    // Pedir numero de factura
    gotoxy(10, 7);
    printf("Numero de factura: ");
    int numero;
    scanf("%d", &numero);

    // Buscar numero de factura
    int i;
    for (i = 0; i < numeroDeRegistros; i++)
    {
        if (numerosFactura[i] == numero)
        {
            // Mostrar datos
            // Numero de factura
            gotoxy(10, 9);
            printf("Numero de factura: %d", numerosFactura[i]);
            // Numero de placa
            gotoxy(10, 11);
            printf("Numero de placa: %s", numeroPlaca[i]);
            // Fecha actual
            gotoxy(10, 13);
            printf("Fecha actual: %s", fechaActual[i]);
            // Hora actual
            gotoxy(10, 15);
            printf("Hora actual: %s", horaActual[i]);
            // Tipo de vehiculo
            gotoxy(10, 17);
            printf("Tipo de vehiculo: %d", tipoVehiculo[i]);
            // Numero de caseta
            gotoxy(10, 19);
            printf("Numero de caseta: %d", numeroCaseta[i]);
            // Monto a pagar
            gotoxy(10, 21);
            printf("Monto a pagar: %.2f", montoPagar[i]);
            // Paga con
            gotoxy(10, 23);
            printf("Paga con: %.2f", pagaCon[i]);
            // Vuelto
            gotoxy(10, 25);
            printf("Vuelto: %.2f", vuelto[i]);
            // Confirmar eliminacion
            gotoxy(10, 27);
            printf("Confirmar eliminacion? (s/n): ");
            char confirmacion;
            scanf("%s", &confirmacion);
            if (confirmacion == 's' || confirmacion == 'S')
            {
                // Eliminar dato, mover datos hacia la izquierda
                for (i = numero; i < numeroDeRegistros; i++)
                {
                    numerosFactura[i] = numerosFactura[i + 1];
                    strcpy(numeroPlaca[i], numeroPlaca[i + 1]);
                    strcpy(fechaActual[i], fechaActual[i + 1]);
                    strcpy(horaActual[i], horaActual[i + 1]);
                    tipoVehiculo[i] = tipoVehiculo[i + 1];
                    numeroCaseta[i] = numeroCaseta[i + 1];
                    montoPagar[i] = montoPagar[i + 1];
                    pagaCon[i] = pagaCon[i + 1];
                    vuelto[i] = vuelto[i + 1];
                }
                // Disminuir numero de registros
                numeroDeRegistros--;
                gotoxy(10, 29);
                printf("Dato eliminado");
                // Pausa
                printf("Presione una tecla para continuar...");
                getch();
            }
            else
            {
                gotoxy(10, 29);
                printf("El dato no sera eliminado");
                // Pausa
                printf("Presione una tecla para continuar...");
                getch();
            }
            return;
        }
    }
    // Numero de factura no existe
    gotoxy(10, 9);
    printf("Numero de factura no existe");
    // Pausa
    printf("Presione una tecla para continuar...");
    getch();
}

// Reporte todos los movimientos registrados: debe mostrar todos los datos guardados en los vectores.
void todosLosMovimientosRegistrados()
{
    system("cls");
    system("color 0F");
    /*
    Ejemplo:
                                      *** Reporte de todos los Movimientos Registrados ***

    N. Factura      Placa       Tipo Vehiculo       Caseta       Fecha/Hora      Monto         Paga        Vuelto
    =============================================================================


    =============================================================================
    Total de Vehiculos:                                                         Total Monto:
    =============================================================================
                                    *** Pulse tecla para regresar al menu de reportes ***


    */
    // Titulo
    gotoxy(10, 5);
    printf("REPORTE DE TODOS LOS MOVIMIENTOS REGISTRADOS");
    // Cabecera
    gotoxy(10, 7);
    printf("N. Factura");
    gotoxy(25, 7);
    printf("Placa");
    gotoxy(40, 7);
    printf("Tipo Vehiculo");
    gotoxy(55, 7);
    printf("Caseta");
    gotoxy(70, 7);
    printf("Fecha/Hora");
    gotoxy(100, 7);
    printf("Monto");
    gotoxy(115, 7);
    printf("Paga");
    gotoxy(130, 7);
    printf("Vuelto");
    gotoxy(10, 8);
    printf("=============================================================================");
    // Datos
    int i;
    int posicion = 9;
    double totalMonto = 0;
    for (i = 0; i < numeroDeRegistros; i++)
    {
        gotoxy(10, posicion);
        printf("%d", numerosFactura[i]);
        gotoxy(25, posicion);
        printf("%s", numeroPlaca[i]);
        gotoxy(40, posicion);
        printf("%d", tipoVehiculo[i]);
        gotoxy(55, posicion);
        printf("%d", numeroCaseta[i]);
        gotoxy(70, posicion);
        printf("%s", fechaActual[i]);
        gotoxy(85, posicion);
        printf("%s", horaActual[i]);
        gotoxy(100, posicion);
        printf("%.2f", montoPagar[i]);
        gotoxy(115, posicion);
        printf("%.2f", pagaCon[i]);
        gotoxy(130, posicion);
        printf("%.2f", vuelto[i]);
        posicion++;
        totalMonto += montoPagar[i];
    }
    // Total de vehiculos
    gotoxy(10, posicion);
    printf("=============================================================================");
    gotoxy(10, posicion + 1);
    printf("Total de Vehiculos: %d", numeroDeRegistros);
    // Total monto
    gotoxy(100, posicion + 1);
    printf("Total Monto: %.2f", totalMonto);
    gotoxy(10, posicion + 2);
    printf("=============================================================================");
    // Regresar al menu de reportes
    gotoxy(10, posicion + 5);
    printf("*** Pulse tecla para regresar al menu de reportes ***");
    getch();
}

// Reporte movimientos por numero de placa: debe mostrar todos los datos que se encuentre registrados a un numero de placa.  Antes de hacer el reporte debe solicitar el numero de placa que desea buscar la informacion y luego buscar y mostrar la informacion en los vectores de acuerdo al filtro seleccionado.
void movimientosPorNumeroDePlaca()
{

    /*
    Ejemplo:
                                      *** Reporte Movimientos por Numero de Placas ***

    N. Factura      Placa       Tipo Vehiculo       Caseta       Fecha/Hora      Monto         Paga        Vuelto
    =============================================================================


    =============================================================================
    Total de Vehiculos:                                                         Total Monto:
    =============================================================================
                                    *** Desea consultar movimientos de otra Placa S/N? ***

    */
    system("cls");
    system("color 0F");

    char numero[15];

    // Titulo
    gotoxy(10, 5);
    printf("REPORTE DE MOVIMIENTOS POR NuMERO DE PLACA");
    // Pedir numero de placa
    do
    {
        gotoxy(10, 7);
        printf("Ingrese el numero de placa: ");
        scanf("%s", numero);
    } while (strlen(numero) < 3);
    // Cabecera
    gotoxy(10, 9);
    printf("N. Factura");
    gotoxy(25, 9);
    printf("Placa");
    gotoxy(40, 9);
    printf("Tipo Vehiculo");
    gotoxy(55, 9);
    printf("Caseta");
    gotoxy(70, 9);
    printf("Fecha/Hora");
    gotoxy(100, 9);
    printf("Monto");
    gotoxy(115, 9);
    printf("Paga");
    gotoxy(130, 9);
    printf("Vuelto");
    gotoxy(10, 10);
    printf("=============================================================================");
    // Datos
    int i;
    int posicion = 11;
    double totalMonto = 0;
    int totalVehiculos = 0;
    for (i = 0; i < numeroDeRegistros; i++)
    {
        if (strcmp(numero, numeroPlaca[i]) == 0)
        {
            gotoxy(10, posicion);
            printf("%d", numerosFactura[i]);
            gotoxy(25, posicion);
            printf("%s", numeroPlaca[i]);
            gotoxy(40, posicion);
            printf("%d", tipoVehiculo[i]);
            gotoxy(55, posicion);
            printf("%d", numeroCaseta[i]);
            gotoxy(70, posicion);
            printf("%s", fechaActual[i]);
            gotoxy(85, posicion);
            printf("%s", horaActual[i]);
            gotoxy(100, posicion);
            printf("%.2f", montoPagar[i]);
            gotoxy(115, posicion);
            printf("%.2f", pagaCon[i]);
            gotoxy(130, posicion);
            printf("%.2f", vuelto[i]);
            posicion++;
            totalMonto += montoPagar[i];
            totalVehiculos++;
        }
    }
    // Total de vehiculos
    gotoxy(10, posicion);
    printf("=============================================================================");
    gotoxy(10, posicion + 1);
    printf("Total de Vehiculos: %d", totalVehiculos);
    gotoxy(100, posicion + 1);
    printf("Total Monto: %.2f", totalMonto);
    gotoxy(10, posicion + 2);
    printf("=============================================================================");
    // Preguntar si desea consultar otro numero de placa
    gotoxy(10, posicion + 5);
    printf("*** Desea consultar movimientos de otra Placa S/N? ***");
    char opcion;
    scanf("%s", &opcion);
    if (opcion == 'S' || opcion == 's')
    {
        movimientosPorNumeroDePlaca();
    }
}

// Reporte movimientos por Numero de Caseta: debe mostrar todos los datos que se encuentre registrados a una caseta (1,2,3).  Antes de hacer el reporte debe solicitar el numero de caseta (1, 2, 3) y luego buscar y mostrar la informacion en los vectores de acuerdo al filtro seleccionado.
void movimientosPorNumeroDeCaseta()
{
    /*
                                            *** Reporte Movimientos por Numero de Caseta ***

    N. Factura      Placa       Tipo Vehiculo       Caseta       Fecha/Hora      Monto         Paga        Vuelto
    =============================================================================


    =============================================================================
    Total de Vehiculos:                                                         Total Monto:
    =============================================================================
                                    *** Desea consultar movimientos de otra Caseta S/N? ***

    */
    system("cls");
    system("color 0F");

    int numero;
    // Titulo
    gotoxy(10, 5);
    printf("REPORTE DE MOVIMIENTOS POR NuMERO DE CASETA");
    // Pedir numero de caseta
    do
    {
        gotoxy(10, 7);
        printf("Ingrese el numero de caseta: ");
        scanf("%d", &numero);
    } while (numero < 1 || numero > 3);
    // Cabecera
    gotoxy(10, 9);
    printf("N. Factura");
    gotoxy(25, 9);
    printf("Placa");
    gotoxy(40, 9);
    printf("Tipo Vehiculo");
    gotoxy(55, 9);
    printf("Caseta");
    gotoxy(70, 9);
    printf("Fecha/Hora");
    gotoxy(100, 9);
    printf("Monto");
    gotoxy(115, 9);
    printf("Paga");
    gotoxy(130, 9);
    printf("Vuelto");
    gotoxy(10, 10);
    printf("=============================================================================");
    // Datos
    int i;
    int posicion = 11;
    double totalMonto = 0;
    int totalVehiculos = 0;
    for (i = 0; i < numeroDeRegistros; i++)
    {
        if (numero == numeroCaseta[i])
        {
            gotoxy(10, posicion);
            printf("%d", numerosFactura[i]);
            gotoxy(25, posicion);
            printf("%s", numeroPlaca[i]);
            gotoxy(40, posicion);
            printf("%d", tipoVehiculo[i]);
            gotoxy(55, posicion);
            printf("%d", numeroCaseta[i]);
            gotoxy(70, posicion);
            printf("%s", fechaActual[i]);
            gotoxy(85, posicion);
            printf("%s", horaActual[i]);
            gotoxy(100, posicion);
            printf("%.2f", montoPagar[i]);
            gotoxy(115, posicion);
            printf("%.2f", pagaCon[i]);
            gotoxy(130, posicion);
            printf("%.2f", vuelto[i]);
            posicion++;
            totalMonto += montoPagar[i];
            totalVehiculos++;
        }
    }
    // Total de vehiculos
    gotoxy(10, posicion);
    printf("=============================================================================");
    gotoxy(10, posicion + 1);
    printf("Total de Vehiculos: %d", totalVehiculos);
    gotoxy(100, posicion + 1);
    printf("Total Monto: %.2f", totalMonto);
    gotoxy(10, posicion + 2);
    printf("=============================================================================");
    // Preguntar si desea consultar otro numero de placa
    gotoxy(10, posicion + 5);
    printf("*** Desea consultar movimientos de otra Caseta S/N? ***");
    char opcion;
    scanf("%s", &opcion);
    if (opcion == 'S' || opcion == 's')
    {
        movimientosPorNumeroDeCaseta();
    }
}

// Reporte movimientos por Tipo de Vehiculo: debe mostrar todos los datos que se encuentre registrados a un tipo de vehiculo (1,2,3, 4).  Antes de hacer el reporte debe solicitar el tipo de vehiculo (1, 2, 3, 4) y luego buscar y mostrar la informacion en los vectores de acuerdo al filtro seleccionado.
void movimientosPorTipoDeVehiculo()
{
    /*
                                            *** Reporte Movimientos por Tipo de Vehiculo ***

    N. Factura      Placa       Tipo Vehiculo       Caseta       Fecha/Hora      Monto         Paga        Vuelto
    =============================================================================
    1	      111111	      1	                  2	1/12/2018 10:09    500	          2000         1500
    2	     222222	      1		   3	1/12/2018 10:50    500	          1000          300
    =============================================================================
    Total de Vehiculos:      2                                                   Total Monto:   1000
    =============================================================================
                                  *** Desea consultar movimientos de otro tipo de Vehiculo S/N? ***

    */
    system("cls");
    system("color 0F");

    int tipo;
    // Titulo
    gotoxy(10, 5);
    printf("REPORTE DE MOVIMIENTOS POR TIPO DE VEHiCULO");
    // Pedir tipo de vehiculo
    do
    {
        gotoxy(10, 7);
        printf("Ingrese el tipo de vehiculo: ");
        scanf("%d", &tipo);
    } while (tipo < 1 || tipo > 4);
    // Cabecera
    gotoxy(10, 9);
    printf("N. Factura");
    gotoxy(25, 9);
    printf("Placa");
    gotoxy(40, 9);
    printf("Tipo Vehiculo");
    gotoxy(55, 9);
    printf("Caseta");
    gotoxy(70, 9);
    printf("Fecha/Hora");
    gotoxy(100, 9);
    printf("Monto");
    gotoxy(115, 9);
    printf("Paga");
    gotoxy(130, 9);
    printf("Vuelto");
    gotoxy(10, 10);
    printf("=============================================================================");
    // Datos
    int i;
    int posicion = 11;
    double totalMonto = 0;
    int totalVehiculos = 0;
    for (i = 0; i < numeroDeRegistros; i++)
    {
        if (tipo == tipoVehiculo[i])
        {
            gotoxy(10, posicion);
            printf("%d", numerosFactura[i]);
            gotoxy(25, posicion);
            printf("%s", numeroPlaca[i]);
            gotoxy(40, posicion);
            printf("%d", tipoVehiculo[i]);
            gotoxy(55, posicion);
            printf("%d", numeroCaseta[i]);
            gotoxy(70, posicion);
            printf("%s", fechaActual[i]);
            gotoxy(85, posicion);
            printf("%s", horaActual[i]);
            gotoxy(100, posicion);
            printf("%.2f", montoPagar[i]);
            gotoxy(115, posicion);
            printf("%.2f", pagaCon[i]);
            gotoxy(130, posicion);
            printf("%.2f", vuelto[i]);
            posicion++;
            totalMonto += montoPagar[i];
            totalVehiculos++;
        }
    }
    // Total de vehiculos
    gotoxy(10, posicion);
    printf("=============================================================================");
    gotoxy(10, posicion + 1);
    printf("Total de Vehiculos: %d", totalVehiculos);
    gotoxy(100, posicion + 1);
    printf("Total Monto: %.2f", totalMonto);
    gotoxy(10, posicion + 2);
    printf("=============================================================================");
    // Preguntar si desea consultar otro numero de placa
    gotoxy(10, posicion + 5);
    printf("*** Desea consultar movimientos de otro tipo de Vehiculo S/N? ***");
    char opcion;
    scanf("%s", &opcion);
    if (opcion == 'S' || opcion == 's')
    {
        movimientosPorTipoDeVehiculo();
    }
}

/*
Menu Principal del Sistema:
1.	Inicializar Vectores
2.	Ingresar Paso Vehicular
3.	Consulta de vehiculos
4.	Modificar Datos Vehiculos
5.	Eliminar Paso de Vehiculo
6.	Submenu de Reportes
    1.	Todos los Movimientos Registrados
    2.	 Movimientos por numero de placa
    3.	Movimientos por numero de caseta
    4.	Movimientos por Tipo de Vehiculo
    5.	Regresar al Menu Principal
7.	Salir
*/
// Submenu de Reportes
void subMenuReportes()
{
    system("cls");
    system("color 0F");

    int opcion;
    // Titulo
    gotoxy(10, 5);
    printf("SUBMENu DE REPORTES");
    // Opciones
    gotoxy(10, 7);
    printf("1. Todos los Movimientos Registrados");
    gotoxy(10, 9);
    printf("2. Movimientos por numero de placa");
    gotoxy(10, 11);
    printf("3. Movimientos por numero de caseta");
    gotoxy(10, 13);
    printf("4. Movimientos por Tipo de Vehiculo");
    gotoxy(10, 15);
    printf("5. Regresar al Menu Principal");
    // Pedir opcion
    do
    {
        gotoxy(10, 17);
        printf("Ingrese la opcion: ");
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > 5);
    // Ejecutar opcion
    switch (opcion)
    {
    case 1:
        todosLosMovimientosRegistrados();
        break;
    case 2:
        movimientosPorNumeroDePlaca();
        break;
    case 3:
        movimientosPorNumeroDeCaseta();
        break;
    case 4:
        movimientosPorTipoDeVehiculo();
        break;
    case 5:
        return;
        break;
    }
    subMenuReportes();
}

// Menu Principal
void menuPrincipal()
{
    system("cls");
    system("color 0F");

    int opcion;
    // Titulo
    gotoxy(10, 5);
    printf("MENU PRINCIPAL");
    // Opciones
    gotoxy(10, 7);
    printf("1. Inicializar Vectores");
    gotoxy(10, 9);
    printf("2. Ingresar Paso Vehicular");
    gotoxy(10, 11);
    printf("3. Consulta de vehiculos");
    gotoxy(10, 13);
    printf("4. Modificar Datos Vehiculos");
    gotoxy(10, 15);
    printf("5. Eliminar Paso de Vehiculo");
    gotoxy(10, 17);
    printf("6. Submenu de Reportes");
    gotoxy(10, 19);
    printf("7. Salir");
    // Pedir opcion
    do
    {
        gotoxy(10, 21);
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > 7);
    // Ejecutar opcion
    switch (opcion)
    {
    case 1:
        inicializarVectores();
        break;
    case 2:
        ingresarPasoVehicular();
        break;
    case 3:
        consultarDeVehiculos();
        break;
    case 4:
        modificarDatosVehiculos();
        break;
    case 5:
        eliminarPasoDeVehicular();
        break;
    case 6:
        subMenuReportes();
        break;
    case 7:
        return;
        break;
    }
    // Volver al menu principal
    menuPrincipal();
}

// Main
int main()
{
    menuPrincipal();
    return 0;
}
