/*funciones:
main
lecturafrase
validacionfrase
identificacionletras
calculafrecuencia
imprimir
*/
#include <stdio.h>

int lecturafrase(char frase[]);                           // lee una frase con espacios por consola
int validacionfrase(char frase[], int cantidad);                                      // valida que la frase no sea vacia ni contenga caracteres no validos, solo se pueden letras aA-zZ
int identificacionletras(char frase[], int cantidad);                                 // identifica las letras sin repetirse y devuelve la cantidad de letras distintas
void letrasdistintas(char frase[], char letras[]);                      // devuelve las letras distintas en un vector
void calculafrecuencia(char frase[], char letras[], int frecuencias[]); // calcula la frecuencia de cada letra y devuelve la cantidad de letras
void imprimir(char letras[], int frecuencias[]);                        // imprime la frecuencia de cada letra

/*ejemplo:

Prueba : Letras
Ingrese la cadena: JUAN_JOS1ESTEVEZ ESTARA#
Ingrese la cadena: JUAN JOSE ESTEVEZ ESTARA DE PASEO
Letras que aparecen: JUANOSETVZRDP
Frecuencia de letras: J:2 U:1 A:4 N:1 O:2 S:4 E:7 T:2 V:1 Z:1 R:1 D:1 P:1
*/
int main()
{
    char frase[100];
    int cantidad;
    printf("Prueba : Letras\n");
    do
    {
        printf("Ingrese la cadena: ");
        cantidad = lecturafrase(frase);
    } while (validacionfrase(frase, cantidad) == 0);
    int cantidadLetras = identificacionletras(frase, cantidad);
    char letras[cantidadLetras];
    int frecuencias[cantidadLetras];
    // zeros
    int i;
    for (i = 0; i < cantidadLetras; i++)
    {
        frecuencias[i] = 0;
    }
    letrasdistintas(frase, letras);
    calculafrecuencia(frase, letras, frecuencias);
    imprimir(letras, frecuencias);
    return 0;
}

int lecturafrase(char frase[])
{
    int i = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        frase[i] = c;
        i++;
    }
    frase[i] = '\0';
    return i;
}

int validacionfrase(char frase[], int cantidad)
{
    int i = 0;
    while (i < cantidad)
    {
        if (frase[i] < 'a' || frase[i] > 'z')
        {
            if (frase[i] < 'A' || frase[i] > 'Z')
            {
                if (frase[i] != ' ')
                {
                    return 0;
                }
            }
        }
        i++;
    }
    return 1;
}

int identificacionletras(char frase[], int cantidad)
{
    char letras[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < cantidad)
    {
        j = 0;
        while (j < 52)
        {
            if (frase[i] == letras[j])
            {
                k++;
                j = 52;
            }
            j++;
        }
        i++;
    }
    return k;
}

void letrasdistintas(char frase[], char letras[])
{
    int i = 0;
    int j = 0;
    while (frase[i] != '\0')
    {
        int k = 0;
        while (k < i)
        {
            if (frase[i] == frase[k])
            {
                break;
            }
            k++;
        }
        if (k == i)
        {
            letras[j] = frase[i];
            i++;
            j++;
        }
    }
}

void calculafrecuencia(char frase[], char letras[], int frecuencias[])
{
    int i = 0;
    while (letras[i] != '\0')
    {
        int j = 0;
        while (frase[j] != '\0')
        {
            if (letras[i] == frase[j])
            {
                frecuencias[i]++;
            }
            j++;
        }
        i++;
    }
}

void imprimir(char letras[], int frecuencias[])
{
    int i = 0;
    printf("Letras que aparecen: ");
    while (letras[i] != '\0')
    {
        // ignorar el espacio
        if (letras[i] != ' ')
        {
            printf("%c", letras[i]);
        }
        i++;
    }
    printf("\nFrecuencia de letras: ");
    while (letras[i] != '\0')
    {
        // ignorar el espacio
        if (letras[i] != ' ')
        {
            printf("%c:%d ", letras[i], frecuencias[i]);
        }
        i++;
    }
    printf("\n");
}
