#include <iostream>

using namespace std;

int main()
{
    float a[5][5];

    // ingresar valores
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "Ingrese el valor de la posicion [" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }

    float sumaColumnas[5] = {0};

    // sumar columnas
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sumaColumnas[i] += a[j][i];
        }
    }

    float mayor = sumaColumnas[0];
    int indicemayor = 0;
    for (int i = 0; i < 5; i++)
    {
        if (mayor < sumaColumnas[i])
        {
            mayor = sumaColumnas[i];
            indicemayor = i;
        }
    }

    float menor = sumaColumnas[0];
    int indicemenor = 0;
    for (int i = 0; i < 5; i++)
    {
        if (menor > sumaColumnas[i])
        {
            menor = sumaColumnas[i];
            indicemenor = i;            
        }
    }

    // imprimir matriz original
    cout << "Matriz original: " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // imprimir suma de columnas
    cout << "Suma de columnas: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Columna " << i << ": " << sumaColumnas[i] << endl;
    }

    // cambiar las columnas
    float aux[5];
    for (int i = 0; i < 5; i++)
    {
        aux[i] = a[i][indicemenor];
        a[i][indicemenor] = a[i][indicemayor];
        a[i][indicemayor] = aux[i];
    }

    // imprimir matriz cambiada
    cout << "Matriz cambiada: " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

    