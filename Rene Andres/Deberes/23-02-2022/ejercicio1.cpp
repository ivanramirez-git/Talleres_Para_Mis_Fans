#include <iostream>
#include <fstream>
#include <vector>
#include <list>
// getline
#include <string>

using namespace std;

template <class T>
class fila : public list<pair<int, T>> // ALMACENA PARES (id_col,valor)
{
private:
    int id_fila;

public:
    // CONSTRUCTOR
    fila(int id_fila) : id_fila(id_fila)
    {
        this->id_fila = id_fila;
    }

    // METODOS
    void insertar(int id_col, T valor)
    {
        this->push_back(make_pair(id_col, valor));
    }

    int getIdFila()
    {
        return this->id_fila;
    }
};

template <class T>
class matriz_dispersa : public vector<fila<T>>
{
private:
    int n; // NUMERO DE COLUMNAS DE LA MATRIZ ORIGINAL
    int m; // NUMERO DE FILAS DE LA MATRIZ ORIGINAL

public:
    // CONSTRUCTOR
    matriz_dispersa(int n, int m) : n(n), m(m)
    {
        this->n = n;
        this->m = m;
    }

    // METODOS
    void insertar(int id_fila, int id_col, T valor)
    {

        // VALIDAR QUE EL ID_FILA Y EL ID_COLUMNA NO SEAN NULOS NI MAYORES A LA MATRIZ ORIGINAL
        if (id_fila > m || id_col > n)
        {
            cout << "ERROR: ID_FILA O ID_COLUMNA MAYORES A LA MATRIZ ORIGINAL" << endl;
            return;
        }

        if (id_fila < 0 || id_col < 0)
        {
            cout << "ERROR: ID_FILA O ID_COLUMNA NULOS" << endl;
            return;
        }

        // BUSCAR LA FILA
        int i = -1;

        for (int j = 0; j < this->size(); j++)
        {
            if (this->at(j).getIdFila() == id_fila)
            {
                i = j;
                break;
            }
        }

        // SI NO EXISTE LA FILA, LA CREAMOS
        if (i == -1)
        {
            this->push_back(fila<T>(id_fila));
            i = this->size() - 1;
        }

        // INSERTAR EN LA FILA
        this->at(i).insertar(id_col, valor);

        // ORDENAR LA FILA
        this->at(i).sort();
    }

    // OPERADORES << Y >>
    friend ostream &operator<<(ostream &os, const matriz_dispersa<T> &matriz)
    {
        // MOSTRAR LA MATRIZ ORIGINAL
        vector<vector<T>> matriz_aux(matriz.m, vector<T>(matriz.n, 0));

        matriz_dispersa<T> matriz_aux2(matriz.n, matriz.m);        
        // COPIAR LA MATRIZ DISPERSA EN LA MATRIZ AUXILIAR
        for (int i = 0; i < matriz.size(); i++)
        {
            matriz_aux2.push_back(matriz.at(i));
        }

        // LLENAR LA MATRIZ AUXILIAR CON 0
        for (int i = 0; i < matriz.m; i++)
        {
            for (int j = 0; j < matriz.n; j++)
            {
                matriz_aux[i][j] = 0;
            }
        }

        // RECORRER LA MATRIZ DISPERSA
        for (int i = 0; i < matriz.size(); i++)
        {
            // RECORRER EL LA LIST DE LA FILA
            while (!matriz_aux2.at(i).empty())
            {
                // INSERTAR EN LA MATRIZ AUXILIAR
                matriz_aux[i][matriz_aux2.at(i).front().first] = matriz_aux2.at(i).front().second;

                // ELIMINAR EL ELEMENTO DE LA FILA
                matriz_aux2.at(i).pop_front();
            }
        }

        // MOSTRAR LA MATRIZ AUXILIAR
        for (int i = 0; i < matriz.m; i++)
        {
            for (int j = 0; j < matriz.n; j++)
            {
                os << matriz_aux[i][j] << " ";
            }
            os << endl;
        }

        return os;
    }

    friend istream &operator>>(istream &is, matriz_dispersa<T> &matriz)
    {
        // LIMPIAR LA MATRIZ
        matriz.clear();

        // LEER LA MATRIZ ORIGINAL
        int id_fila, id_col, valor;
        char fin_fila = ';';
        char fin_valor = ',';
        char opcion;

        for (int i = 0; i < matriz.m; i++)
        {
            is >> id_fila;
            for (int j = 0; j < matriz.n; j++)
            {
                is >> id_col >> valor >> opcion;
                matriz.insertar(id_fila, id_col, valor);
                if (opcion == fin_fila)
                {
                    break;
                }                
            }
        }

        return is;
    }
};

// PRUEBAS
void prueba1()
{
    matriz_dispersa<int> matriz(3, 3);

    matriz.insertar(0, 0, 1);
    matriz.insertar(0, 1, 2);
    matriz.insertar(1, 0, 4);
    matriz.insertar(1, 1, 5);
    matriz.insertar(2, 0, 7);
    matriz.insertar(2, 2, 9);
    
    cout << "Matriz << : " << endl;
    cout << matriz << endl;
}

void prueba2()
{
    matriz_dispersa<int> matriz(3, 3);
    
    cout << "Ingrese la matriz: " << endl;
    cout << "Usando , para separar las columnas y ; para separar las filas" << endl;
    cout << "Ejemplo: " << endl;
    cout << "\n0 0 4, 2 3;\n1 1 5;\n2 0 1, 1 -5;\n" << endl;

    cin >> matriz;

    cout << endl;

    cout << "Matriz << : " << endl;
    cout << endl << matriz << endl;
}

// PROGRAMA PRINCIPAL
int main()
{
    prueba1();
    prueba2();

    return 0;
}
