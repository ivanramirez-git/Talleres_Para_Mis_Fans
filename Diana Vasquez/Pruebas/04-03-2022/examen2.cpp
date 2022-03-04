#include <iostream>
#include "punto1.h"
#include "punto2.h"
#include "punto3.h"

using namespace std;

void punto1()
{
    // Punto 1
    int n[] = {6, 10, 12};
    // Mostrar cada clase de numero
    for (int i = 0; i < 3; i++)
    {
        switch (claseNumero(n[i]))
        {
        case 'A':
            cout << n[i] << " es Abundante" << endl;
            break;
        case 'P':
            cout << n[i] << " es Perfecto" << endl;
            break;
        case 'D':
            cout << n[i] << " es Deficiente" << endl;
            break;
        case 'N':
            cout << n[i] << " es Normal" << endl;
            break;
        }
    }
}

void punto2()
{

    vector<string> datos = cargarDatos();                  // Cargar datos del archivo NOMINA.txt
    vector<pair<int, int>> datosGrupos = emparejar(datos); // Emparejar datos, se demora un poco porque es una funcion que aleatoriamente genera parejas que no se repiten
    for (int i = 0; i < datosGrupos.size(); i++)
    {
        cout << datos[datosGrupos[i].first] << " trabaja con ....." << datos[datosGrupos[i].second] << endl; // Imprimir los datos
    }
}

void punto3()
{

    Matriz matriz(3, 3);                             // Crear una matriz de 3x3
    int m[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // Datos de Matriz de 3x3
    // Se cargan los datos de la matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz.setValue(i, j, m[i][j]);
        }
    }
    // Se imprimen los datos de la matriz
    cout << "Matriz original" << endl;
    matriz.print(); // Print es una funcion de la clase Matriz

    // Es Simetrica
    if (matriz.esSimetrica())
    {
        cout << "Es Simetrica" << endl;
    }
    else
    {
        cout << "No es Simetrica" << endl;
    }

    // Es Antsimetrica
    if (matriz.esAntisimetrica())
    {
        cout << "Es Antisimetrica" << endl;
    }
    else
    {
        cout << "No es Antisimetrica" << endl;
    }

    // Multiplicar por un escalar
    Matriz escalar = multiplicarEscalar(matriz, 2);
    cout << "Matriz escalar: Original*2" << endl;
    escalar.print();

    // Multiplicar por otra matriz
    Matriz matriz2(3, 3);
    int m2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz2.setValue(i, j, m2[i][j]);
        }
    }
    cout << "Matriz 2: " << endl;
    matriz2.print();
    Matriz multiplicacion = multiplicarMatrices(matriz, matriz2);
    cout << "Matriz original*Matriz 2" << endl;
    multiplicacion.print();


    // Caso 2
    Matriz matriz3(2, 2);
    int m3[2][2] = {{1, 0}, {0, 1}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matriz3.setValue(i, j, m3[i][j]);
        }
    }
    cout << "Matriz 3: " << endl;
    matriz3.print();
    // Simetrica
    if (matriz3.esSimetrica())
    {
        cout << "Es Simetrica" << endl;
    }
    else
    {
        cout << "No es Simetrica" << endl;
    }
    // Antisimetrica
    if (matriz3.esAntisimetrica())
    {
        cout << "Es Antisimetrica" << endl;
    }
    else
    {
        cout << "No es Antisimetrica" << endl;
    }
    // Multiplicar por un escalar
    Matriz escalar2 = multiplicarEscalar(matriz3, -4);
    cout << "Matriz escalar: Original*-4" << endl;
    escalar2.print();
    // Multiplicar por otra matriz
    Matriz matriz4(2, 2);
    int m4[2][2] = {{2, 3}, {4, 5}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matriz4.setValue(i, j, m4[i][j]);
        }
    }
    cout << "Matriz 4: " << endl;
    matriz4.print();
    Matriz multiplicacion2 = multiplicarMatrices(matriz3, matriz4);
    cout << "Matriz original*Matriz 2" << endl;
    multiplicacion2.print();

    // Caso 3
    Matriz matriz5(2, 2);
    int m5[2][2] = {{0, -3}, {3, 0}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matriz5.setValue(i, j, m5[i][j]);
        }
    }
    cout << "Matriz 5: " << endl;
    matriz5.print();
    // AntiSimetrica
    if (matriz5.esAntisimetrica())
    {
        cout << "Es Antisimetrica" << endl;
    }
    else
    {
        cout << "No es Antisimetrica" << endl;
    }    
}

// Menu
int main()
{
    int opcion;
    do
    {
        cout << "1. Punto 1" << endl;
        cout << "2. Punto 2" << endl;
        cout << "3. Punto 3" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Punto 1" << endl;
            punto1();
            cout << endl;
            break;
        case 2:
            cout << "Punto 2 (Funciona pero se demora un poco, porque busca parejas que no se repitan)" << endl;
            punto2();
            cout << endl;
            break;
        case 3:
            cout << "Punto 3" << endl;
            punto3();
            cout << endl;
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida" << endl;
        }
    } while (opcion != 0);
    return 0;
}
