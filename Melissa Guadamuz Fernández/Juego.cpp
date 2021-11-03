#include <iostream>

using namespace std;

// Funcion que genera un numero aleatorio entre 1 y 19
int generarNumero() {
    int numero = rand() % 19 + 1;
    return numero;
}

// Funcion que llena un tablero con numeros aleatorios
void llenarTablero(int tablero[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tablero[i][j] = generarNumero();
        }
    }
}

int main(){
    // Bienvenida
    cout << "Bienvenido al juego Parejas y tríos: suma a 20." << endl;

    //Debe pedir nombre de cada jugador al inicio, solamente 2 jugadores, alternar turnos de cada jugador hasta que haya un ganador. 
    string jugador1, jugador2;

    cout << "Ingrese el nombre del jugador 1: ";
    cin >> jugador1;
    cout << "Ingrese el nombre del jugador 2: ";
    cin >> jugador2;

    // Configuracion de tableros
    int tableroJugador1[8][8]={0};
    int tableroJugador2[8][8]={0};

    // Llenar tableros
    llenarTablero(tableroJugador1);

    // Iniciar juego



    
    return 0;
}