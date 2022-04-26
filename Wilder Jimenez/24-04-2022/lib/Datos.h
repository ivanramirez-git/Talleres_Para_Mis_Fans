// Datos de la base de datos y manejador de archivos
// Language: C
// Path: 24-04-2022\lib\Datos.c

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Librerias
#include "./Cajeros.h"
#include "./Clientes.h"
#include "./Efectivo.h"
#include "./Retiros.h"

// Cargar Datos, carga los datos desde los archivos binarios
void CargarDatos()
{
    CargarCajeros();
    CargarClientes();
    CargarEfectivo();
    CargarRetiros();
}

// Guardar Datos, guarda los datos en los archivos binarios
void GuardarDatos()
{
    GuardarCajeros();
    GuardarClientes();
    GuardarEfectivo();
    GuardarRetiros();
}

// Controles de Retiros

/*
    Retiros

    Codigo cajero:
    <<Ubicacion, ciudad>>
    Num. cuenta cliente:
    <<Nombre cliente>>
    Fecha: xx/xx/xxxx
    Monto a retirar:
*/
void retirarRetiro()
{
    int codigoCajero;
    int numeroCuenta;
    char fechaRetiro[11];
    float montoRetiro;
    int X, Y;
    // Calcular fecha de hoy formato dd/mm/aaaa
    time_t t;
    struct tm *tm;
    char fechayhora[100];

    t = time(NULL);
    tm = localtime(&t);
    strftime(fechayhora, 100, "%d/%m/%Y", tm);

    strcpy(fechaRetiro, fechayhora);
    fechaRetiro[10] = '\0';

    printf("Hoy es: %s\n", fechayhora);

    /*
        Programa retiros: Proceso a realizar.
        a) Se escribe el numero de cajero y se busca en el archivo Cajeros, si no existe, se
        presenta un mensaje y se vuelve a leer; si existe, se toman la ubicacion y la
        ciudad y se les da salida (<<Ubicacion, Ciudad>>), tambien se toman las
        denominaciones, menor y mayor, para determinar en el paso d) la cantidad de
        billetes a retirar.
        b) Se lee el numero de cuenta del cliente y se busca en el archivo Clientes, si no
        existe, se presenta un mensaje y se vuelve a leer; si existe, se toman el nombre y
        el balance. Se presenta el nombre (<<Nombre>>).
        c) Se lee el monto a retirar. Si el monto es mayor que el balance leido del archivo
        Clientes ( paso b) ), se presenta el mensaje: “No dispone de fondos suficientes
        para esta cantidad”, y se vuelve a leer.
        d) Se determina la cantidad de billetes correspondientes al monto leido para
        actualizar el archivo Efectivo. Por ejemplo, si la denominacion menor del cajero
        es igual a 100, y la mayor es igual a 200, y el monto a retirar es igual a 500, se
        restan en el archivo Efectivo, dos billetes de 200 y uno de 100.
        e) El valor del monto debe corresponder con las denominaciones del cajero, por
        ejemplo, un monto de 700 no es valido para un cajero con denominaciones de
        500 y 1000.
        f) Se resta al balance del cliente el monto retirado, en el archivo Clientes.
        g) Se presenta el mensaje: “Transaccion exitosa”.
        h) Se regresa al menu retiros.
    */
    printf("\nRetiro\n");
    char paso = 'a';
    do
    {

        switch (paso)
        {
        case 'a':
            printf("\nIngrese el codigo del cajero: ");
            scanf("%d", &codigoCajero);
            if (BuscarCajero(codigoCajero) == -1)
            {
                printf("\nEl codigo del cajero no existe\n");
                printf("\n");
                paso = 'a';
            }
            else
            {
                // Ubicacion y Ciudad
                printf("\n");
                printf("\n%s, %s", cajeros[BuscarCajero(codigoCajero)].ubicacion, cajeros[BuscarCajero(codigoCajero)].ciudad);
                paso = 'b';
            }
            break;
        case 'b':
            printf("\nIngrese el numero de cuenta del cliente: ");
            scanf("%d", &numeroCuenta);
            if (BuscarCliente(numeroCuenta) == -1)
            {
                printf("\nEl numero de cuenta del cliente no existe\n");
                printf("\n");
                paso = 'b';
            }
            else
            {
                // Nombre
                printf("\n");
                printf("\n%s", clientes[BuscarCliente(numeroCuenta)].nombreCliente);
                paso = 'c';
            }
            break;
        case 'c':
            printf("\nIngrese el monto a retirar: ");
            scanf("%f", &montoRetiro);
            if (montoRetiro > clientes[BuscarCliente(numeroCuenta)].balance)
            {
                printf("\nNo dispone de fondos suficientes para esta cantidad\n");
                printf("\n");
                paso = 'c';
            }
            else
            {
                paso = 'd';
            }
            break;
        case 'd':
            // Validar que el monto corresponda con las denominaciones del cajero
            // montoRetiro = (denominacionMayor * X) + (denominacionMenor * Y)

            X = montoRetiro / cajeros[BuscarCajero(codigoCajero)].denominacionMayor;
            if (montoRetiro > 0){
                montoRetiro = montoRetiro - (cajeros[BuscarCajero(codigoCajero)].denominacionMayor * X);
            }
            Y = montoRetiro / cajeros[BuscarCajero(codigoCajero)].denominacionMenor;
            if (montoRetiro > 0){
                montoRetiro = montoRetiro - (cajeros[BuscarCajero(codigoCajero)].denominacionMenor * Y);
            }
            if (montoRetiro > 0){
                printf("\nEl monto no corresponde con las denominaciones del cajero\n");
                printf("\n");
                paso = 'c';
            }
            else{
                montoRetiro = (cajeros[BuscarCajero(codigoCajero)].denominacionMayor * X) + (cajeros[BuscarCajero(codigoCajero)].denominacionMenor * Y);
                paso = 'e';
            }
            break;
        case 'e':
            // Actualizar el archivo Efectivo
            if (X > efectivo[BuscarEfectivo(codigoCajero)].cantidadDenominacionMayor || Y > efectivo[BuscarEfectivo(codigoCajero)].cantidadDenominacionMenor)
            {
                printf("\nNo hay suficientes billetes para realizar el retiro\n");
                printf("\n");
                paso = 'c';
            }
            else
            {
                efectivo[BuscarEfectivo(codigoCajero)].cantidadDenominacionMayor = efectivo[BuscarEfectivo(codigoCajero)].cantidadDenominacionMayor - X;
                efectivo[BuscarEfectivo(codigoCajero)].cantidadDenominacionMenor = efectivo[BuscarEfectivo(codigoCajero)].cantidadDenominacionMenor - Y;
            }
            // Imprimir X, Y
            printf("\n");
            printf("\nSe entregaron %d billetes de %d y %d billetes de %d\n", X, cajeros[BuscarCajero(codigoCajero)].denominacionMayor, Y, cajeros[BuscarCajero(codigoCajero)].denominacionMenor);
            paso = 'f';
            break;
        case 'f':
            // Restar al balance del cliente el monto retirado            
            printf("\nBalance: %.2f\n", clientes[BuscarCliente(numeroCuenta)].balance);
            clientes[BuscarCliente(numeroCuenta)].balance -= 0.0 + montoRetiro;
            printf("\nRetiro: %0.2f\n", montoRetiro);
            printf("\nBalance Final: %.2f\n", clientes[BuscarCliente(numeroCuenta)].balance);
            paso = 'g';
            break;
        case 'g':
            // Registrar retiro en el archivo Retiros
            printf("\n");
            retiros[numeroRetiros].codigoCajero = codigoCajero;
            retiros[numeroRetiros].numeroCuenta = numeroCuenta;
            retiros[numeroRetiros].montoRetiro = montoRetiro;
            strcpy(retiros[numeroRetiros].fechaRetiro, fechaRetiro);

            printf("\nTransaccion exitosa\n");
            paso = 'h';
            break;
        case 'h':
            break;
        default:
            break;
        }
    } while (paso != 'h');
}

