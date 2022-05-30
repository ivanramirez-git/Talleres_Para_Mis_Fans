/*
karen stefania rodriguez duque codigo 104340
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 5


void pedirDatos(float v[], float r[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Ingrese el voltaje de la fuente %d: ", i + 1);
        scanf("%f", &v[i]);
        printf("Ingrese el valor de la resistencia %d en Ohmios: ", i + 1);
        scanf("%f", &r[i]);
    }
}



int menu()
{
    char opcion[1];
    printf("\nIngrese una opcion: S: Serie, P: Paralelo, I: Imprimir, E: Salir\n");
    scanf("%s", &opcion);
    switch (opcion[0])
    {
    case 'S':
    case 's':
        return 1;
    case 'P':
    case 'p':
        return 2;
    case 'I':
    case 'i':
        return 3;
    case 'E':
    case 'e':
        return 0;
    default:
        return -1;
    }
}


void Serie(float v[], float r[], int n)
{
    // Suma de todas las resistencias
    int i;
    float suma = 0;
    for (i = 0; i < n; i++)
    {
        suma += r[i];
    }

    // Mostrar resultado
    printf("\nEl resultado de la serie es: %f", suma);
}

void Paralelo(float v[], float r[], int n)
{
    float p;
    // Rparalelo = R1 * R2 / (R1 + R2)
    int i;
    for (i = 1; i < n; i++)
    {
        p = (r[i - 1] * r[i]) / (r[i - 1] + r[i]);
    }

    // Mostrar resultado
    printf("\nEl resultado paralelo es: %f", p);
}


void imprimir(float v[], float r[], int n)
{
    // encabezados
    printf("\n\nItem\tR(Ohm)\tCorriente(A)\tVoltaje(V)\tPotencia(W)\n");

    // datos
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t%f\t%f\t%f\t%f\n", i + 1, r[i], v[i] / r[i], v[i], v[i] * r[i]);
    }

    printf("\n\n");
}

int main()
{
    float v[N], r[N];
    int opcion;

    pedirDatos(v, r, N);

    do
    {
        opcion = menu();
        switch (opcion)
        {
        case 1:
            Serie(v, r, N);
            break;
        case 2:
            Paralelo(v, r, N);
            break;
        case 3:
            imprimir(v, r, N);
            break;
        case 0:
            break;
        default:
            printf("Opcion no valida");
            break;
        }
    } while (opcion != 0);

    return 0;
}
