/*
 Lavecindad
Al quitarle cuatro kilos al peso de Quico se obtiene dos veces el peso del chavo y
si sumamos los pesos de Quico y el chavo se obtiene cinco veces el peso de
Noño (todos en pesos enteros). En la vecindad se dice que una persona está en
etapa 'uno' si está entre 0 y 20 kilos, en etapa 'dos' si está entre 21 y 40 kilos, en
etapa 'tres si está entre 41 y 80 kilos y en etapa 'cuatro' si está por encima de 80
kilos. Dado el peso del chavo, realizar un programa que imprima en la primera
línea los pesos del Chavo, Quico y Ñoño separados por un solo espacio y en la
segunda línea indique en qué etapa se encuentra Ñoño.
Entrada:
Un número entero que representa el peso de Chavo
Salida:
En la primera línea tres números enteros separados por espacio que representan
los pesos del Chavo, Quico y Ñoño separados por un solo espacio. En la segunda
línea se debe indicar en qué etapa se encuentra Ñoño escrita en letras
minúsculas.
*/
// Language: c++
#include <iostream>
using namespace std;
int main()
{
    int chavo, quico, nono;
    cin >> chavo;
    quico -= 4;
    quico *= 2;
    nono = 5 * ( quico + chavo );
    switch ( nono )
    {
        case 0 ... 20:
            cout << chavo << "\n" << quico << "\n" << nono << endl << "uno";
            break;
        case 21 ... 40:
            cout << chavo << "\n" << quico << "\n" << nono << endl << "dos";
            break;
        case 41 ... 80:
            cout << chavo << "\n" << quico << "\n" << nono << endl << "tres";
            break;
        default:
            if ( nono > 80 )
                cout << chavo << "\n" << quico << "\n" << nono << endl << "cuatro";
    }
    return 0;
}