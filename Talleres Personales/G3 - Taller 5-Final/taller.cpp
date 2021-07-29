#include <iostream>
#include <vector>
using namespace std;

/*
    Estructura de los nodos que conforman el árbol
    Contiene el estado(matriz), el valor que represanta la función herística, el número de hijos y un vector de hijos
*/
struct Nodo{
    char estado[3][3];
    int valor;
    int nhijos;
    vector<Nodo *>hijos;
};


/*
    Función que retorna el número de espacios libres que tiene un tablero(matriz)
    Sirve para determinar el número de hijos que tiene un estado
*/
int numeroEspacios(char estado[3][3]){
    int espacios = 0;
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (estado[i][j] == '-'){
                espacios ++;
            }
        }
    }
    return espacios;
}


/*
    Función que crea y retorna un nuevo nodo
    Recibe el estado(matriz) que corresponde a ese nodo
*/
Nodo * crearNodo(char estado[3][3]){
    Nodo *nuevo_nodo = new Nodo();
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            nuevo_nodo->estado[i][j] = estado[i][j];
        }
    }
    nuevo_nodo->nhijos = numeroEspacios(estado);
    nuevo_nodo->valor = 0;
    return nuevo_nodo;
}


/*
    Función que imprime un estado(matriz, juego)
*/
void imprimirEstado(char estado[3][3]){
    cout << "   |-----|-----|-----|" << endl;
    for(int i = 0; i < 3; i++){
        cout << "   |  ";
        if (estado[i][0] == '-'){
            cout << " ";
        }
        else{
            cout << estado[i][0];
        }
        cout << "  |  ";
        if (estado[i][1] == '-'){
            cout << " ";
        }
        else{
            cout << estado[i][1];
        }
        cout << "  |  ";
        if (estado[i][2] == '-'){
            cout << " ";
        }
        else{
            cout << estado[i][2];
        }
        cout << "  |" << endl;
        cout << "   |-----|-----|-----|" << endl;
    }
}


/*
    Función que valida si los datos de entrada del oponente son válidos
*/
bool validarDatos(int fila, int columna, char estado[3][3]){
    if (estado[fila][columna] == '-'){
        estado[fila][columna] = 'o';
        return true;
    }
    else{
        return false;
    }
}


/*
    Función que valida sin un oponente ganó el juego
*/
bool validarJugada(char estado[3][3], char jugador){
    for (int i = 0; i < 3; i++){
        int count = 0;
        for (int j = 0; j < 3; j++){
            if (estado[i][j] == jugador){
                count ++;
            }
        }
        if (count == 3){
            return true;
        }
    }
    for (int j = 0; j < 3; j++){
        int count = 0;
        for (int i = 0; i < 3; i++){
            if (estado[i][j] == jugador){
                count ++;
            }
        }
        if (count == 3){
            return true;
        }
    }
    if((estado[0][0] == jugador) && (estado[1][1] == jugador) && (estado[2][2] == jugador)){
        return true;
    }
    if((estado[0][2] == jugador) && (estado[1][1] == jugador) && (estado[2][0] == jugador)){
        return true;
    }
    return false;
}


/*
    Función que genera los sucesores de un estado
    Recibe el estado y el caracter del jugador
*/
void llenar_hijos(Nodo *&nodo, char jugador){
    int count = 0;
    for (int i = 0; i < nodo->nhijos; i++){
        int count2 = 0;
        int count3 = 0;
        char estado_nuevo [3][3];
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                if (nodo->estado[j][k] == '-' && count2 == count && count3 == 0){
                    estado_nuevo[j][k] = jugador;
                    count ++;
                    count3 ++;
                }
                else if(nodo->estado[j][k] == '-'){
                    count2 ++;
                    estado_nuevo[j][k] = nodo->estado[j][k];
                }
                else{
                    estado_nuevo[j][k] = nodo->estado[j][k];
                }
            }
        }
        count2 ++;
        Nodo* nodo_nuevo = crearNodo(estado_nuevo);
        (nodo->hijos).push_back(nodo_nuevo); 
    }
}


