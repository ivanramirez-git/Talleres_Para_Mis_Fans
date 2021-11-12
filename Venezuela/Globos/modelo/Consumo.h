/*
Debe crear una clase denominada Consumo con dos clases hijas, denominadas Helio y
Freon12. La clase Consumo tendrá los atributos unidadMedida (cadena de caracteres) y
cantidad (entero).
*/
#ifndef CONSUMO_H
#define CONSUMO_H

#include <iostream>

using namespace std;


class Consumo
{
private:
protected:
    string unidadMedida;
    int cantidad;
public:
    Consumo():unidadMedida(""),cantidad(0){}
    Consumo(string, int){
        unidadMedida = unidadMedida;
        cantidad = cantidad;
    }
    virtual ~Consumo(){
        unidadMedida = "";
        cantidad = 0;
    }
    string getUnidadMedida(){
        return unidadMedida;
    }
    int getCantidad(){
        return cantidad;
    }
    void setUnidadMedida(string){
        unidadMedida = unidadMedida;
    }
    void setCantidad(int){
        cantidad = cantidad;
    }
    void mostrar(){
        cout << "Unidad de medida: " << unidadMedida << endl;
        cout << "Cantidad: " << cantidad << endl;
    }

};

// Metodos de la clase Consumo

// Clases hijas

class Helio : public Consumo
{
public:
    Helio():Consumo(){
        unidadMedida = "";
        cantidad = 0;
    }
    Helio(string, int){
        unidadMedida = unidadMedida;
        cantidad = cantidad;
    }
    virtual ~Helio(){
        unidadMedida = "Mililitros";
        cantidad = 500;
    }
    void mostrar(){
        cout << "Unidad de medida: " << unidadMedida << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
protected:
private:
};

class Freon12 : public Consumo
{
public:
    Freon12():Consumo(){
        unidadMedida = "Gramos";
        cantidad = 350;
    }
    Freon12(string, int){
        unidadMedida = unidadMedida;
        cantidad = cantidad;
    }
    virtual ~Freon12(){
        unidadMedida = "";
        cantidad = 0;
    }
    void mostrar(){
        cout << "Unidad de medida: " << unidadMedida << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
protected:
private:
};

#endif // FREON12_H