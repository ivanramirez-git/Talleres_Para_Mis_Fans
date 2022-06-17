#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>


// Gestor de directorios
void crearDirectorio(char *nombreDirectorio)
{
    mkdir(nombreDirectorio);
}

void eliminarDirectorio(char *nombreDirectorio)
{
    rmdir(nombreDirectorio);
}

// Gestor de archivos
void crearArchivo(char *nombreArchivo)
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "w");
    fclose(archivo);
}

void eliminarArchivo(char *nombreArchivo)
{
    remove(nombreArchivo);
}

// arbol de directorios y archivos
typedef struct nodo
{
    char nombre[100]; // si termina con * es un directorio
    char ruta[100];
    struct nodo *padre;
    struct nodo *hijo;
    struct nodo *hermano;
    struct nodo *anterior;
} nodo;



// menu
void crearDirectorioMenu();
void eliminarDirectorioMenu();
void crearArchivoMenu();
void eliminarArchivoMenu();
void imprimirArbolMenu();

// Es Directorio ? 1 : 0
int esDirectorio(char *nombreDirectorio)
{
    if (nombreDirectorio[strlen(nombreDirectorio) - 1] == '*')
    {
        return 1;
    }
    return 0;
}

// Quitar * al final
char *nombreDir(char *nombreDirectorio)
{
    char *nombre = malloc(sizeof(char) * 100);
    strcpy(nombre, nombreDirectorio);
    nombre[strlen(nombre) - 1] = '\0';
    return nombre;
}

// Agregar * al final
char *nombreDirAgregado(char *nombreDirectorio)
{
    char *nombre = malloc(sizeof(char) * 100);
    strncpy(nombre, nombreDirectorio, strlen(nombreDirectorio));
    nombre[strlen(nombreDirectorio)] = '*';
    nombre[strlen(nombreDirectorio) + 1] = '\0';
    return nombre;
}

// Remplazar todos los * por / en la ruta
char *rutaDir(char *rutaDirectorio)
{
    char *ruta = malloc(sizeof(char) * 100);
    strcpy(ruta, rutaDirectorio);
    int i;
    for (i = 0; i < strlen(ruta); i++)
    {
        if (ruta[i] == '*')
        {
            ruta[i] = '/';
        }
    }
    return ruta;
}

