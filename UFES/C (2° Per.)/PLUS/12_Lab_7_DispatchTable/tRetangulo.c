#include <stdio.h>
#include <stdlib.h>
#include "tRetangulo.h"


tRetangulo criaRetangulo(tPonto p1, tPonto p2){
  tRetangulo ret;
  ret.p1 = p1;
  ret.p2 = p2;

  return ret;
}

float calcularAreaRetangulo(tRetangulo r)
{
  return fabs((r.p1.x - r.p2.x) * (r.p1.y - r.p2.y));
}

float areaRetangulo(void *r)
{
  tRetangulo *r2 = (tRetangulo *)r;
  return fabs((r2->p1.x - r2->p2.x) * (r2->p1.y - r2->p2.y));
}