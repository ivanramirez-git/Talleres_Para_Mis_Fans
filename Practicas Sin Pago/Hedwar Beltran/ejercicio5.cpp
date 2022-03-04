/*

El costo de las llamadas telefónicas internacionales depende de la zona geográfica en la que se encuentre el país destino y del numero de minutos hablados.
En la siguiente tabla se presenta el costo del minuto por zona, a cada zona se le ha asociado una clave:
    CLAVE ZONA PRECIO
    12 América del Norte 4
    15 América Central 3.2
    18 América del Sur 5.5
    19 Europa 4.8 23 Asia 7
    25 África 7 29 Oceanía 4  
Construya el algoritmo que le permita calcular e imprimir el costo total de una llamada.

*/

#include <iostream>

using namespace std;

int main()
{
    int minutos;
    float costo;
    string zona;
    cout << "Ingrese el numero de minutos: ";
    cin >> minutos;
    cout << "Ingrese la zona: ";
    cin >> zona;

    if (zona == "12")
    {
        costo = minutos * 4;
    }
    else if (zona == "15")
    {
        costo = minutos * 3.2;
    }
    else if (zona == "18")
    {
        costo = minutos * 5.5;
    }
    else if (zona == "19")
    {
        costo = minutos * 4.8;
    }
    else if (zona == "25")
    {
        costo = minutos * 7;
    }
    else if (zona == "29")
    {
        costo = minutos * 4;
    }
    else
    {
        cout << "Zona no valida" << endl;
    }

    cout << "El costo de la llamada es: " << costo << " $" << endl;

    return 0;
}