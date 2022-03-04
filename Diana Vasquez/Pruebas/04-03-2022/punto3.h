/*

Usando la clase matriz:
    - Escriba una funcion miembro que indique si una matriz es simetrica.
    - Escriba una funcion miembro que indique si una matriz es antisimetrica.
    - Escriba una funcion que realice la operacion de multiplicacion de una matriz por un escalar.
    - Escriba una funcion que realice la operacion de multiplicacion de matrices.
*/

#ifndef PUNTO3_H
#define PUNTO3_H

class Matriz
{
private:
    int filas;            // Numero de filas
    int columnas;         // Numero de columnas
    int matriz[100][100]; // Matriz de enteros
public:
    // Constructor
    Matriz(int filas, int columnas)
    {
        // validar que las filas y columnas sean mayores a 0 y menores a 100
        if (filas > 0 && filas < 100 && columnas > 0 && columnas < 100)
        {
            this->filas = filas;
            this->columnas = columnas;
        }
        else
        {
            this->filas = 0;
            this->columnas = 0;
        }
    }
    // Destructor
    ~Matriz()
    {
        // Destructor
    }
    // Setters
    void setFilas(int filas)
    {
        this->filas = filas;
    }
    void setColumnas(int columnas)
    {
        this->columnas = columnas;
    }
    void setMatriz(int matriz[100][100])
    {
        for (int i = 0; i < this->filas; i++)
        {
            for (int j = 0; j < this->columnas; j++)
            {
                this->matriz[i][j] = matriz[i][j];
            }
        }
    }
    void setValue(int fila, int columna, int valor)
    {
        this->matriz[fila][columna] = valor;
    }
    // Getters
    int getFilas()
    {
        return this->filas;
    }
    int getColumnas()
    {
        return this->columnas;
    }
    int getMatriz(int i, int j)
    {
        return this->matriz[i][j];
    }
    // Metodos
    bool esSimetrica()
    {
        for (int i = 0; i < this->filas; i++)
        {
            for (int j = 0; j < this->columnas; j++)
            {
                if (this->matriz[i][j] != this->matriz[j][i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    Matriz transpuesta()
    {
        Matriz matrizTranspuesta(this->columnas, this->filas);
        for (int i = 0; i < this->filas; i++)
        {
            for (int j = 0; j < this->columnas; j++)
            {
                matrizTranspuesta.setValue(j, i, this->matriz[i][j]);
            }
        }
        return matrizTranspuesta;
    }
    Matriz negativa(){
        Matriz matrizNegativa(this->filas, this->columnas);
        for (int i = 0; i < this->filas; i++)
        {
            for (int j = 0; j < this->columnas; j++)
            {
                matrizNegativa.setValue(i, j, -this->matriz[i][j]);
            }
        }
        return matrizNegativa;
    }
    bool esAntisimetrica()
    {
        // Su transpuesta debe ser igual a la negativa de la matriz original
        Matriz matrizTranspuesta = this->transpuesta();
        Matriz matrizNegativa = this->negativa();

        for (int i = 0; i < this->filas; i++)
        {
            for (int j = 0; j < this->columnas; j++)
            {
                if (matrizTranspuesta.getMatriz(i, j) != matrizNegativa.getMatriz(i, j))
                {
                    return false;
                }
            }
        }
        return true;        
    }
    void print()
    {
        for (int i = 0; i < this->filas; i++)
        {
            for (int j = 0; j < this->columnas; j++)
            {
                cout << this->matriz[i][j] << " ";
            }
            cout << endl;
        }
    }
};

Matriz multiplicarEscalar(Matriz m, int escalar)
{
    Matriz resultado(m.getFilas(), m.getColumnas());
    for (int i = 0; i < m.getFilas(); i++)
    {
        for (int j = 0; j < m.getColumnas(); j++)
        {
            resultado.setValue(i, j, m.getMatriz(i, j) * escalar);
        }
    }
    return resultado;
}

Matriz multiplicarMatrices(Matriz m1, Matriz m2)
{
    Matriz resultado(m1.getFilas(), m2.getColumnas());
    for (int i = 0; i < m1.getFilas(); i++)
    {
        for (int j = 0; j < m2.getColumnas(); j++)
        {
            int suma = 0;
            for (int k = 0; k < m1.getColumnas(); k++)
            {
                suma += m1.getMatriz(i, k) * m2.getMatriz(k, j);
            }
            resultado.setValue(i, j, suma);
        }
    }
    return resultado;
}

#endif // PUNTO3_H