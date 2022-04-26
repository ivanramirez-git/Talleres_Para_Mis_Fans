// Simulacion de Retiros
// Language: C

// Bibiliotecas
#include <stdio.h>

// Librerias

// Definiciones
#define CANTIDAD_RETIROS 100

// Nombres
#define ARCHIVO_RETIROS "retiros.dat"

// Ruta de archivos
#define RUTA_DATOS "./datos/"

/*
    Codigo cajero (entero)
    Num. cuenta cliente (entero)
    Fecha retiro (10 caracteres)
    Monto retiro (flotante)
*/

struct retiro
{
    int codigoCajero;
    int numeroCuenta;
    char fechaRetiro[11];
    float montoRetiro;
} retiros[CANTIDAD_RETIROS];
int numeroRetiros = 0;

// Buscar Retiro, retorna la posicion del retiro en el arreglo
int BuscarRetiro(int numeroCuenta)
{
    int i;
    for (i = 0; i < numeroRetiros; i++)
    {
        if (retiros[i].numeroCuenta == numeroCuenta)
        {
            return i;
        }
    }
    return -1;
}

// Cargar Retiros, carga el array de retiros desde el archivo binario
void CargarRetiros()
{
    FILE *pArchivo;
    pArchivo = fopen(RUTA_DATOS ARCHIVO_RETIROS, "rb");
    if (pArchivo != NULL)
    {
        fread(retiros, sizeof(retiros), 1, pArchivo);
        
    }
    fclose(pArchivo);

    numeroRetiros = 0;
    int i;
    for (i = 0; i < CANTIDAD_RETIROS; i++)
    {
        if (retiros[i].codigoCajero != 0)
        {
            numeroRetiros++;
        }
    }
}

// Guardar Retiros, guarda el array de retiros en el archivo binario
void GuardarRetiros()
{
    FILE *pArchivo;
    pArchivo = fopen(RUTA_DATOS ARCHIVO_RETIROS, "wb");
    if (pArchivo == NULL)
    {
        printf("Error en la apertura del archivo %s\n", RUTA_DATOS ARCHIVO_RETIROS);
        exit(1);
    }
    fwrite(retiros, sizeof(retiros), 1, pArchivo);
    fclose(pArchivo);
}

/*
    1. Retirar.
    2. Consultar.
    3. Finalizar.

    Leer opcion:
*/
int menuRetiros()
{
    int opcion;

    do
    {
        printf("\nMenu Retiros\n");
        printf("1. Retirar\n");
        printf("2. Consultar\n");
        printf("3. Finalizar\n");
        printf("\nLeer opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        default:
            printf("Opcion invalida\n");
        }
    } while (opcion != 3);
}
