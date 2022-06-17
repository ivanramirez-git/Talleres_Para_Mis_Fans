// Programa que calcula la suma, resta, multiplicacion y division de polinomios
// Lenguaje: C++
// Autor:
// Fecha: 30/05/2022

#include <iostream>
#define MAX 10

using namespace std;

// Polinomio 1
float coeficientes1[MAX];
int exponentes1[MAX];
int grado1;

// Polinomio 2
float coeficientes2[MAX];
int exponentes2[MAX];
int grado2;

// Polinomio resultante
float coeficientesR[MAX];
int exponentesR[MAX];
int gradoR;

void leerPolinomios()
{
    cout << "Ingrese el grado del primer polinomio: ";
    cin >> grado1;
    cout << "Ingrese los coeficientes del primer polinomio: " << endl;
    for (int i = 0; i < grado1 + 1; i++)
    {
        cout << "Coeficiente " << i << ": ";
        cin >> coeficientes1[i];
        exponentes1[i] = i;
    }

    cout << "Ingrese el grado del segundo polinomio: ";
    cin >> grado2;
    cout << "Ingrese los coeficientes del segundo polinomio: " << endl;
    for (int i = 0; i < grado2 + 1; i++)
    {
        cout << "Coeficiente " << i << ": ";
        cin >> coeficientes2[i];
        exponentes2[i] = i;
    }
}

// imprimir polinomio
void imprimirPolinomio(float coeficientes[MAX], int exponentes[MAX], int grado)
{
    for (int i = grado; i >= 0; i--)
    {
        if (coeficientes[i] != 0)
        {
            if (i == 0)
            {
                cout << coeficientes[i];
            }
            else if (i == 1)
            {
                cout << coeficientes[i] << "x";
            }
            else
            {
                cout << coeficientes[i] << "x^" << i;
            }
            if (i > 0)
            {
                if (coeficientes[i - 1] > 0)
                {
                    cout << "+";
                }
            }
        }
    }
}

void sumarPolinomios()
{
    gradoR = grado1 > grado2 ? grado1 : grado2;
    for (int i = 0; i < gradoR + 1; i++)
    {
        coeficientesR[i] = coeficientes1[i] + coeficientes2[i];
        exponentesR[i] = i;
    }
}

void restarPolinomios()
{
    gradoR = grado1 > grado2 ? grado1 : grado2;
    for (int i = 0; i < gradoR + 1; i++)
    {
        coeficientesR[i] = coeficientes1[i] - coeficientes2[i];
        exponentesR[i] = i;
    }
}

void multiplicarPolinomios()
{
    gradoR = grado1 + grado2;
    for (int i = 0; i < gradoR + 1; i++)
    {
        coeficientesR[i] = 0;
        exponentesR[i] = i;
    }
    for (int i = 0; i < grado1 + 1; i++)
    {
        for (int j = 0; j < grado2 + 1; j++)
        {
            coeficientesR[i + j] += coeficientes1[i] * coeficientes2[j];
        }
    }
}

void dividirPolinomios()
{
    gradoR = grado1 > grado2 ? grado1 - grado2 : 0;
    for (int i = 0; i < gradoR + 1; i++)
    {
        coeficientesR[i] = 0;
        exponentesR[i] = i;
    }
    for (int i = 0; i < grado1 + 1; i++)
    {
        for (int j = 0; j < grado2 + 1; j++)
        {
            coeficientesR[i - j] += coeficientes1[i] * coeficientes2[j];
        }
    }
}

// menu
void menu()
{
    cout << "1. Sumar polinomios" << endl;
    cout << "2. Restar polinomios" << endl;
    cout << "3. Multiplicar polinomios" << endl;
    cout << "4. Dividir polinomios" << endl;
    cout << "0. Salir" << endl;

    int opcion;
    do
    {
        cout << "Ingrese una opcion: ";
        cin >> opcion;
    } while (opcion < 0 || opcion > 4);

    switch (opcion)
    {
    case 1:
        cout << "Polinomio 1: ";
        imprimirPolinomio(coeficientes1, exponentes1, grado1);
        cout << endl;
        cout << "Polinomio 2: ";
        imprimirPolinomio(coeficientes2, exponentes2, grado2);
        cout << endl;
        sumarPolinomios();
        cout << "Polinomio resultante: ";
        imprimirPolinomio(coeficientesR, exponentesR, gradoR);
        break;

    case 2:
        cout << "Polinomio 1: ";
        imprimirPolinomio(coeficientes1, exponentes1, grado1);
        cout << endl;
        cout << "Polinomio 2: ";
        imprimirPolinomio(coeficientes2, exponentes2, grado2);
        cout << endl;
        restarPolinomios();
        cout << "Polinomio resultante: ";
        imprimirPolinomio(coeficientesR, exponentesR, gradoR);
        break;

    case 3:
        cout << "Polinomio 1: ";
        imprimirPolinomio(coeficientes1, exponentes1, grado1);
        cout << endl;
        cout << "Polinomio 2: ";
        imprimirPolinomio(coeficientes2, exponentes2, grado2);
        cout << endl;
        multiplicarPolinomios();
        cout << "Polinomio resultante: ";
        imprimirPolinomio(coeficientesR, exponentesR, gradoR);
        break;

    case 4:
        cout << "Polinomio 1: ";
        imprimirPolinomio(coeficientes1, exponentes1, grado1);
        cout << endl;
        cout << "Polinomio 2: ";
        imprimirPolinomio(coeficientes2, exponentes2, grado2);
        cout << endl;
        dividirPolinomios();
        cout << "Polinomio resultante: ";
        imprimirPolinomio(coeficientesR, exponentesR, gradoR);
        break;

    case 0:
        cout << "Saliendo..." << endl;
        return;

    default:
        cout << "Opcion invalida" << endl;
        break;
    }

    cout << endl;

    menu();

    return;
}

int main()
{
    leerPolinomios();
    menu();

    return 0;
}