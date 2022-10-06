#ifndef TCIRCULO_H
#define TCIRCULO_H

#include "tPonto.h"

#define PI 3.141592

typedef struct{
  tPonto p;
  float raio;
}tCirculo;

/**
 * @brief criaCirculo: cria um circulo a partir  de um ponto no plano e um valor real positivo.
 * 
 * @param p : ponto (x, y)
 * @param r : raio, valor real nulo ou positivo.
 * @return circulo com coordenas e raio validos.
 */
tCirculo criaCirculo(tPonto p, float r);


/**
 * @brief calcularArea: calcua area do circulo com coordenas e raio validos.
 * 
 * @param c circulo com coordenas e raio validos.
 * @return area do circulo.
 */
float calcularArea(tCirculo c);


/**
 * @brief imprimeCirculo: impirme informacoes do circulo.
 * 
 * @param c circulo com informacoes validas.
 */
void imprimeCirculo (tCirculo c);

#endif