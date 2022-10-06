#ifndef TPONTO_H
#define TPONTO_H

#include<stdio.h>
#include<math.h>


typedef struct {
  float x;
  float y;
}tPonto;


/**
Criar um ponto a partir de dois numeros flutuantes

@x - float maior que zero
@y - floar maior que zero

return  um tipo tPonto preenchido
*/
tPonto criaPonto(float x, float y);


/**
 * @brief calcula a distancia a partir de dois pontos cartesianos;
 * 
 * @param p1 coordenada valida do ponto 1 
 * @param p2 coordenada valida do ponto 2
 * @return a distancia em ponto flutuante. 
 */
float distancia (tPonto p1, tPonto p2);


/**
 * @brief imprime ponto
 * 
 * @param p ponto
 */
void imprime (tPonto p);

#endif