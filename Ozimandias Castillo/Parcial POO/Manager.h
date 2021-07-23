#ifndef MANAGER_H
#define MANAGER_H

class Manager {

private:
  int NroPlayers;
  Manager();
  Manager instancia;

public:
  int Dificultad;
  Manager obtenerManager();

};

#include "Manager.hxx"

#endif