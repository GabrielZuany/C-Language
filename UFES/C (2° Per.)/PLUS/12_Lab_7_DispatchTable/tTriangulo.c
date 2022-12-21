#include <stdio.h>
#include <stdlib.h>
#include "tTriangulo.h"

tTriangulo criaTriangulo(tPonto p1, tPonto p2, tPonto p3){
  tTriangulo t;
  t.p1 = p1;
  t.p2 = p2;
  t.p3 = p3;
  return t;
}

float areaTriangulo(void *t)
{
  tTriangulo *t2 = (tTriangulo *)t;
  float a11 = t2->p1.x;
  float a12 = t2->p1.y;
  float a21 = t2->p2.x;
  float a22 = t2->p2.y;
  float a31 = t2->p3.x;
  float a32 = t2->p3.y;
  float det=(((a11*a22*1)+(a21*a32*1)+(a31*a12*1))-((a31*a22*1)+(a11*a32*1)+(a21*a12*1)));
  return fabs(det/2);
}