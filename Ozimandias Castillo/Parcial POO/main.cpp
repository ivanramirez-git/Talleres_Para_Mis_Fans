// Your C++ Program

#include <iostream>
#include "Manager.h"
#include

int main() {

    Enemigo enemigo;
    
    enemigo = CreadorEnemigos.CrearSoldado();
    enemigo.setTipo("ACUATICO");

    enemigo.setEspecialidadAdd("BARCO");
    enemigo.setEspecialidadAdd("SUBMARINO");

    return 0;
}
