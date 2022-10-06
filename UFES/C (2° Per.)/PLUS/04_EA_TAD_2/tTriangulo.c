#include "tTriangulo.h"
#include "tPonto.h"
#include <stdlib.h>

tTriangulo criaTri(tPonto p1, tPonto p2, tPonto p3){
  float dist_1_2, dist_2_3, dist_3_1;
  dist_1_2 = distancia(p1, p2);
  dist_2_3 = distancia(p2, p3);
  dist_3_1 = distancia(p3, p1);

  if(dist_1_2 >= dist_2_3+dist_3_1 || dist_2_3>= dist_1_2+dist_3_1 || dist_3_1>=dist_1_2+dist_2_3){
    printf("Triangulo invalido\n");
    exit(1);
  }

  tTriangulo tri;
  tri.p1 = p1;
  tri.p2 =p2;
  tri.p3 = p3;

  return tri;
}