#include <stdio.h> // printf
#include <string.h> // strlen
#include <stdlib.h> // malloc
#define TAM_DATOS 100 // Tamaño de los datos
#define TAM_STRING 30 // Tamaño de los strings

struct Dato{
    
    // documento
    char documento[TAM_STRING];
    // nombre
    char nombre[TAM_STRING];
    // edad
    int edad;
    // sexo
    char sexo;

};


// Funcion para guardar los datos en el archivo csv
void guardar_datos(struct Dato datos[TAM_DATOS], int cantidad_datos){

    FILE *archivo;
    archivo = fopen("datos.csv", "w");

    if(archivo == NULL){
        printf("Error al abrir el archivo");
        exit(1);
    }

    // Escribir encabezados
    fprintf(archivo, "Documento\tNombre\tEdad\tSexo\n");

    // Escribir datos
    int i;
    for( i = 0; i < cantidad_datos; i++){
        fprintf(archivo, "%s\t%s\t%d\t%c", datos[i].documento, datos[i].nombre, datos[i].edad, datos[i].sexo);
        // si no es el ultimo dato, escribir un salto de linea
        if(i != cantidad_datos - 1){
            fprintf(archivo, "\n");
        }
    }

    // Cerrar archivo
    fclose(archivo);
}

// Funcion para leer los datos del archivo csv
int leer_datos(struct Dato datos[TAM_DATOS], int cantidad_datos){

    int aux_cantidad_datos = cantidad_datos;
    char linea[TAM_DATOS];

    FILE *archivo;
    archivo = fopen("datos.csv", "r");

    if(archivo == NULL){
        printf("Error al abrir el archivo");
        exit(1);
    }

    // Leer encabezados
    fgets(linea, TAM_DATOS, archivo);

    // Leer datos
    while(!feof(archivo)){
        // Leer linea y validar
        fgets(linea, TAM_DATOS, archivo);

        if(strlen(linea) > 3 && linea[0] != '\n'){
            // Guardar datos
            sscanf(linea, "%s\t%s\t%d\t%c", datos[cantidad_datos].documento, datos[cantidad_datos].nombre, &datos[cantidad_datos].edad, &datos[cantidad_datos].sexo);
            aux_cantidad_datos++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    return aux_cantidad_datos;
}

// Funcion para mostrar los datos
void mostrar_datos(struct Dato datos[TAM_DATOS], int cantidad_datos){
    int i ;
    for( i = 0; i < cantidad_datos; i++){
        printf("\nDocumento: %s\nNombre: %s\nEdad: %d\nSexo: %c\n", datos[i].documento, datos[i].nombre, datos[i].edad, datos[i].sexo);
    }

    return;
}

// Funcion para buscar un dato en la lista
int buscar_dato(struct Dato datos[TAM_DATOS], int cantidad_datos){

    int posicion = -1;
    char documento[TAM_STRING];

    printf("\nIngrese el documento del dato a buscar: ");
    scanf("%s", documento);
    int i;
    for( i = 0; i < cantidad_datos; i++){
        if(strcmp(documento, datos[i].documento) == 0){
            posicion = i;
            break;
        }
    }
    return posicion;
}

// Funcion para modificar un dato en la lista
void modificar_dato(struct Dato datos[TAM_DATOS], int cantidad_datos){

    printf("\nModificar dato\n");
    int posicion = buscar_dato(datos, cantidad_datos);

    if(posicion != -1){
        printf("\nDocumento: %s\nNombre: %s\nEdad: %d\nSexo: %c\n", datos[posicion].documento, datos[posicion].nombre, datos[posicion].edad, datos[posicion].sexo);
        printf("\nIngrese el nuevo nombre: ");
        scanf("%s", datos[posicion].nombre);
        printf("\nIngrese la nueva edad: ");
        scanf("%d", &datos[posicion].edad);
        printf("\nIngrese el nuevo sexo: ");
        // Limpiar buffer
        fflush(stdin);
        scanf("%c", &datos[posicion].sexo);
    }

    return;
}

// Funcion para eliminar un dato en la lista, retorna la cantidad de datos restantes
int eliminar_dato(struct Dato datos[TAM_DATOS], int cantidad_datos){

    printf("\nEliminar dato\n");
    int posicion = buscar_dato(datos, cantidad_datos);

    if(posicion != -1){
        int i;
        for( i = posicion; i < cantidad_datos - 1; i++){
            datos[i] = datos[i + 1];
        }
        cantidad_datos--;
    }

    return cantidad_datos;
}

// Funcion para ordenar los datos por nombre
void ordenar_datos(struct Dato datos[TAM_DATOS], int cantidad_datos){

    struct Dato aux;
    int i;
    for( i = 0; i < cantidad_datos - 1; i++){
        int j;
        for( j = i + 1; j < cantidad_datos; j++){
            if(strcmp(datos[i].nombre, datos[j].nombre) > 0){
                aux = datos[i];
                datos[i] = datos[j];
                datos[j] = aux;
            }
        }
    }

    return;
}

// Funcion agregar datos, retorna la cantidad de datos
int agregar_datos(struct Dato datos[TAM_DATOS], int cantidad_datos){

    printf("\nAgregar dato\n");
    struct Dato nuevo_dato;

    printf("\nIngrese el documento: ");
    scanf("%s", nuevo_dato.documento);
    printf("\nIngrese el nombre: ");
    scanf("%s", nuevo_dato.nombre);
    printf("\nIngrese la edad: ");
    scanf("%d", &nuevo_dato.edad);
    printf("\nIngrese el sexo: ");
    // Limpiar buffer
    fflush(stdin);
    scanf("%c", &nuevo_dato.sexo);

    datos[cantidad_datos] = nuevo_dato;
    cantidad_datos++;

    return cantidad_datos;
}

// Funcion para mostrar el menu, se carga y se guarda automaticamente
void mostrar_menu(){
    
    printf("\n1. Agregar dato\n");
    printf("2. Buscar dato\n");
    printf("3. Modificar dato\n");
    printf("4. Eliminar dato\n");
    printf("5. Ordenar datos\n");
    printf("6. Mostrar datos\n");
    printf("7. Salir\n");

    return;
}

// Switch para el menu
void menu(struct Dato datos[TAM_DATOS], int cantidad_datos){

    int opcion;

    do{
        mostrar_menu();
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                cantidad_datos = agregar_datos(datos, cantidad_datos);
                guardar_datos(datos, cantidad_datos);
                break;
            case 2:
                printf("\nDato: %s\n", datos[buscar_dato(datos, cantidad_datos)].nombre);
                break;
            case 3:
                modificar_dato(datos, cantidad_datos);
                guardar_datos(datos, cantidad_datos);
                break;
            case 4:
                cantidad_datos = eliminar_dato(datos, cantidad_datos);
                guardar_datos(datos, cantidad_datos);
                break;
            case 5:
                ordenar_datos(datos, cantidad_datos);
                break;
            case 6:
                mostrar_datos(datos, cantidad_datos);
                break;
            case 7:
                break;
            default:
                printf("\nOpcion incorrecta\n");
                break;
        }
    }while(opcion != 7);

    return;
}

// Funcion principal
int main(){

    struct Dato datos[TAM_DATOS];
    int cantidad_datos = 0;

    char cargar_datos = 'n';

    printf("\nCargar datos? (s/n): ");
    scanf("%c", &cargar_datos);

    if(cargar_datos == 's'){
        cantidad_datos = leer_datos(datos, 0);
    }

    menu(datos, cantidad_datos);

    return 0;
}
