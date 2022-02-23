#include <iostream>
#define MAX 10

using namespace std;

// Structura arbol con N hijos
struct Nodo{
    int dato;
    Nodo *hijos[MAX];

    Nodo(int d){
        dato = d;
        for(int i = 0; i < MAX; i++){
            hijos[i] = NULL;
        }
    }

    void insertar(int d){
        int i = 0;
        while(i < MAX && hijos[i] != NULL){
            i++;
        }
        if(i < MAX){
            hijos[i] = new Nodo(d);
        }
    }

    // Devuelve el numero de hijos que tiene el nodo
    int numHijos(){
        int i = 0;
        while(i < MAX && hijos[i] != NULL){
            i++;
        }
        return i;
    }

    void imprimir(){
        if(this != NULL){
            cout << dato << " ";
        }
        for(int i = 0; i < numHijos(); i++){
            if(hijos[i] != NULL){
                cout << hijos[i]->dato << " ";
            }
        }
        cout << endl;
        for(int i = 0; i < numHijos(); i++){
            if(hijos[i] != NULL){
                hijos[i]->imprimir();
            }
            cout << endl;
        }
    }

    // Retorna la altura del arbol
    int altura(){
        int altura = 0;
        for(int i = 0; i < MAX; i++){
            if(hijos[i] != NULL){
                altura = max(altura, hijos[i]->altura() + 1);
            }
        }
        return altura;
    }
    
    // Recorre el arbol segun el indice y devuelve el nodo
    Nodo* recorrer(int i){
        if(i < MAX){
            if(hijos[i] != NULL){
                return hijos[i];
            }
        }
        return NULL;
    }
};


// Funcion insertar
void insertar(Nodo *&arbol, int d){
    if(arbol == NULL){
        arbol = new Nodo(d);
    }else{
        arbol->insertar(d);
    }
}

// Funcion que imprime el arbol
void imprimir(Nodo *arbol){
    if(arbol != NULL){
        // Imprime el dato del nodo
        cout << arbol->dato << " [";
        // Recorre los hijos del nodo
        for(int i = 0; i < arbol->numHijos()-1; i++){
            // Imprime el hijo
            imprimir(arbol->hijos[i]);
            cout << ", ";
        }
        // Imprime el ultimo hijo
        if(arbol->numHijos() > 0){
            imprimir(arbol->hijos[arbol->numHijos()-1]);
        }
        // Cierra el nodo
        cout << " ]";
    }
}

// Funcion que recibe un arbol y un numero e inserta en sus hijos los divisores del numero
void divisores(Nodo *&arbol, int n){
    if(arbol != NULL){
        for(int i = 1; i <= n; i++){
            if(n % i == 0 && i != n && i != 1){
                insertar(arbol, i);
                //cout << "Insertado " << i << " en el padre " << arbol->dato << endl;
            }
        }
        // Recorre los hijos del arbol
        for(int i = 0; i < arbol->numHijos(); i++){
            divisores(arbol->hijos[i], arbol->hijos[i]->dato);
        }
    }
}

// Main
int main(){
    // Pedimos el numero
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    Nodo *arbol = new Nodo(n);
    divisores(arbol, n);
    cout << endl;
    arbol->imprimir();
    cout << endl;

    return 0;
}