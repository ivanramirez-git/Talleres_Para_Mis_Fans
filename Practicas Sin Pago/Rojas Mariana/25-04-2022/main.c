#include <stdio.h>

int sumaDeNumeros(int, int);
int restaDeNumeros(int, int);
int multiplicacionDeNumeros(int, int);
float divisionDeNumeros(int, int);

int main()
{
    int opcion, num1, num2, suma, resta, multi, divi;

    do
    {
        printf("1.Suma de dos numeros enteros.\n");
        printf("2.Resta de dos numeros enteros.\n");
        printf("3.Multiplicacion de dos numeros enteros.\n");
        printf("4.Division de dos numeros enteros.\n");
        printf("5.Salir del programa.\n");
        printf("Ingresar el numero que se quiera ejecutar:\n");
        scanf("%d", &opcion);

        if (opcion == 1)
        {
            printf("Ingresar dos numeros para sumar:\n");
            scanf("%d %d", &num1, &num2);
            suma = sumaDeNumeros(num1, num2);
            printf("La suma de los numeros es: %d\n", sumaDeNumeros(num1, num2));
        }
        else if (opcion == 2)
        {
            printf("Ingresar dos numeros para restar:\n");
            scanf("%d %d", &num1, &num2);
            printf("La resta de los numeros es: %d\n", restaDeNumeros(num1, num2));
        }
        else if (opcion == 3)
        {
            printf("Ingresar dos numeros para multiplicar:\n");
            scanf("%d %d", &num1, &num2);
            printf("La multiplicacion de los numeros es: %d\n", multiplicacionDeNumeros(num1, num2));
        }
        else if (opcion == 4)
        {
            printf("Ingresar dos numeros para dividir:\n");
            scanf("%d %d", &num1, &num2);
            printf("La division de los numeros es: %0.2f\n", divisionDeNumeros(num1, num2));
        }
    } while (opcion != 5);
    return 0;
}

int sumaDeNumeros(int num1, int num2)
{
    int suma;
    suma = num1 + num2;
    return suma;
}

int restaDeNumeros(int num1, int num2)
{
    int resta;
    resta = num1 - num2;
    return resta;
}

int multiplicacionDeNumeros(int num1, int num2)
{
    int multi;
    multi = num1 * num2;
    return multi;
}

float divisionDeNumeros(int num1, int num2)
{
    float divi = 0;
    if (num2 == 0)
    {
        printf("No se puede dividir por cero.\n");
    }
    else
    {
        divi = (float)num1 / num2;
    }
    return divi;
}

