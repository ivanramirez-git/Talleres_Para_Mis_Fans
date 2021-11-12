#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>

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
    private:
    protected:
        string unidadMedida;
        int cantidad;
    public:
        Consumo():unidadMedida(""),cantidad(0){}
        Consumo(string, int);
        virtual ~Consumo();
        string getUnidadMedida();
        int getCantidad();
        void setUnidadMedida(string);
        void setCantidad(int);
        void mostrar();
    
};

// Metodos de la clase Consumo

// Clases hijas

class Helio : public Consumo
{
    public:
        Helio():Consumo(){
            unidadMedida = "Litros";
            cantidad = 0;
        }
        Helio(string, int);
        virtual ~Helio();
        void mostrar();
    protected:
    private:
};

class Freon12 : public Consumo
{
    public:
        Freon12():Consumo(){
            unidadMedida = "gramos";
            cantidad = 0;
        }
        Freon12(string, int);
        virtual ~Freon12();
        void mostrar();
    protected:
    private:
};


///////////////////////////////////



class Globo{
    private:
        string codigo;
        string propietario;
        int cantidadMediciones;
        vector<Consumo> consumos;
    public:
        Globo(string codigo, string propietario, int cantidadMediciones){
            this->codigo = codigo;
            this->propietario = propietario;
            this->cantidadMediciones = cantidadMediciones;
        }
        ~Globo(){
            cout << "Destruyendo Globo" << endl;
        }
        void setCodigo(string codigo){
            this->codigo = codigo;
        }
        void setPropietario(string propietario){
            this->propietario = propietario;
        }
        void setCantidadMediciones(int cantidadMediciones){
            this->cantidadMediciones = cantidadMediciones;
        }
        void setConsumo(Consumo consumo, int posicion){
            consumos.insert(consumos.begin()+posicion, consumo);
        }
        string getCodigo(){
            return codigo;
        }
        string getPropietario(){
            return propietario;
        }
        int getCantidadMediciones(){
            return cantidadMediciones;
        }
        Consumo getConsumo(int posicion){
            return consumos[posicion];
        }
        void addConsumo(Consumo consumo){
            consumos.push_back(consumo);
        }
        void mostrar(){
            cout << "Codigo: " << codigo << endl;
            cout << "Propietario: " << propietario << endl;
            cout << "Cantidad de mediciones: " << cantidadMediciones << endl;
            for(int i = 0; i < consumos.size(); i++){
                consumos[i].mostrar();
            }
        }
};


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

            if (codigo == codigoAltimetro) {
                datoAltimetroTemporal = datoAltimetroTemporal.substr(datoAltimetroTemporal.find("/") + 1);
                cantidadMediciones = stringToInt(datoAltimetroTemporal.substr(0, datoAltimetroTemporal.find("/")));
                datoAltimetroTemporal = datoAltimetroTemporal.substr(datoAltimetroTemporal.find("/") + 1);
                mediciones = stringToLong(datoAltimetroTemporal);
                int* bin = longToBin(mediciones);
                // Impresion de binarios
                for (int j = 0; j < 32; ++j) {
                    cout << bin[j];
                }
                cout << endl;
                // Fin impresion de binarios
            }
                
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

    // Mostrar vector de globos
    for (int i = 0; i < vGlobos.size(); ++i) {
        vGlobos[i]->mostrar();
    }
    
    cout << "Hello World!" << endl;
    return 0;
}