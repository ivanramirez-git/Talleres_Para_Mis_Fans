#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <string.h>

using namespace std;

class Data
{
    private:
        char datosGlobo[5][25];
        char datosAltimetro[5][25];
        int longitud;

    public:
        Data();
        string getDatosGlobo(int);
        string getDatosAltimetro(int);
        int getLongitud();
};

// Metodos
Data::Data()
{
    strcpy(datosGlobo[0],"12345-UNET");
    strcpy(datosGlobo[1],"67890-PELLIZARI");
    strcpy(datosGlobo[2],"21369-GARZON");
    strcpy(datosGlobo[3],"93647-CIRO SANCHEZ");
    strcpy(datosGlobo[4],"77722-BETEL");

    strcpy(datosAltimetro[0],"93647/4/654637289");
    strcpy(datosAltimetro[1],"67890/2/427384939");
    strcpy(datosAltimetro[2],"77722/2/637929853");
    strcpy(datosAltimetro[3],"12345/3/647939873");
    strcpy(datosAltimetro[4],"21369/5/736936402");

    longitud = 5;
}

string Data::getDatosGlobo(int i)
{
    return datosGlobo[i];
}

string Data::getDatosAltimetro(int i)
{
    return datosAltimetro[i];
}

int Data::getLongitud()
{
    return longitud;
}
#endif // DATA_H
