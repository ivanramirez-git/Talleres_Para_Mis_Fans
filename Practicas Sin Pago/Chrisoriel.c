// Una escuela aplica M examenes a N estudiantes, donde M y N son valores a capturar.
// Crear un programa que realice lo solicidado y presente el resultados obtenidos.
// - Solicitar los nombres de los estudiantes y las notas obtenidas en cada examen.
// Para cada estudiante, calcular e imprimir eñ promedio y determinar la solucion a presentar
/*
    a) El aspirante que obtenga un promedio menor a 71 es rechazado e indicara un mensaje
    b) El aspirante que obtenga un promedio entre 71 y 85 sera aceptado y adicional, se indicara otro mesaje: "Tu promedio es mayor a 70, pero menor o igual 85"
    c) El aspirante que obtenga un promedio mayor a 85 sera aceptado y adicional, se indicara otro mesaje: "Tu promedio es mayor a 85"
    d) ¿Cual es el promedio mas alto y quien lo obtuvo?
    e) ¿Cual es el promedio mas bajo y quien lo obtuvo?
    f) Identificar cuantos estudiantes pertenece a cada categoria (aceptados y rechazados)
*/

#include <stdio.h>

int main()
{
    printf("Bienvenido a la escuela de programacion\n");
    printf("Ingrese el numero de estudiantes: ");
    int n;
    scanf("%d", &n);
    printf("Ingrese el numero de examenes: ");
    int m;
    scanf("%d", &m);
    char estudiantes[n][20];
    int examenes[m];
    int promedio[n];
    int i, j, k;
    int promedio_mas_alto = 0;
    int promedio_mas_bajo = 100;
    int promedio_alto_estudiante = 0;
    int promedio_bajo_estudiante = 0;
    int aceptados = 0;
    int rechazados = 0;

    for (i = 0; i < n; i++)
    {
        printf("Ingrese el nombre del estudiante: ");
        scanf("%s", estudiantes[i]);
        printf("Ingrese las notas del estudiante: ");
        for (j = 0; j < m; j++)
        {
            scanf("%d", &examenes[j]);
        }
        promedio[i] = 0;
        for (j = 0; j < m; j++)
        {
            promedio[i] += examenes[j];
        }
        promedio[i] = promedio[i] / m;
        if (promedio[i] < 71)
        {
            printf("%s fue rechazado\n", estudiantes[i]);
            rechazados++;
        }
        else if (promedio[i] >= 71 && promedio[i] <= 85)
        {
            printf("%s fue aceptado\n", estudiantes[i]);
            aceptados++;
        }
        else
        {
            printf("%s fue aceptado\n", estudiantes[i]);
            aceptados++;
        }
        if (promedio[i] > promedio_mas_alto)
        {
            promedio_mas_alto = promedio[i];
            promedio_alto_estudiante = i;
        }
        if (promedio[i] < promedio_mas_bajo)
        {
            promedio_mas_bajo = promedio[i];
            promedio_bajo_estudiante = i;
        }
    }
    printf("El promedio mas alto fue %d y fue obtenido por %s\n", promedio_mas_alto, estudiantes[promedio_alto_estudiante]);
    printf("El promedio mas bajo fue %d y fue obtenido por %s\n", promedio_mas_bajo, estudiantes[promedio_bajo_estudiante]);
    for (i = 0; i < n; i++)
    {
        if (promedio[i] < 71)
        {
            printf("%s fue rechazado\n", estudiantes[i]);
        }
        else if (promedio[i] >= 71 && promedio[i] <= 85)
        {
            printf("%s fue aceptado\n", estudiantes[i]);
        }
        else
        {
            printf("%s fue aceptado\n", estudiantes[i]);
        }
    }
    printf("Cantidad de estudiantes aceptados: %d\n", aceptados);
    printf("Cantidad de estudiantes rechazados: %d\n", rechazados);

    return 0;
}
