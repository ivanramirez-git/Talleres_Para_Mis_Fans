#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool isPrime(long int n)
{
    if (n <= 1) return false;
    int i=2;
    while(i*i<=n)
    {
        if(n%i==0) return false;
        i++;
    }
    return true;
}

class goldbach: public vector<int>
{
private:
    int n;
    int p;
    int q;
    int r;
public:
    // Constructor
    goldbach()
    {
        n = 0;
        p = 0;
        q = 0;
        r = 0;
    }
    // Setters
    void set_n(int n0)
    {
        n = n0;
    }
    // Getters
    int get_n()
    {
        return n;
    }
    int get_p()
    {
        return p;
    }
    int get_q()
    {
        return q;
    }
    int get_r()
    {
        return r;
    }
    // Sobrecarga de operador >>
    friend istream &operator>>(istream &is, goldbach &obj)
    {
        is >> obj.n;
        // Guardar todos los primos en el vector <= n
        for (int i = 2; i <= obj.n; i++)
        {
            if (isPrime(i))
            {
                obj.push_back(i);
            }
        }
        return is;
    }
    // Sobrecarga de operador <<
    friend ostream &operator<<(ostream &os, const goldbach &obj)
    {
        // Caso fuerte
        if (obj.r == 0 && obj.p != 0 && obj.q != 0 && obj.n != 0)
        {
            cout << "Caso fuerte: " << " p: " << obj.p << " , q: " << obj.q << ".";
        }
        // Caso debil
        else if (obj.p != 0 && obj.q != 0 && obj.n != 0 && obj.r != 0)
        {
            cout << "Caso debil: " << " p: " << obj.p << " , q: " << obj.q << " , r: " << obj.r << ".";
        }
        // Caso no se puede resolver
        else
        {
            cout << "Caso no se puede resolver.";
        }
        return os;
    }

    void conjetura(int m)
    {
        // validar que m sea menor que n
        if (m > n)
        {
            cout << "m debe ser menor que n.";
            return;
        }
        // Caso fuerte
        if (m % 2 == 0 && n > 2)
        {
            // Buscar dos primos menores que m que sumen m
            for (int i = 0; i < size(); i++)
            {
                for (int j = 0; j < size(); j++)
                {
                    if (at(i) + at(j) == m)
                    {
                        p = at(i);
                        q = at(j);
                        r = 0;
                        return;
                    }
                }
            }
        }
        // Caso debil
        else if (m % 2 == 1 && n > 5)
        {
            // Buscar dos primos menores que m que sumen m
            for (int i = 0; i < size(); i++)
            {
                for (int j = 0; j < size(); j++)
                {
                    for (int k = 0; k < size(); k++)
                    {
                        if (at(i) + at(j) + at(k) == m)
                        {
                            p = at(i);
                            q = at(j);
                            r = at(k);
                            return;
                        }
                    }
                }
            }
        }
    }
};

// Pruebas
void prueba1()
{
    goldbach obj;
    cout << "Ingrese n: ";
    cin >> obj;
    int m;
    cout << "Ingrese m: ";
    cin >> m;
    obj.conjetura(m);
    cout << obj << endl;
}

// Programa Principal
int main()
{
    prueba1();
    return 0;
}