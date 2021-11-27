#include <stdio.h>

// Desarolle una funcion llamada double notaMasRepite(double notas[], int size, double valoresExcluidos[], int sizeValoresExcluir), la cual encargara de determinar y retornar la nota que mas se repide de un listado notas[].
double notaMasRepite(double notas[], int size, double valoresExcluidos[], int sizeValoresExcluidos) {
    // Retorna la nota que mas se repite de un listado notas[], sin tener en cuenta las notas que se encuentran en el listado valoresExcluidos[].
    int i, j, k, contador = 0, contadorMax = 0;
    double notaMasRepite = 0;
    for (i = 0; i < size; i++) {
        contador = 0;
        // validar si i esta en el listado valoresExcluidos[].
        for (j = 0; j < sizeValoresExcluidos; j++) {
            if (notas[i] == valoresExcluidos[j]) {
                break;
            }
        }
        if (j == sizeValoresExcluidos) {
            for (k = 0; k < size; k++) {
                if (notas[i] == notas[k]) {
                    contador++;
                }
            }
            if (contador > contadorMax) {
                contadorMax = contador;
                notaMasRepite = notas[i];
            }
        }
    }
    return notaMasRepite;
}

// Desarrollar una funcion lalmada void obtener NotasEstudiante(double notas[], int size), la cual se encargara de llenar el arreglo con los datos introducidos por el usuario.
void obtenerNotasEstudiante(double notas[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        //Validar que sea menor o igual a 100, y mayor o igual a 0.
        do {
            printf("Introducir Nota Estudiante No. %d: ", i + 1);
            scanf("%lf", &notas[i]);
        } while (notas[i] < 0 || notas[i] > 100);
    }
}

// Desarrollar una funcion llamada void obtenerTop3NotasRepite(double top3Notas[3], double notasAnalizar[], int sizeNotasAnalizar), la cual se encargara llenar el arreglo top3Notas con los 3 valores mas repetidos de notasAnalizar[].
void obtenerTop3NotasRepite(double top3Notas[3], double notasAnalizar[], int sizeNotasAnalizar) {
    int i, j, k, contador = 0, contadorMax = 0;
    double notaMasRepite = 0;
    for(i = 0; i<sizeNotasAnalizar; i++){
        contador = 0;
        for(j = 0; j<sizeNotasAnalizar; j++){
            if(notasAnalizar[i] == notasAnalizar[j]){
                contador++;
            }
        }
        if(contador > contadorMax){
            contadorMax = contador;
            notaMasRepite = notasAnalizar[i];
        }
    }
    top3Notas[0] = notaMasRepite;
    contadorMax = 0;
    notaMasRepite = 0;
    for(i = 0; i<sizeNotasAnalizar; i++){
        contador = 0;
        for(j = 0; j<sizeNotasAnalizar; j++){
            if(notasAnalizar[i] == notasAnalizar[j]){
                contador++;
            }
        }
        if(contador > contadorMax && notasAnalizar[i] != top3Notas[0]){
            contadorMax = contador;
            notaMasRepite = notasAnalizar[i];
        }
    }
    top3Notas[1] = notaMasRepite;
    contadorMax = 0;
    notaMasRepite = 0;
    for(i = 0; i<sizeNotasAnalizar; i++){
        contador = 0;
        for(j = 0; j<sizeNotasAnalizar; j++){
            if(notasAnalizar[i] == notasAnalizar[j]){
                contador++;
            }
        }
        if(contador > contadorMax && notasAnalizar[i] != top3Notas[0] && notasAnalizar[i] != top3Notas[1]){
            contadorMax = contador;
            notaMasRepite = notasAnalizar[i];
        }
    }
    top3Notas[2] = notaMasRepite;
}

int main(){
    // Pedir numero de notas al usuario.
    int numeroNotas;
    printf("Introducir Cantidad Estudiantes Evaluar: ");
    scanf("%d", &numeroNotas);
    // Pedir notas excluidas al usuario.
    //int numeroNotasExcluidas;
    //printf("Ingrese el numero de notas excluidas: ");
    //scanf("%d", &numeroNotasExcluidas);
    
    // Ingresar notas al arreglo.
    double notas[numeroNotas];
    //printf("Ingrese las notas del estudiante: \n");
    obtenerNotasEstudiante(notas, numeroNotas);

    // Ingresar notas excluidas al arreglo.
    //double notasExcluidas[numeroNotasExcluidas];
    //printf("Ingrese las notas excluidas: \n");
    //obtenerNotasEstudiante(notasExcluidas, numeroNotasExcluidas);

    // Obtener nota mas repetida sin tener en cuenta las notas excluidas.
    //double notaMasRepiten = notaMasRepite(notas, numeroNotas, notasExcluidas, numeroNotasExcluidas);
    //printf("La nota mas repetida es: %.2lf\n", notaMasRepiten);

    printf("\n");

    // Listado Notas Registradas
    printf("*************** Listado Notas Registradas *****************\n");
    int i;
    
    printf("    Nota\n");
    for (i = 0; i < numeroNotas; i++) {
        printf("   %.2lf\n", notas[i]);
    }

    printf("---------\n\n");
    // Obtener top 3 notas mas repetidas.
    double top3Notas[3];
    obtenerTop3NotasRepite(top3Notas, notas, numeroNotas);
    printf("******** TOP 3 NOTAS ********\n");
    i=0;
    for(i = 0; i<3; i++){
        printf("   %.2lf\n", top3Notas[i]);
    }

    printf("\n");
    // Promedio total de notas.
    double promedioTotal=0;
    i=0;
    while(i<numeroNotas){
        promedioTotal+=notas[i];
        i++;
    }
    promedioTotal=promedioTotal/numeroNotas;
    printf("Promedio:   %.2lf\n", promedioTotal);

    return 0;    
}
