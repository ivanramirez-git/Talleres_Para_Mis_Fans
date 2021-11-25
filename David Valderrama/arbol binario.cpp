#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *izq;
    Nodo *der;
};

// Funciones
void insertar(Nodo *&arbol, int dato);
void mostrarNivel(Nodo *arbol, int nivel);
void mostrarPromedio(Nodo *arbol, int dato);

int main(){
    Nodo *arbol = NULL;
    int opcion;
    int dato;
    int nivel;
    int promedio;

    do{
        cout << "1. Insertar" << endl;
        cout << "2. Mostrar nivel" << endl;
        cout << "3. Mostrar promedio" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;

        switch(opcion){
            case 1:
                cout << "Ingrese un numero: ";
                cin >> dato;
                cout << endl;
                insertar(arbol, dato);
                break;
            case 2:
                cout << "Ingrese un numero: ";
                cin >> nivel;
                cout << endl;
                mostrarNivel(arbol, nivel);
                break;
            case 3:
                cout << "Ingrese un numero: ";
                cin >> promedio;
                cout << endl;
                mostrarPromedio(arbol, promedio);
                break;
            case 4:
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }
    }while(opcion != 4);

    return 0;
}


void insertar(Nodo *&arbol, int dato){
    if(arbol == NULL){
        arbol = new Nodo;
        arbol->dato = dato;
        arbol->izq = NULL;
        arbol->der = NULL;
    }else{
        if(dato < arbol->dato){
            insertar(arbol->izq, dato);
        }else{
            insertar(arbol->der, dato);
        }
    }
}


void mostrarNivel(Nodo *arbol, int nivel){
    if(arbol != NULL){
        if(nivel == 1){
            cout << arbol->dato << endl;
        }else{
            mostrarNivel(arbol->izq, nivel - 1);
            mostrarNivel(arbol->der, nivel - 1);
        }
    }
}


void mostrarPromedio(Nodo *arbol, int dato){
    if(arbol != NULL){
        if(arbol->dato == dato){
            if(arbol->izq != NULL && arbol->der != NULL){
                cout << "El promedio entre " << dato << " y sus hijos es: " << (arbol->izq->dato + arbol->der->dato) / 2 << endl;
            }else{
                cout << "El nodo " << dato << " no tiene hijos" << endl;
            }
        }else{
            mostrarPromedio(arbol->izq, dato);
            mostrarPromedio(arbol->der, dato);
        }
    }
}

