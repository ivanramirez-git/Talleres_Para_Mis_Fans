#ifndef NAVE_H
#define NAVE_H

#include "ITrasladable.h"

class Nave {
private:
  int NroAlas;
public:
  aterrizar();
  void mover(ITrasladable transladable);

};

#include "Nave.hxx"

#endif