#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "modelo/Globo.h"
#include "modelo/Data.h"

#define ALT_MAXIMA_GLOBO 1196.58
#define ALT_MINIMA_GLOBO 740.41


using namespace std;


// Funcion que recibe un int y retorna un array de int que representa el numero en binario
int* longToBin(long numero){
    int* bin = new int[32];
    for(int i = 0; i < 32; i++){
        bin[i] = 0;
    }
    int i = 0;
    while(numero > 0){
        bin[i] = numero % 2;
        numero = numero / 2;
        i++;
    }
    // Invertir
    int* binInvertido = new int[32];
    for(int i = 0; i < 32; i++){
        binInvertido[i] = bin[31 - i];
    }
    return binInvertido;
}

// funcion que recibe un array de int y retorna un int que representa el numero en decimal, donde tam representa el numero de bits menos significativos que se van a tomar encuenta
int binToInt(int* bin, int tam){
    int numero = 0;
    //cout << "bandera1" << endl;
    for(int i = 31; i > 31-tam; i--){
        numero += bin[i] * pow(2, 31-i);

        cout << numero << " ";

    }
    //cout << "bandera2" << endl;
    return numero;
}

// Fincion que recibe un string y retorna un numero entero
int stringToInt(string numero){
    int num = 0;
    for(int i = 0; i < numero.length(); i++){
        num = num * 10 + (numero[i] - '0');
    }
    return num;
}

// Fincion que recibe un string y retorna un numero long
long stringToLong(string numero){
    long num = 0;
    for(int i = 0; i < numero.length(); i++){
        num = num * 10 + (numero[i] - '0');
    }
    return num;
}

// Funcion que llena el vector de globos con los datos de la base de datos
vector<Globo *> llenarVector(vector<Globo *> globos, Data &data) {

    for (int i = 0; i < data.getLongitud(); ++i) {


        string codigo;
        string propietario;
        int cantidadMediciones;
        long mediciones;
        vector<Consumo> consumos;
        Consumo consumoTemporal;

        string datoGloboTemporal = data.getDatosGlobo(i);
        codigo = datoGloboTemporal.substr(0, datoGloboTemporal.find("-"));
        datoGloboTemporal = datoGloboTemporal.substr(datoGloboTemporal.find("-") + 1);
        propietario = datoGloboTemporal;

        for (int j = 0; j < data.getLongitud(); ++j) {
            string datoAltimetroTemporal=data.getDatosAltimetro(j);
            string codigoAltimetro = datoAltimetroTemporal.substr(0, datoAltimetroTemporal.find("/"));

            if (codigo == codigoAltimetro) {
                datoAltimetroTemporal = datoAltimetroTemporal.substr(datoAltimetroTemporal.find("/") + 1);
                cantidadMediciones = stringToInt(datoAltimetroTemporal.substr(0, datoAltimetroTemporal.find("/")));
                datoAltimetroTemporal = datoAltimetroTemporal.substr(datoAltimetroTemporal.find("/") + 1);
                mediciones = stringToLong(datoAltimetroTemporal);

                int* bin = longToBin(mediciones);

                // mostrar bin
                for (int k = 0; k < 32; ++k) {
                    cout << bin[k];
                }
                // Imprimir los ultimos 4 bits
                cout << " ";
                int altura = 100*binToInt(bin, 4);
                cout << endl;


                if(altura>ALT_MAXIMA_GLOBO){
                    Helio * helio = new Helio();
                    consumoTemporal = *helio;

                }else if(altura<ALT_MINIMA_GLOBO){
                    Freon12 * freon12 = new Freon12();
                    consumoTemporal = *freon12;

                } else{
                    Consumo * consumo = new Consumo();
                    consumoTemporal = *consumo;
                }
            }
        }
        Globo globo = Globo(codigo, propietario, cantidadMediciones);
        globo.addConsumo(consumoTemporal);

        globos.push_back(&globo);
    }
    return globos;
}



int main()
{
    // Instancia de clase Data
    Data data = Data();

    // Vector polimorfico vGlobos
    vector<Globo*> vGlobos;

    // Llenar vector de globos
    vGlobos = llenarVector(vGlobos, data);

    // Mostrar vector de globos
    for (int i = 0; i < vGlobos.size(); ++i) {
        vGlobos[i]->mostrar();
    }

    // Generar reporte
    /*
     Propietario Globo  Codigo Globo   Cant.    Mediciones Alturas
        UNET            12345          3        100
                                                200
                                                700
        PELLIZARI       67890          2        1100
        ...             ...            ...      ...
        ...             ...            ...      ...


    */

    // Reporte
    cout << "Propietario Globo  Codigo Globo   Cant.    Mediciones Alturas" << endl;
    for (int i = 0; i < vGlobos.size(); ++i) {
        cout << vGlobos[i]->getPropietario() << "            " << vGlobos[i]->getCodigo() << "          " << vGlobos[i]->getCantidadMediciones() << "        ";

        cout << endl;
    }

    cout << "Hello World!" << endl;
    return 0;
}