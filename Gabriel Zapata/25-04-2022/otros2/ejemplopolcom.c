/******************************************************************************
 *
 * ejemplopolcom.c: ejemplo de un prgrama con la libreria "policom-op.h"
 *
 * Programmer: Cristobal Guzman Poblete, Cesar Sandoval Mondaca
 *
 * Santiago de Chile, 28/04/2022
 *
 ******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "policom-op.h"

int main (int argc, char **argv){
  struct politerm *p, *q, *z, *d, *r;
  struct com c;
  
  p = Iniciarpol(p);
  p = leerpol();
  escribirpol(p);
  q = Iniciarpol(q);
  q = leerpol();
  escribirpol (q);
  z = Iniciarpol (z);
  z = sumpol((p), (q));
  escribirpol (z);
  d= Iniciarpol (d);
  d = respol((p), (q));
  escribirpol (d);
  r = Iniciarpol (r);
  r = mulpol((p),(q));
  escribirpol (r) ;
  evpc((p));
}

