#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Clima{
private:
    int anho;
    map<string,vector<float> > precipitaciones;
public:
    Clima(int anho, map<string,vector<float> > precipitaciones){
        this->anho = anho;
        this->precipitaciones = precipitaciones;
    }
    Clima(){
        this->anho = 0;
        this->precipitaciones = map<string,vector<float> >();
    }
    int getAnho(){
        return anho;
    }
    map<string,vector<float> > getPrecipitaciones(){
        return precipitaciones;
    }
    void setAnho(int anho){
        this->anho = anho;
    }
    void setPrecipitaciones(map<string,vector<float> > precipitaciones){
        this->precipitaciones = precipitaciones;
    }
};

// Mapa de ciudades
map<string,Clima> ciudades;

// Funcion que devuelve el total de precipitaciones en verano (Enero, Febrero, Marzo)
float totalPrecVerano(){
    float total = 0;
    for(map<string,Clima>::iterator it = ciudades.begin(); it != ciudades.end(); it++){
        total += it->second.getPrecipitaciones()["Enero"][0] + it->second.getPrecipitaciones()["Febrero"][0] + it->second.getPrecipitaciones()["Marzo"][0];
    }
    return total;
}

// Funcion que imprime el nombre de la ciudad mas lluviosa en el mes de julio y el promedio de caida de agua a nivel nacioional
void masLluviosas(){
    // Ciudad mas lluviosa en Julio
    float max = 0;
    string ciudadMax = "";
    for(map<string,Clima>::iterator it = ciudades.begin(); it != ciudades.end(); it++){
        if(it->second.getPrecipitaciones()["Julio"][0] > max){
            max = it->second.getPrecipitaciones()["Julio"][0];
            ciudadMax = it->first;
        }
    }
    cout << "Ciudad mas lluviosa en Julio: " << ciudadMax << endl;

    // Promedio de caida de agua a nivel nacional
    float promedio = 0;
    for(map<string,Clima>::iterator it = ciudades.begin(); it != ciudades.end(); it++){
        promedio += it->second.getPrecipitaciones()["Julio"][0];
    }
    promedio = promedio / ciudades.size();
    cout << "Promedio de caida de agua a nivel nacional: " << promedio << endl;
}

int main(){
    // Pruebas
    map<string,vector<float> > precipitaciones;

    precipitaciones["Enero"].push_back(0.54);
    precipitaciones["Febrero"].push_back(0.55);
    precipitaciones["Marzo"].push_back(0.56);
    precipitaciones["Abril"].push_back(0.57);
    precipitaciones["Mayo"].push_back(0.58);
    precipitaciones["Junio"].push_back(0.59);
    precipitaciones["Julio"].push_back(0.60);
    precipitaciones["Agosto"].push_back(0.61);
    precipitaciones["Septiembre"].push_back(0.62);
    precipitaciones["Octubre"].push_back(0.63);
    precipitaciones["Noviembre"].push_back(0.64);
    precipitaciones["Diciembre"].push_back(0.65);
    
    Clima clima1;
    clima1.setAnho(2001);
    clima1.setPrecipitaciones(precipitaciones);
    ciudades["Santiago"] = clima1;
    
    precipitaciones["Enero"].clear();
    precipitaciones["Febrero"].clear();
    precipitaciones["Marzo"].clear();
    precipitaciones["Abril"].clear();
    precipitaciones["Mayo"].clear();
    precipitaciones["Junio"].clear();
    precipitaciones["Julio"].clear();
    precipitaciones["Agosto"].clear();
    precipitaciones["Septiembre"].clear();
    precipitaciones["Octubre"].clear();
    precipitaciones["Noviembre"].clear();
    precipitaciones["Diciembre"].clear();

    precipitaciones["Enero"].push_back(0.66);
    precipitaciones["Febrero"].push_back(0.67);
    precipitaciones["Marzo"].push_back(0.68);
    precipitaciones["Abril"].push_back(0.69);
    precipitaciones["Mayo"].push_back(0.70);
    precipitaciones["Junio"].push_back(0.71);
    precipitaciones["Julio"].push_back(0.72);
    precipitaciones["Agosto"].push_back(0.73);
    precipitaciones["Septiembre"].push_back(0.74);
    precipitaciones["Octubre"].push_back(0.75);
    precipitaciones["Noviembre"].push_back(0.76);
    precipitaciones["Diciembre"].push_back(0.77);

    Clima clima2;
    clima2.setAnho(2001);
    clima2.setPrecipitaciones(precipitaciones);
    ciudades["Valparaiso"] = clima2;

    // Prueba 1

    cout << "Total de precipitaciones en verano: " << totalPrecVerano() << endl;

    // Prueba 2

    masLluviosas();

    return 0;
}

