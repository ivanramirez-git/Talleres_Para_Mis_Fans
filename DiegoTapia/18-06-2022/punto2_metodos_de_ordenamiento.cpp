#include <iostream>
#define INFINITY 9999999
using namespace std;

// Selection Sort
void selectionSort(int vec[], int tam);

// Binary Search
int binarySearch(int vec[], int tam, int valor);

// Buscar el 1 y 2 elementos mas grandes de un vector
pair<int, int> buscarDosMaximos(int vec[], int tam);

// Print vector
void printVector(int vec[], int tam);

// Main
int main()
{
    // pedir el tamaño del vector
    int tam;
    cout << "Ingrese el tamaño del vector: ";
    do
    {
        cin >> tam;
    } while (tam <= 0);

    // pedir los valores del vector
    int vec[tam];
    int aux[tam];
    pair<int, int> resultado;
    cout << "Ingrese los valores del vector: \n";
    for (int i = 0; i < tam; i++)
    {
        cout << "vec[" << i << "]: ";
        cin >> vec[i];
        aux[i] = vec[i];
    }

    // menu
    int opcion;
    bool ordenado = false;
    do
    {
        cout << "1. Ordenar con Selection Sort" << endl;
        cout << "2. Buscar un valor en el vector" << endl;
        cout << "3. Buscar los dos elementos mas grandes del vector" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            selectionSort(vec, tam);
            cout << "Vector original: ";
            printVector(aux, tam);
            cout << "Vector ordenado: ";
            printVector(vec, tam);
            ordenado = true;
            break;
        case 2:
            if (ordenado)
            {

                int valor;
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                if (binarySearch(vec, tam, valor) == -INFINITY)
                {
                    cout << "El valor no se encuentra en el vector" << endl;
                }
                else
                {
                    cout << "El valor se encuentra en el vector" << endl;
                }
            }
            else
            {
                cout << "El vector no esta ordenado" << endl;
            }
            break;
        case 3:
            resultado = buscarDosMaximos(vec, tam);
            cout << "El primer elemento mas grande es: " << resultado.first << endl;
            cout << "El segundo elemento mas grande es: " << resultado.second << endl;
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    } while (opcion != 0);

    return 0;
}

// Selection Sort
void selectionSort(int vec[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        int min = i;
        for (int j = i + 1; j < tam; j++)
        {
            if (vec[j] < vec[min])
            {
                min = j;
            }
        }
        int aux = vec[i];
        vec[i] = vec[min];
        vec[min] = aux;
    }
}

// Binary Search
int binarySearch(int vec[], int tam, int valor)
{
    int inicio = 0;
    int fin = tam - 1;
    int medio;
    while (inicio <= fin)
    {
        medio = (inicio + fin) / 2;
        if (vec[medio] == valor)
        {
            return medio;
        }
        else if (vec[medio] < valor)
        {
            inicio = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
    }
    // -infinito
    return -INFINITY;
}

// Buscar el 1 y 2 elementos mas grandes de un vector
pair<int, int> buscarDosMaximos(int vec[], int tam)
{
    int max1 = vec[0];
    int max2 = vec[0];
    for (int i = 1; i < tam; i++)
    {
        if (vec[i] > max1)
        {
            max2 = max1;
            max1 = vec[i];
        }
        else if (vec[i] > max2)
        {
            max2 = vec[i];
        }
    }
    return make_pair(max1, max2);
}

// Print vector
void printVector(int vec[], int tam)
{
    cout << "[";
    for (int i = 0; i < tam; i++)
    {
        cout << vec[i];
        if (i != tam - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}