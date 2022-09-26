
#include <iostream>
#include <vector>

using namespace std;

class conjunto : public vector<int>
{
private:
    int suma;

public:
    // constructor
    conjunto()
    {
        suma = 0;
    }
    // destructor
    ~conjunto()
    {
        // dtor
    }
    // Calcula la suma de los elementos del conjunto
    void CalcularSuma()
    {
        for (int i = 0; i < this->size(); i++)
        {
            suma += this->at(i);
        }
    }
    // Retorna el rango=max-min de los datos.
    int Rango()
    {
        int max = 0;
        int min = 0;
        for (int i = 0; i < this->size(); i++)
        {
            if (this->at(i) > max)
            {
                max = this->at(i);
            }
            if (this->at(i) < min)
            {
                min = this->at(i);
            }
        }
        return max - min;
    }
    // Sobrecargar <<. //Retorna todos los numeros y la suma.
    friend ostream &operator<<(ostream &os, const conjunto &c)
    {
        for (int i = 0; i < c.size(); i++)
        {
            os << c.at(i) << " ";
        }
        os << "suma: " << c.suma << endl;
        return os;
    }
    // Sobrecargar >>. //Usar el formato que usted considere adecuado.
    friend istream &operator>>(istream &is, conjunto &c)
    {
        int n;
        is >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            is >> x;
            c.push_back(x);
        }
        return is;
    }
    // setters
    void setSuma(int s)
    {
        suma = s;
    }
    // getters
    int getSuma()
    {
        return suma;
    }
};



void Particionamiento(conjunto S, conjunto &S1, conjunto &S2)
{
    for (int i = 0; i < S.size(); i++)
    {
        if (i % 2 == 0)
        {
            S1.push_back(S.at(i));
        }
        else
        {
            S2.push_back(S.at(i));
        }
    }
    S1.CalcularSuma();
    S2.CalcularSuma();
    int ObjBest = abs(S1.getSuma() - S2.getSuma());
    for (int i = 0; i < S1.size(); i++)
    {
        for (int j = 0; j < S2.size(); j++)
        {
            int Obj = abs((S1.getSuma() - S1.at(i) + S2.at(j)) - (S2.getSuma() + S1.at(i) - S2.at(j)));
            if (Obj < ObjBest)
            {
                ObjBest = Obj;
                // Intercambiar el elemento i de S1 con el elemento j de S2
                int aux = S1.at(i);
                S1.at(i) = S2.at(j);
                S2.at(j) = aux;
            }
        }
    }
}

int main()
{
    conjunto S;
    cout << "Ingrese el conjunto de numeros, primero la cantidad de numeros y luego los numeros separados por espacios: ";
    cin >> S;
    S.CalcularSuma();
    cout << S;
    conjunto S1;
    conjunto S2;
    Particionamiento(S, S1, S2);
    cout << "S1: " << S1;
    cout << "S2: " << S2;
    return 0;
}