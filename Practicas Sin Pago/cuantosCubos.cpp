/*
N:
¿Cuántos paralelepípedos rectangulares podemos construir con estos
cubos? Escriba un programa que encuentre el número de formas en que se
puede construir un paralelepípedo rectangular si sabemos cuántos cubos
con un lado unidad tenemos.
*/
// Language: cpp
// Path: cuantosCubos.cpp

#include <iostream>
using namespace std;

int main()
{
    int cubos;
    int la2[3][100];
    int numLa2 = 0;
    int i, j, k;
    int suma, sumaLados;

    do
    {
        cin >> cubos;
    } while (cubos < 0 && cubos > 100);

    // Buscar los posibles cubos rectangulares
    for (i = 1; i <= cubos; i++)
    {
        for (j = 1; j <= cubos; j++)
        {
            for (k = 1; k <= cubos; k++)
            {
                if (i * j * k == cubos)
                {
                    la2[0][numLa2] = i;
                    la2[1][numLa2] = j;
                    la2[2][numLa2] = k;
                    numLa2++;
                    // Eliminar si ya existe
                    suma = i + j + k;
                    for (int l = 0; l < numLa2; l++)
                    {
                        sumaLados = la2[0][l] + la2[1][l] + la2[2][l];
                        if (suma == sumaLados && l != numLa2 - 1)
                        {
                            la2[0][l] = la2[0][numLa2 - 1];
                            la2[1][l] = la2[1][numLa2 - 1];
                            la2[2][l] = la2[2][numLa2 - 1];
                            numLa2--;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    // Imprimir los cubos rectangulares
    for (i = 0; i < numLa2; i++)
    {
        cout << la2[0][i] << " " << la2[1][i] << " " << la2[2][i] << endl;
    }

    return 0;
}