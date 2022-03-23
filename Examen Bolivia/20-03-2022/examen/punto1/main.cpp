#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*PROTOTIPO DE FUNCIONES Y PROCEDIMIENTOS*/
void cargar_datos(char estado[], int asiento[], string carnet[21]);
void mostrar_libres(char estado[], int libre[21]);
void mostrar_planilla(char estado[], string carnet[21]);
void reservar(char estado[], string carnet[10]);
int busca_carnet(string carnet[10], char ci[]);

/*PROGRAMA PRINCIPAL*/
int main()
{
    int asiento[21], op;
    char estado[21];
    int libre[21];
    string carnet[21];
    system("color 1e");
    cargar_datos(estado, asiento, carnet);
    do
    {
        cout << "------*TRANS VELOZ*------------------------------------" << endl;
        cout << "-------OPCIONES----------------------------------------" << endl;
        cout << "1. MOSTRAR ASIENTOS LIBRES                             " << endl;
        cout << "2. RESERVAR ASIENTO                                    " << endl;
        cout << "3. Salir                                               " << endl;
        cout << "-------------------------------------------------------" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            mostrar_libres(estado, libre);
            break;
        case 2:
            reservar(estado, carnet);
            mostrar_planilla(estado, carnet);
            break;
        case 3:
            break;
        }
    } while (op != 3);
    return 0;
}

/*PROCEDMIENTOS*/
void cargar_datos(char estado[], int asiento[], string carnet[21])
{
    int i;
    char ci[10];
    for (i = 0; i < 20; i++)
    {
        asiento[i] = i + 1;
        do
        {
            cout << "Ingrese el estado del asiento " << asiento[i] << " (L o R): ";
            cin >> estado[i];
        } while (estado[i] != 'L' && estado[i] != 'R');
        if (estado[i] == 'R')
        {
            do
            {
                cout << "Ingrese el carnet del pasajero para el asiento " << asiento[i] << ": ";
                cin >> ci;
            } while (busca_carnet(carnet, ci) != -1);
            carnet[i] = ci;
        }
    }
}

void mostrar_libres(char estado[], int libre[21])
{
    int i;
    for (i = 0; i < 21; i++)
    {
        if (estado[i] == 'L')
        {
            libre[i] = i + 1;
        } else
        {
            libre[i] = 0;
        }
    }
    cout << "ASIENTOS LIBRES: " << endl;
    for (i = 0; i < 21; i++)
    {
        if (libre[i] != 0)
        {
            cout << libre[i] << " ";
        }
    }
    cout << endl;
}

void mostrar_planilla(char estado[], string carnet[21])
{
    string encabezados[] = {"ASIENTO", "ESTADO", "UBICACION", "PRECIO", "CI"};
    // Imprimir toda la planilla
    for (int i = 0; i < 5; i++)
    {
        cout << encabezados[i];
        int e = encabezados[i].length();
        while (e < 20)
        {
            cout << " ";
            e++;
        }
    }
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << i + 1;
        int e = 1;
        while (e < 20)
        {
            cout << " ";
            e++;
        }
        cout << estado[i];
        e = 1;
        while (e < 20)
        {
            cout << " ";
            e++;
        }
        string u = "UBICACION";
        cout << u;
        e = u.length();
        while (e < 20)
        {
            cout << " ";
            e++;
        }
        cout << "40";
        e = 2;
        while (e < 20)
        {
            cout << " ";
            e++;
        }
        cout << carnet[i];
        cout << endl;
    }
    for (int i = 9; i < 20; i++)
    {
        cout << i + 1;
        int e = 2;
        while (e < 20)
        {
            cout << " ";
            e++;
        }
        cout << estado[i];
        e = 1;
        while (e < 20)
        {
            cout << " ";
            e++;
        }
        string u = "BAJO";
        cout << u;
        e = u.length();
        while (e < 20)
        {
            cout << " ";
            e++;
        }
        cout << "35";
        e = 2;
        while (e < 20)
        {
            cout << " ";
            e++;
        }
        cout << carnet[i];
        cout << endl;
    }
}

void reservar(char estado[], string carnet[21])
{
    int i, asiento;
    char ci[10];
    cout << "Ingrese el numero de asiento: ";
    cin >> asiento;
    cout << "Ingrese el carnet: ";
    cin >> ci;
    i = busca_carnet(carnet, ci);
    if (i != -1)
    {
        cout << "El carnet existe, no se pueden reservar dos veces con el mismo carnet" << endl;
    }
    else
    {
        estado[asiento - 1] = 'R';
        carnet[asiento - 1] = ci;
    }
}

int busca_carnet(string carnet[10], char ci[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (carnet[i] == ci)
        {
            return i;
        }
    }
    return -1;
}