/*

Ejercicio 4 (2) Dado un vector de n puntos en el plano P = ( (x0, y0),(x1, y1), . . . ,(xn−1, yn−1) ) y un entero positivo
k > 1, con n multiplo de k. El problema del k-particionamiento consiste en dividir P en k grupos, tales que los puntos dentro
de un grupo sean muy similares de acuerdo a algun tipo de medida. Usaremos la distancia euclidiana:

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>

using namespace std;

// distancia euclidiana entre dos puntos
double d(pair<double, double> p1, pair<double, double> p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

class grupo : public list<pair<double, double>> // lista de puntos en el grupo incluido el centro
{
public:
    pair<double, double> centro;
};

class particion : public vector<grupo>
{
public:
    int k;
    //  Sobrecargar los operadores << de las clases anteriores.

    // Centro 1: Puntos en el grupo
    // Centro 2: Puntos en el grupo
    // ....
    friend ostream &operator<<(ostream &os, const particion &p)
    {
        for (int i = 0; i < p.size(); i++)
        {
            os << "Centro " << i << ": ";
            for (auto it = p[i].begin(); it != p[i].end(); it++)
            {
                os << "(" << it->first << "," << it->second << ") ";
            }
            os << endl;
        }
        return os;
    }
    // constructor
    particion(int k)
    {
        this->k = k;
        resize(k);
    }
};

void prueba()
{
    vector<pair<double, double>> puntos = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}, {10, 10}};
}

int main()
{
    // Cargar archivo puntos.txt
    int k = 12;
    vector<pair<double, double>> puntos;
    ifstream archivo("puntos.txt");
    double x, y;
    // cargar puntos hasta que sea 0 0
    /*
    Para resolver este problema se puede usar el siguiente algoritmo: se inicia seleccionando k puntos de P, mismos que representar´an los centro de cada grupo Ci
, ∀i = 0, . . . , k − 1. En un proceso iterativo, se asignan a los puntos restante al grupo
con el centro m´as cercano. Al final de la iteraci´on se calcula el nuevo centro del grupo y el proceso se repite hasta que los
centros no cambien.

    */
    while (archivo >> x >> y)
    {
        if (x == 0 && y == 0)
            break;
        puntos.push_back({x, y});
    }
    // Ordenar los puntos usando el criterio Pi < Pj si d(Pi, 0) < d(Pj , 0)
    sort(puntos.begin(), puntos.end(), [](pair<double, double> p1, pair<double, double> p2)
         { return d(p1, {0, 0}) < d(p2, {0, 0}); });

    /*
    Selecciona los puntos A = {(n/k) −1, 2(n/k)−1, . . . , n−1} y tomarlos como centros de cada grupo G0 = {C0 = Psub_(n/k −1)}, . . . , Gn−1 ={Csub_(k−1) = Pn}.
    */
    vector<pair<double, double>> centros;
    for (int i = 0; i < k; i++)
        centros.push_back(puntos[(puntos.size() / k) * i]);
    // imprimir centros
    for (auto c : centros)
        cout << c.first << " " << c.second << endl;

    /*

    Asignar los objetos P \ ∪ki=1Ci al grupo con centro mas cercano, es decir,
    – Para i no ∈ A:
    * Calcular el grupo ℓ tal que la distancia entre el punto i y el centro del grupo Cℓ sea minima.
    * Gℓ = Gℓ ∪ {Pi}
    */
    particion p(k);
    for (int i = 0; i < puntos.size(); i++)
    {
        double min = 1000000000;
        int grupo = 0;
        for (int j = 0; j < centros.size(); j++)
        {
            double dist = d(puntos[i], centros[j]);
            if (dist < min)
            {
                min = dist;
                grupo = j;
            }
        }
        p[grupo].push_back(puntos[i]);
    }
    // Actualizar el valor del centro del cluster (media en cada componente)
    for (int i = 0; i < p.size(); i++)
    {
        double x = 0, y = 0;
        for (auto it = p[i].begin(); it != p[i].end(); it++)
        {
            x += it->first;
            y += it->second;
        }
        p[i].centro = {x / p[i].size(), y / p[i].size()};
    }
    // imprimir particion
    cout << p;

    return 0;
}
