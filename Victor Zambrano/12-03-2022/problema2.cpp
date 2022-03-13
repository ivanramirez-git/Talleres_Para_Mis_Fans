// TAREA FINAL ESTRUCTURA
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

using namespace std;

class Biblioteca
{
private:
    int numerosBiblioteca[MAX]; // Numeros generados aleatoriamente de 3 a 5 digitos, [100, 99999]
    int cantidad;

public:
    Biblioteca(int cantidad)
    {
        this->cantidad = cantidad;
        for (int i = 0; i < cantidad; i++)
        {
            numerosBiblioteca[i] = 100 + rand() % (99999 - 100);
        }
    }

    // a) Suma de los numeros que estan en el intervalo [253, 5245]
    int sumaIntervalo()
    {
        int suma = 0;
        for (int i = 0; i < cantidad; i++)
        {
            if (numerosBiblioteca[i] >= 253 && numerosBiblioteca[i] <= 5245)
            {
                suma += numerosBiblioteca[i];
            }
        }
        return suma;
    }

    bool estaEnIntervalo(int numero)
    {
        if (numero >= 253 && numero <= 5245)
        {
            return true;
        }
        return false;
    }

    // b) Cantidad de numeros que terminan en 33
    int cantidadTerminan33()
    {
        int contador = 0;
        for (int i = 0; i < cantidad; i++)
        {
            if (numerosBiblioteca[i] % 10 == 3)
            {
                if (numerosBiblioteca[i] % 100 / 10 == 3)
                {
                    contador++;
                }
            }
        }
        return contador;
    }

    bool terminaEn33(int numero)
    {
        if (numero % 10 == 3)
        {
            if (numero % 100 / 10 == 3)
            {
                return true;
            }
        }
        return false;
    }

    // c) Suma de numeros menores a 1354
    int sumaMenores1354()
    {
        int suma = 0;
        for (int i = 0; i < cantidad; i++)
        {
            if (numerosBiblioteca[i] < 1354)
            {
                suma += numerosBiblioteca[i];
            }
        }
        return suma;
    }

    bool menor1354(int numero)
    {
        if (numero < 1354)
        {
            return true;
        }
        return false;
    }

    // d) Promedio de todos los numeros que inician con 4
    int promedioInician4()
    {
        int suma = 0;
        int contador = 0;
        for (int i = 0; i < cantidad; i++)
        {
            // numeros entre 100 y 999, que inician con 4
            if (numerosBiblioteca[i] >= 100 && numerosBiblioteca[i] <= 999 && numerosBiblioteca[i] / 100 == 4)
            {
                suma += numerosBiblioteca[i];
                contador++;
                // cout << "[" << i << "]: " << numerosBiblioteca[i] << " / " << 100 << " = " << numerosBiblioteca[i] / 100 << endl;
            }
            // numeros entre 1000 y 9999, que inician con 4
            if (numerosBiblioteca[i] >= 1000 && numerosBiblioteca[i] <= 9999 && numerosBiblioteca[i] / 1000 == 4)
            {
                suma += numerosBiblioteca[i];
                contador++;
                // cout << "[" << i << "]: " << numerosBiblioteca[i] << " / " << 1000 << " = " << numerosBiblioteca[i] / 1000 << endl;
            }
            // numeros entre 10000 y 99999, que inician con 4
            if (numerosBiblioteca[i] >= 10000 && numerosBiblioteca[i] <= 99999 && numerosBiblioteca[i] / 10000 == 4)
            {
                suma += numerosBiblioteca[i];
                contador++;
                // cout << "[" << i << "]: " << numerosBiblioteca[i] << " / " << 10000 << " = " << numerosBiblioteca[i] / 10000 << endl;
            }
        }
        if (contador == 0)
        {
            cout << "No hay numeros que inician con 4" << endl;
            return 0;
        }
        else
        {
            return suma / contador;
        }
    }

    bool inician4(int numero)
    {
        if (numero >= 100 && numero <= 999 && numero / 100 == 4)
        {
            return true;
        }
        if (numero >= 1000 && numero <= 9999 && numero / 1000 == 4)
        {
            return true;
        }
        if (numero >= 10000 && numero <= 99999 && numero / 10000 == 4)
        {
            return true;
        }

        return false;
    }

    // Funcion que imprime los numeros generados
    void imprimirNumeros()
    {
        cout << "Numeros generados: [ ";
        for (int i = 0; i < cantidad - 1; i++)
        {
            // imprimir numeros de colores, si inician con 4, se imprimen en verde, si terminan en 33, se imprimen en rojo, si es menor a 1354, se imprimen en azul y si estan en el intervalo [253, 5245] se imprimen en amarillo, los demas se imprimen normalmente
            if (inician4(numerosBiblioteca[i]))
            {
                cout << "\033[1;32m" << numerosBiblioteca[i] << "\033[0m";
            }
            else if (terminaEn33(numerosBiblioteca[i]))
            {
                cout << "\033[1;31m" << numerosBiblioteca[i] << "\033[0m";
            }
            else if (menor1354(numerosBiblioteca[i]))
            {
                cout << "\033[1;34m" << numerosBiblioteca[i] << "\033[0m";
            }
            else if (estaEnIntervalo(numerosBiblioteca[i]))
            {
                cout << "\033[1;33m" << numerosBiblioteca[i] << "\033[0m";
            }
            else
            {
                cout << numerosBiblioteca[i];
            }
            if (i != cantidad - 2)
            {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }
};

// Pruebas
void pruebas()
{
    srand(time(NULL));
    Biblioteca biblioteca(1000);
    biblioteca.imprimirNumeros();
    cout << "a) Suma de los numeros que estan en el intervalo [253, 5245]: " << biblioteca.sumaIntervalo() << endl;
    cout << "b) Cantidad de numeros que terminan en 33: " << biblioteca.cantidadTerminan33() << endl;
    cout << "c) Suma de numeros menores a 1354: " << biblioteca.sumaMenores1354() << endl;
    cout << "d) Promedio de todos los numeros que inician con 4: " << biblioteca.promedioInician4() << endl;
}

// Main
int main()
{
    pruebas();
    return 0;
}
