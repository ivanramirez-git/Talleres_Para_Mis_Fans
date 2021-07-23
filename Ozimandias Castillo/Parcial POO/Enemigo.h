#ifndef ENEMIGO_H
#define ENEMIGO_H

class Enemigo {
private:
  float posicionX;
  float posicionY;
  void disparar();
public:
  void buscarEnemigo();
  void mover();
};

#include "Enemigo.hxx"

#endif