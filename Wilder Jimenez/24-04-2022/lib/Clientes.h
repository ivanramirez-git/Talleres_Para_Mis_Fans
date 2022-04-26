// Simulacion de Clientes
// Language: C

// Bibiliotecas
#include <stdio.h>

// Librerias

// Definiciones
#define CANTIDAD_CLIENTES 100

// Nombres
#define ARCHIVO_CLIENTES "clientes.dat"

// Ruta de archivos
#define RUTA_DATOS "./datos/"

/*
    Codigo cliente (entero)
    Nombre cliente (25 caracteres.)
    Numero cuenta (entero)
    Balance (flotante)
*/
struct cliente
{
    int codigoCliente;
    char nombreCliente[25];
    int numeroCuenta;
    float balance;
} clientes[CANTIDAD_CLIENTES];
int numeroClientes = 0;

// Buscar Cliente, retorna la posicion del cliente en el arreglo
int BuscarCliente(int numeroCuenta)
{
    int i;
    for (i = 0; i < numeroClientes; i++)
    {
        if (clientes[i].numeroCuenta == numeroCuenta)
        {
            return i;
        }
    }
    return -1;
}

int BuscarClienteCodigo(int codigoCliente)
{
    int i;
    for (i = 0; i < numeroClientes; i++)
    {
        if (clientes[i].codigoCliente == codigoCliente)
        {
            return i;
        }
    }
    return -1;
}

// Guardar Clientes, guarda el array de clientes en el archivo binario
void GuardarClientes()
{
    FILE *pArchivo;
    pArchivo = fopen(RUTA_DATOS ARCHIVO_CLIENTES, "wb");
    if (pArchivo == NULL)
    {
        printf("Error en la apertura del archivo %s\n", RUTA_DATOS ARCHIVO_CLIENTES);
        exit(1);
    }
    fwrite(clientes, sizeof(clientes), 1, pArchivo);
    fclose(pArchivo);
}

// Cargar Clientes, carga el array de clientes desde el archivo binario
void CargarClientes()
{
    FILE *pArchivo;
    pArchivo = fopen(RUTA_DATOS ARCHIVO_CLIENTES, "rb");
    if (pArchivo != NULL)
    {
        fread(clientes, sizeof(clientes), 1, pArchivo);
        
    }
    fclose(pArchivo);

    numeroClientes = 0;

    int i;
    for (i = 0; i < CANTIDAD_CLIENTES; i++)
    {
        if (clientes[i].codigoCliente != 0)
        {
            numeroClientes++;
        }
    }
}

/*
    1. Actualizar.
    2. Consultar.
    3. Finalizar.

    Leer opcion:
*/
int menuClientes()
{
    int opcion = 0;

    do
    {
        printf("\nMenu Clientes\n");
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
            printf("Opcion invalida\n");
        }
    } while (opcion != 3);
}