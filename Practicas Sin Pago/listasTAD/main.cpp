#include <iostream>
#include "listaT.h"

using namespace std;

// Programa principal
int main() {
    Lista<int> lista;
    lista.insertarCabeza(1);
    lista.insertarCabeza(2);
    lista.insertarCabeza(3);
    lista.imprimir();

    return 0;
}