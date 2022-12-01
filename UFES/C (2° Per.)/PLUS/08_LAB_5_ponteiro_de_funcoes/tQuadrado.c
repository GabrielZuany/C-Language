#include <stdio.h>
#include <stdlib.h>
#include "tQuadrado.h"

tQuadrado criaQuadrado(tPonto p1, tPonto p2){
  tQuadrado q;
  q.p1 = p1;
  q.p2 = p2;

  return q;
}

float calcularAreaQuadrado(tQuadrado q)
{
  return fabs((q.p1.x - q.p2.x) * (q.p1.y - q.p2.y));
}

float areaQuadrado(void *q)
{
  tQuadrado *q2 = (tQuadrado *)q;
  return fabs((q2->p1.x - q2->p2.x) * (q2->p1.y - q2->p2.y));
}