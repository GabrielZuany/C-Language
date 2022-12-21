#include "tGeometrica.h"

typedef float (*fptrArea)(void *);

float area(fptrArea forma, void *x)
{
  return forma(x);
}



