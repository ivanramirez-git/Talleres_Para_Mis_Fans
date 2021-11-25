#include <stdio.h>
#include <stdlib.h>



/**
Desarrollar un programa que almacene N cantidad de matriculas introducidas por el usuario.
También el programa debe permitir almacenar la nota de cada matrícula y al final mostrar
un listado de las matrículas y notas introducidas. Este listado debe estar formateado.
*/



void obtenerDatosEstudiante(int mat[], float notas[], int size){
int i;
for(i = 0; i < size; i++){
printf("Introducir Matr%ccula Estudiante No.%d: ", 161, i+1);
scanf("%d", &mat[i]);
printf("Introducir Nota Estudiante No.%d: ", i+1);
scanf("%f", &notas[i]);
}
return;
}



void imprimirDatosEstudiante(int mat[], float notas[], int size){
int i;
char textoMatricula[12];



sprintf(textoMatricula,"Matr%ccula", 161);



printf("%-10s %10s\n", textoMatricula, "Nota");



for(i =0; i < size; i++){
printf("%-10d %10.2f\n", mat[i], notas[i]);
}
}
int main(){



int cantEstudiantes;
int i;



printf("Introducir cantidad estudiantes a evaluar: ");
scanf("%d", &cantEstudiantes);



int matriculas[cantEstudiantes];
float notas[cantEstudiantes];



obtenerDatosEstudiante(matriculas, notas, cantEstudiantes);



printf("\n\n****************** Listado Estudiantes ******************\n");



imprimirDatosEstudiante(matriculas,notas,cantEstudiantes);
printf("\n\n");


printf("\n________________________________________________________________\n");

// Imprimir el promedio de las notas
float promedio = 0;
for(i = 0; i < cantEstudiantes; i++){
promedio += notas[i];
}
promedio = promedio / cantEstudiantes;
printf("El promedio de las notas es: %.2f\n", promedio);

// Imprimir la nota maxima
float notaMaxima = 0;
for(i = 0; i < cantEstudiantes; i++){
if(notas[i] > notaMaxima){
notaMaxima = notas[i];
}
}
printf("La nota maxima es: %.2f\n", notaMaxima);


}