/*
    Función utilizada por la función heurística para encontrar las posibilidades de juego de un jugador 'x' o 'o'
    Recibe el estado, el caracter del jugador y el caracter del oponente
*/
int buscar_lineas(char estado[3][3], char jugador, char oponente){
    int lineas = 0;
    for (int i = 0; i < 3; i++){
        int count = 0;
        if ((estado[i][0] != oponente) && (estado[i][1] != oponente) && (estado[i][2] != oponente)){
            for (int j = 0; j < 3; j++){
                if (estado[i][j] == jugador){
                    count ++;
                }
            }
            if (count == 2){
                lineas ++;
            }
            else if(count == 3){
                lineas = 10;
                return lineas;
            }
        }
    }
    for (int j = 0; j < 3; j++){
        int count = 0;
        if ((estado[0][j] != oponente) && (estado[1][j] != oponente) && (estado[2][j] != oponente)){
            for (int i = 0; i < 3; i++){
                if (estado[i][j] == jugador){
                    count ++;
                }
            }
            if (count == 2){
                lineas ++;
            }
            else if(count == 3){
                lineas = 10;
                return lineas;
            }
        }
    }
    if (estado[1][1] != oponente){
        if((estado[0][0] != oponente) && (estado[2][2] != oponente)){
            int count = 0;
            for (int i = 0; i < 3; i++){
                if (estado[i][i] == jugador){
                    count ++;
                }
            }
            if (count == 2){
                lineas = lineas + 2;
            }
            else if(count == 3){
                lineas = 10;
                return lineas;
            }
        }
        if((estado[0][2] != oponente) && (estado[2][0] != oponente)){
            int count = 0;
            for (int i = 0, j = 2; i < 3; i++, j--){
                if (estado[i][j] == jugador){
                    count ++;
                }
            }
            if (count == 2){
                lineas = lineas + 2;
            }
            else if(count == 3){
                lineas = 10;
                return lineas;
            }
        }
    }
    return lineas;
}


/*
    Función heurística
    Recibe el estado a validar
*/
int heuristica(char estado[3][3]){
    int lineas_x = buscar_lineas(estado, 'x', 'o');
    int lineas_o = buscar_lineas(estado, 'o', 'x');
    int valor = lineas_x - lineas_o;
    if (lineas_x > 0){
        valor ++;
    }
    return valor;
}


/*
    Algoritmo minMax
    Recibe el estado actual y retorna estado final a jugar
*/
Nodo * minMax(Nodo *&nodo){
    Nodo * resultado;
    int mayor = -10;
    for (int i = 0; i < nodo->nhijos; i++){
        int menor = 0;
        for (int j = 0; j < nodo->hijos[i]->nhijos; j++){
            Nodo* nodoN = nodo->hijos[i]->hijos[j];
            nodoN->valor = heuristica(nodoN->estado);
            if (nodoN->valor < menor){
                menor = nodoN->valor;
            }
        }
        nodo->hijos[i]->valor = menor;
        
        if (menor > mayor){
            mayor = menor;
            resultado = nodo->hijos[i];
        } 
    }
    return resultado;
}


int main(){
    cout << "---------TRIQUI!---------" << endl;
    int opcion = 0;
    char estado[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    Nodo* nodo = crearNodo(estado); 
    while(opcion != 2){
        cout << "       Turno de 'x'      " << endl;
        llenar_hijos(nodo, 'x');
        for (int i = 0; i < nodo->nhijos; i++){
            llenar_hijos(nodo->hijos[i], 'o');
        }
        Nodo* resultado = minMax(nodo);
        imprimirEstado(resultado->estado);
        bool finalizado = validarJugada(resultado->estado, 'x');
        if (finalizado){
            cout << "Perdiste, juego finalizado" << endl;
            opcion = 2;
        }
        else if(numeroEspacios(resultado->estado) == 0){
            cout << "Empate, juego finalizado" << endl;
            opcion = 2;
        }
        else{
            cout << endl << "       Turno de 'o'      " << endl;
            int columna, fila;
            cout << "Ingrese el numero de la fila: ";
            cin >> fila;
            cout << "Ingrese el numero de la columna: ";
            cin >> columna;
            if ((fila >= 0 && fila <= 2) && (columna >= 0 && columna <= 2)){
                bool valido = validarDatos(fila, columna, resultado->estado);
                if (valido){
                    nodo = crearNodo(resultado->estado);
                    cout << endl;
                    imprimirEstado(nodo->estado);
                    cout << endl;
                    bool finalizado = validarJugada(nodo->estado, 'o');
                    
                    if (finalizado){
                        cout << "Ganaste, juego finalizado" << endl;
                        opcion = 2;
                    }
                }
                else{
                    cout << endl << "Ya existe una jugada en el campo seleccionado" << endl << endl;
                }
            }
            else{
                cout << endl << "Datos incorrectos" << endl << endl;
            }
        }
    }
}
