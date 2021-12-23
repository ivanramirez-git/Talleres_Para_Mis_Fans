
// Language: c
// Path: Jocelyn Nery/4punto.c

#include <stdio.h>

struct libro{
    char titulo[50];
    char autor[50];
    int anio;
    char editorial[50];
    int edicion;
    char codigo[50];
};

// Generar codigo de libro
char* generarCodigo(struct libro l){
    char codigo[50];
    strcpy(codigo, l.autor);
    strcat(codigo, l.editorial);
    strcat(codigo, to_string(l.anio));
    strcat(codigo, l.titulo);
    strcat(codigo, to_string(l.edicion));
    printf("Codigo: %s\n", codigo);
    return codigo;
}

int main(){
    struct libro l;
    printf("Ingrese el titulo del libro: ");
    scanf("%s", l.titulo);
    printf("Ingrese el autor del libro: ");
    scanf("%s", l.autor);
    printf("Ingrese el año de publicacion del libro: ");
    scanf("%d", &l.anio);
    printf("Ingrese la editorial del libro: ");
    scanf("%s", l.editorial);
    printf("Ingrese la edicion del libro: ");
    scanf("%d", &l.edicion);
    l.codigo = generarCodigo(l);
    return 0;
}