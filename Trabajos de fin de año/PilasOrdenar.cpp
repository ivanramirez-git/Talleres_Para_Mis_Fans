#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct pilas
{
    string dato;
    pilas *a;
} * c, *e, *aux;

void menu(void);
void ingresar(void);
void sacar(void);
void ordenar_ascendente(void);
void actualizar_pila(void);

main()
{
    menu();
}
void menu(void)
{
    int y, opc;
    for (;;)
    {
        system("cls");
        cout << "\n1. Ingresar datos (PALABRAS)";
        cout << "\n2. Imprimir datos";
        cout << "\n3. Borrar datos";
        cout << "\n4. Ordenar ascendente";
        cout << "\n0. Salir";
        cout << "\n Ingrese opcion: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            ingresar();
            break;
        case 2:
            actualizar_pila();
            break;
        case 3:
            sacar();
            break;
        case 4:
            ordenar_ascendente();
            break;
        case 0:
            exit(1);
        default:
            cout << "\n Opcion no valida!!";
            break;
        }

        // actualizar menú
        cout << "\n\nOprima una tecla para continuar";
        getch();
    }
}

void ingresar(void) // ingresa los datos
{
    if (!c)
    {
        c = new (pilas);
        cout << "Ingrese datos: ";
        cin >> c->dato;
        c->a = NULL;
        return;
    }

    e = new (pilas);
    cout << "\nIngrese dato: ";
    cin >> e->dato;
    e->a = c;
    c = e;
}

void sacar(void) // elimina los datos
{
    if (!c)
    {
        cout << "\n\nNo hay datos!!";
        return;
    }

    e = new (pilas);
    e = c;
    cout << "\n\ndato eliminado: " << e->dato;
    c = e->a;
    delete (e);
}
void actualizar_pila(void) // actualiza la pila
{
    int y = 2, i, ca = 0;
    e = c;
    while (e)
    {
        ca++;
        e = e->a;
    }

    for (i = 0; i <= ca; i++)
    {
        cout << " ";
    }
    // muestro lo que tiene la pila!!
    i = 0;
    e = c;
    while (e)
    {
        cout << "\n";
        cout << ++i << " - " << e->dato;
        e = e->a;
    }
}

void ordenar_ascendente(void) // ordena los datos de la pila
{
    int y = 2, i, ca = 0;
    string aux;
    e = c;
    while (e)
    {
        ca++;
        e = e->a;
    }

    for (i = 0; i <= ca; i++)
    {
        cout << " ";
    }
    // Copiar la pila a una pila auxiliar para ordenarla
    aux = c->dato;
    e = c;
    while (e)
    {
        e->dato = aux;
        e = e->a;
    }

    // Ordenar la pila auxiliar
    for (i = 0; i < ca; i++)
    {
        for (e = c; e; e = e->a)
        {
            if (e->dato > e->a->dato)
            {
                aux = e->dato;
                e->dato = e->a->dato;
                e->a->dato = aux;
            }
        }
    }

    // Mostrar la pila ordenada
    for (i = 0; i <= ca; i++)
    {
        cout << " ";
    }
    // muestro lo que tiene la pila!!
    i = 0;
    e = c;
    while (e)
    {
        cout << "\n";
        cout << ++i << " - " << e->dato;
        e = e->a;
    }
}