nodo *raiz = NULL;
// main
int main()
{
    // pedir el nombre del directorio raiz
    char nombreDirectorio[100];
    printf("Ingrese el nombre del directorio raiz: ");
    scanf("%s", nombreDirectorio);
    // colocar * al final
    strcpy(nombreDirectorio, nombreDirAgregado(nombreDirectorio));

    // inicializar el arbol
    nodo *nodoRaiz = malloc(sizeof(nodo));
    strcpy(nodoRaiz->nombre, nombreDirectorio);
    strcpy(nodoRaiz->ruta, nombreDirectorio);
    nodoRaiz->hijo = NULL;
    nodoRaiz->hermano = NULL;
    nodoRaiz->padre = NULL;
    nodoRaiz->anterior = NULL;
    raiz = nodoRaiz;

    // crear el directorio raiz
    printf(nombreDir(nombreDirectorio));
    crearDirectorio(nombreDir(nombreDirectorio));

    int opcion;
    do
    {
        printf("\n\n");
        printf("1. Crear directorio\n");
        printf("2. Eliminar directorio\n");
        printf("3. Crear archivo\n");
        printf("4. Eliminar archivo\n");
        printf("5. Imprimir arbol de directorios y archivos\n");
        printf("0. Salir\n");
        printf("\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            crearDirectorioMenu();
            break;
        case 2:
            eliminarDirectorioMenu();
            break;
        case 3:
            crearArchivoMenu();
            break;
        case 4:
            eliminarArchivoMenu();
            break;
        case 5:
            imprimirArbolMenu();
            break;
        case 0:
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (opcion != 0);
    return 0;
}

// buscar un archivo o directorio
nodo *buscar(char *nombre, struct nodo *actual)
{
    if (actual == NULL)
    {
        return NULL;
    }
    if (strcmp(actual->nombre, nombre) == 0)
    {
        return actual;
    }
    if (actual->hijo != NULL)
    {
        nodo *nodo = buscar(nombre, actual->hijo);
        if (nodo != NULL)
        {
            return nodo;
        }
    }
    if (actual->hermano != NULL)
    {
        nodo *nodo = buscar(nombre, actual->hermano);
        if (nodo != NULL)
        {
            return nodo;
        }
    }
    return NULL;
}

void crearDirectorioMenu()
{
    // pedir el nombre del directorio padre
    char nombreDirectorio[100];
    printf("Ingrese el nombre del directorio padre: ");
    scanf("%s", nombreDirectorio);
    // colocar * al final
    strcpy(nombreDirectorio, nombreDirAgregado(nombreDirectorio));

    // buscar el directorio padre
    nodo *padre = buscar(nombreDirectorio, raiz);
    if (padre == NULL)
    {
        printf("El directorio padre no existe\n");
        return;
    }

    // validar que sea un directorio
    if (!esDirectorio(padre->nombre))
    {
        printf("El directorio padre no es un directorio\n");
        return;
    }

    // pedir el nombre del directorio hijo
    printf("Ingrese el nombre del directorio hijo: ");
    scanf("%s", nombreDirectorio);
    // colocar * al final
    strcpy(nombreDirectorio, nombreDirAgregado(nombreDirectorio));

    // buscar el directorio hijo
    nodo *hijo = buscar(nombreDirectorio, raiz);
    if (hijo != NULL)
    {
        printf("El directorio hijo ya existe\n");
        return;
    }

    // agregar al arbol
    nodo *nodoHijo = malloc(sizeof(nodo));
    strcpy(nodoHijo->nombre, nombreDirectorio);
    strcpy(nodoHijo->ruta, rutaDir(padre->ruta));
    strcat(nodoHijo->ruta, nombreDirectorio);
    nodoHijo->hijo = NULL;
    nodoHijo->hermano = NULL;
    nodoHijo->padre = padre;
    nodoHijo->anterior = NULL;
    if (padre->hijo == NULL)
    {
        padre->hijo = nodoHijo;
    }
    else
    {
        nodo *aux = padre->hijo;
        while (aux->hermano != NULL)
        {
            aux = aux->hermano;
        }
        aux->hermano = nodoHijo;
        nodoHijo->anterior = aux;
    }
    
    // crear el directorio
    crearDirectorio(rutaDir(nodoHijo->ruta));

    // informar que se creo el directorio
    printf("Se creo el directorio %s\n", nodoHijo->nombre);
}

void eliminarNodo(nodo *eliminar)
{
    // si tiene hijo lo elimina
    if (eliminar->hijo != NULL)
    {
        eliminarNodo(eliminar->hijo);
    }
    // si tiene anterior lo apunta al hermano
    if (eliminar->anterior != NULL)
    {
        eliminar->anterior->hermano = eliminar->hermano;
    }
    // si tiene hermano lo apunta al anterior
    if (eliminar->hermano != NULL)
    {
        eliminar->hermano->anterior = eliminar->anterior;
    }
    // si tiene padre lo apunta al hermano
    if (eliminar->padre != NULL)
    {
        if (eliminar->padre->hijo == eliminar)
        {
            eliminar->padre->hijo = eliminar->hermano;
        }
        else
        {
            eliminar->padre->hermano = eliminar->hermano;
        }
    }
    // si es raiz lo apunta a NULL
    if (eliminar == raiz)
    {
        return;
    }
    // si es el ultimo nodo lo apunta a NULL
    if (eliminar->hermano == NULL)
    {
        eliminar->padre->hermano = NULL;
    }
    // liberar memoria
    free(eliminar);
    eliminar = NULL;
}
void eliminarDirectorioMenu()
{
    // pedir el nombre del directorio a eliminar
    char nombreDirectorio[100];
    printf("Ingrese el nombre del directorio a eliminar: ");
    scanf("%s", nombreDirectorio);
    // colocar * al final
    strcpy(nombreDirectorio, nombreDirAgregado(nombreDirectorio));

    // buscar el directorio a eliminar
    nodo *eliminar = buscar(nombreDirectorio, raiz);
    if (eliminar == NULL)
    {
        printf("El directorio a eliminar no existe\n");
        return;
    }

    // validar que sea un directorio
    if (!esDirectorio(eliminar->nombre))
    {
        printf("El directorio a eliminar no es un directorio\n");
        return;
    }

    // eliminar el directorio
    eliminarDirectorio(rutaDir(eliminar->ruta));

    // informar que se elimino el directorio
    printf("El directorio %s fue eliminado\n", eliminar->nombre);

    // eliminar el directorio del arbol
    eliminarNodo(eliminar);
}

void crearArchivoMenu()
{
    // pedir el nombre del directorio padre
    char nombreDirectorio[100];
    printf("Ingrese el nombre del directorio padre: ");
    scanf("%s", nombreDirectorio);
    // colocar * al final
    strcpy(nombreDirectorio, nombreDirAgregado(nombreDirectorio));

    // buscar el directorio padre
    nodo *padre = buscar(nombreDirectorio, raiz);
    if (padre == NULL)
    {
        printf("El directorio padre no existe\n");
        return;
    }

    // validar que sea un directorio
    if (!esDirectorio(padre->nombre))
    {
        printf("El directorio padre no es un directorio\n");
        return;
    }

    // pedir el nombre del archivo
    printf("Ingrese el nombre del archivo: ");
    scanf("%s", nombreDirectorio);

    // buscar el archivo
    nodo *archivo = buscar(nombreDirectorio, raiz);
    if (archivo != NULL)
    {
        printf("El archivo ya existe\n");
        return;
    }

    // agregar al arbol
    nodo *nodoArchivo = malloc(sizeof(nodo));
    strcpy(nodoArchivo->nombre, nombreDirectorio);
    strcpy(nodoArchivo->ruta, rutaDir(padre->ruta));
    strcat(nodoArchivo->ruta, nombreDirectorio);
    nodoArchivo->hijo = NULL;
    nodoArchivo->hermano = NULL;
    nodoArchivo->padre = padre;
    nodoArchivo->anterior = NULL;
    if (padre->hijo == NULL)
    {
        padre->hijo = nodoArchivo;
    }
    else
    {
        nodo *aux = padre->hijo;
        while (aux->hermano != NULL)
        {
            aux = aux->hermano;
        }
        aux->hermano = nodoArchivo;
        nodoArchivo->anterior = aux;
    }

    // crear el archivo
    crearArchivo(rutaDir(nodoArchivo->ruta));

    // informar que se creo el archivo
    printf("El archivo %s fue creado\n", nodoArchivo->nombre);
}
void eliminarArchivoMenu()
{
    // pedir el nombre del archivo a eliminar
    char nombreDirectorio[100];
    printf("Ingrese el nombre del archivo a eliminar: ");
    scanf("%s", nombreDirectorio);

    // buscar el archivo a eliminar
    nodo *eliminar = buscar(nombreDirectorio, raiz);
    if (eliminar == NULL)
    {
        printf("El archivo a eliminar no existe\n");
        return;
    }

    // validar que sea un archivo
    if (esDirectorio(eliminar->nombre))
    {
        printf("El archivo a eliminar no es un archivo\n");
        return;
    }

    // eliminar el archivo
    eliminarArchivo(rutaDir(eliminar->ruta));

    // informar que se elimino el archivo
    printf("El archivo %s fue eliminado\n", eliminar->nombre);

    // eliminar el archivo del arbol
    eliminarNodo(eliminar);
}

void imprimirArbol(nodo *nodoActual, int nivel)
{
    if (nodoActual == NULL)
    {
        return;
    }
    imprimirArbol(nodoActual->hermano, nivel);
    int i;
    for (i = 0; i < nivel; i++)
    {
        printf("   ");
    }
    printf("%s\n", nodoActual->nombre);
    imprimirArbol(nodoActual->hijo, nivel + 1);
}

void imprimirArbolMenu()
{
    struct nodo *aux = raiz;
    imprimirArbol(aux, 0);
}
