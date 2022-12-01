#include "tCirculo.h"


tCirculo criaCirculo(tPonto p, float r)
{
  tCirculo c = {p, r};
  return c;
}
float calcularAreaCirculo(tCirculo c){
    float area = PI*c.raio*c.raio;
	
     return area;
}

float areaCirculo(void *c2){
    tCirculo *c = (tCirculo *)c2;
    float area = PI*c->raio*c->raio;
     return area;
}



void imprimeCirculo (tCirculo c){
  
  imprime(c.p);
	printf ("r: %.2f \n", c.raio);

}