/*
Consulta Retiros

Numero cuenta:
Nombre: <<Nombre cliente>>
Balance: <<Balance>>
Fecha Monto
xx/xx/xxxx xxxx.xx
xx/xx/xxxx xxxx.xx
… …
*/
void consultarRetiro()
{

    int numeroCuenta;
    int i;

    /*
    Consulta de retiros: Presenta los retiros realizados por un cliente. Proceso a
    realizar:

    a) Se lee el numero de cuenta del cliente y se busca en el archivo Clientes. Si no
    existe, se presenta un mensaje y se vuelve a leer; si existe, se toman el nombre y
    el balance, y se les da salida (<<Nombre cliente>> y <<Balance>>).
    b) Se lee el archivo Retiros y se presentan la fecha y el monto correspondientes a
    los retiros realizados con el numero de cuenta leido.
    c) Regresar al menu Retiros.
    */
    printf("\nConsulta Retiros\n");
    char paso = 'a';
    do
    {

        switch (paso)
        {
        case 'a':
            printf("\nIngrese el numero de cuenta del cliente: ");
            scanf("%d", &numeroCuenta);
            if (BuscarCliente(numeroCuenta) == -1)
            {
                printf("\nEl numero de cuenta del cliente no existe\n");
                printf("\n");
                paso = 'a';
            }
            else
            {
                // Nombre
                printf("\n");
                printf("\nNombre: %s", clientes[BuscarCliente(numeroCuenta)].nombreCliente);
                // Balance
                printf("\nBalance: %.2f", clientes[BuscarCliente(numeroCuenta)].balance);
                paso = 'b';
            }
            break;
        case 'b':
            // Buscar en el archivo Retiros
            if (BuscarRetiro(numeroCuenta) == -1)
            {
                printf("\nEl cliente no ha realizado retiros\n");
                printf("\n");
                paso = 'b';
            }
            else
            {
                // Mostrar los retiros
                printf("\n");
                printf("\nFecha\tMonto\n");
                for (i = 0; i < numeroRetiros; i++)
                {
                    if (retiros[i].numeroCuenta == numeroCuenta)
                    {
                        printf("%s\t%.2f\n", retiros[i].fechaRetiro, retiros[i].montoRetiro);
                    }
                }
                paso = 'c';
            }
            paso = 'c';
            break;
        case 'c':
            break;
        default:
            break;
        }
    } while (paso != 'c');
}

