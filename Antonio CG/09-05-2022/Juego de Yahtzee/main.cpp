// Juego Yahtzee
#include <iostream>
#include <time.h>
#include <math.h>
// Colores de impresion
#define RESET "\033[0m"
#define ROJO "\033[31m"
#define VERDE "\033[32m"
#define AZUL "\033[34m"
#define AMARILLO "\033[33m"
#define MAGENTA "\033[35m"
#define AGUAMARINA "\033[36m"
#define NORMAL ""

using namespace std;

// Menu
int menu()
{
    cout << AGUAMARINA;
    cout << "========================================================" << endl;
    cout << "|                 BIENVENIDO A YAHTZEE                 |" << endl;
    cout << "========================================================" << endl;
    cout << "|                                                      |" << endl;
    cout << "|            1. Ingresar datos de jugadores            |" << endl;
    cout << "|            2. Jugar                                  |" << endl;
    cout << "|            0. Salir                                  |" << endl;
    cout << "|                                                      |" << endl;
    cout << "========================================================" << RESET << endl;
    cout << "Seleccione una opcion: ";
    string opcion;
    cin >> opcion;
    switch (opcion[0])
    {
    case '1':
        return 1;
    case '2':
        return 2;
    case '0':
        return 0;
    default:
        cout << "Opcion no valida" << endl;
        return menu();
    }
}

// Aleatorio
int aleatorio(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Imprimir dado
void imprimirDado(int dado)
{
    cout << ROJO << endl;
    switch (dado)
    {
    case 1:
        cout << "- - - - -" << endl;
        cout << "|       |" << endl;
        cout << "|   *   |" << endl;
        cout << "|       |" << endl;
        cout << "- - - - -" << endl;
        break;
    case 2:
        cout << "- - - - -" << endl;
        cout << "| *     |" << endl;
        cout << "|       |" << endl;
        cout << "|     * |" << endl;
        cout << "- - - - -" << endl;
        break;
    case 3:
        cout << "- - - - -" << endl;
        cout << "| *     |" << endl;
        cout << "|   *   |" << endl;
        cout << "|     * |" << endl;
        cout << "- - - - -" << endl;
        break;
    case 4:
        cout << "- - - - -" << endl;
        cout << "| *   * |" << endl;
        cout << "|       |" << endl;
        cout << "| *   * |" << endl;
        cout << "- - - - -" << endl;
        break;
    case 5:
        cout << "- - - - -" << endl;
        cout << "| *   * |" << endl;
        cout << "|   *   |" << endl;
        cout << "| *   * |" << endl;
        cout << "- - - - -" << endl;
        break;
    case 6:
        cout << "- - - - -" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "| *   * |" << endl;
        cout << "- - - - -" << endl;
        break;
    default:
        cout << "Error" << endl;
        break;
    }
    cout << RESET;
}

// Imprimir dado
string lineaDado(int dado, int linea)
{
    string lineas[5];
    switch (dado)
    {
    case 1:
        lineas[0] = "- - - - -";
        lineas[1] = "|       |";
        lineas[2] = "|   *   |";
        lineas[3] = "|       |";
        lineas[4] = "- - - - -";
        break;
    case 2:
        lineas[0] = "- - - - -";
        lineas[1] = "| *     |";
        lineas[2] = "|       |";
        lineas[3] = "|     * |";
        lineas[4] = "- - - - -";
        break;
    case 3:
        lineas[0] = "- - - - -";
        lineas[1] = "| *     |";
        lineas[2] = "|   *   |";
        lineas[3] = "|     * |";
        lineas[4] = "- - - - -";
        break;
    case 4:
        lineas[0] = "- - - - -";
        lineas[1] = "| *   * |";
        lineas[2] = "|       |";
        lineas[3] = "| *   * |";
        lineas[4] = "- - - - -";
        break;
    case 5:
        lineas[0] = "- - - - -";
        lineas[1] = "| *   * |";
        lineas[2] = "|   *   |";
        lineas[3] = "| *   * |";
        lineas[4] = "- - - - -";
        break;
    case 6:
        lineas[0] = "- - - - -";
        lineas[1] = "| *   * |";
        lineas[2] = "| *   * |";
        lineas[3] = "| *   * |";
        lineas[4] = "- - - - -";
        break;
    default:
        cout << "Error" << endl;
        break;
    }
    if (linea == 0)
    {
        return lineas[0];
    }
    else if (linea == 1)
    {
        return lineas[1];
    }
    else if (linea == 2)
    {
        return lineas[2];
    }
    else if (linea == 3)
    {
        return lineas[3];
    }
    else if (linea == 4)
    {
        return lineas[4];
    }
    else
    {
        cout << "Error" << endl;
        return "";
    }
}

// Imprimir dados
void imprimirDados(int dados[])
{
    cout << "Dado 0: ";
    imprimirDado(dados[0]);
    cout << "Dado 1: ";
    imprimirDado(dados[1]);
    cout << "Dado 2: ";
    imprimirDado(dados[2]);
    cout << "Dado 3: ";
    imprimirDado(dados[3]);
    cout << "Dado 4: ";
    imprimirDado(dados[4]);
}
// Imprimir dados, horizontalmente
void imprimirDadosHorizontal(int dados[])
{
    cout << "Dado 0: \t\t Dado 1: \t\t Dado 2: \t\t Dado 3: \t\t Dado 4: " << endl;
    string lineas[5];
    for (int i = 0; i < 5; i++)
    {
        lineas[i] = "";
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            lineas[i] += lineaDado(dados[j], i) + " \t\t ";
        }
    }
    cout << ROJO;
    cout << lineas[0] << endl;
    cout << lineas[1] << endl;
    cout << lineas[2] << endl;
    cout << lineas[3] << endl;
    cout << lineas[4] << endl;
    cout << RESET;
}

// Devolver puntajes
// Unos
int puntajeUnos(int dados[])
{
    // Contador de unos
    int unos = 0;
    // Recorrer dados
    for (int i = 0; i < 5; i++)
    {
        // Si es uno
        if (dados[i] == 1)
        {
            // Sumar uno
            unos++;
        }
    }
    // Retornar unos
    return unos;
}

// Doses
int puntajeDoses(int dados[])
{
    // Contador de doses
    int doses = 0;
    // Recorrer dados
    for (int i = 0; i < 5; i++)
    {
        // Si es dos
        if (dados[i] == 2)
        {
            // Sumar dos
            doses++;
        }
    }
    // Retornar doses
    return doses * 2;
}

// Treses
int puntajeTreses(int dados[])
{
    // Contador de treses
    int treses = 0;
    // Recorrer dados
    for (int i = 0; i < 5; i++)
    {
        // Si es tres
        if (dados[i] == 3)
        {
            // Sumar tres
            treses++;
        }
    }
    // Retornar treses
    return treses * 3;
}

// Cuatroses
int puntajeCuatroses(int dados[])
{
    // Contador de cuatroses
    int cuatroses = 0;
    // Recorrer dados
    for (int i = 0; i < 5; i++)
    {
        // Si es cuatro
        if (dados[i] == 4)
        {
            // Sumar cuatro
            cuatroses++;
        }
    }
    // Retornar cuatroses
    return cuatroses * 4;
}

// Cincoes
int puntajeCincoes(int dados[])
{
    // Contador de cincoes
    int cincoes = 0;
    // Recorrer dados
    for (int i = 0; i < 5; i++)
    {
        // Si es cinco
        if (dados[i] == 5)
        {
            // Sumar cinco
            cincoes++;
        }
    }
    // Retornar cincoes
    return cincoes * 5;
}

// Seises
int puntajeSeises(int dados[])
{
    // Contador de seises
    int seises = 0;
    // Recorrer dados
    for (int i = 0; i < 5; i++)
    {
        // Si es seis
        if (dados[i] == 6)
        {
            // Sumar seis
            seises++;
        }
    }
    // Retornar seises
    return seises * 6;
}

// Tres de un tipo: Consigue tres dados con el mismo número. Los puntos son la suma de todos los dados (no solo los tres de un tipo).
int puntajeTresIguales(int dados[])
{
    // Contador de tres iguales
    int suma = 0;
    // Numeros
    int contadores[6] = {0, 0, 0, 0, 0, 0};
    // Recorrer dados
    for (int i = 0; i < 5; i++)
    {
        // Sumar uno al contador
        contadores[dados[i] - 1]++;
    }
    // Recorrer contadores2
    for (int i = 0; i < 6; i++)
    {
        // Si es tres
        if (contadores[i] == 3)
        {
            // Sumar todos los dados
            suma = dados[0] + dados[1] + dados[2] + dados[3] + dados[4];
        }
    }
    // Retornar tres iguales
    return suma;
}

// Cuatro de un tipo: Obtén cuatro dados con el mismo número. Los puntos son la suma de todos los dados (no solo los cuatro de un tipo).
int puntajeCuatroIguales(int dados[])
{
    // Contador de cuatro iguales
    int suma = 0;
    // Numeros
    int contadores[6] = {0, 0, 0, 0, 0, 0};
    // Recorrer dados
    for (int i = 0; i < 5; i++)
    {
        // Sumar uno al contador
        contadores[dados[i] - 1]++;
    }
    // Recorrer contadores
    for (int i = 0; i < 6; i++)
    {
        // Si es cuatro
        if (contadores[i] == 4)
        {
            // Sumar todos los dados
            suma = dados[0] + dados[1] + dados[2] + dados[3] + dados[4];
        }
    }
    // Retornar cuatro iguales
    return suma;
}

