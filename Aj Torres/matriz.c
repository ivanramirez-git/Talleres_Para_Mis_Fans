#include <stdio.h>

// Programa principal
int main() {
    float notas[3][4] = {0};
    float porcentajes[4] = {0};

    // Pedimos las notas
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Introduzca la nota %d del alumno %d: ", j + 1, i + 1);
            scanf("%f", &notas[i][j]);
            // validar que este entre 0 y 10
            while (notas[i][j] < 0 || notas[i][j] > 10) {
                printf("La nota debe estar entre 0 y 10.\n");
                printf("Introduzca la nota %d del alumno %d: ", j + 1, i + 1);
                scanf("%f", &notas[i][j]);
            }
        }
    }

    // Pedirmos los porcentajes
    for (int i = 0; i < 4; i++) {
        printf("Introduzca el porcentaje %d: ", i + 1);
        scanf("%f", &porcentajes[i]);
        // validar que este entre 0 y 1
        while (porcentajes[i] < 0 || porcentajes[i] > 1) {
            printf("El porcentaje debe estar entre 0 y 1.\n");
            printf("Introduzca el porcentaje %d: ", i + 1);
            scanf("%f", &porcentajes[i]);
        }
    }

    // Calculamos las notas finales
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            notas[i][j] = notas[i][j] * porcentajes[j];
        }
    }

    // Mostramos promedios de cada estudiante
    int mayorPromedio = 0;
    int indice = 0;
    for (int i = 0; i < 3; i++) {
        float promedio = 0;
        for (int j = 0; j < 4; j++) {
            promedio += notas[i][j];
        }
        printf("Estudiante %d: %.2f\n", i + 1, promedio);
        if (promedio > mayorPromedio) {
            mayorPromedio = promedio;
            indice = i;
        }
    }

    // Mostramos el estudiante con mayor promedio
    printf("El estudiante con mayor promedio es el %d con un promedio de %.2f\n", indice + 1, mayorPromedio);

    return 0;
}