// Controles de Efectivo
/*
    Actualizar Efectivo

    Codigo cajero:
    Denominacion: <<menor>>
    Cantidad
    Denominacion: <<mayor>>
    Cantidad
*/
void actualizarEfectivo()
{
    int codigoCajero;
    int cantidadDenominacionMenor;
    int cantidadDenominacionMayor;
    /*
        Programa actualizar efectivo: Registra la cantidad de billetes que contiene el
        cajero, de cada denominacion indicada en el archivo Cajeros
        Se debe validar el numero de cajero indicado, es decir, este numero debe existir en
        el archivo Cajeros. Se debe realizar una busqueda para verificar que existe.
        Si no existe el numero de cajero, se presenta un mensaje indicando esta situacion, y
        se vuelve a leer; si existe, se toman las denominaciones, menor y mayor para darles
        salida (ver <<menor>> y <<mayor>> en programa).
        10. Las fechas deben leerse con el formato: dd/mm/aaaa; deben definirse con el tipo
        caracter. Ejemplo: 31/12/2021.
    */
    printf("\nActualizar Efectivo\n");
    char paso = 'a';
    do
    {
        switch (paso)
        {
        case 'a':
            printf("\nIngrese el codigo del cajero: ");
            scanf("%d", &codigoCajero);
            if (BuscarCajero(codigoCajero) == -1)
            {
                printf("\nEl codigo del cajero no existe\n");
                printf("\n");
                paso = 'a';
            }
            else
            {
                paso = 'b';
            }
            break;
        case 'b':
            if (BuscarEfectivo(codigoCajero) == -1)
            {
                efectivo[numeroEfectivo].codigoCajero = codigoCajero;
                numeroEfectivo++;
            }
            else
            {
                printf("\nLa cantidad de billetes del cajero actualmente es:\n");
                printf("\nCanidad de billetes menor: %d", efectivo[BuscarEfectivo(codigoCajero)].cantidadDenominacionMenor);
                printf("\nCanidad de billetes mayor: %d", efectivo[BuscarEfectivo(codigoCajero)].cantidadDenominacionMayor);
                printf("\n");
            }

            printf("\nIngrese la cantidad de denominacion menor: ");
            scanf("%d", &cantidadDenominacionMenor);
            printf("\nIngrese la cantidad de denominacion mayor: ");
            scanf("%d", &cantidadDenominacionMayor);
            paso = 'c';

            break;
        case 'c':

            efectivo[BuscarEfectivo(codigoCajero)].cantidadDenominacionMenor = cantidadDenominacionMenor;
            efectivo[BuscarEfectivo(codigoCajero)].cantidadDenominacionMayor = cantidadDenominacionMayor;
            efectivo[BuscarEfectivo(codigoCajero)].codigoCajero = codigoCajero;

            paso = 'd';
            break;
        case 'd':
            printf("\n");
            break;
        default:
            break;
        }
    } while (paso != 'd');
}

