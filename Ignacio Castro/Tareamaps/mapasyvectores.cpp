#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    vector<int> lista;
    map<int, vector<int> > respaldo;
    int auxiliar;

    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);
    lista.push_back(40);
    lista.push_back(50);
    lista.push_back(60);
    lista.push_back(70);
    lista.push_back(80);
    lista.push_back(90);
    lista.push_back(100);
    lista.push_back(110);

    auxiliar = -1;
    int tamanio;
    if(lista.size() % 5 == 0){
        tamanio = lista.size();
    }
    else{
        tamanio=1+(lista.size()/5);
    }

    cout << "Tamanio: " << tamanio << endl;

    // Guardar en mapa con llave i+1, vector de 5 elementos de lista desde 0 hasta fin
    for(int i=0; i<tamanio; i++){
        vector<int> aux;
        for(int j=0; j<5; j++){
            aux.push_back(lista[i*5+j]);
            if(i*5+j == lista.size()-1){
                break;
            }
        }
        // Eliminar el elemento de aux si es igual a i+1
        if(aux[0] == i+1){
            aux.erase(aux.begin());
        }
        respaldo.insert(pair<int, vector<int> >(i+1, aux));
    }

    // Imprimir lista
    cout<<"Lista original: {";
    for(int i=0; i<lista.size()-1; i++){
        cout<<lista[i]<<", ";
    }
    cout<<lista[lista.size()-1]<<"}"<<endl;

    // Imprimir llave y vector de cada elemento del mapa
    for(map<int, vector<int> >::iterator it=respaldo.begin(); it!=respaldo.end(); ++it){
        cout<<"Llave: "<<it->first<<" Vector: {";
        for(int i=0; i<it->second.size()-1; i++){
            cout<<it->second[i]<<", ";
        }
        cout<<it->second[it->second.size()-1]<<"}"<<endl;
    }


    return 0;
}