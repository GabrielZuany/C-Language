#ifndef TQUADRADO_H
#define TQUADRADO_H
#include "tPonto.h"

typedef struct{
  tPonto p1, p2;
}tQuadrado;


tQuadrado criaQuadrado(tPonto p1, tPonto p2);

float calcularAreaQuadrado(tQuadrado q);

float areaQuadrado(void *q);

#endif