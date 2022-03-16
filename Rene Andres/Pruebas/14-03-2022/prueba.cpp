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

	bool equals(fila<T> f)
	{
		// Solo comparar los elementos de la lista
		if (this->size() != f.size())
			return false;
		
		for (auto it = this->begin(); it != this->end(); it++)
		{
			auto it2 = f.begin();
			while (it2 != f.end())
			{
				if (it->first == it2->first && it->second == it2->second)
					break;
				it2++;
			}
			if (it2 == f.end())
				return false;
		}
		return true;
	}

	// operador !=
	bool operator!=(const fila<T> &f)
	{
		return !(*this == f);
	}

	// operador +
	fila<T> operator+(const fila<T> &f)
	{
		// Comparar los id_fila de las dos filas
		if (this->id_fila == f.id_fila)
		{
			fila<T> fila_resultado(this->id_fila);
			// Si son iguales, comparar los id_col de las dos filas
			for (auto it = this->begin(); it != this->end(); it++)
			{
				// Si el id_col de la fila 1 es distinto al id_col de la fila 2, insertar el par en la fila resultado
				if (it->first != f.find(it->first)->first)
				{
					fila_resultado.insertar(it->first, it->second);
				}
				// Si son iguales, sumar los valores de los id_col
				else
				{
					fila_resultado.insertar(it->first, it->second + f.find(it->first)->second);
				}

			}
			return fila_resultado;
		}
		else
		{
			throw "Las filas no tienen el mismo id_fila";
		}
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

	// +
	matriz_dispersa<T> operator+(const matriz_dispersa<T> &matriz)
	{
		
		// MOSTRAR LA MATRIZ ORIGINAL1
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

		//MOSTRAR LA MATRIZ ORIGINAL2
		vector<vector<T>> matriz_aux3(matriz.m, vector<T>(matriz.n, 0));

		matriz_dispersa<T> matriz_aux4(matriz.n, matriz.m);        
		// COPIAR LA MATRIZ DISPERSA EN LA MATRIZ AUXILIAR
		for (int i = 0; i < matriz.size(); i++)
		{
			matriz_aux4.push_back(this->at(i));
		}

		// LLENAR LA MATRIZ AUXILIAR CON 0
		for (int i = 0; i < matriz.m; i++)
		{
			for (int j = 0; j < matriz.n; j++)
			{
				matriz_aux3[i][j] = 0;
			}
		}

		// RECORRER LA MATRIZ DISPERSA
		for (int i = 0; i < matriz.size(); i++)
		{
			// RECORRER EL LA LIST DE LA FILA
			while (!matriz_aux4.at(i).empty())
			{
				// INSERTAR EN LA MATRIZ AUXILIAR
				matriz_aux3[i][matriz_aux4.at(i).front().first] = matriz_aux4.at(i).front().second;

				// ELIMINAR EL ELEMENTO DE LA FILA
				matriz_aux4.at(i).pop_front();
			}
		}

		// SUMA DE LAS MATRICES
		matriz_dispersa<T> matriz_suma(matriz.m, matriz.n);
		for (int i = 0; i < matriz.m; i++)
		{
			for (int j = 0; j < matriz.n; j++)
			{
				matriz_suma.insertar(i, j, matriz_aux[i][j] + matriz_aux3[i][j]);
			}
		}

		return matriz_suma;
	}

	// *
	matriz_dispersa<T> operator*(const matriz_dispersa<T> &matriz)
	{
		
		// MOSTRAR LA MATRIZ ORIGINAL1
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

		//MOSTRAR LA MATRIZ ORIGINAL2
		vector<vector<T>> matriz_aux3(matriz.m, vector<T>(matriz.n, 0));

		matriz_dispersa<T> matriz_aux4(matriz.n, matriz.m);        
		// COPIAR LA MATRIZ DISPERSA EN LA MATRIZ AUXILIAR
		for (int i = 0; i < matriz.size(); i++)
		{
			matriz_aux4.push_back(this->at(i));
		}

		// LLENAR LA MATRIZ AUXILIAR CON 0
		for (int i = 0; i < matriz.m; i++)
		{
			for (int j = 0; j < matriz.n; j++)
			{
				matriz_aux3[i][j] = 0;
			}
		}

		// RECORRER LA MATRIZ DISPERSA
		for (int i = 0; i < matriz.size(); i++)
		{
			// RECORRER EL LA LIST DE LA FILA
			while (!matriz_aux4.at(i).empty())
			{
				// INSERTAR EN LA MATRIZ AUXILIAR
				matriz_aux3[i][matriz_aux4.at(i).front().first] = matriz_aux4.at(i).front().second;

				// ELIMINAR EL ELEMENTO DE LA FILA
				matriz_aux4.at(i).pop_front();
			}
		}

		// MULTIPLICACION DE LAS MATRICES (Multiplicacion Matricial)
		matriz_dispersa<T> matriz_multi(matriz.m, matriz.n);
		// Ejemplo:
		/*
		1 2 3 * 1 2 3 = c11 c12 c13
		4 5 6   4 5 6   c21 c22 c23
		7 8 9   7 8 9   c31 c32 c33

		c11 = 1*1 + 2*4 + 3*7
		c12 = 1*2 + 2*5 + 3*8
		c13 = 1*3 + 2*6 + 3*9
		...
		c33 = 3*3 + 6*6 + 9*9
		*/
		for (int i = 0; i < matriz.m; i++)
		{
			for (int j = 0; j < matriz.n; j++)
			{
				T suma = 0;
				for (int k = 0; k < matriz.m; k++)
				{
					suma += matriz_aux[i][k] * matriz_aux3[k][j];
				}
				matriz_multi.insertar(i, j, suma);
			}
		}
		return matriz_multi;
	}

	void EliminarDuplicados(){
		// Elimina una fila si esta duplicada
		for (int i = 0; i < this->size(); i++)
		{
			for (int j = 0; j < this->size(); j++)
			{
				if (i != j)
				{
					if (this->at(i) == this->at(j))
					{
						this->erase(this->begin() + i);
					}
				}
			}
		}
	}





	
};

