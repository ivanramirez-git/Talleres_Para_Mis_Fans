// Simulacion de Cajero Bancario

//Nombre: Wilder Jimenez / Matricula: 2-21-0179 /  Grupo: 003//

// Bibliotecas

// Librerias
#include "./lib/Datos.h"

// Menu General
void menuGeneral()
{
    /*
        1. Cajeros.
        2. Clientes.
        3. Efectivo.
        4. Retiros.
        5. Finalizar.

        Leer opcion:
    */
    printf("Bienvenido al cajero Bancario\n");
    int opcion;
    int opcionCajero;
    int opcionCliente;
    int opcionEfectivo;
    int opcionRetiro;
    do
    {
        printf("\n1. Cajeros\n");
        printf("2. Clientes\n");
        printf("3. Efectivo\n");
        printf("4. Retiros\n");
        printf("5. Finalizar\n");
        printf("\nLeer opcion: ");
        scanf("%d", &opcion);
        printf("\n");
        switch (opcion)
        {
        case 1:
            do
            {
                opcionCajero = menuCajeros();
                switch (opcionCajero)
                {
                case 1:
                    actualizarCajero();
                    GuardarDatos();
                    break;
                case 2:
                    CargarDatos();
                    consultarCajero();
                    break;
                case 3:
                    printf("\n");
                    break;
                default:
                    printf("Opcion invalida\n");
                }
            } while (opcionCajero != 3);
            break;
        case 2:
            do
            {
                opcionCliente = menuClientes();
                switch (opcionCliente)
                {
                case 1:
                    actualizarCliente();
                    GuardarDatos();
                    break;
                case 2:
                    CargarDatos();
                    consultarCliente();
                    break;
                case 3:
                    printf("\n");
                    break;
                default:
                    printf("Opcion invalida\n");
                }
            } while (opcionCliente != 3);
            break;
        case 3:
            do
            {
                opcionEfectivo = menuEfectivo();
                switch (opcionEfectivo)
                {
                case 1:
                    actualizarEfectivo();
                    GuardarDatos();
                    break;  
                case 2:
                    CargarDatos();
                    consultaEfectivo();
                    break;
                case 3:
                    printf("\n");
                    break;
                default:
                    printf("Opcion invalida\n");
                }
            } while (opcionEfectivo != 3);
            break;
        case 4:
            do
            {
                opcionRetiro = menuRetiros();
                switch (opcionRetiro)
                {
                case 1:
                    retirarRetiro();
                    GuardarDatos();
                    break;
                case 2:
                    CargarDatos();
                    consultarRetiro();
                    break;
                case 3:
                    printf("\n");
                    break;
                default:    
                    printf("Opcion invalida\n");
                }
            } while (opcionRetiro != 3);
            break;
        case 5:
            printf("Gracias por utilizar el cajero Bancario\n");
            // Guardar datos
            GuardarDatos();
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    } while (opcion != 5);
}

// Main
int main()
{
    // Cargar datos
    CargarDatos();
    menuGeneral();
    return 0;
}