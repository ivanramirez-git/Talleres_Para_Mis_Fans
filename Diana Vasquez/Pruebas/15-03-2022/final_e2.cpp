#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

// Liga de Futbol

// lectura de nombre de equipos
vector<string> leer_equipos(string nombre_archivo)
{
    vector<string> equipos;
    ifstream archivo(nombre_archivo);
    string equipo;
    while (getline(archivo, equipo))
    {
        equipos.push_back(equipo);
    }
    return equipos;
}

// aleatorios
int aleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

vector<vector<int>> generarCompeticion(int n)
{
    // generar matriz de competicion, 3 ganar, 1 empate, 0 perder
    vector<vector<int>> grafo(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                grafo[i][j] = 0;
            }
            else
            {
                grafo[i][j] = 1 - aleatorio(0, 2);
                grafo[j][i] = - grafo[i][j];
            }
        }
    }
    return grafo;
}

// imprimir grafo
void imprimir_grafo(vector<vector<int>> grafo)
{
    for (int i = 0; i < grafo.size(); i++)
    {
        for (int j = 0; j < grafo.size(); j++)
        {
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }
}

// Imprimir nomnbre de equipos
void imprimir_equipos(vector<string> equipos)
{
    for (int i = 0; i < equipos.size(); i++)
    {
        cout << equipos[i] << endl;
    }
}

// Generar liga
vector<vector<string> > generarLiga(vector<string> equipos, vector<vector<int>> competicion)
{
    
    // construir estructura de liga
    /*
    NOMBRE, PJ, PG, PE, PP, PTS
    */
    vector<string> encabezado = {"NOMBRE", "PJ", "PG", "PE", "PP", "PTS"};
    vector<vector<string> > liga;
    int liga_numeros[equipos.size()][6] = {0};

    // generar liga
    for (int i = 0; i < equipos.size(); i++)
    {
        int pj = 0;
        int pg = 0;
        int pe = 0;
        int pp = 0;
        int pts = 0;
        vector<string> fila;
        fila.push_back(equipos[i]);
        liga_numeros[i][0] = i; // indice de equipo
        for (int j = 0; j < equipos.size(); j++)
        {
            if (i != j)
            {
                pj++;
                liga_numeros[i][1] = pj;
                if (competicion[i][j] == 1)
                {
                    pg++;
                    liga_numeros[i][2] = pg;
                }
                else if (competicion[i][j] == 0)
                {
                    pp++;
                    liga_numeros[i][4] = pp;
                }
                else
                {
                    pe++;
                    liga_numeros[i][3] = pe;
                }
            }
            pts = (pg * 3) + pe;
            liga_numeros[i][5] = pts;
        }
    }

    /* Ordenar liga_numeros por puntaje */
    for (int i = 0; i < equipos.size(); i++)
    {
        for (int j = 0; j < equipos.size() - 1; j++)
        {
            if (liga_numeros[j][5] < liga_numeros[j + 1][5])
            {
                int aux[6] = {0};
                for (int k = 0; k < 6; k++)
                {
                    aux[k] = liga_numeros[j][k];
                    liga_numeros[j][k] = liga_numeros[j + 1][k];
                    liga_numeros[j + 1][k] = aux[k];
                }
            }
        }
    }

    // construir liga
    liga.push_back(encabezado);
    for (int i = 0; i < equipos.size(); i++)
    {
        vector<string> fila;
        fila.push_back(equipos[liga_numeros[i][0]]);
        fila.push_back(to_string(liga_numeros[i][1]));
        fila.push_back(to_string(liga_numeros[i][2]));
        fila.push_back(to_string(liga_numeros[i][3]));
        fila.push_back(to_string(liga_numeros[i][4]));
        fila.push_back(to_string(liga_numeros[i][5]));
        liga.push_back(fila);
    }

    return liga;
}

// Imprimir liga
void imprimir_liga(vector<vector<string> > liga)
{
    for (int i = 0; i < liga.size(); i++)
    {
        // Imprimir nombre de equipo
        cout << liga[i][0];
        // Imprimir " ", 30 espacios - nombre de equipo.size()
        for (int j = 0; j < 30 - liga[i][0].size(); j++)
        {
            cout << " ";
        }
        // Imprimir PJ, PG, PE, PP, PTS
        cout << "\t" << liga[i][1] << "\t";
        cout << liga[i][2] << "\t";
        cout << liga[i][3] << "\t";
        cout << liga[i][4] << "\t";
        cout << liga[i][5] << endl;
    }
}

// pruebas
void pruebas()
{
    vector<string> equipos = leer_equipos("equipos2022.txt");
    vector<vector<int>> competicion = generarCompeticion(equipos.size());
    vector<vector<string> > liga = generarLiga(equipos, competicion);
    imprimir_liga(liga);
}

// main
int main()
{
    srand(time(NULL));
    pruebas();
    return 0;
}