/*
Consulta Efectivo

Cod. caj. Cant. den. men. Cant. den. may.
 xxxx xxxx xxxx
 xxxx xxxx xxxx
 … … …
*/
void consultaEfectivo()
{
    // Imprimir Encabezados
    printf("Cod. caja.\tCant. den. men.\tCant. den. may");
    int i = 0;
    for (i = 0; i < numeroEfectivo; i++)
    {
        printf("\n%d\t%d\t%d", efectivo[i].codigoCajero, efectivo[i].cantidadDenominacionMenor, efectivo[i].cantidadDenominacionMayor);
    }
}

// Controles de Clientes

/*
    Actualizar Clientes

    Codigo cliente:
    Nombre cliente:
    Numero cuenta:
    Balance:
*/
void actualizarCliente()
{
    int codigoCliente;
    char nombreCliente[25];
    int numeroCuenta;
    float balance;
    /*
         Si el codigo existe, se modifica el registro, si no existe, se crea o
        agrega un registro nuevo. El numero de cuenta debe ser mayor que cero y unico en
        el archivo.
    */
    printf("\nActualizar Cliente\n");
    char paso = 'a';
    do
    {
        switch (paso)
        {
        case 'a':
            printf("\nIngrese el codigo del cliente: ");
            scanf("%d", &codigoCliente);
            if (BuscarClienteCodigo(codigoCliente) == -1)
            {
                printf("\nEl codigo del cliente no existe\n");
                printf("\n");
                paso = 'b';
            }
            else
            {
                paso = 'c';
            }
            break;
        case 'b':
            // Nuevo registro
            printf("\nIngrese el nombre del cliente: ");
            scanf("%s", &nombreCliente);
            printf("\nIngrese el numero de cuenta: ");
            scanf("%d", &numeroCuenta);
            printf("\nIngrese el balance: ");
            scanf("%f", &balance);
            // Validar que el numero de cuenta sea unico
            if (BuscarCliente(numeroCuenta) == -1)
            {
                // Agregar el registro
                clientes[numeroClientes].codigoCliente = codigoCliente;
                strcpy(clientes[numeroClientes].nombreCliente, nombreCliente);
                clientes[numeroClientes].numeroCuenta = numeroCuenta;
                clientes[numeroClientes].balance = balance;
                numeroClientes++;
                paso = 'd';
            }
            else
            {
                printf("\nEl numero de cuenta ya existe\n");
                printf("\n");
                paso = 'b';
            }
            break;
        case 'c':
            // Actualizar el registro
            printf("\nIngrese el nombre del cliente: ");
            scanf("%s", &nombreCliente);
            printf("\nIngrese el numero de cuenta: ");
            scanf("%d", &numeroCuenta);
            printf("\nIngrese el balance: ");
            scanf("%f", &balance);

            // Actualizar el registro
            strcpy(clientes[BuscarClienteCodigo(codigoCliente)].nombreCliente, nombreCliente);
            clientes[BuscarClienteCodigo(codigoCliente)].numeroCuenta = numeroCuenta;
            clientes[BuscarClienteCodigo(codigoCliente)].balance = balance;

            paso = 'd';
            break;
        case 'd':
            break;
        default:
            break;
        }
    } while (paso != 'd');
}

