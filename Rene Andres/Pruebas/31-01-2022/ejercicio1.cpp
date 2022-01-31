#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Matriz
template <class T>
class Matriz:private vector<vector<T> >
{
    private:
        int n_filas;
        int n_cols;
    public:
        //constructor
        Matriz(int filas, int cols):n_filas(filas),n_cols(cols)
        {
            for(int i=0;i<filas;i++)
            {
                vector<T> aux;
                for(int j=0;j<cols;j++)
                {
                    aux.push_back(0);
                }
                this->push_back(aux);
            }
        }
        // constructor vacio
        Matriz():n_filas(0),n_cols(0)
        {
        }
        //sobrecargar >>, <<
        friend ostream& operator<<(ostream& os, const Matriz<T>& m)
        {
            if(m.n_filas==0)
            {
                os << "Matriz vacia" << endl;
                return os;
            }
            else
            {
                for(int i=0;i<m.n_filas;i++)
                {
                    for(int j=0;j<m.n_cols;j++)
                    {
                        os<<m[i][j]<<" ";
                    }
                    os<<endl;
                }
                return os;
            }
        }

        friend istream& operator>>(istream& is, Matriz<T>& m)
        {
            if(m.n_filas==0)
            {
                int filas,cols;
                is>>filas>>cols;
                m.n_filas=filas;
                m.n_cols=cols;
                for(int i=0;i<filas;i++)
                {
                    vector<T> aux;
                    for(int j=0;j<cols;j++)
                    {
                        T valor;
                        is>>valor;
                        aux.push_back(valor);
                    }
                    m.push_back(aux);
                }
            }
            else
            {
                for(int i=0;i<m.n_filas;i++)
                {
                    for(int j=0;j<m.n_cols;j++)
                    {
                        is>>m[i][j];
                    }
                }
            }
            return is;
        }
        //retorna el valor de la fila i y la columna j
        T celda(int i, int j)
        {
            return this->at(i).at(j);
        }
        //retorna un vector con la diagonal principal(si es cuadrada)
        vector<T> diagonal_principal()
        {
            vector<T> aux;
            for(int i=0;i<n_filas;i++)
            {
                aux.push_back(this->at(i).at(i));
            }
            return aux;
        }
        //retorna la matriz formada por todas las columnas desde col_inicial hasta col_final
        //(col_inicial<=col_final)
        Matriz<T> sub_matriz(int col_inicial, int col_final)
        {
            // validar que col_inicial<=col_final
            if(col_inicial>col_final)
            {
                int aux=col_inicial;
                col_inicial=col_final;
                col_final=aux;
            }
            
            Matriz<T> aux(n_filas,col_final-col_inicial+1);
            for(int i=0;i<n_filas;i++)
            {
                for(int j=col_inicial;j<=col_final;j++)
                {
                    aux[i][j-col_inicial]=this->at(i).at(j);
                }
            }
            return aux;
        }
};

// Pruebas
void prueba1()
{
    Matriz<int> m(3,3);
    cout<<"Ingrese la matriz: "<<endl;
    cin>>m;
    cout<<"La matriz es: "<<endl;
    cout<<m;
    cout<<"La diagonal principal es: "<<endl;
    // imprimir la diagonal principal
    vector<int> d=m.diagonal_principal();
    for(int i=0;i<d.size();i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;
    cout<<"La submatriz es: "<<endl;
    cout<<m.sub_matriz(1,2);
}

void prueba2()
{
    // leer un archivo de texto matriz.txt y mostrar la matriz
    ifstream archivo("matriz.txt");
    if(archivo.is_open())
    {
        Matriz<int> m;
        archivo>>m;
        cout<<"La matriz es: "<<endl;
        cout<<m;
        cout<<"La diagonal principal es: "<<endl;
        // imprimir la diagonal principal
        vector<int> d=m.diagonal_principal();
        for(int i=0;i<d.size();i++)
        {
            cout<<d[i]<<" ";
        }
        cout<<endl;
        cout<<"La submatriz es: "<<endl;
        cout<<m.sub_matriz(1,2);
    }
    else
    {
        cout<<"No se pudo abrir el archivo"<<endl;
    }
}

// Programa principal
int main()
{
    //prueba1();
    prueba2();
    return 0;
}