#include <stdio.h>

struct examen {

    char rut[10];
    char correo[20];
    float puntaje_escrita;
    float puntaje_oral;
};

// TDA pila
struct nodo {
    struct examen dato;
    struct nodo *sig;
};

struct pila {
    struct nodo *tope;
};

// Funcion que crea una pila
struct pila *crear_pila() {
    struct pila *p = (struct pila *) malloc(sizeof (struct pila));
    p->tope = NULL;
    return p;
}

// Funcion que inserta un elemento en la pila
void insertar_pila(struct pila *p, struct examen dato) {
    struct nodo *nuevo = (struct nodo *) malloc(sizeof (struct nodo));
    nuevo->dato = dato;
    nuevo->sig = p->tope;
    p->tope = nuevo;
}

// Funcion que saca un elemento de la pila
struct examen sacar_pila(struct pila *p) {
    struct examen dato;
    struct nodo *aux;
    if (p->tope != NULL) {
        dato = p->tope->dato;
        aux = p->tope;
        p->tope = p->tope->sig;
        free(aux);
    }
    return dato;
}

// colocar puntaje examen oral
void colocar_puntaje_oral(struct pila *p, float puntaje) {
    struct examen dato;
    dato = sacar_pila(p);
    dato.puntaje_oral = puntaje;
    insertar_pila(p, dato);
}

// Revisar si el examen en la parte escrita tiene mas de 60 puntos
int examen_escrita(struct examen dato) {
    if (dato.puntaje_escrita > 60) {
        // 
        printf("El examen escrita fue aprobado\n");
        return 1;
    } else {
        printf("El examen escrita fue reprobado\n");
        // Colocar puntaje en el examen oral
        printf("Ingrese el puntaje del examen oral: ");
        scanf("%f", &dato.puntaje_oral);
        return 0;
    }
}

int main(){
    struct pila *p = crear_pila();
    struct examen dato;
    int i;
    for (i = 0; i < 3; i++) {
        printf("Ingrese el rut: ");
        scanf("%s", dato.rut);
        printf("Ingrese el correo: ");
        scanf("%s", dato.correo);
        printf("Ingrese el puntaje escrita: ");
        scanf("%f", &dato.puntaje_escrita);
        insertar_pila(p, dato);
    }
    int aprobados = 0;
    for (i = 0; i < 3; i++) {
        dato = sacar_pila(p);
        if (examen_escrita(dato)) {
            aprobados++;
        }
    }
    printf("Aprobaron %d alumnos\n", aprobados);
    return 0;
}

// 