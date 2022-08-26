#include <stdio.h>

int lecturacadena(char cadena[], int longitud)
{
    int i, longitudcadena;
    for (i = 0; i < longitud; i++)
    {
        scanf("%c", &cadena[i]);
        if (cadena[i] == '\n')
        {
            longitudcadena = i;
            break;
        }
    }
    return longitudcadena;
}

// Leer 3 caracteres
void lecturacadena3(char cadena[])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        scanf("%c", &cadena[i]);
    }
}

// Elimina caracteres indistintamente si son mayusculas o minusculas
void eliminacaracteres(char cadena[], int longitud, char a, char b, char c)
{
    int i, j;
    for (i = 0; i < longitud; i++)
    {
        if (cadena[i] == a || cadena[i] == b || cadena[i] == c || cadena[i] == a - 32 || cadena[i] == b - 32 || cadena[i] == c - 32 || cadena[i] - 32 == a || cadena[i] - 32 == b || cadena[i] - 32 == c)
        {
            for (j = i; j < longitud; j++)
            {
                cadena[j] = cadena[j + 1];
            }
            i--;
            longitud--;
        }
    }
}

// Imprime una cadena de caracteres
void imprimircadena(char cadena[], int longitud)
{
    int i;
    for (i = 0; i < longitud; i++)
    {
        printf("%c", cadena[i]);
    }
}

// Main
int main()
{
    printf("Prueba 4: Nombre [num unico]\n");
    printf("Supresion de caracteres\n");
    printf("Ingrese cadena: ");
    char cadena[100];
    int longitudcadena = lecturacadena(cadena, 100);
    
    printf("Caracter a suprimir 1: ");
    char a;
    scanf("%c", &a);
    printf("Caracter a suprimir 2: ");
    char b;
    scanf("%c", &b);
    scanf("%c", &b);
    printf("Caracter a suprimir 3: ");
    char c;
    scanf("%c", &c);
    scanf("%c", &c);

    eliminacaracteres(cadena, longitudcadena, a, b, c);

    printf("Resultado: ");
    imprimircadena(cadena, longitudcadena);

    return 0;
}
