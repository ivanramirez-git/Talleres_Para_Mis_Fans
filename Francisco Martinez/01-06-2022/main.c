// cola
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    int id; // autoincremental
    char nombre[20];
    int edad;
    struct nodo *sig;
} nodo;

nodo *crearNodo(char nombre[20], int edad)
{
    nodo *nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->id = 1;
    strcpy(nuevo->nombre, nombre);
    nuevo->edad = edad;
    nuevo->sig = NULL;
    return nuevo;
}

void agregarNodo(nodo **lista, char nombre[20], int edad)
{
    int id = 2;
    nodo *nuevo = crearNodo(nombre, edad);
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        nodo *aux = *lista;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
            id++;
        }
        aux->sig = nuevo;
        nuevo->id = id;
    }
}

void mostrarLista(nodo *lista)
{
    nodo *aux = lista;
    while (aux != NULL)
    {
        printf("\t\t%d. %s %d anios\n", aux->id, aux->nombre, aux->edad);
        aux = aux->sig;
    }
}

void eliminarNodo(nodo **lista, int id)
{
    nodo *aux = *lista;
    nodo *ant = NULL;
    while (aux != NULL)
    {
        if (aux->id == id)
        {
            if (ant == NULL)
            {
                *lista = aux->sig;
            }
            else
            {
                ant->sig = aux->sig;
            }
            free(aux);
            break;
        }
        ant = aux;
        aux = aux->sig;
    }
}

void modificarNodo(nodo **lista, int id, char nombre[20], int edad)
{
    nodo *aux = *lista;
    while (aux != NULL)
    {
        if (aux->id == id)
        {
            strcpy(aux->nombre, nombre);
            aux->edad = edad;
            printf("\t*** Elemento editado ***\n\n");
            return;
        }
        aux = aux->sig;
    }
    printf("\t*** Elemento no encontrado ***\n\n");
}

// funcion principal
int main()
{
    nodo *lista = NULL;

    int opcion;
    char nombre[20];
    int edad;

    do
    {
        printf("1. Agregar contacto\n");
        printf("2. Editar contacto\n");
        printf("3. Eliminar contacto\n");
        printf("4. Mostrar elementos\n");
        printf("5. Salir\n\n");
        printf("Que operacion desea realizar? ");
        scanf("%d", &opcion);
        printf("\n");
        switch (opcion)
        {
        case 1:
            printf("\t*** Agregar el elemento ***\n");
            printf("\t\tCual es el nombre? ");
            scanf("%s", nombre);
            printf("\t\tCual es la edad? ");
            scanf("%d", &edad);
            agregarNodo(&lista, nombre, edad);
            printf("\t*** Elemento agregado ***\n\n");
            break;
        case 2:
            printf("\t*** Editar el elemento ***\n");
            printf("\t*** Contactos ***\n");
            mostrarLista(lista);
            printf("\t\tCual es el id del elemento? ");
            scanf("%d", &opcion);
            printf("\t\tCual es el nombre? ");
            scanf("%s", nombre);
            printf("\t\tCual es la edad? ");
            scanf("%d", &edad);
            modificarNodo(&lista, opcion, nombre, edad);
            break;
        case 3:
            printf("\t*** Eliminar el elemento ***\n");
            printf("\t*** Contactos ***\n");
            mostrarLista(lista);
            printf("\t\tCual es el id del elemento? ");
            scanf("%d", &opcion);
            eliminarNodo(&lista, opcion);
            printf("\t*** Elemento eliminado ***\n\n");
            break;
        case 4:
            printf("\t*** Lista de elementos ***\n");
            mostrarLista(lista);
            printf("\t*** Fin de la lista ***\n\n");
            break;
        case 5:
            printf("\t*** Saliendo del programa ***\n\n");
            break;
        default:
            printf("\t*** Opcion no valida ***\n\n");
            break;
        }
    } while (opcion != 5);
    return 0;
}
