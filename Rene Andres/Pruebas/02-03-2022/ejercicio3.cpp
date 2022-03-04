#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

class puntos : private list<pair<int, int>> // Lista de punto P
{
public:
    // Constructor
    puntos()
    {
        // Inicializamos la lista
        list<pair<int, int>>::iterator it;
        for (it = begin(); it != end(); it++)
        {
            it->first = 0;
            it->second = 0;
        }
    }
    // Destructor
    ~puntos()
    {
        // Vaciamos la lista
        list<pair<int, int>>::iterator it;
        for (it = begin(); it != end(); it++)
        {
            it->first = 0;
            it->second = 0;
        }
    }

    // Funciones
    bool EliminarPunto(pair< int, int> Pj) // Elimina el punto Pj de la lista
    {
        list<pair<int, int>>::iterator it;
        for (it = begin(); it != end(); it++)
        {
            if (it->first == Pj.first && it->second == Pj.second)
            {
                it = erase(it);
                return true;
            }
        }
        return false;
    }

    void Ordenar_Ascendente() // Considere A<=B, si d(A,(0,0))<=d(B,(0,0))
    {
        // Ordenamos la lista de menor a mayor
        list<pair<int, int>>::iterator it;
        for (it = begin(); it != end(); it++)
        {
            list<pair<int, int>>::iterator it2;
            for (it2 = it; it2 != end(); it2++)
            {
                if (it->first > it2->first)
                {
                    pair<int, int> aux = *it;
                    *it = *it2;
                    *it2 = aux;
                }
            }
        }
    }

    void Invertir_Orden() // Invierte el orden de los elementos de la lista
    {
        list<pair<int, int>>::iterator it;
        for (it = begin(); it != end(); it++)
        {
            list<pair<int, int>>::iterator it2;
            for (it2 = it; it2 != end(); it2++)
            {
                pair<int, int> aux = *it;
                *it = *it2;
                *it2 = aux;
            }
        }
    }

    // Sobrecarga de operadores >> , <<
    friend ostream &operator<<(ostream &out, puntos &P)
    {
        list<pair<int, int>>::iterator it;
        for (it = P.begin(); it != P.end(); it++)
        {
            out << "(" << it->first << "," << it->second << ") ";
        }
        return out;
    }

    friend istream &operator>>(istream &in, puntos &P) // La lectura termina cuando se ingrese el punto (0,0)
    {        
        int x, y;
        in >> x >> y;
        while (x != 0 && y != 0)
        {
            P.push_back(make_pair(x, y));
            in >> x >> y;
        }
        return in;
    }

    // Sobrecargar empy, size, begin, end
    bool empty()
    {
        return list<pair<int, int>>::empty();
    }

    int size()
    {
        return list<pair<int, int>>::size();
    }

    list<pair<int, int>>::iterator begin()
    {
        return list<pair<int, int>>::begin();
    }

    list<pair<int, int>>::iterator end()
    {
        return list<pair<int, int>>::end();
    }

};

// Funcion
vector<pair<int, int> > Camino_Hamiltoniano(puntos P, pair<int, int> P0)
{
    vector<pair<int, int> > C;
    // Hacer W = P
    puntos W = P;
    // Incluir P0 en C y eliminar P0 de W
    if (W.EliminarPunto(P0))
    {
        C.push_back(P0);
    } else
    {
        cout << "El punto " << P0.first << "," << P0.second << " no esta en la lista" << endl;
        return C;
    }

    // while W no esta vacia
    while (!W.empty())
    {
        // Buscar el punto mas cercano a P0 en W
        pair<int, int> Pj;
        int distancia = 1000000;
        list<pair<int, int>>::iterator it;
        for (it = W.begin(); it != W.end(); it++)
        {
            int dist = sqrt(pow(it->first - P0.first, 2) + pow(it->second - P0.second, 2));
            if (dist < distancia)
            {
                distancia = dist;
                Pj = *it;
            }
        }
        // Incluir Pj en C y eliminar Pj de W
        if (W.EliminarPunto(Pj))
        {
            C.push_back(Pj);
        } else
        {
            cout << "El punto " << Pj.first << "," << Pj.second << " no esta en la lista" << endl;
            return C;
        }
        // Actualizar P0
        P0 = Pj;
    }
    return C;
}

// Pruebas
void prueba1(){
    // Leer archivo "Puntos 2.txt"
    puntos P;
    ifstream in("Puntos 2.txt");
    in >> P;
    cout << "Puntos leidos: \n" << P << endl;
    // Ordenar la lista
    P.Ordenar_Ascendente();
    cout << "Puntos ordenados: \n" << P << endl;
    // Invertir el orden de los elementos de la lista
    P.Invertir_Orden();
    cout << "Puntos invertidos: \n" << P << endl;
    // Eliminar el punto (-16,32)
    P.EliminarPunto(make_pair(-16, 32));
    cout << "Puntos eliminados: \n" << P << endl;

    // Calcular el camino Hamiltoniano
    cout << "Camino Hamiltoniano: \n";
    cout << "Ingrese el punto inicial: ";
    pair<int, int> P0;
    cout << "x: ";
    cin >> P0.first;
    cout << "y: ";
    cin >> P0.second;

    vector<pair<int, int> > C = Camino_Hamiltoniano(P, P0);
    for (int i = 0; i < C.size(); i++)
    {
        // (xn,yn) -> (xr,yr) : distancia(xn,yn,xr,yr)
        cout << "(" << C[i].first << "," << C[i].second << ") -> (" << C[(i + 1) % C.size()].first << "," << C[(i + 1) % C.size()].second << ") : " << sqrt(pow(C[i].first - C[(i + 1) % C.size()].first, 2) + pow(C[i].second - C[(i + 1) % C.size()].second, 2)) << endl;
    }
    cout << endl;
}

// Programa principal
int main()
{
    prueba1();
    return 0;
}