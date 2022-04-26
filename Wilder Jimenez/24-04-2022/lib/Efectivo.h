// Simulacion de Efectivo
// Language: C

// Bibiliotecas
#include <stdio.h>

// Librerias

// Definiciones
#define CANTIDAD_EFECTIVO 100

// Nombres
#define ARCHIVO_EFECTIVO "efectivo.dat"

// Ruta de archivos
#define RUTA_DATOS "./datos/"

/*
    Codigo cajero (entero)
    Cantidad den. menor (entero)
    Cantidad den. mayor (entero)
*/

struct efectivo
{
    int codigoCajero;
    int cantidadDenominacionMenor;
    int cantidadDenominacionMayor;
} efectivo[CANTIDAD_EFECTIVO];
int numeroEfectivo = 0;

// Buscar Efectivo, retorna la posicion del efectivo en el arreglo
int BuscarEfectivo(int codigoCajero)
{
    int i;
    for (i = 0; i < numeroEfectivo; i++)
    {
        if (efectivo[i].codigoCajero == codigoCajero)
        {
            return i;
        }
    }
    return -1;
}

// Guardar Efectivo, guarda el array de efectivos en el archivo binario
void GuardarEfectivo()
{
    FILE *pArchivo;
    pArchivo = fopen(RUTA_DATOS ARCHIVO_EFECTIVO, "wb");
    if (pArchivo == NULL)
    {
        printf("Error en la apertura del archivo %s\n", RUTA_DATOS ARCHIVO_EFECTIVO);
        exit(1);
    }
    fwrite(efectivo, sizeof(efectivo), 1, pArchivo);
    fclose(pArchivo);
}

// Cargar Efectivo, carga el array de efectivos desde el archivo binario
void CargarEfectivo()
{
    FILE *pArchivo;
    pArchivo = fopen(RUTA_DATOS ARCHIVO_EFECTIVO, "rb");
    if (pArchivo != NULL)
    {
        fread(efectivo, sizeof(efectivo), 1, pArchivo);
        
    }
    fclose(pArchivo);

    numeroEfectivo = 0;

    int i;
    for (i = 0; i < CANTIDAD_EFECTIVO; i++)
    {
        if (efectivo[i].codigoCajero != 0)
        {
            numeroEfectivo++;
        }
    }
}

/*
    1. Actualizar.
    2. Consultar.
    3. Finalizar.

    Leer opcion:
*/
int menuEfectivo()
{
    int opcion = 0;

    do
    {
        printf("\nMenu Efectivo\n");
        printf("1. Actualizar\n");
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
            printf("Opcion no valida\n");
            break;
        }
    } while (opcion != 3);
}
