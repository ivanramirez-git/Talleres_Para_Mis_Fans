// Punto 1 - Prueba
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string,vector<float> > vectoresMapa(vector<string> ruts, vector<float> notas);

int main(){

    // vector<string> ruts = {"1-9","2-7","3-5","2-7","1-9","3-5","2-7","1-9","3-5","1-9"};
    // vector<float> notas = {6,2,7,5.5,4.5,7,2,1.5,2.8,5};

    vector<string> ruts;
    vector<float> notas;

    ruts.push_back("1-9");
    ruts.push_back("2-7");
    ruts.push_back("3-5");
    ruts.push_back("2-7");
    ruts.push_back("1-9");
    ruts.push_back("3-5");
    ruts.push_back("2-7");
    ruts.push_back("1-9");
    ruts.push_back("3-5");
    ruts.push_back("1-9");

    notas.push_back(6);
    notas.push_back(2);
    notas.push_back(7);
    notas.push_back(5.5);
    notas.push_back(4.5);
    notas.push_back(7);
    notas.push_back(2);
    notas.push_back(1.5);
    notas.push_back(2.8);
    notas.push_back(5);

    // Imprimir los vectores
    cout << "Vectores: " << endl;
    for(int i = 0; i < ruts.size(); i++){
        cout << ruts[i] << " :" << notas[i] << endl;
    }

    // Mapa
    map<string,vector<float> > mapa = vectoresMapa(ruts,notas);
    // Imprimir el mapa
    cout << "Mapa: " << endl;
    for(map<string,vector<float> >::iterator it = mapa.begin(); it != mapa.end(); it++){
        cout << it->first << " :";
        for(int i = 0; i < it->second.size()-1; i++){
            cout << it->second[i] << ", ";
        }
        cout << it->second[it->second.size()-1] << endl;
    }

    return 0;
}

// Funcion
map<string,vector<float> > vectoresMapa(vector<string> ruts, vector<float> notas){

    map<string,vector<float> > mapa;

    for(int i = 0; i < ruts.size(); i++){
        // Añadir al mapa las notas segun el rut
        mapa[ruts[i]].push_back(notas[i]);
    }

    return mapa;
}