/*
Debe crear una clase Globo que contendrá los atributos privados: codigo (cadena de caracteres),
propietario (cadena de caracteres), cantidadMediciones (entero) y un vector dinámico
polimórfico de la clase Consumo llamado consumos, del tamaño de la cantidad de mediciones,
éste contendrá en cada posición el consumo que tuvo que hacer el globo, dependiendo cada
medición de altura:

- Si la altura rebasó el límite superior, la instancia a crear debe ser de gas Freón12.
- Si la altura cae por debajo del límite inferior, la instancia a crear debe ser de Helio.
- Si la altura se encuentra en el rango de seguridad, la instancia será de Consumo. 

*/
#ifndef GLOBO_H
#define GLOBO_H
#include "Consumo.h"

using namespace std;

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
        //cout << "Destruyendo Globo" << endl;
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
    void addConsumo(Consumo consumo){
        consumos.push_back(consumo);
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
    vector<Consumo> getConsumos(int posicion){
        return consumos;
    }
    Consumo getConsumo(int posicion){
        return consumos[posicion];
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


#endif
