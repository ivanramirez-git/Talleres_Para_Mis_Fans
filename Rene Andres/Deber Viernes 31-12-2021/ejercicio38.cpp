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
    // Constructor
    mochila()
    {
        W = 0;
        l = 0;
        k = 0;
    }
    // Constructor recibe W, l, k
    mochila(int W0, int l0, int k0)
    {
        W = W0;
        l = l0;
        k = k0;
    }
    // Getters
    int get_W()
    {
        return W;
    }
    int get_l()
    {
        return l;
    }
    int get_k()
    {
        return k;
    }
    objeto get_objeto(int i)
    {
        return at(i);
    }
    // Setters
    void set_W(int W0)
    {
        W = W0;
    }
    void set_l(int l0)
    {
        l = l0;
    }
    void set_k(int k0)
    {
        k = k0;
    }
    // Sobrecarga de operador <<
    friend ostream &operator<<(ostream &os, const mochila &m)
    {
        os << "W: " << m.W << ", l: " << m.l << ", k: " << m.k << ", Objetos: { ";
        for (int i = 0; i < m.size() - 1; i++)
        {
            os << m[i] << ", ";
        }
        os << m[m.size() - 1] << " }.";
        return os;
    }
    // Sobrecarga de operador >>
    friend istream &operator>>(istream &is, mochila &m)
    {
        // Leer W
        is >> m.W;
        // Leer cantidad de objetos
        int cantidad_objetos;
        is >> cantidad_objetos;
        // Leer objetos
        for (int i = 0; i < cantidad_objetos; i++)
        {
            objeto obj;
            is >> obj;
            m.push_back(obj);
        }
        return is;
    }
/*
archivo: file_ejercicio38.txt
100
14
10 5
1 3
5 8
4 7
2 6
3 4
1 2
9 18
11 23
12 24
5 76
12 34
1 2
86 3
*/
    // encontrar l y k para maximizar beneficio sin sobrepasar peso maximo
    void resolver(){
        int beneficio_mayor = 0;
        int beneficio_suma = 0;
        int suma_peso = 0;
        for(int i = 0; i < size(); i++){
            for(int j = i; j < size(); j++){
                suma_peso = 0;
                beneficio_suma = 0;
                for(int k = i; k <= j; k++){
                    suma_peso += get_objeto(k).get_w();
                    beneficio_suma += get_objeto(k).get_c();
                }
                if(suma_peso <= W && beneficio_suma > beneficio_mayor){
                    l = i;
                    k = j;
                    beneficio_mayor = beneficio_suma;
                }
            }
        }
    }
};

// Pruebas
void prueba1()
{
    mochila m;
    // Leer archivo
    ifstream file;
    file.open("file_ejercicio38.txt");
    if (!file.is_open())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    // Guardar en mochila
    file >> m;
    // Cerrar archivo
    file.close();
    // Resolver
    m.resolver();
    // Mostrar mochila
    cout << m << endl;
    // Mostrar maximos
    int suma_peso = 0;
    for (int i = m.get_l(); i <= m.get_k(); i++)
    {
        suma_peso += m.get_objeto(i).get_w();
    }
    cout << "Peso maximo: " << suma_peso << endl;
    int beneficio_maximo = 0;
    for (int i = m.get_l(); i <= m.get_k(); i++)
    {
        beneficio_maximo += m.get_objeto(i).get_c();
    }
    cout << "Beneficio maximo: " << beneficio_maximo << endl;

}
// Programa principal
int main()
{
    prueba1();
    return 0;
}
