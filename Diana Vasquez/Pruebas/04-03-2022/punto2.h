/*

Guardar en un vector los datos del archivo "NOMINA.txt"
Empareja los datos de una manera aleatoria

*/

#ifndef PUNTO2_H
#define PUNTO2_H

#include <fstream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

vector<string> cargarDatos()
{

    vector<string> datos;
    string nombre;
    ifstream archivo("NOMINA.txt");

    getline(archivo, nombre);
    getline(archivo, nombre);

    if (archivo.is_open())
    {
        while (getline(archivo, nombre))
        {
            datos.push_back(nombre);
        }
    }

    return datos;
}

int aleatorio(int min, int max)
{
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}

pair<int, int> buscarPareja(vector<int> indices, int num1, int max)
{
    // Buscar una pareja que no este en el indice
    int num2 = aleatorio(0, max); // Numero aleatorio entre 0 y max
    for (int i = 0; i < indices.size(); i++)
    {
        if (indices[i] == num2 && num1 == num2)
        {
            num2 = aleatorio(0, max); // Numero aleatorio entre 0 y max
            i = 0; // Volver a empezar el ciclo para buscar otra pareja
        }
    }
    return make_pair(num1, num2); // Retornar la pareja
}

vector<pair<int, int>> emparejar(vector<string> datos)
{
    vector<pair<int, int>> datosGrupos; // Vector de pares
    vector<int> indices;               // Vector de indices
    int max = datos.size() - 1;        // Maximo valor del vector
    int num1, num2;                   // Numeros aleatorios
    for (int i = 0; i < datos.size(); i++)
    {
        num1 = aleatorio(0, max); // Numero aleatorio
        num2 = aleatorio(0, max); // Numero aleatorio
        while (indices.size() < datos.size())
        {
            if (num1 != num2)
            {
                indices.push_back(num1); // Agregar el numero al vector de indices
                indices.push_back(num2); // Agregar el numero al vector de indices
            }
            else
            {
                num2 = aleatorio(0, max); // Numero aleatorio
            }
        }
        datosGrupos.push_back(buscarPareja(indices, num1, max)); // Agregar el pareja al vector de pares
        indices.clear(); // Limpiar el vector de indices
    }
    return datosGrupos; // Retornar el vector de pares
}

#endif