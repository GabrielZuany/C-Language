#include "tGeometrica.h"

typedef float (*ftprCalculaArea)(void*);
ftprCalculaArea operacoes[255] = {NULL};

void InicializaOperacoes(){
   operacoes['T'] = areaTriangulo;
   operacoes['Q'] = areaQuadrado;
   operacoes['C'] = areaCirculo;
   operacoes['R'] = areaRetangulo;
}

float CalculaArea_FTPR(char op, void* tipo){
   ftprCalculaArea operacao;
   operacao = operacoes[op];
   return operacao(tipo);
}

int main()
{  
   InicializaOperacoes();

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

   printf("fptrArea(DispatchTable) triangulo: %.2f\n", CalculaArea_FTPR('T', &t));
   printf("fptrArea(DispatchTable) quadrado: %.2f\n", CalculaArea_FTPR('Q', &q));

   return 0;
}
