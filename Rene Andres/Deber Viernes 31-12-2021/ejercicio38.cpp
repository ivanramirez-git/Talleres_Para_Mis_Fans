#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class objeto
{
private:
    int w; // Peso
    int c; // Beneficio
public:
    // Constructor
    objeto()
    {
        w = 0;
        c = 0;
    }
    // Constructor recibe w, c
    objeto(int w0, int c0)
    {
        w = w0;
        c = c0;
    }
    // Getters
    int get_w()
    {
        return w;
    }
    int get_c()
    {
        return c;
    }
    // Setters
    void set_w(int w0)
    {
        w = w0;
    }
    void set_c(int c0)
    {
        c = c0;
    }
    // Sobrecarga de operador <<
    friend ostream &operator<<(ostream &os, const objeto &obj)
    {
        os << "{" << obj.w << ", " << obj.c << "}";
        return os;
    }
    // Sobrecarga de operador >>
    friend istream &operator>>(istream &is, objeto &obj)
    {
        is >> obj.w >> obj.c;
        return is;
    }

};

class mochila : private vector<objeto>
{
private:
    int W; // Peso maximo
    int l; // Indice inicial
    int k; // Indice final donde l <= k
public:

