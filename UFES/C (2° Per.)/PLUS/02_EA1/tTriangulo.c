#include "tTriangulo.h"
#include <stdio.h>
#include <math.h>

tTriangulo LeTriangulo(){
    tTriangulo triangulo;
    scanf("%f %f", &triangulo.comprimento, &triangulo.largura);
    return triangulo;
}

float RetornaAreaTriangulo(tTriangulo triangulo){
  return triangulo.comprimento*(triangulo.largura/2);
}

float RetornaMultaTriangulo(float area){
    return area*0.7;
}