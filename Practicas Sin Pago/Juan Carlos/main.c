#include <stdio.h>
#include <conio.h>
#include <windows.h>
// Contar cuantas vocales y consonantes tiene una cadena
int main()
{
    char cadena[100];
    int vocales = 0, consonantes = 0;
    printf("Introduce una cadena: ");
    fgets(cadena, 100, stdin);
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u' || cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')
        {
            vocales++;
        }
        else
        {
            // Validar que sea una consonante
            if (cadena[i] >= 'A' && cadena[i] <= 'Z' || cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                consonantes++;
            }
        }
    }
    printf("La cadena tiene %d vocales y %d consonantes\n", vocales, consonantes);
    return 0;
}