#include "tTriangulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

tTriangulo CriaTriangulo(float base, float altura){
    tTriangulo triangulo;
    if(base>=0 && altura>=0){
      triangulo.base = base;
      triangulo.altura = altura;
      return triangulo;
    }
    printf("Algum dos valores digitados para o triangulo nao eh valido!\n");
    exit(0);
}

float RetornaAreaTriangulo(tTriangulo triangulo){
  return triangulo.comprimento*(triangulo.largura/2);
}

float RetornaMultaTriangulo(float area){
    return area*0.7;
}