// Full house: Obtenga tres de un tipo y un par, por ejemplo, 1,1,3,3,3 o 3,3,3,6,6. Obtiene 25 puntos.
int puntajeFullHouse(int dados[])
{
    // Contador de casa llena
    int suma = 0;
    // Numeros
    int contadores[6] = {0, 0, 0, 0, 0, 0};
    // Validadores
    bool trio = false;
    bool par = false;
    // Recorrer dados
    for (int i = 0; i < 5; i++)
    {
        // Sumar uno al contador
        contadores[dados[i] - 1]++;
    }
    // Recorrer contadores
    for (int i = 0; i < 6; i++)
    {
        // Si es trio
        if (contadores[i] == 3)
        {
            // Sumar trio
            trio = true;
        }
        // Si es par
        if (contadores[i] == 2)
        {
            // Sumar par
            par = true;
        }
    }
    // Si es trio y par
    if (trio && par)
    {
        // Sumar 25
        suma = 25;
    }
    // Retornar casa llena
    return suma;
}

// Escalera baja: Obtén cuatro dados secuenciales, 1,2,3,4 o 2,3,4,5 o 3,4,5,6. Obtiene 30 puntos.
int puntajeEscaleraBaja(int dados[])
{
    // Contador de escalera small
    int suma = 0;
    // Numeros
    int contadores[6] = {0, 0, 0, 0, 0, 0};
    // Validadores
    bool escalera = false;
    // Recorrer dados
    for (int i = 0; i < 5; i++)
    {
        // Sumar uno al contador
        contadores[dados[i] - 1]++;
    }
    // Contador de escalera
    int escaleraContador = 0;
    // Validar si hay 4 unos seguidos
    if (contadores[0] > 0 && contadores[1] > 0 && contadores[2] > 0 && contadores[3] > 0)
    {
        // Sumar escalera
        escalera = true;
    }
    else if (contadores[1] > 0 && contadores[2] > 0 && contadores[3] > 0 && contadores[4] > 0)
    {
        // Sumar escalera
        escalera = true;
    }
    else if (contadores[2] > 0 && contadores[3] > 0 && contadores[4] > 0 && contadores[5] > 0)
    {
        // Sumar escalera
        escalera = true;
    }

    // Si es escalera
    if (escalera)
    {
        // Sumar 30
        suma = 30;
    } /* else {
        cout << "contadores: " << contadores[0] << " " << contadores[1] << " " << contadores[2] << " " << contadores[3] << " " << contadores[4] << " " << contadores[5] << endl;
    } */
    // Retornar escalera small
    return suma;
}

// Escalera alta: Obtén cinco dados secuenciales, 1,2,3,4,5 o 2,3,4,5,6. Obtiene 40 puntos.
int puntajeEscaleraAlta(int dados[])
{
    // Contador de escalera grande
    int suma = 0;
    // Numeros
    int contadores[6] = {0, 0, 0, 0, 0, 0};
    // Validadores
    bool escalera = false;
    // Recorrer dados
    for (int i = 0; i < 5; i++)
    {
        // Sumar uno al contador
        contadores[dados[i] - 1]++;
    }
    // Contador de escalera
    int escaleraContador = 0;
    // Validar si hay 5 unos seguidos
    if (contadores[0] > 0 && contadores[1] > 0 && contadores[2] > 0 && contadores[3] > 0 && contadores[4] > 0)
    {
        // Sumar escalera
        escalera = true;
    }
    else if (contadores[1] > 0 && contadores[2] > 0 && contadores[3] > 0 && contadores[4] > 0 && contadores[5] > 0)
    {
        // Sumar escalera
        escalera = true;
    }

    // Si es escalera
    if (escalera)
    {
        // Sumar 40
        suma = 40;
    } /* else {
        cout << "contadores: " << contadores[0] << " " << contadores[1] << " " << contadores[2] << " " << contadores[3] << " " << contadores[4] << " " << contadores[5] << endl;
    } */
    // Retornar escalera grande
    return suma;
}

// Chance: : Puedes poner cualquier cosa al azar, es básicamente como un cubo de basura cuando no tienes nada más para lo que puedas usar los dados. La puntuación es simplemente la suma de los dados.
int puntajeChance(int dados[])
{
    // Contador de chance
    int suma = 0;
    // Sumar todos los dados
    for (int i = 0; i < 5; i++)
    {
        suma += dados[i];
    }
    // Retornar chance
    return suma;
}

// YAHTZEE: Cinco de un tipo. Obtiene 50 puntos. Opcionalmente, puede obtener múltiples Yahtzees, consulte a continuación para obtener más detalles.
int puntajeYahtzee(int dados[])
{
    // Contador de yahtzee
    int suma = 0;
    // Numeros
    int contadores[6] = {0, 0, 0, 0, 0, 0};
    // Validadores
    bool yahtzee = false;
    // Recorrer dados
    for (int i = 0; i < 5; i++)
    {
        // Sumar uno al contador
        contadores[dados[i] - 1]++;
    }
    // Recorrer contadores
    for (int i = 0; i < 6; i++)
    {
        // Si es yahtzee
        if (contadores[i] == 5)
        {
            // Sumar yahtzee
            yahtzee = true;
        }
    }
    // Si es yahtzee
    if (yahtzee)
    {
        // Sumar 50
        suma = 50;
    }
    // Retornar yahtzee
    return suma;
}

