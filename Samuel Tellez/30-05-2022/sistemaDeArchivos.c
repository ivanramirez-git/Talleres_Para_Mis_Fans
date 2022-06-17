// Sistema de manejo de archivos tipo *nix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_NOMBRE_ARCHIVO 50
// Nodo del arbol
typedef struct Nodo
{
    char nombre[MAX_NOMBRE_ARCHIVO];
    char tipo;            // 'D: directorio, 'A: archivo
    time_t fechaCreacion; // fecha de creacion
    // Lista de archivos en el directorio
    struct Nodo *siguiente;
    struct Nodo *anterior;
    // Arbol
    struct Nodo *hijo;
    struct Nodo *padre;
} Nodo;
// Funciones
int mkdir(const char *pathname, mode_t mode);
int rmdir(const char *pathname);
// Solicitar el nombe del directorio raiz
void solicitarNombreDirectorioRaiz(struct Nodo *raiz);
// Agregar un directorio al arbol
void agregarDirectorioEnNodoActual(struct Nodo *actual);
// Agregar un archivo al arbol
void agregarArchivoEnNodoActual(struct Nodo *actual);
// Mostrar el arbol
void mostrarArbolCompleto(struct Nodo *raiz);
// Mostrar archivos y directorios del nodo
void mostrarArchivosDirectorio(struct Nodo *actual);
// Buscar un nodo en el arbol
struct Nodo *buscarNodo(struct Nodo *actual, char *nombre);
// Eliminar un nodo del arbol
void eliminarArchivoDirectorio(struct Nodo *actual);
// imprimir ruta
void mostrarRutaDesdeDirectorioActual(struct Nodo *actual);
// Funcion principal
int main()
{
    // Pedir el nombre del directorio raiz
    struct Nodo *raiz = (struct Nodo *)malloc(sizeof(struct Nodo));
    solicitarNombreDirectorioRaiz(raiz);
    struct Nodo *actual = raiz;
    // cd: cambiar directorio, ls: listar archivos y directorios del directorio actual
    char comando[MAX_NOMBRE_ARCHIVO];
    while (1)
    {
        printf("\n");
        mostrarRutaDesdeDirectorioActual(actual);
        printf(" > ");
        scanf("%s", comando);
        if (strcmp(comando, "cd") == 0)
        {
            char nombreDirectorio[MAX_NOMBRE_ARCHIVO];
            scanf("%s", nombreDirectorio);
            if (strcmp(nombreDirectorio, "..") == 0)
            {
                // cd ..: cambiar al directorio padre
                if (actual->padre != NULL)
                {
                    actual = actual->padre;
                }
            }
            else
            {
                // cd: cambiar a un directorio hijo
                struct Nodo *nodo = buscarNodo(actual, nombreDirectorio);
                if (nodo != NULL && nodo->tipo == 'D')
                {
                    actual = nodo;
                }
                else
                {
                    printf("No existe el directorio %s\n", nombreDirectorio);
                }
            }
        }
        else if (strcmp(comando, "ls") == 0)
        {
            // ls: listar archivos y directorios del directorio actual
            mostrarArchivosDirectorio(actual);
        }
        else if (strcmp(comando, "mkdir") == 0)
        {
            // mkdir: crear un directorio en el directorio actual
            agregarDirectorioEnNodoActual(actual);
        }
        else if (strcmp(comando, "touch") == 0)
        {
            // touch: crear un archivo en el directorio actual
            agregarArchivoEnNodoActual(actual);
        }
        else if (strcmp(comando, "rm") == 0)
        {
            // rm: eliminar un archivo o directorio
            eliminarArchivoDirectorio(actual);
        }
        else if (strcmp(comando, "print") == 0)
        {
            // print: imprimir el arbol
            mostrarArbolCompleto(raiz);
        }
        else if (strcmp(comando, "exit") == 0)
        {
            // exit: salir del programa
            break;
        }
        else
        {
            printf("Comando no reconocido\n");
        }
        // Limpiar el buffer
        fflush(stdin);
    }
    return 0;
}
// Funciones
// imprimir ruta
void mostrarRutaDesdeDirectorioActual(struct Nodo *actual)
{

    if (actual != NULL)
    {
        mostrarRutaDesdeDirectorioActual(actual->padre);
        printf("%s/", actual->nombre);
    }
    else
    {
        printf("./");
    }
}
// ruta
char *darRuta(struct Nodo *actual)
{
    char *ruta = (char *)malloc(sizeof(char) * MAX_NOMBRE_ARCHIVO);
    if (actual != NULL)
    {
        strcpy(ruta, darRuta(actual->padre));
        strcat(ruta, actual->nombre);
        strcat(ruta, "/");
    }
    else
    {
        strcpy(ruta, "./");
    }
    return ruta;
}
// gestor de archivos
void gestorArchivos(struct Nodo *directorio, char orden, struct Nodo *dato)
{
    if (directorio == NULL)
    {
        printf("No hay directorio\n");
        return;
    }
    // validar si es un directorio
    if (directorio->tipo == 'D')
    {

        char rutaConNombre[100];

        // validar si existe el directorio
        if (dato != NULL && dato->tipo == 'D')
        {
            // orden: e = eliminar, c = crear
            if (orden == 'c')
            {
                // Crear directorio con el nombre del nodo
                strcpy(rutaConNombre, darRuta(dato));
                mkdir(rutaConNombre, S_IRWXU);
            }
            else if (orden == 'e')
            {
                char llamada[100];
                // Eliminar directorio
                char rutaConNombre[100];
                strcpy(rutaConNombre, darRuta(dato));
                rmdir(rutaConNombre);
            }
        }
        else if (dato != NULL && dato->tipo == 'A')
        {
            FILE *archivo;
            // orden: e = eliminar, c = crear
            if (orden == 'c')
            {
                char rutaConNombre[100];
                strcpy(rutaConNombre, darRuta(dato));
                // Crear archivo con el nombre
                archivo = fopen(rutaConNombre, "w");
                if (archivo == NULL)
                {
                    printf("No se pudo crear el archivo\n");
                }
                else
                {
                    fclose(archivo);
                }
            }
            else if (orden == 'e')
            {
                char llamada[100];
                // Eliminar archivo
                char rutaConNombre[100];
                strcpy(rutaConNombre, darRuta(dato));
                remove(rutaConNombre);
            }
        }
        else
        {
            printf("No existe el directorio o archivo\n");
        }
    }
    else
    {
        printf("No se puede crear un archivo en un archivo\n");
    }
}
// Solicitar el nombe del directorio raiz
void solicitarNombreDirectorioRaiz(struct Nodo *raiz)
{
    printf("Ingrese el nombre del directorio raiz: ");
    scanf("%s", raiz->nombre);
    raiz->tipo = 'D';
    raiz->fechaCreacion = time(NULL);
    raiz->siguiente = NULL;
    raiz->anterior = NULL;
    raiz->hijo = NULL;
    raiz->padre = NULL;

    char *llamda = (char *)malloc(sizeof(char) * 100);
    strcpy(llamda, "mkdir ");
    strcat(llamda, raiz->nombre);
    printf("%s\n", llamda);
    system(llamda);
}
// Agregar un directorio al arbol
void agregarDirectorioEnNodoActual(struct Nodo *actual)
{
    // Crear un nodo
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    // Pedir el nombre del directorio
    printf("Ingrese el nombre del directorio: ");
    scanf("%s", nuevo->nombre);
    nuevo->tipo = 'D';
    nuevo->fechaCreacion = time(NULL);
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    nuevo->hijo = NULL;
    nuevo->padre = actual;

    // Agregar el nodo al arbol
    if (actual->hijo == NULL)
    {
        actual->hijo = nuevo;
    }
    else
    {
        struct Nodo *aux = actual->hijo;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }
    // Gestionar archivos
    gestorArchivos(actual, 'c', nuevo);
}
// Agregar un archivo al arbol
void agregarArchivoEnNodoActual(struct Nodo *actual)
{
    // Crear un nodo
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    // Pedir el nombre del archivo
    printf("Ingrese el nombre del archivo: ");
    scanf("%s", nuevo->nombre);
    nuevo->tipo = 'A';
    nuevo->fechaCreacion = time(NULL);
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    nuevo->hijo = NULL;
    nuevo->padre = actual;

    // Agregar el nodo al arbol
    if (actual->hijo == NULL)
    {
        actual->hijo = nuevo;
    }
    else
    {
        struct Nodo *aux = actual->hijo;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }
    // Gestionar archivos
    gestorArchivos(actual, 'c', nuevo);
}
// Eliminar un nodo del arbol
void eliminarArchivoDirectorio(struct Nodo *actual)
{
    // Pedir el nombre del archivo
    printf("Ingrese el nombre del archivo o directorio a eliminar: ");
    char nombre[25];
    scanf("%s", nombre);
    struct Nodo *aux = buscarNodo(actual, nombre);
    if (aux != NULL)
    {
        if (aux->tipo == 'D')
        {
            // Eliminar el nodo
            if (aux->anterior != NULL)
            {
                aux->anterior->siguiente = aux->siguiente;
            }
            if (aux->siguiente != NULL)
            {
                aux->siguiente->anterior = aux->anterior;
            }
            if (aux->padre->hijo == aux)
            {
                aux->padre->hijo = aux->siguiente;
            }
            // Eliminar los hijos del nodo
            struct Nodo *aux2 = aux->hijo;
            while (aux2 != NULL)
            {
                eliminarArchivoDirectorio(aux2);
                aux2 = aux2->siguiente;
            }
        }
        else
        {
            // Eliminar el nodo
            if (aux->anterior != NULL)
            {
                aux->anterior->siguiente = aux->siguiente;
            }
            if (aux->siguiente != NULL)
            {
                aux->siguiente->anterior = aux->anterior;
            }
            if (aux->padre->hijo == aux)
            {
                aux->padre->hijo = aux->siguiente;
            }
        }
        // Gestionar archivos
        gestorArchivos(actual, 'e', aux);
    }
    else
    {
        printf("El archivo o directorio no existe\n");
    }
}
// Mostrar el arbol
void mostrarArbol(struct Nodo *actual)
{
    char fecha[25];
    if (actual != NULL)
    {
        strftime(fecha, 25, "%d/%m/%Y %H:%M:%S", localtime(&actual->fechaCreacion));
        if (actual->siguiente == NULL)
        {
            if (actual->tipo == 'D')
            {
                printf("{\"nombre\":\"%s\",\"tipo\":\"%c\",\"fechaCreacion\":\"%s\",\"hijos\":[", actual->nombre, actual->tipo, fecha);
                mostrarArbol(actual->hijo);
                printf("]}");
            }
            else
            {
                printf("{\"nombre\":\"%s\",\"tipo\":\"%c\",\"fechaCreacion\":\"%s\"}", actual->nombre, actual->tipo, fecha);
            }
        }
        else
        {
            if (actual->tipo == 'D')
            {
                printf("{\"nombre\":\"%s\",\"tipo\":\"%c\",\"fechaCreacion\":\"%s\",\"hijos\":[", actual->nombre, actual->tipo, fecha);
                mostrarArbol(actual->hijo);
                printf("]},");
            }
            else
            {
                printf("{\"nombre\":\"%s\",\"tipo\":\"%c\",\"fechaCreacion\":\"%s\"},", actual->nombre, actual->tipo, fecha);
            }
            mostrarArbol(actual->siguiente);
        }
    }
}
// Mostrar el arbol
void mostrarArbolCompleto(struct Nodo *raiz)
{
    // Formato json
    printf("{\"raiz\":\"%s\",\"hijos\":[", raiz->nombre);
    mostrarArbol(raiz->hijo);
    printf("]}");
}
// Imprime una cadena y luego espacios faltantes para completar el espacio
char *imprimirConEspacios(char cadena[])
{
    int tam = 25;
    char *cadenaAux = (char *)malloc(sizeof(char) * tam);
    strcpy(cadenaAux, cadena);
    int i = 0;
    while (i < tam - strlen(cadena))
    {
        strcat(cadenaAux, " ");
        i++;
    }
    return cadenaAux;
}
// Mostrar archivos y directorios del nodo
void mostrarArchivosDirectorio(struct Nodo *actual)
{
    // Encabezados de la lista
    printf("%s%s%s\n", imprimirConEspacios("Nombre"), imprimirConEspacios("Tipo"), "Fecha de creacion");
    char fecha[25];
    if (actual != NULL)
    {
        strftime(fecha, 25, "%d/%m/%Y %H:%M:%S", localtime(&actual->fechaCreacion));
        struct Nodo *aux = actual->hijo;
        while (aux != NULL)
        {
            char *tipos = (char *)malloc(sizeof(char) * 13);
            if (aux->tipo == 'A')
            {
                strcpy(tipos, "Archivo");
            }
            else
            {
                strcpy(tipos, "Directorio");
            }
            printf("%s%s%s\n", imprimirConEspacios(aux->nombre), imprimirConEspacios(tipos), fecha);
            aux = aux->siguiente;
        }
    }
}
// Buscar un nodo en el arbol
struct Nodo *buscarNodo(struct Nodo *actual, char *nombre)
{
    struct Nodo *aux = actual->hijo;
    while (aux != NULL)
    {
        if (strcmp(aux->nombre, nombre) == 0)
        {
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}