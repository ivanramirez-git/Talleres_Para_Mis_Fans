#include <stdio.h>

struct postulante{
// nombre
    char nombre[20];
// direccion
    char direccion[20];
// telefono
    char telefono[10];
// correo
    char correo[20];
};

struct comision{
    // postulante
    struct postulante postulante;
    // Resultado A=Aceptado, R=Rechazado, P=Pendiente
    char resultado;
    // Indice
    int dia;
    int orden;
};

// funcion que traspone una matriz de 6x8 a 8x6, siendo el primer elemento de la matriz de 6x8 el ultimo elemento de la matriz de 8x6
void trasponer(struct postulante matriz[6][8], struct postulante matriz_traspuesta[8][6]) {
    int i, j, k, l;
    for (i = 6, j = 0; i > 0; i--, j++) {
        for (k = 8, l = 0; k > 0; k--, l++) {
            matriz_traspuesta[l][j] = matriz[i-1][k-1];
        }
    }
}

// comision
struct comision entrevista(int dia, int orden, struct postulante p){

    struct comision c;
    c.dia = dia;
    c.orden = orden;
    c.postulante = p;
    printf("Ingrese el resultado de la entrevista, A=Aceptado, R=Rechazado, P=Pendiente: ");
    scanf("%c", &c.resultado);

    return c;
}

int main(){
    // Matriz de 6x8, enumerada del 1 al 48
    struct postulante matriz[6][8];
    struct postulante matriz_traspuesta[8][6];
    struct comision comisiones[48];

    int i, j, k;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 8; j++) {
            printf("Ingrese el nombre del postulante %d: ", (i*8)+j+1);
            scanf("%s", matriz[i][j].nombre);
            printf("Ingrese la direccion del postulante %d: ", (i*8)+j+1);
            scanf("%s", matriz[i][j].direccion);
            printf("Ingrese el telefono del postulante %d: ", (i*8)+j+1);
            scanf("%s", matriz[i][j].telefono);
            printf("Ingrese el correo del postulante %d: ", (i*8)+j+1);
            scanf("%s", matriz[i][j].correo);
        }
    }

    // Trasponer la matriz
    trasponer(matriz, matriz_traspuesta);

    // Entrevistas
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 8; j++) {
            comisiones[(i*8)+j] = entrevista(i+1, j+1, matriz_traspuesta[j][i]);
        }
    }

    // Imprimir resultados
    for (i = 0; i < 48; i++) {
        printf("\n\nResultado de la entrevista %d: ", i+1);
        printf("\nNombre: %s", comisiones[i].postulante.nombre);
        printf("\nDireccion: %s", comisiones[i].postulante.direccion);
        printf("\nTelefono: %s", comisiones[i].postulante.telefono);
        printf("\nCorreo: %s", comisiones[i].postulante.correo);
        printf("\nResultado: %c", comisiones[i].resultado);
        printf("\nDia: %d", comisiones[i].dia);
        printf("\nOrden: %d", comisiones[i].orden);
    }

    return 0;
}