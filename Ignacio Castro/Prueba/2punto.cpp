// Punto 2 - Prueba
#include <iostream>
#include <map>
#include <stack>

using namespace std;

map<string, stack<float> > stackMap;

void agregarNotas(string rut, float nota){
    // Solo se pueden agregar maximo 4 notas por rut
    if(stackMap[rut].size() < 4){
        stackMap[rut].push(nota);
    } else {
        cout << "Excede el maximo de notas" << endl;
    }
}

int main(){

    string rut, opcion;
    float nota;

    // Ingresar notas
    do{
        cout << "Ingrese el rut: ";
        cin >> rut;
        do{
            cout << "Ingrese la nota: ";
            cin >> nota;

            agregarNotas(rut, nota);
            cout << "Desea ingresar otra nota? (s/n): ";
            cin >> opcion;
        } while(opcion == "s");
        cout << "Desea ingresar otro rut? (s/n): ";
        cin >> opcion;
    } while(opcion == "s");
    
    // Imprimir todos los elementos del mapa
    cout << "Mapa: " << endl;
    for(map<string,stack<float> >::iterator it = stackMap.begin(); it != stackMap.end(); it++){
        cout << it->first << " :";
        int f = it->second.size();
        for(int i = 0; i < f; i++){
            cout << it->second.top() << " ";
            it->second.pop();
        }
        cout << endl;
    }
    return 0;
}