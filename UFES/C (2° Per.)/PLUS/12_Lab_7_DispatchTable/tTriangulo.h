#ifndef TTRIANGULO_H
#define TTRIANGULO_H
#include "tPonto.h"

typedef struct{
  tPonto p1, p2, p3;
}tTriangulo;

tTriangulo criaTriangulo(tPonto p1, tPonto p2, tPonto p3);

float areaTriangulo(void *t);

#endif