// PRUEBAS
void prueba1()
{
    matriz_dispersa<int> matriz1(3, 3);

    matriz1.insertar(0, 0, 1);
    matriz1.insertar(0, 1, 2);
    matriz1.insertar(1, 0, 4);
    matriz1.insertar(1, 1, 5);
    matriz1.insertar(2, 0, 7);
    matriz1.insertar(2, 2, 9);
    
    cout << "Matriz 1: " << endl;
    cout << matriz1 << endl;


    matriz_dispersa<int> matriz2(3, 3);
    
    cout << "Leyendo archivo 'datos.txt' : " << endl;
	ifstream archivo("datos.txt");
	if (archivo.is_open())
	{
		archivo >> matriz2;
		archivo.close();
	}

    cout << endl;

    cout << "Matriz 2: " << endl;
    cout << endl << matriz2 << endl;

	matriz_dispersa<int> matriz3(3, 3);
	matriz3 = matriz1 + matriz2;

	cout << "Matriz 3 = Matriz 1 + Matriz 2: " << endl;
	cout << endl << matriz3 << endl;

	// Matriz 3 * Matriz 2
	matriz_dispersa<int> matriz4(3, 3);
	matriz4 = matriz3 * matriz2;

	cout << "Matriz 3 * Matriz 2: " << endl;
	cout << endl << matriz4 << endl;

	// Funcion para eliminar duplicados
	matriz_dispersa<int> matriz5(3, 3);
	matriz5.insertar(0, 0, 1);
	matriz5.insertar(0, 1, 2);
	matriz5.insertar(1, 0, 4);
	matriz5.insertar(1, 1, 5);
	matriz5.insertar(2, 0, 1);
	matriz5.insertar(2, 1, 2);

	cout << "Matriz 5: " << endl;
	cout << endl << matriz5 << endl;
	
	cout << "Eliminando duplicados: " << endl;
	matriz5.EliminarDuplicados();
	cout << endl << matriz5 << endl;


}

// PROGRAMA PRINCIPAL
int main()
{
    prueba1();

    return 0;
}
