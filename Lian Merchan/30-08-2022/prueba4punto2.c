#include <stdio.h>

// funcion reemplazar palabra por otra
/*
Prueba 4: Reemplazo
Ingrese frase: Yo soy ecuatoriano, si senor.
Ingrese palabra a buscar: soy
Ingrese palabra a de remplazo: estoy
Nueva frase: Yo estoy ecuatoriano, si senor.
*/

// funciones
void pedirFrase(char frase[], int tam);
void reemplazarPalabra(char *frase, char *palabra, char *nuevaPalabra);
void imprimirFrase(char *frase);
// stringstr
char *stringstr(char *cadena, char *subcadena);
// stringcpy
char *stringcpy(char *destino, char *origen);
// stringlen
int stringlen(char *cadena);
// stringcmp
int stringcmp(char *cadena1, char *cadena2);
// stringcat
char *stringcat(char *cadena1, char *cadena2);
// stringchr
char *stringchr(char *cadena, char caracter);

int main()
{
    printf("Prueba 4: Reemplazo\n");
    char frase[100];
    char palabra[100];
    char nuevaPalabra[100];
    pedirFrase(frase, 100);
    printf("Ingrese palabra a buscar: ");
    scanf("%s", palabra);
    printf("Ingrese palabra a de remplazo: ");
    scanf("%s", nuevaPalabra);
    reemplazarPalabra(frase, palabra, nuevaPalabra);
    imprimirFrase(frase);
    return 0;
}

void pedirFrase(char frase[], int tam)
{
    printf("Ingrese frase: ");
    while (scanf("%[^\n]", frase) != 1)
    {
        printf("Error, ingrese frase: ");
        while (getchar() != '\n')
            ;
    }
}

// stringstr
char *stringstr(char *cadena, char *subcadena)
{
    int i = 0;
    int j = 0;
    while (cadena[i] != '\0')
    {
        if (cadena[i] == subcadena[j])
        {
            j++;
            if (subcadena[j] == '\0')
            {
                return &cadena[i];
            }
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
        i++;
    }
    return NULL;
}

// stringcpy
char *stringcpy(char *destino, char *origen)
{
    int i = 0;
    while (origen[i] != '\0')
    {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
    return destino;
}

// stringlen
int stringlen(char *cadena)
{
    int i = 0;
    while (cadena[i] != '\0')
    {
        i++;
    }
    return i;
}

// stringcmp
int stringcmp(char *cadena1, char *cadena2)
{
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0')
    {
        if (cadena1[i] != cadena2[i])
        {
            return cadena1[i] - cadena2[i];
        }
        i++;
    }
    return cadena1[i] - cadena2[i];
}

// stringcat
char *stringcat(char *cadena1, char *cadena2)
{
    int i = 0;
    int j = 0;
    while (cadena1[i] != '\0')
    {
        i++;
    }
    while (cadena2[j] != '\0')
    {
        cadena1[i] = cadena2[j];
        i++;
        j++;
    }
    cadena1[i] = '\0';
    return cadena1;
}

// stringchr
char *stringchr(char *cadena, char caracter)
{
    int i = 0;
    while (cadena[i] != '\0')
    {
        if (cadena[i] == caracter)
        {
            return &cadena[i];
        }
        i++;
    }
    return NULL;
}

void reemplazarPalabra(char *frase, char *palabra, char *nuevaPalabra)
{
    char *p = frase;
    char *q = frase;
    char aux[100];

    char *esta = frase;
    if ((esta = stringstr(esta, palabra)) != NULL)
    {
        while (*p != '\0')
        {
            if (*p == *palabra)
            {
                stringcpy(aux, p);
                stringcpy(p, nuevaPalabra);
                p += stringlen(nuevaPalabra);
                stringcpy(p, aux);
                p += stringlen(aux);
            }
            else
            {
                *q = *p;
                p++;
                q++;
            }
        }
        char *r = frase;
        r = stringstr(r, palabra);
        if (r != NULL)
        {
            while (*r != '\0')
            {
                *r = *(r + stringlen(palabra));
                r++;
            }
        }
    }
    else
    {
        printf("No existe palabra buscada\n");
    }
}

void imprimirFrase(char *frase)
{
    printf("Nueva frase: %s\n", frase);
}