string campoMedio(int espacios, char caracter, string cadena, string COLOR)
{
    // Imprimir la cadela en la mitad de los espacios
    int tamanioCadena = cadena.size();
    int espaciosSinCadena = espacios - tamanioCadena;
    int espaciosDerecha = espaciosSinCadena / 2;
    int espaciosIzquierda = espaciosSinCadena - espaciosDerecha;
    string espaciosIzquierdaString = "";
    string espaciosDerechaString = "";
    // Imprimir espacios izquierda
    for (int i = 0; i < espaciosIzquierda; i++)
    {
        espaciosIzquierdaString += caracter;
    }
    // Imprimir espacios derecha
    for (int i = 0; i < espaciosDerecha; i++)
    {
        espaciosDerechaString += caracter;
    }
    // Retornar cadena
    return COLOR + espaciosIzquierdaString + cadena + espaciosDerechaString + RESET;
}

// funcion que invierte una cadena
string reverseStr(string cadena)
{
    // Invertir cadena
    string cadenaInvertida = "";
    // Recorrer cadena
    for (int i = cadena.size() - 1; i >= 0; i--)
    {
        // Agregar caracter
        cadenaInvertida += cadena[i];
    }
    // Retornar cadena invertida
    return cadenaInvertida;
}

// itos
string itos(int numero)
{
    // Convertir a string
    string cadena = "";
    // Si es cero
    if (numero == 0)
    {
        cadena = "0";
    }
    // Recorrer numero
    while (numero > 0)
    {
        // Sumar al numero
        cadena += (numero % 10) + '0';
        // Restar al numero
        numero -= numero % 10;
        // Dividir al numero
        numero /= 10;
    }
    // invertar cadena
    cadena = reverseStr(cadena);

    // Retornar numero
    return cadena;
}

// stoi
int stoi(string cadena)
{
    // Convertir a int
    int numero = 0;
    // Recorrer cadena
    for (int i = 0; i < cadena.size(); i++)
    {
        // Sumar al numero
        numero += (cadena[i] - '0') * pow(10, cadena.size() - i - 1);
    }
    // Retornar numero
    return numero;
}

