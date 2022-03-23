#include <string.h>
using namespace std;
/** funcion para contar palabras*/
int contarPalabras(char texto[])
{
    int contador = 0;
    int i = 0;
    while (texto[i] != '\0')
    {
        if (texto[i] == ' ')
        {
            contador++;
        }
        i++;
    }
    return contador + 1;
}

/**Procedimiento invertir cadena*/
void Ivertir(char cade[])
{
    int i = 0;
    int j = strlen(cade) - 1;
    char aux;
    while (i < j)
    {
        aux = cade[i];
        cade[i] = cade[j];
        cade[j] = aux;
        i++;
        j--;
    }
}