#include <stdio.h>

int main(){

    // Pedir al usuario una cantidad n de alumnos
    int n;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);


    // 4 Vectores inicializados en 0 NUM_CONTROL, CAL1, CAL2, CAL3, PROMEDIO
    float num_control[n];
    float cal1[n];
    float cal2[n];
    float cal3[n];
    float promedio[n];

    // Inicializar los vectores
    for(int i = 0; i < n; i++){
        num_control[i] = 0;
        cal1[i] = 0;
        cal2[i] = 0;
        cal3[i] = 0;
        promedio[i] = 0;
    }

    // Pedir al usuario los datos de cada alumno
    for(int i = 0; i < n; i++){
        printf("\nAlumno %d\n", i+1);
        printf("Numero de control: ");
        scanf("%f", &num_control[i]);
        printf("Calificacion 1: ");
        scanf("%f", &cal1[i]);
        printf("Calificacion 2: ");
        scanf("%f", &cal2[i]);
        printf("Calificacion 3: ");
        scanf("%f", &cal3[i]);
    }

    // Calcular el promedio de cada alumno
    for(int i = 0; i < n; i++){
        promedio[i] = (cal1[i] + cal2[i] + cal3[i]) / 3;
    }

    // Imprimir los resultados
    printf("\n\nN.o de control\tCalificacion 1\tCalificacion 2\tCalificacion 3\tPromedio\n");
    for(int i = 0; i < n; i++){
        printf("%.0f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", num_control[i], cal1[i], cal2[i], cal3[i], promedio[i]);
    }

    // Sumatoria de 0 a 100
    float suma = 0;
    for(int i = 0; i < n; i++){
        suma += promedio[i];
    }
    // Imprimir
    printf("\n\nLa suma de los promedios es: %.2f\n", suma);

    // copilot saluda   //
        
    
    return 0;
}