/*
Consulta Clientes

Codigo Nombre Cuenta Balance
 xxxx xxxxxxxx xxxxxxx xxxx.xx
 xxxx xxxxxxxx xxxxxxxx xxxx.xx
 … … … …
*/
void consultarCliente()
{
    // Imprimir Encabezados
    printf("Codigo\tNombre\tNumero Cuenta\tBalance");
    int i = 0;
    for (i = 0; i < numeroClientes; i++)
    {
        printf("\n%d\t%s\t%d\t%.2f", clientes[i].codigoCliente, clientes[i].nombreCliente, clientes[i].numeroCuenta, clientes[i].balance);
    }
}

// Controles de Cajeros

/*
    Actualizar Cajeros

    Codigo cajero:
    Ubicacion:
    Ciudad:
    Denominacion menor:
    Denominacion mayor:
*/
void actualizarCajero()
{
    int codigoCajero;
    char ubicacion[20];
    char ciudad[20];
    int denominacionMenor;
    int denominacionMayor;
    /*
        Si el codigo existe, se modifica el registro, si no existe, se crea
        o agrega un registro nuevo. El valor de las denominaciones debe ser: 100, 200,
        500, 1000, de lo contrario, se deben volver a leer.
    */
    printf("\nActualizar Cajero\n");
    char paso = 'a';
    do
    {
        switch (paso)
        {
        case 'a':
            printf("\nIngrese el codigo del cajero: ");
            scanf("%d", &codigoCajero);
            if (BuscarCajero(codigoCajero) == -1)
            {
                printf("\nEl codigo del cajero no existe\n");
                printf("\n");
                paso = 'b';
            }
            else
            {
                paso = 'c';
            }
            break;
        case 'b':
            // Nuevo registro
            printf("\nIngrese la ubicacion del cajero: ");
            scanf("%s", &ubicacion);
            printf("\nIngrese la ciudad del cajero: ");
            scanf("%s", &ciudad);
            printf("\nIngrese la denominacion menor: ");
            scanf("%d", &denominacionMenor);
            printf("\nIngrese la denominacion mayor: ");
            scanf("%d", &denominacionMayor);
            // Validar que las denominaciones sean correctas
            if (denominacionMenor < denominacionMayor)
            {
                // Agregar el registro
                cajeros[numeroCajeros].codigoCajero = codigoCajero;
                strcpy(cajeros[numeroCajeros].ubicacion, ubicacion);
                strcpy(cajeros[numeroCajeros].ciudad, ciudad);
                cajeros[numeroCajeros].denominacionMenor = denominacionMenor;
                cajeros[numeroCajeros].denominacionMayor = denominacionMayor;
                numeroCajeros++;
                paso = 'd';
            }
            else
            {
                printf("\nLas denominaciones no son correctas\n");
                printf("\n");
                paso = 'c';
            }
            break;
        case 'c':
            // Actualizar el registro
            printf("\nIngrese la ubicacion del cajero: ");
            scanf("%s", &ubicacion);
            printf("\nIngrese la ciudad del cajero: ");
            scanf("%s", &ciudad);
            printf("\nIngrese la denominacion menor: ");
            scanf("%d", &denominacionMenor);
            printf("\nIngrese la denominacion mayor: ");
            scanf("%d", &denominacionMayor);

            // Actualizar el registro
            strcpy(cajeros[BuscarCajero(codigoCajero)].ubicacion, ubicacion);
            strcpy(cajeros[BuscarCajero(codigoCajero)].ciudad, ciudad);
            cajeros[BuscarCajero(codigoCajero)].denominacionMenor = denominacionMenor;
            cajeros[BuscarCajero(codigoCajero)].denominacionMayor = denominacionMayor;

            paso = 'd';
            break;
        case 'd':
            break;
        default:
            break;
        }
    } while (paso != 'd');
}

/*
Consulta Cajeros

Codigo Ubicacion Ciudad Denominaciones
 xxxx xxxxxxxxx xxxxxx xxx xxx
 xxxx xxxxxxxxx xxxxxx xxx xxx
 … … … … …
*/
void consultarCajero()
{
    // Imprimir Encabezados
    printf("Codigo\tUbicacion\tCiudad\tDenominaciones");
    int i = 0;
    for (i = 0; i < numeroCajeros; i++)
    {
        printf("\n%d\t%s\t%s\t%d\t%d", cajeros[i].codigoCajero, cajeros[i].ubicacion, cajeros[i].ciudad, cajeros[i].denominacionMenor, cajeros[i].denominacionMayor);
    }
}
