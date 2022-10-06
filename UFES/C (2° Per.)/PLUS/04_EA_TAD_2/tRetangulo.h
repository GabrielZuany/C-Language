#ifndef TRETANGULO_H
#define TRETANGULO_H
#include "tPonto.h"

typedef struct{
  tPonto p1, p2;
}tRetangulo;


/**
 * @brief cria um retangulo caso os valores dados sejam validos .
 * 
 * @param p1 ponto dado pelo usuario.
 * @param p2 ponto dado pelo usuario.
 * @return tRetangulo 
 */
tRetangulo criaRetangulo(tPonto p1, tPonto p2);

#endif