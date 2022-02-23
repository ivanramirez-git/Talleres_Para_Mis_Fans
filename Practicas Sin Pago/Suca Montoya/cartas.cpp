/*JUEGO DE CARTAS
-Crear una clase Carta que contenga un palo y un valor.
-Crear PilaDeCartas que vaya apilando las cartas una debajo de otra, pero sólo permita apilarlas si son de un número inmediatamente inferior y de distinto palo. Si se intenta apilar una carta incorrecta, debe lanzar una excepción.
-Agregar un método a la clase PilaDeCartas, para imprimir las cartas que se hayan apilado hasta el momento.*/

#include <iostream>

using namespace std;

struct Carta{
    char palo; // A: Pica, B: Corazones, C: Diamantes, D: Treboles
    int valor; //1: A, 2: 2, 3: 3, 4: 4, 5: 5, 6: 6, 7: 7, 8: 8, 9: 9, 10: 10, 11: J, 12: Q, 13: K

    Carta(char palo, int valor){
        this->palo = palo;
        this->valor = valor;
    }

    Carta(){
        this->palo = 'A';
        this->valor = 1;
    }

    void imprimir(){
        cout << this->palo << this->valor << endl;
    }

};

// Pilas de cartas
struct Nodo{
    Carta carta;
    Nodo *siguiente;
    
    Nodo(Carta carta){
        this->carta = carta;
        this->siguiente = NULL;
    }   

    Nodo(){
        this->siguiente = NULL;
    }

    ~Nodo(){
        delete this->siguiente;
    }

    void imprimir(){
        carta.imprimir();
    }
};



// Pila de cartas
struct PilaDeCartas{
    Nodo *cima;

    PilaDeCartas(){
        this->cima = NULL;
    }

    ~PilaDeCartas(){
        delete this->cima;
    }

    Carta desapilar(){
        Carta carta = this->cima->carta;
        Nodo *aux = this->cima;
        this->cima = this->cima->siguiente;
        delete aux;
        return carta;
    }

    void apilar(Carta carta){
        // Solo apilar si es una carta correcta
        if(this->cima == NULL){
            this->cima = new Nodo(carta);
        }else{
            if(this->cima->carta.palo != carta.palo && this->cima->carta.valor - 1 == carta.valor){
                Nodo *aux = new Nodo(carta);
                aux->siguiente = this->cima;
                this->cima = aux;
            }else{
                throw "No se puede apilar";
            }
        }        
    }

    void imprimir(){
        Nodo *aux = this->cima;
        while(aux != NULL){
            aux->imprimir();
            aux = aux->siguiente;
        }
    }
};

// Main
int main(){
    PilaDeCartas pila;
    
    // Menu
    int opcion;
    do{
        cout << "1. Apilar carta" << endl;
        cout << "2. Imprimir pila" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;
        switch(opcion){
            case 1:
                try{
                    Carta carta;
                    cout << "Ingrese palo (A: Pica, B: Corazones, C: Diamantes, D: Treboles): ";
                    char palo;
                    cin >> palo;
                    cout << "Ingrese valor: ";
                    int valor;
                    cin >> valor;
                    // Validar que la carta sea correcta
                    if(palo == 'A' || palo == 'B' || palo == 'C' || palo == 'D'){
                        if(valor >= 1 && valor <= 13){
                            carta = Carta(palo, valor);
                            pila.apilar(carta);
                        }else{
                            throw "Valor incorrecto";
                        }
                    }else{
                        throw "Palo incorrecto";
                    }                    
                }catch(const char *e){
                    cout << e << endl;
                }
                break;
            case 2:
                pila.imprimir();
                break;
            case 3:
                break;
            default:
                cout << "Opción inválida" << endl;
        }
    }while(opcion != 3);
    return 0;
}