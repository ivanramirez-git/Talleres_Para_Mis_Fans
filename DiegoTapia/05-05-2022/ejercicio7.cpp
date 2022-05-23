// Con pila y cola crear la función Palindromo.
#include <iostream>
#include <cstring>

using namespace std;

// Nodo
struct Nodo{
    char dato;
    Nodo *sig;
};

// Cola
struct Cola{
    Nodo *frente;
    Nodo *final;
};

// Crear cola
void crearCola(Cola &c){
    c.frente = NULL;
    c.final = NULL;
}

// Cola vacia
bool colaVacia(Cola c){
    return c.frente == NULL;
}

// Insertar en cola
void insertarCola(Cola &c, char dato){
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->sig = NULL;
    if(colaVacia(c)){
        c.frente = nuevo;
        c.final = nuevo;
    }else{
        c.final->sig = nuevo;
        c.final = nuevo;
    }
}

// Extraer de cola
void extraerCola(Cola &c, char &dato){
    if(!colaVacia(c)){
        Nodo *aux = c.frente;
        dato = aux->dato;
        c.frente = c.frente->sig;
        // Imprime el dato
        cout << dato;
        delete aux;
    }
}

// Imprimir cola
void imprimirCola(Cola c){
    Nodo *aux = c.frente;
    while(aux != NULL){
        cout << aux->dato << " ";
        aux = aux->sig;
    }
    cout << endl;
}

// Pila
struct Pila{
    Nodo *frente;
};

// Crear pila
void crearPila(Pila &p){
    p.frente = NULL;
}

// Pila vacia
bool pilaVacia(Pila p){
    return p.frente == NULL;
}

// Insertar en pila
void insertarPila(Pila &p, char dato){
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->sig = p.frente;
    p.frente = nuevo;
}

// Extraer de pila
void extraerPila(Pila &p, char &dato){
    if(!pilaVacia(p)){
        Nodo *aux = p.frente;
        dato = aux->dato;
        p.frente = p.frente->sig;
        // Imprime el dato
        cout << dato;
        delete aux;
    }
}

// Imprimir pila
void imprimirPila(Pila p){
    Nodo *aux = p.frente;
    while(aux != NULL){
        cout << aux->dato << " ";
        aux = aux->sig;
    }
    cout << endl;
}

// Palindromo
bool palindromo(Cola c, Pila p){
    bool res = true;
    while(!colaVacia(c) && !pilaVacia(p)){
        char dato1, dato2;
        extraerCola(c, dato1);
        cout << "|";
        extraerPila(p, dato2);
        cout << endl;
        if(dato1 != dato2){
            res = false;
            break;
        }
        cout << " ---- | ---- " << endl;
    }
    return res;
}

// Main
int main(){
    Cola c;
    crearCola(c);
    Pila p;
    crearPila(p);
    char *dato;
    cout << "Ingrese una palabra: " << endl;
    cin >> dato;
    for(int i = 0; i < strlen(dato); i++){
        insertarCola(c, dato[i]);
        insertarPila(p, dato[i]);
    }
    bool res = palindromo(c, p);
    if(res){
        cout << "PALABRA ES PALINDROMO!!!!" << endl;
    }else{
        cout << "PALABRA NO ES PALINDROMO!!!!" << endl;
    }
    return 0;
}