void imprimirTabla(string jug1, string jug2, int puntosJug1[], int puntosJug2[], int jug, int puntosPosibles[])
{

    string retorno;

    // Definir formato de tabla
    /*
    |================================|
    |                  | Jug1 | Jug2 |
    |--------------------------------|
    | Unos             |   0  |   0  |
    |--------------------------------|
    | Doses            |   0  |   0  |
    |--------------------------------|
    | Treses           |   0  |   0  |
    |--------------------------------|
    | Cuatros          |   0  |   0  |
    |--------------------------------|
    | Cincoes          |   0  |   0  |
    |--------------------------------|
    | Seises           |   0  |   0  |
    |================================|
    | Suma             |   0  |   0  |
    |--------------------------------|
    | Bonus            |   0  |   0  |
    |================================|
    | Tres iguales     |   0  |   0  |
    |--------------------------------|
    | Cuatro iguales   |   0  |   0  |
    |--------------------------------|
    | Full House       |   0  |   0  |
    |--------------------------------|
    | Escalera Baja    |   0  |   0  |
    |--------------------------------|
    | Escalera Alta    |   0  |   0  |
    |--------------------------------|
    | Chance           |   0  |   0  |
    |--------------------------------|
    | YAHTZEE          |   0  |   0  |
    |================================|
    | Total            |   0  |   0  |
    |================================|
    */

    if (jug == 1)
    {

        // Imprimir tabla
        cout << endl;
        cout << campoMedio(56, '=', "", NORMAL) << endl;
        cout << "|                              |" << campoMedio(11, ' ', jug1, AMARILLO) << "|" << campoMedio(11, ' ', jug2, AMARILLO) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Unos                         |" << campoMedio(11, ' ', puntosJug1[0] == -1 ? itos(puntosPosibles[0]) : itos(puntosJug1[0]), puntosJug1[0] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[0]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Doses                        |" << campoMedio(11, ' ', puntosJug1[1] == -1 ? itos(puntosPosibles[1]) : itos(puntosJug1[1]), puntosJug1[1] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[1]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Treses                       |" << campoMedio(11, ' ', puntosJug1[2] == -1 ? itos(puntosPosibles[2]) : itos(puntosJug1[2]), puntosJug1[2] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[2]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Cuatros                      |" << campoMedio(11, ' ', puntosJug1[3] == -1 ? itos(puntosPosibles[3]) : itos(puntosJug1[3]), puntosJug1[3] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[3]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Cincoes                      |" << campoMedio(11, ' ', puntosJug1[4] == -1 ? itos(puntosPosibles[4]) : itos(puntosJug1[4]), puntosJug1[4] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[4]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Seises                       |" << campoMedio(11, ' ', puntosJug1[5] == -1 ? itos(puntosPosibles[5]) : itos(puntosJug1[5]), puntosJug1[5] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[5]), NORMAL) << "|" << endl;
        cout << campoMedio(56, '=', "", NORMAL) << endl;
        cout << "| Suma                         |" << campoMedio(11, ' ', itos(puntosJug1[6]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[6]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Bonus                        |" << campoMedio(11, ' ', itos(puntosJug1[7]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[7]), NORMAL) << "|" << endl;
        cout << campoMedio(56, '=', "", NORMAL) << endl;
        cout << "| Tres Iguales                 |" << campoMedio(11, ' ', puntosJug1[8] == -1 ? itos(puntosPosibles[6]) : itos(puntosJug1[8]), puntosJug1[8] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[8]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Cuatro Iguales               |" << campoMedio(11, ' ', puntosJug1[9] == -1 ? itos(puntosPosibles[7]) : itos(puntosJug1[9]), puntosJug1[9] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[9]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Full House                   |" << campoMedio(11, ' ', puntosJug1[10] == -1 ? itos(puntosPosibles[8]) : itos(puntosJug1[10]), puntosJug1[10] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[10]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Escalera Baja                |" << campoMedio(11, ' ', puntosJug1[11] == -1 ? itos(puntosPosibles[9]) : itos(puntosJug1[11]), puntosJug1[11] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[11]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Escalera Alta                |" << campoMedio(11, ' ', puntosJug1[12] == -1 ? itos(puntosPosibles[10]) : itos(puntosJug1[12]), puntosJug1[12] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[12]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Chance                       |" << campoMedio(11, ' ', puntosJug1[13] == -1 ? itos(puntosPosibles[11]) : itos(puntosJug1[13]), puntosJug1[13] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[13]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| YAHTZEE                      |" << campoMedio(11, ' ', puntosJug1[14] == -1 ? itos(puntosPosibles[12]) : itos(puntosJug1[14]), puntosJug1[14] == -1 ? ROJO : NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[14]), NORMAL) << "|" << endl;
        cout << campoMedio(56, '=', "", NORMAL) << endl;
        cout << endl;
    }
    else if (jug == 2)
    {

        cout << endl;
        cout << campoMedio(56, '=', "", NORMAL) << endl;
        cout << "|                              |" << campoMedio(11, ' ', jug1, AMARILLO) << "|" << campoMedio(11, ' ', jug2, AMARILLO) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Unos                         |" << campoMedio(11, ' ', itos(puntosJug1[0]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[0] == -1 ? itos(puntosPosibles[0]) : itos(puntosJug2[0]), puntosJug2[0] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Doses                        |" << campoMedio(11, ' ', itos(puntosJug1[1]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[1] == -1 ? itos(puntosPosibles[1]) : itos(puntosJug2[1]), puntosJug2[1] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Treses                       |" << campoMedio(11, ' ', itos(puntosJug1[2]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[2] == -1 ? itos(puntosPosibles[2]) : itos(puntosJug2[2]), puntosJug2[2] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Cuatros                      |" << campoMedio(11, ' ', itos(puntosJug1[3]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[3] == -1 ? itos(puntosPosibles[3]) : itos(puntosJug2[3]), puntosJug2[3] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Cincoes                      |" << campoMedio(11, ' ', itos(puntosJug1[4]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[4] == -1 ? itos(puntosPosibles[4]) : itos(puntosJug2[4]), puntosJug2[4] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Seises                       |" << campoMedio(11, ' ', itos(puntosJug1[5]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[5] == -1 ? itos(puntosPosibles[5]) : itos(puntosJug2[5]), puntosJug2[5] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Suma                         |" << campoMedio(11, ' ', itos(puntosJug1[6]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[6]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Bonus                        |" << campoMedio(11, ' ', itos(puntosJug1[7]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[7]), NORMAL) << "|" << endl;
        cout << campoMedio(56, '=', "", NORMAL) << endl;
        cout << "| Tres Iguales                 |" << campoMedio(11, ' ', itos(puntosJug1[8]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[8] == -1 ? itos(puntosPosibles[6]) : itos(puntosJug2[8]), puntosJug2[8] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Cuatro Iguales               |" << campoMedio(11, ' ', itos(puntosJug1[9]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[9] == -1 ? itos(puntosPosibles[7]) : itos(puntosJug2[9]), puntosJug2[9] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Full House                   |" << campoMedio(11, ' ', itos(puntosJug1[10]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[10] == -1 ? itos(puntosPosibles[8]) : itos(puntosJug2[10]), puntosJug2[10] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Escalera Baja                |" << campoMedio(11, ' ', itos(puntosJug1[11]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[11] == -1 ? itos(puntosPosibles[9]) : itos(puntosJug2[11]), puntosJug2[11] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Escalera Alta                |" << campoMedio(11, ' ', itos(puntosJug1[12]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[12] == -1 ? itos(puntosPosibles[10]) : itos(puntosJug2[12]), puntosJug2[12] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Chance                       |" << campoMedio(11, ' ', itos(puntosJug1[13]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[13] == -1 ? itos(puntosPosibles[11]) : itos(puntosJug2[13]), puntosJug2[13] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << campoMedio(56, '=', "", NORMAL) << endl;
        cout << "| YAHTZEE                      |" << campoMedio(11, ' ', itos(puntosJug1[14]), NORMAL) << "|" << campoMedio(11, ' ', puntosJug2[14] == -1 ? itos(puntosPosibles[12]) : itos(puntosJug2[14]), puntosJug2[14] == -1 ? ROJO : NORMAL) << "|" << endl;
        cout << campoMedio(56, '=', "", NORMAL) << endl;
        cout << endl;
    }
    else
    {
        // Imprimir tabla
        cout << endl;
        cout << campoMedio(56, '=', "", NORMAL) << endl;
        cout << "|                              |" << campoMedio(11, ' ', jug1, AMARILLO) << "|" << campoMedio(11, ' ', jug2, AMARILLO) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Unos                         |" << campoMedio(11, ' ', itos(puntosJug1[0]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[0]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Doses                        |" << campoMedio(11, ' ', itos(puntosJug1[1]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[1]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Treses                       |" << campoMedio(11, ' ', itos(puntosJug1[2]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[2]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Cuatros                      |" << campoMedio(11, ' ', itos(puntosJug1[3]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[3]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Cincoes                      |" << campoMedio(11, ' ', itos(puntosJug1[4]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[4]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Seises                       |" << campoMedio(11, ' ', itos(puntosJug1[5]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[5]), NORMAL) << "|" << endl;
        cout << campoMedio(56, '=', "", NORMAL) << endl;
        cout << "| Suma                         |" << campoMedio(11, ' ', itos(puntosJug1[6]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[6]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Bonus                        |" << campoMedio(11, ' ', itos(puntosJug1[7]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[7]), NORMAL) << "|" << endl;
        cout << campoMedio(56, '=', "", NORMAL) << endl;
        cout << "| Tres iguales                 |" << campoMedio(11, ' ', itos(puntosJug1[8]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[8]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Cuatro iguales               |" << campoMedio(11, ' ', itos(puntosJug1[9]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[9]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Full House                   |" << campoMedio(11, ' ', itos(puntosJug1[10]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[10]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Escalera Baja                |" << campoMedio(11, ' ', itos(puntosJug1[11]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[11]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Escalera Alta                |" << campoMedio(11, ' ', itos(puntosJug1[12]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[12]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| Chance                       |" << campoMedio(11, ' ', itos(puntosJug1[13]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[13]), NORMAL) << "|" << endl;
        cout << "|" << campoMedio(54, '-', "", NORMAL) << "|" << endl;
        cout << "| YAHTZEE                      |" << campoMedio(11, ' ', itos(puntosJug1[14]), NORMAL) << "|" << campoMedio(11, ' ', itos(puntosJug2[14]), NORMAL) << "|" << endl;
        cout << campoMedio(56, '=', "", NORMAL) << endl;
        cout << endl;
    }
}

// Gestor de puntos Posibles
void gestorPuntosPosibles(int dados[], int puntosPosibles[])
{
    puntosPosibles[0] = puntajeUnos(dados);
    puntosPosibles[1] = puntajeDoses(dados);
    puntosPosibles[2] = puntajeTreses(dados);
    puntosPosibles[3] = puntajeCuatroses(dados);
    puntosPosibles[4] = puntajeCincoes(dados);
    puntosPosibles[5] = puntajeSeises(dados);
    puntosPosibles[6] = puntajeTresIguales(dados);
    puntosPosibles[7] = puntajeCuatroIguales(dados);
    puntosPosibles[8] = puntajeFullHouse(dados);
    puntosPosibles[9] = puntajeEscaleraBaja(dados);
    puntosPosibles[10] = puntajeEscaleraAlta(dados);
    puntosPosibles[11] = puntajeChance(dados);
    puntosPosibles[12] = puntajeYahtzee(dados);
}

// Lanzar dados
void lanzarDados(int dados[], bool confirmados[])
{
    for (int i = 0; i < 5; i++) // Recorre los dados
    {
        if (!confirmados[i]) // Si el dado no ha sido confirmado
        {
            dados[i] = rand() % 6 + 1; // Se le asigna un valor aleatorio
        }
    }
}

// Pedir confirmacion
void pedirConfirmacionDados(bool confirmaciones[])
{
    string entrada;
    int indices[5] = {-1, -1, -1, -1, -1};

    cout << AGUAMARINA << " Ingrese sin separar por espacios el indice de los dados que quiere mantener (-1 para avanzar)" << NORMAL << endl;
    cin >> entrada;

    if (entrada == "-1")
        return;

    for (int i = 0; i < entrada.length(); i++)
    {
        if (entrada[i] >= '0' && entrada[i] <= '5')
        {
            indices[entrada[i] - '0'] = i;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (indices[i] == -1)
        {
            confirmaciones[i] = false;
        }
        else
        {
            confirmaciones[i] = true;
        }
    }
}

bool pedirConfirmacionPuntos(int puntosConfirmados[], int puntosPosibles[])
{
    /*
    Indices de puntos:
    0. Unos
    1. Doses
    2. Treses
    3. Cuatros
    4. Cincoes
    5. Seises
    6. Suma
    7. Bonus
    8. Tres iguales
    9. Cuatro iguales
    10. Full House
    11. Escalera Baja
    12. Escalera Alta
    13. Chance
    14. YAHTZEE
    15. Total
    */

    /*
    Indices de puntos posibles:
    0. Unos
    1. Doses
    2. Treses
    3. Cuatros
    4. Cincoes
    5. Seises
    6. Tres iguales
    7. Cuatro iguales
    8. Full House
    9. Escalera Baja
    10. Escalera Alta
    11. Chance
    */
    cout << AGUAMARINA;
    // Actualizar indices
    if (puntosConfirmados[0] == -1)
    {
        cout << "1. Unos: " << puntosPosibles[0] << endl;
    }
    if (puntosConfirmados[1] == -1)
    {
        cout << "2. Doses: " << puntosPosibles[1] << endl;
    }
    if (puntosConfirmados[2] == -1)
    {
        cout << "3. Treses: " << puntosPosibles[2] << endl;
    }
    if (puntosConfirmados[3] == -1)
    {
        cout << "4. Cuatros: " << puntosPosibles[3] << endl;
    }
    if (puntosConfirmados[4] == -1)
    {
        cout << "5. Cincoes: " << puntosPosibles[4] << endl;
    }
    if (puntosConfirmados[5] == -1)
    {
        cout << "6. Seises: " << puntosPosibles[5] << endl;
    }
    if (puntosConfirmados[8] == -1)
    {
        cout << "7. Tres iguales: " << puntosPosibles[6] << endl;
    }
    if (puntosConfirmados[9] == -1)
    {
        cout << "8. Cuatro iguales: " << puntosPosibles[7] << endl;
    }
    if (puntosConfirmados[10] == -1)
    {
        cout << "9. Full House: " << puntosPosibles[8] << endl;
    }
    if (puntosConfirmados[11] == -1)
    {
        cout << "10. Escalera Baja: " << puntosPosibles[9] << endl;
    }
    if (puntosConfirmados[12] == -1)
    {
        cout << "11. Escalera Alta: " << puntosPosibles[10] << endl;
    }
    if (puntosConfirmados[13] == -1)
    {
        cout << "12. Chance: " << puntosPosibles[11] << endl;
    }
    if (puntosConfirmados[14] == -1)
    {
        cout << "13. YAHTZEE: " << puntosPosibles[12] << endl;
    }

    cout << AMARILLO << "Ingrese una opcion para confirmar un puntaje (-1 para avanzar)" << RESET << endl;
    int opcion;
    cin >> opcion;

    if (opcion == -1)
        return false;

    if (opcion >= 1 && opcion <= 6 && puntosConfirmados[opcion - 1] == -1)
    {
        puntosConfirmados[opcion - 1] = puntosPosibles[opcion - 1];
        return true;
    }
    else if (opcion >= 7 && opcion <= 13 && puntosConfirmados[opcion + 1] == -1)
    {
        puntosConfirmados[opcion + 1] = puntosPosibles[opcion - 1];
        return true;
    }

    return false;
}

// Main
int main()
{
    system("cls");

    // Semilla para generar numeros aleatorios
    srand(time(NULL));
    // puntos de jugadores
    int puntosJug1[16] = {-1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1}; // puntos de jugador 1
    int puntosJug2[16] = {-1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1}; // puntos de jugador 2
    /*
    Indices de puntos:
    0. Unos
    1. Doses
    2. Treses
    3. Cuatros
    4. Cincoes
    5. Seises
    6. Suma
    7. Bonus
    8. Tres iguales
    9. Cuatro iguales
    10. Full House
    11. Escalera Baja
    12. Escalera Alta
    13. Chance
    14. YAHTZEE
    15. Total
    */
    // puntos posibles
    int puntosPosibles[13] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    /*
    Indices de puntos posibles:
    0. Unos
    1. Doses
    2. Treses
    3. Cuatros
    4. Cincoes
    5. Seises
    6. Tres iguales
    7. Cuatro iguales
    8. Full House
    9. Escalera Baja
    10. Escalera Alta
    11. Chance
    */
    // Dados
    int dados[5] = {0, 0, 0, 0, 0};                            // Dados seleccionables
    bool confirmados[5] = {false, false, false, false, false}; // Dados confirmados
    // Nombres de jugadores
    string jugador1, jugador2;
    // jugador1 = "Antonio";
    // jugador2 = "Juan";
    // Historico de dados
    string tablaPuntuaciones[100][5];
    // Indice de historico
    int indiceHistorico = 0;

    do
    {
        switch (menu())
        {
        case 1:
            // Imprimir en aguamarina
            cout << AGUAMARINA << "Ingrese nombre de jugador 1: ";
            cin >> jugador1;
            // Preguntar si desea ingresar otro jugador
            cout << AZUL << "Desea ingresar otro jugador? (s/n): " << RESET;
            char respuesta;
            cin >> respuesta;
            if (respuesta == 's')
            {
                // Imprimir en magenta
                cout << MAGENTA << "Ingrese nombre de jugador 2: ";
                cin >> jugador2;
            }
            // Imprimir en normal
            cout << RESET;
            break;
        case 2:

            // Un jugador
            if (jugador1.length() > 0 && jugador2.length() == 0)
            {
                for (int i = 0; i < 13; i++)
                {
                    cout << VERDE << "Turno " << i + 1 << " de " << jugador1 << RESET << endl;
                    // Limpiar dados confirmados
                    confirmados[0] = false;
                    confirmados[1] = false;
                    confirmados[2] = false;
                    confirmados[3] = false;
                    confirmados[4] = false;

                    for (int j = 0; j < 3; j++)
                    {
                        // Lanzar dados
                        lanzarDados(dados, confirmados);
                        // Gestor de puntos posibles
                        gestorPuntosPosibles(dados, puntosPosibles);
                        // Imprimir tabla
                        imprimirTabla(jugador1, jugador2, puntosJug1, puntosJug2, 1, puntosPosibles);
                        // Imprimir dados confirmados
                        imprimirDadosHorizontal(dados);
                        // Si selecciona un puntaje ir al siguiente turno
                        if (pedirConfirmacionPuntos(puntosJug1, puntosPosibles))
                            break;
                        // Pedir confirmacion
                        if (j < 2)
                            pedirConfirmacionDados(confirmados);
                    }
                }
            }
            else if (jugador1.length() > 0)
            {
                // 2 jugadores
                for (int i = 0; i < 13; i++)
                {
                    cout << VERDE << "Turno " << i + 1 << " de " << jugador1 << RESET << endl;
                    // Limpiar dados confirmados
                    confirmados[0] = false;
                    confirmados[1] = false;
                    confirmados[2] = false;
                    confirmados[3] = false;
                    confirmados[4] = false;

                    for (int j = 0; j < 3; j++)
                    {
                        // Lanzar dados
                        lanzarDados(dados, confirmados);
                        // Gestor de puntos posibles
                        gestorPuntosPosibles(dados, puntosPosibles);
                        // Imprimir tabla
                        imprimirTabla(jugador1, jugador2, puntosJug1, puntosJug2, 1, puntosPosibles);
                        // Imprimir dados confirmados
                        imprimirDadosHorizontal(dados);
                        // Si selecciona un puntaje ir al siguiente turno
                        if (pedirConfirmacionPuntos(puntosJug1, puntosPosibles))
                            break;
                        // Pedir confirmacion
                        if (j < 2)
                            pedirConfirmacionDados(confirmados);
                    }

                    cout << VERDE << "Turno " << i + 1 << " de " << jugador2 << RESET << endl;
                    // Limpiar dados confirmados
                    confirmados[0] = false;
                    confirmados[1] = false;
                    confirmados[2] = false;
                    confirmados[3] = false;
                    confirmados[4] = false;

                    for (int j = 0; j < 3; j++)
                    {
                        // Lanzar dados
                        lanzarDados(dados, confirmados);
                        // Gestor de puntos posibles
                        gestorPuntosPosibles(dados, puntosPosibles);
                        // Imprimir tabla
                        imprimirTabla(jugador1, jugador2, puntosJug1, puntosJug2, 2, puntosPosibles);
                        // Imprimir dados confirmados
                        imprimirDadosHorizontal(dados);
                        // Si selecciona un puntaje ir al siguiente turno
                        if (pedirConfirmacionPuntos(puntosJug2, puntosPosibles))
                            break;
                        // Pedir confirmacion
                        if (j < 2)
                            pedirConfirmacionDados(confirmados);
                    }
                }
            }
            else
            {
                // Imprimir en rojo
                cout << ROJO << "No hay nombres de jugadores" << RESET << endl;
            }

            // Actualizar totales y los bonos

            // Imprimir tabla general

            // Guardar historico

            // Borrar los nombres de jugadores

            break;
        case 0:
            cout << "Saliendo..." << endl;
            return 0;
            break;
        default:
            cout << "Opcion no valida" << endl;
        }
    } while (true);
}
