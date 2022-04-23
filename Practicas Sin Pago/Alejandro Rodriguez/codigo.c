#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float nota1[5] = {2.5, 3.0, 4.8, 3.1, 2.1}, nota2[5] = {5.0, 4.0, 2.0, 3.0, 1.0}, nota3[5] = {1, 2, 3, 4, 5}, def[5], prom = 0, suma = 0;
    char nombres[5][30] = {"jose maria", "maria jose", "luisa fernanda", "luis alejandro", "santiago"}, apellidos[5][30] = {"diaz", "casas", "perez", "castaneda", "forero"};
    int cPerd, cSupProm, ubic, posmax, posmin;
    float max = 0, min = 5;
    printf("\nSISTEMA INTEGRAL DE NOTAS\n");
    /*for(ubic=0;ubic<10;ubic++)
    {
        printf("\nDigite el nombre del estudiante\n");
        gets(nombres[ubic]);
    }*/
    for (ubic = 0; ubic < 5; ubic++)
    {
        printf("\n%d\t%s", ubic + 1, nombres[ubic]);
    }
    printf("\n");
    system("pause");
    system("cls");

    ubic = 0;
    do
    {
        printf("\n%d\t%s", ubic + 1, apellidos[ubic]);
        ubic++;
    } while (ubic < 5);
    printf("\n");
    system("pause");
    system("cls");
    for (ubic = 0; ubic < 5; ubic++)
    {
        def[ubic] = (nota1[ubic] * 0.3 + nota2[ubic] * 0.3 + nota3[ubic] * 0.4);
    }
    printf("\nnum\tnombres\tapellidos\tnota1\tnota2\tnota3");
    ubic = 0;
    while (ubic < 5)
    {
        printf("\n%d\t%s\t%s\t%0.1f\t%0.1f\t%0.1f\t%0.2f", ubic + 1, apellidos[ubic], nombres[ubic], nota1[ubic], nota2[ubic], nota3[ubic], def[ubic]);
        ubic++;
    }
    printf("\n");
    system("pause");
    system("cls");
    for (ubic = 0; ubic < 5; ubic++)
    {
        if (def[ubic] > max)
        {
            max = def[ubic];
            posmax = ubic;
        }
    }
    for (ubic = 0; ubic < 5; ubic++)
    {
        if (def[ubic] < min)
        {
            min = def[ubic];
            posmin = ubic;
        }
    }
    printf("\nEl mejor estudiante es %s %s con nota definitiva de %0.2f", apellidos[posmax], nombres[posmax], def[posmax]);
    printf("\nEl peor estudiante es %s %s con nota definitiva de %0.2f", apellidos[posmin], nombres[posmin], def[posmin]);
    system("pause");
    system("cls");
    for (ubic = 0; ubic < 5; ubic++)
    {
        suma = suma + def[ubic];
    }
    prom = suma / 5;
    printf("\nEl promedio de notas definitivas es %0.2f", prom);
    system("pause");
    system("cls");
    cPerd = 0;
    cSupProm = 0;
    for (ubic = 0; ubic < 5; ubic++)
    {
        if (def[ubic] < prom)
        {
            cPerd++;
        }
        else
        {
            cSupProm++;
        }
    }
    printf("\nHay %d estudiantes con nota definitiva inferior al promedio", cPerd);
    printf("\nHay %d estudiantes con nota definitiva superior al promedio", cSupProm);
    system("pause");
    system("cls");
    return 0;
}