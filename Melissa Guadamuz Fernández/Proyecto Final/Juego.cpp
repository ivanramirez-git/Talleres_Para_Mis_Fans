#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>



#define MAX 10
#define Juego_Archivo "Juego.dat"
#define Jugadores_Archivo "Jugadores.dat"
#define Juego_Archivo_Pruebas "Juego_test.dat"
#define Jugadores_Archivo_Pruebas "Jugadores_test.dat"

using namespace std;

// Estructura para guardar un jugador
struct Jugador
{
    string nombreCompleto;
    string documento;
};

// Estructura para guardar tablero y punjates de tablero
struct Tablero
{
    int principal[MAX][MAX];
    int contador[MAX][MAX];

};

// Estructura para guardar un juego
struct Juego
{
    int numero;
    Jugador jugador1;
    Jugador jugador2;
    int puntosJugador1;
    int puntosJugador2;
};


/* 
1;1638;4;2892;3
2;1638;8;7373;3
3;9082;7;8831;6
4;9082;3;8345;4
5;2892;5;8831;2
6;2892;1;8345;9

*/// Funcion para leer un archivo de texto de un Juego con el anterior formato
bool cargarJuegos(vector<Juego> &juegos)
{
    ifstream archivo;
    Juego juego;
    archivo.open(Juego_Archivo);
    if (archivo.fail())
    {
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    // Los datos estan divididos por ;
    while (!archivo.eof())
    {
        archivo >> juego.numero;
        if (archivo.eof())
            break;
        archivo.ignore();
        getline(archivo, juego.jugador1.nombreCompleto, ';');
        getline(archivo, juego.jugador1.documento, ';');
        archivo >> juego.puntosJugador1;
        archivo.ignore();
        getline(archivo, juego.jugador2.nombreCompleto, ';');
        getline(archivo, juego.jugador2.documento, ';');
        archivo >> juego.puntosJugador2;
        archivo.ignore();
        juegos.push_back(juego);
    }
    archivo.close();
    cout << "Se cargaron " << juegos.size() << " juegos" << endl;
    return true;
}


// Funcion para leer un archivo de texto de un Jugador con el siguiente formato
/*
1638;Juan
1391;Pedro
2892;Ana
8345;Melissa
8831;Rosa
7373;Carmen
8984;Juana
9081;Jorge
9082;Jose

*/
bool cargarJugadores(vector<Jugador> &jugadores)
{
    ifstream archivo;
    Jugador jugador;
    archivo.open(Jugadores_Archivo);
    if (archivo.fail())
    {
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    // En una linea esta el documento y el nombre completo en separador es ;
    // Tokenizar las lineas para obtener el documento y el nombre completo
    while (!archivo.eof())
    {
        getline(archivo, jugador.documento, ';');
        if (archivo.eof())
            break;
        getline(archivo, jugador.nombreCompleto);
        jugadores.push_back(jugador);
    }
    archivo.close();
    cout << "Se han cargado " << jugadores.size() << " jugadores" << endl;
    return true;
}

// Funciones de guardado de archivos
// Juegos
bool guardarJuegos(vector<Juego> &juegos)
{
    ofstream archivo;
    archivo.open(Juego_Archivo_Pruebas);
    if (archivo.fail())
    {
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    for (int i = 0; i < juegos.size(); i++)
    {
        archivo << juegos[i].numero << ";";
        archivo << juegos[i].jugador1.nombreCompleto << ";";
        archivo << juegos[i].puntosJugador1 << ";";
        archivo << juegos[i].jugador2.nombreCompleto << ";";
        archivo << juegos[i].puntosJugador2 << endl;
    }
    archivo.close();
    return true;
}

// Jugadores
bool guardarJugadores(vector<Jugador> &jugadores)
{
    ofstream archivo;
    archivo.open(Jugadores_Archivo_Pruebas);
    if (archivo.fail())
    {
        cout << "Error al abrir el archivo" << endl;
        return false;
    }
    for (int i = 0; i < jugadores.size(); i++)
    {
        archivo << jugadores[i].documento << ";";
        archivo << jugadores[i].nombreCompleto << endl;
    }
    archivo.close();
    return true;
}

// Funcion para imprimir un vector de Juegos
void imprimirJuegos(vector<Juego> juegos)
{
    for (int i = 0; i < juegos.size(); i++)
    {
        cout << "Juego " << juegos[i].numero << endl;
        cout << "Jugador 1: " << juegos[i].jugador1.nombreCompleto << endl;
        cout << "Puntos Jugador 1: " << juegos[i].puntosJugador1 << endl;
        cout << "Jugador 2: " << juegos[i].jugador2.nombreCompleto << endl;
        cout << "Puntos Jugador 2: " << juegos[i].puntosJugador2 << endl;
        cout << endl;
    }
}

// Funcion para imprimir un vector de Jugadores
void imprimirJugadores(vector<Jugador> jugadores)
{
    for (int i = 0; i < jugadores.size(); i++)
    {
        cout << "Jugador " << i + 1 << endl;
        cout << "Identificacion: " << jugadores[i].documento << endl;
        cout << "Nombre: " << jugadores[i].nombreCompleto << endl;
        cout << endl;
    }
}

// Funcion para buscar un jugador en un vector de jugadores
int buscarJugador(vector<Jugador> jugadores, string documento)
{
    for (int i = 0; i < jugadores.size(); i++)
    {
        if (jugadores[i].documento == documento)
            return i;
    }
    return -1;
}

void agregarJugador(vector<Jugador> &jugadores, Jugador jugador)
{
    jugadores.push_back(jugador);
}

// Funcion que pide los datos de un jugador y los agrega al vector de Jugadores
void agregarJugador(vector<Jugador> &jugadores)
{
    Jugador jugador;
    cout << "Ingrese el documento del jugador: ";
    cin >> jugador.documento;
    cout << "Ingrese el nombre completo del jugador: ";
    cin >> jugador.nombreCompleto;
    jugadores.push_back(jugador);
}

// Funcion que retorna un numero aleatorio entre un rango
int numeroAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Funcion que simula un dado
int tirarDado()
{
    return numeroAleatorio(1, 6);
}

// Funcion que crea un tablero aleatorio
Tablero crearTableroAleatorio()
{
    Tablero tablero;
    for (int i = 0; i < MAX ; i++)
    {
        for (int j = 0; j < MAX ; j++)
        {
            // Numeros aleatorios entre 1 y 36
            tablero.principal[i][j] = numeroAleatorio(1, 36);
            tablero.contador[i][j] = 0;
        }
    }
    return tablero;
}


// Turno 1 - Jugador 1


// Funcion para iniciar un juego y agregarlo en un vector de Juegos
void iniciarJuego(vector<Juego> &juegos, vector<Jugador> jugadores)
{
    cout << "Juego " << endl;
    // Guardar archivo jugador
    guardarJugadores(jugadores);
}



int main()
{

    // Variables
    vector<Juego> juegos;
    vector<Jugador> jugadores;

    // Cargar los datos de los jugadores
    cargarJugadores(jugadores);
    
    // Imprimir los datos de los jugadores
    imprimirJugadores(jugadores);

    // Cargar los datos de los juegos
    cargarJuegos(juegos);

    // Imprimir los datos de los juegos
    imprimirJuegos(juegos);

    // Menu
    int opcion;
    do
    {
        cout << "1. Agregar Jugador" << endl;
        cout << "2. Guardar Jugador" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion)
        {
        case 1:
            agregarJugador(jugadores);
            break;
        case 2:
            iniciarJuego(juegos, jugadores);
            break;
        case 3:
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != 3);
    
    return 0;
}