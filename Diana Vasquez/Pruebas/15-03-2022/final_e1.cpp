#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>

using namespace std;

// aleatorios
int aleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// generar grafo
vector<vector<int>> generar_grafo(int n)
{
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
                grafo[i][j] = aleatorio(0, 1);
                grafo[j][i] = grafo[i][j];
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

bool es_regular(vector<vector<int>> grafo)
{
    // es regular si la suma de todas las filas es igual
    int sumas[grafo.size()];
    for (int i = 0; i < grafo.size(); i++)
    {
        sumas[i] = 0;
        for (int j = 0; j < grafo.size(); j++)
        {
            sumas[i] += grafo[i][j];
        }
    }
    for (int i = 0; i < grafo.size(); i++)
    {
        if (sumas[i] != sumas[0])
        {
            return false;
        }
    }
    return true;
}

bool es_completo(vector<vector<int>> grafo)
{
    // es completo la sumade cada fila es igual a el tamanio de la fila - 1
    int sumas[grafo.size()];
    for (int i = 0; i < grafo.size(); i++)
    {
        sumas[i] = 0;
        for (int j = 0; j < grafo.size(); j++)
        {
            sumas[i] += grafo[i][j];
        }
    }
    for (int i = 0; i < grafo.size(); i++)
    {
        if (sumas[i] != grafo.size() - 1)
        {
            return false;
        }
    }
    return true;
}

// pruebas
void prueba1()
{
    int n = aleatorio(4, 10);
    vector<vector<int>> grafo = generar_grafo(n);
    cout << "n: " << n << endl;
    cout << "grafo (Aleatorio): " << endl;
    imprimir_grafo(grafo);
    if (es_regular(grafo))
    {
        cout << "es regular" << endl;
    }
    else
    {
        cout << "no es regular" << endl;
    }
    if (es_completo(grafo))
    {
        cout << "es completo" << endl;
    }
    else
    {
        cout << "no es completo" << endl;
    }
}

void prueba2()
{
    // grafo completo
    int n = 4;
    vector<vector<int>> grafo = {{0, 1, 1, 1},
                                 {1, 0, 1, 1},
                                 {1, 1, 0, 1},
                                 {1, 1, 1, 0}};
    // grafo regular
    int n2 = 4;
    vector<vector<int>> grafo2 = {{0, 1, 0, 1},
                                  {1, 0, 1, 0},
                                  {0, 1, 0, 1},
                                  {1, 0, 1, 0}};
    cout << endl;
    cout << "n: " << n << endl;
    cout << "grafo: " << endl;
    imprimir_grafo(grafo);
    if (es_regular(grafo))
    {
        cout << "es regular" << endl;
    }
    else
    {
        cout << "no es regular" << endl;
    }
    if (es_completo(grafo))
    {
        cout << "es completo" << endl;
    }
    else
    {
        cout << "no es completo" << endl;
    }
    cout << endl;
    cout << "n2: " << n2 << endl;
    cout << "grafo2: " << endl;
    imprimir_grafo(grafo2);
    if (es_regular(grafo2))
    {
        cout << "es regular" << endl;
    }
    else
    {
        cout << "no es regular" << endl;
    }
    if (es_completo(grafo2))
    {
        cout << "es completo" << endl;
    }
    else
    {
        cout << "no es completo" << endl;
    }
}

// main
int main()
{
    srand(time(NULL));
    prueba1();
    prueba2();
    return 0;
}