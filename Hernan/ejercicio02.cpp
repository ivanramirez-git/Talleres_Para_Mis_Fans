#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <string>

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



///////////////////////////////////



class Consumo
{
    public:
        Consumo();
        Consumo(string, int);
        virtual ~Consumo();
        string getUnidadMedida();
        int getCantidad();
        void setUnidadMedida(string);
        void setCantidad(int);
        void mostrar();
    protected:
        string unidadMedida;
        int cantidad;
    private:
};

// Metodos de la clase Consumo

// Clases hijas

class Helio : public Consumo
{
    public:
        Helio();
        Helio(string, int);
        virtual ~Helio();
        void mostrar();
    protected:
    private:
};

// Metodos de la clase Helio
Helio::Helio()
{
    unidadMedida = "Litro";
    cantidad = 0;
}

class Freon12 : public Consumo
{
    public:
        Freon12();
        Freon12(string, int);
        virtual ~Freon12();
        void mostrar();
    protected:
    private:
};

// Contructores y destructores de la clase Consumo
Freon12::Freon12()
{
    unidadMedida = "";
    cantidad = 0;
}




///////////////////////////////////



class Globo{
    private:
        string codigo;
        string propietario;
        int cantidadMediciones;
        vector<Consumo> consumos;
    public:
        Globo(string codigo, string propietario, int cantidadMediciones);
        ~Globo();
        void setCodigo(string codigo);
        void setPropietario(string propietario);
        void setCantidadMediciones(int cantidadMediciones);
        void setConsumo(Consumo consumo, int posicion);
        string getCodigo();
        string getPropietario();
        int getCantidadMediciones();
        Consumo getConsumo(int posicion);
        void addConsumo(Consumo consumo);
        void mostrar();
};

// Metodos
Globo::Globo(string codigo, string propietario, int cantidadMediciones){
    this->codigo = codigo;
    this->propietario = propietario;
    this->cantidadMediciones = cantidadMediciones;
    consumos.resize(cantidadMediciones);
}

// Destructor
Globo::~Globo(){
    cout << "Destruyendo objeto Globo" << endl;
}

// Setters
void Globo::setCodigo(string codigo){
    this->codigo = codigo;
}

void Globo::setPropietario(string propietario){
    this->propietario = propietario;
}

void Globo::setCantidadMediciones(int cantidadMediciones){
    this->cantidadMediciones = cantidadMediciones;
}

void Globo::setConsumo(Consumo consumo, int posicion){
    consumos[posicion] = consumo;
}

string Globo::getCodigo(){
    return codigo;
}

string Globo::getPropietario(){
    return propietario;
}

int Globo::getCantidadMediciones(){
    return cantidadMediciones;
}

Consumo Globo::getConsumo(int posicion){
    return consumos[posicion];
}

void Globo::mostrar(){
    cout << "Codigo: " << codigo << endl;
    cout << "Propietario: " << propietario << endl;
    cout << "Cantidad de mediciones: " << cantidadMediciones << endl;
    for(int i = 0; i < cantidadMediciones; i++){
        cout << "Consumo " << i << ": ";
        consumos[i].mostrar();
    }
}

///////////////////////////////////

// Funcion que recibe un long y retorna un array de int[32] que representa el numero en binario
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
    return bin;
}
// Funcion que llena el vector de globos con los datos de la base de datos
void llenarVector(vector<Globo *> globos, Data &data) {


    for (int i = 0; i < data.getLongitud(); ++i) {


        string codigo;
        string propietario;
        int cantidadMediciones;
        long mediciones;


        string datoGloboTemporal = data.getDatosGlobo(i);
        codigo = datoGloboTemporal.substr(0, datoGloboTemporal.find("-"));
        datoGloboTemporal = datoGloboTemporal.substr(datoGloboTemporal.find("-") + 1);
        propietario = datoGloboTemporal;

        for (int j = 0; j < data.getLongitud(); ++j) {
            string datoAltimetroTemporal=data.getDatosAltimetro(j);
            string codigoAltimetro = datoAltimetroTemporal.substr(0, datoAltimetroTemporal.find("/"));
            datoAltimetroTemporal = datoAltimetroTemporal.substr(datoAltimetroTemporal.find("/") + 1);
            mediciones = stoi(datoAltimetroTemporal);

        }
        // convertir mediciones a binario
        int* bin = longToBin(mediciones);

        // Impresion de binarios
        for (int j = 0; j < 32; ++j) {
            cout << bin[j];
        }


        Globo globo = Globo(codigo, propietario, cantidadMediciones);

        globos.push_back(&globo);
    }
    string propietario;
    int cantidadMediciones;
    vector<Consumo> consumos;

    // Instancia de clase Globo


}

int main()
{

    // Instancia de clase Data
    Data data = Data();

    // Vector polimorfico vGlobos
    vector<Globo*> vGlobos;

    // Llenar vector de globos
    llenarVector(vGlobos, data);
    cout << "Hello World!" << endl;
    return 0;
}
