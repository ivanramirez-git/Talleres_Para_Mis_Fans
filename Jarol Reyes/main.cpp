// Considere el siguiente problema que aparece en manufactura o transporte
// • ENTRADA: Un conjunto S = {P1, . . . , Pn} de puntos en el plano.
// • SALIDA: Cual es el orden en que se deben visitar los puntos (exactamente una sola vez) tal que se minimice la distancia total recorrida.
#include <iostream>
#include <fstream>
#include <set>
#include <math.h>
#include <iterator>

using namespace std;

class trabajo : public pair<double, double>
{
private:
    string id; // identificador unico de cada trabajo
public:
    // setters
    void setId(string id) { this->id = id; }
    void setX(double x) { this->first = x; }
    void setY(double y) { this->second = y; }
    // getters
    string getId() const { return id; }
    double getX() const { return first; }
    double getY() const { return second; }

    friend istream &operator>>(istream &is, trabajo &t)
    {
        string id;
        double x, y;
        is >> id >> x >> y;
        t.setId(id);
        t.setX(x);
        t.setY(y);
        return is;
    }

    friend ostream &operator<<(ostream &os, const trabajo &t)
    {
        os << "{ " << t.getId() << ", " << t.getX() << ", " << t.getY() << " }";
        return os;
    }

    // get this
    trabajo getThis() const { return *this; }
};

// distancia euclideana entre trabajos
double distancia(const trabajo &t1, const trabajo &t2)
{
    return sqrt(pow(t1.getX() - t2.getX(), 2) + pow(t1.getY() - t2.getY(), 2));
}

class trabajos_ordenados : public multiset<trabajo>
{
public:
    // sobrecargar >>
    // formato del txt:
    /*
    n
    codigo x_i y_i
    A1 12 34
    A2 56 78
    ...
    An n m
    */
    friend istream &operator>>(istream &is, trabajos_ordenados &t)
    {
        int n;
        is >> n;
        string trash;
        is >> trash >> trash >> trash;
        for (int i = 0; i < n; i++)
        {
            trabajo tr;
            is >> tr;
            // t.insert(tr.getThis());
            t.insert(tr);
        }
        return is;
    }

    // sobrecargar <<
    friend ostream &operator<<(ostream &os, const trabajos_ordenados &t)
    {
        os << "[ ";
        for (auto it = t.begin(); it != t.end(); it++)
        {
            os << *it << " ";
        }
        os << "]";
        return os;
    }

    /*
    Una funci´on que retorne el primer trabajo que se va a ejecutar.
• Una funci´on miembro que permita determinar la mayor distancia recorrida entre trabajos consecutivos de acuerdo al
orden de ejecuci´on.
• Una funci´on miembro que permita determinar la distancia total recorrida, es decir, si el orden de ejecuci´on de los
trabajos es: P0, P1, P2, . . . , Pn se debe calcular:
d(P1, P0) + d(P2, P1) + . . . + d(Pn, Pn−1)
*/
    // primer trabajo a ejecutar
    trabajo primer_trabajo()
    {
        return *begin();
    }

    // trabajos con mayor distancia
    pair<trabajo,trabajo> mayor_distancia()
    {
       
        auto it = begin();
        auto it2 = next(it);
        double mayor = distancia(*it, *it2);
        pair<trabajo,trabajo> p;
        p.first = *it;
        p.second = *it2;
        for (it = begin(); it != end(); it++)
        {
            it2 = next(it);
            if (it2 == end())
                break;
            double dist = distancia(*it, *it2);
            if (dist > mayor)
            {
                mayor = dist;
                p.first = *it;
                p.second = *it2;
            }
        }
        return p;
    }

    // distancia total recorrida
    double distancia_total()
    {
        double total = 0;
        auto it = begin();
        auto it_next = next(it);
        while (it_next != end())
        {
            total += distancia(*it, *it_next);
            it++;
            it_next++;
        }
        return total;
    }

    // orden de ejecucion
    void orden_ejecucion()
    {
        auto it = begin();
        auto it_next = next(it);
        while (it_next != end())
        {
            cout << distancia(*it, *it_next) << endl;
            it++;
            it_next++;
        }
    }

};

void prueba_lectura()
{
    trabajos_ordenados t;
    ifstream ifs("trabajos.txt");
    ifs >> t;
    cout << t << endl;
    cout << "primer trabajo: " << t.primer_trabajo() << endl;
    cout << "mayor distancia: " << t.mayor_distancia().first << " " << t.mayor_distancia().second << endl;
    cout << "distancia total: " << t.distancia_total() << endl;
    t.orden_ejecucion();

}

int main()
{
    prueba_lectura();
    return 0;
}
