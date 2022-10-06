#ifndef TTRIANGULO_H
#define TTRIANGULO_H

#include "tPonto.h"

typedef struct{
  tPonto p1, p2, p3;
}tTriangulo;


/**
 * @brief Cria triangulo caso os pontos dados sejam validos.
 * 
 * @param p1, @param p2, @param p3 coordenadas dadas pelo usuario. 
 * 
 * @return tTriangulo caso os pontos sejam validos para a construcao de um triangulo.
 */
tTriangulo criaTri(tPonto p1, tPonto p2, tPonto p3);

#endif