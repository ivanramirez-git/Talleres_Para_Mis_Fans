// Simulacion de Cajeros
// Language: C

// Bibiliotecas
#include <stdio.h>

// Librerias

// Definiciones
#define CANTIDAD_CAJEROS 100

// Nombres
#define ARCHIVO_CAJEROS "cajeros.dat"

// Ruta de archivos
#define RUTA_DATOS "./datos/"

// Librerias

/*
    Codigo cajero (entero)
    Ubicacion (20 caracteres)
    Ciudad (20 caracteres.)
    Denominacion menor (entero)
    Denominacion mayor (entero)
*/

struct cajero
{
    // Atributos
    int codigoCajero;
    char ubicacion[20];
    char ciudad[20];
    int denominacionMenor;
    int denominacionMayor;

} cajeros[CANTIDAD_CAJEROS];
int numeroCajeros = 0;

// Buscar Cajeros, retorna la posicion del cajero en el arreglo
int BuscarCajero(int codigoCajero)
{
    int i;
    for (i = 0; i < numeroCajeros; i++)
    {
        if (cajeros[i].codigoCajero == codigoCajero)
        {
            return i;
        }
    }
    return -1;
}

// Guardar Cajeros, guarda el array de cajeros en el archivo binario
void GuardarCajeros()
{
    FILE *pArchivo;
    pArchivo = fopen(RUTA_DATOS ARCHIVO_CAJEROS, "wb");
    if (pArchivo == NULL)
    {
        printf("Error en la apertura del archivo %s\n", RUTA_DATOS ARCHIVO_CAJEROS);
        exit(1);
    }
    fwrite(cajeros, sizeof(cajeros), 1, pArchivo);
    fclose(pArchivo);
}

// Cargar Cajeros, carga el array de cajeros desde el archivo binario
void CargarCajeros()
{
    FILE *pArchivo;
    pArchivo = fopen(RUTA_DATOS ARCHIVO_CAJEROS, "rb");
    if (pArchivo != NULL)
    {
        fread(cajeros, sizeof(cajeros), 1, pArchivo);
    }
    fclose(pArchivo);

    numeroCajeros = 0;

    int i;
    for (i = 0; i < CANTIDAD_CAJEROS; i++)
    {
        if (cajeros[i].codigoCajero != 0)
        {
            numeroCajeros++;
        }
    }
}

/*
    1. Actualizar.
    2. Consultar.
    3. Finalizar.

    Leer opcion:
*/
int menuCajeros()
{
    int opcion = 0;

    do
    {
        printf("\nMenu Cajeros\n");
        printf("\n1. Actualizar\n");
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