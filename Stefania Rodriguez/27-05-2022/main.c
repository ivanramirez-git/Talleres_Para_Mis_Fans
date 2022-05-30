/*
Escriba un algoritmo en C que le permita resolver un circuito de5resistencias teniendo en cuenta las siguientes
condiciones:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 5

/*
1. El programa le solicita al usuario que ingrese el valor del voltaje de la fuenteyel valor de cinco(5) resis
tencias en Ohmios(5%).
*/
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

/*
2. Luego de ingresar los valores de voltajeyresistencias,aparecerá un menú donde le pregunte al usuario
que digite la letra"P"si quiere resolver el circuito en Paralelooque digite la letra"S"si quiere resolver el
circuito en Serie.(10%).
*/
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

/*
3. Cree una función para cada opción:Función llamada"Serie",tendrá toda la lógica de un circuito serie
teniendo en cuenta que el voltaje en cada resistencia se divide.Función llamada"Paralelo",tendrá toda
la lógica de un circuito en paralelo teniendo en cuenta que la corriente en cada resistencia se divide
(50%).
*/
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

/*
4. Una vez calculados todos los valores,deberá generar una matriz con la siguiente información con el
formato mostrado en la siguiente tabla(35%):
Item R(Ohm) Corriente(A) Voltaje(V) Potencia(W)
*/
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
