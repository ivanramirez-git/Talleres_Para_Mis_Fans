#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Funcion que genera numeros aleatorios de 1 a K - 1
int generarAleatorio(int K)
{
    // [1, K - 1] o (0, K)
    return rand() % K + 1;
}

// Funcion que genera aleatorios binarios
int aleatorioBinario()
{
    return generarAleatorio(100) % 2;
}

class subconjunto
{
private:
    vector<int> sol; // Vector binario que representa los datos que se toman en cuenta
    vector<int> c;   // Vector de numeros naturales menores a K, la suma de los elementos tomados en cuenta es igual a K
    int K;           // Numero K es igual a la sumatoria de elementos tomados en cuenta del vector c
public:
    // Constructor
    subconjunto()
    {
        K = 0;
    }
    // Constructor recibe n, K
    subconjunto(int n, int K0)
    {
        K = K0;
        // Generar n numeros aleatorios menores a K
        for (int i = 0; i < n; i++)
        {
            c.push_back(generarAleatorio(K));
        }
    }
    // Validar solucion
    bool validar_sol(vector<vector<int> > As)
    {
        // Validar que la suma de los elementos tomados en cuenta es igual a K
        int suma;
        for (int i = 0; i < As.size(); i++)
        {
            suma = 0;
            for (int j = 0; j < As[i].size(); j++)
            {
                suma += As[i][j] * c[j];
            }
            if (suma == K)
            {
                // Copiar vector actual a sol
                for (int k = 0; k < As[i].size(); k++)
                {
                    sol.push_back(As[i][k]);
                }
                return true;
            }
        }
        return false;
    }
    // Dar tamanio de c
    int tamanio_c()
    {
        return c.size();
    }
    // Sobrecarga del operador <<
    friend ostream &operator<<(ostream &os, const subconjunto &s)
    {
        os << endl;
        os << "Conjunto: ";
        if (s.c.size() == 0)
        {
            os << "vacio" << endl;
        }
        else
        {
            os << "{ ";
            for (int i = 0; i < s.c.size() - 1; i++)
            {
                os << s.c[i] << ", ";
            }
            os << s.c[s.c.size() - 1] << " }" << endl;
        }
        os << endl;
        os << "Solucion: ";
        if (s.sol.size() == 0)
        {
            os << "vacio" << endl;
        }
        else
        {
            os << "{ ";
            for (int i = 0; i < s.sol.size() - 1; i++)
            {
                os << s.sol[i] << ", ";
            }
            os << s.sol[s.sol.size() - 1] << " }" << endl;
        }
        os << endl;
        // K
        os << "K: " << s.K << endl;
        os << endl;
        // sumatoria de c * sol
        int suma = 0;
        if (s.sol.size() == 0)
        {
            os << "Suma: 0" << endl;
        }
        else
        {
            for (int i = 0; i < s.sol.size(); i++)
            {
                suma += s.c[i] * s.sol[i];
            }
            os << "Suma: " << suma << endl;
        }
        os << endl;
        // Si suma == K, entonces la solucion es valida
        if (suma == s.K)
        {
            os << "Solucion valida" << endl;
        }
        else
        {
            os << "Solucion invalida" << endl;
        }
        return os;
    }
    // Sobrecarga del operador >>
    friend istream &operator>>(istream &is, subconjunto &s)
    {
        // Leer K
        cout << "K: ";
        is >> s.K;
        // Limpiar vector sol
        s.sol.clear();
        // Limpiar vector c
        s.c.clear();
        // Llenar vector c
        cout << "Ingrese el numero de elementos de c: ";
        int n;
        is >> n;
        bool salida;
        int numero;
        for (int i = 0; i < n; i++)
        {
            numero = 0;
            salida = false;
            while (!salida)
            {
                cout << "Ingrese el elemento " << i + 1 << " de c: ";
                is >> numero;
                if (numero >= s.K && numero <= 0)
                {
                    cout << "El elemento debe ser menor a K y mayor o igual a 0" << endl;
                }
                else
                {
                    salida = true;
                    s.c.push_back(numero);
                }
            }
        }
        return is;
    }
};

// funcion que genera una matriz As de filas binarias m x n
vector<vector<int> > generar_As(int m, int n)
{
    vector<vector<int> > As;
    for (int i = 0; i < m; i++)
    {
        vector<int> fila;
        for (int j = 0; j < n; j++)
        {
            fila.push_back(aleatorioBinario());
        }
        As.push_back(fila);
    }
    // Eliminar filas duplicadas
    vector<int> fila_aux;
    for (int i = 0; i < As.size(); i++)
    {
        fila_aux = As[i];
        for (int j = 0; j < As.size(); j++)
        {
            if (i != j)
            {
                if (fila_aux == As[j])
                {
                    As.erase(As.begin() + j);
                }
            }
        }
    }
    return As;
}

// Pruebas
void prueba1()
{
    subconjunto s(3, 17);
    vector<vector<int> > As = generar_As(3, 3);
    // Imprimir As
    cout << "As: " << endl;
    for (int i = 0; i < As.size(); i++)
    {
        for (int j = 0; j < As[i].size(); j++)
        {
            cout << As[i][j] << " ";
        }
        cout << endl;
    }
    s.validar_sol(As);
    cout << s;
}

void prueba2()
{
    subconjunto s;
    cout << "Ingrese los datos: " << endl;
    cin >> s;
    vector<vector<int> > As = generar_As(100, s.tamanio_c());
    cout << "As: " << endl;
    for (int i = 0; i < As.size(); i++)
    {
        cout << i << ": ";
        for (int j = 0; j < As[i].size(); j++)
        {
            cout << As[i][j] << " ";
        }
        cout << endl;
    }
    s.validar_sol(As);
    cout << s;
}

// Programa principal
int main()
{
    prueba1();
    prueba2();
    return 0;
}