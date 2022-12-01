#include "tGeometrica.h"

int main()
{ 
   tPonto centro = criaPonto(10.0, 20.5);
   tCirculo c = criaCirculo(centro, 5.0);

   imprimeCirculo(c);

   printf("Area: %.2f\n", calcularAreaCirculo(c));

   tPonto p1 = criaPonto(0.0, 0.0);

   tPonto p2 = criaPonto(0.0, 1.0);

   tPonto p3 = criaPonto(1.0, 0.0);

   tQuadrado q = criaQuadrado(p1, p2);
   tTriangulo t = criaTriangulo(p1, p2, p3);

   tCirculo *c2 = &c;

   printf("fptrArea: %.2f\n", area(areaQuadrado, &q));

   printf("fptrArea: %.2f\n", area(areaTriangulo, &t));


   return 0;
}
