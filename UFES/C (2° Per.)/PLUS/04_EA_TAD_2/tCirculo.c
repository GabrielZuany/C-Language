#include "tCirculo.h"

tCirculo criaCirculo(tPonto p, float r){ 
  if(r >= 0){
    tCirculo c = {p, r};
    return c; 
  }
  printf("Circulo invalido\n");
  exit(1);
}

float calcularArea(tCirculo c){
  float area = PI*c.raio*c.raio;
  return area;
}

void imprimeCirculo (tCirculo c){
    imprime(c.p);
    printf ("r: %.2f \n", c.raio);
}