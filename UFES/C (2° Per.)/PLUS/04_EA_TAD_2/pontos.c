/**
introdu�o  Tipos definidos pelo usu�rio
*/
#include<stdio.h>
#include<math.h>
#define PI 3.141592


typedef struct {
  float x;
  float y;
}tPonto;


typedef struct{
  tPonto p1, p2, p3;
}tTriangulo;

typedef struct{
  tPonto p1, p2;
}tRetangulo;

typedef struct{
  tPonto p;
  float raio;
}tCirculo;


tPonto criaPonto(float x, float y){
  tPonto p;
  p.x = x;
  p.y = y;
  return p;
}
float calcularArea(tCirculo c){
    float area = PI*c.raio*c.raio;
    return area;
}


float distancia (tPonto p1, tPonto p2){
  return sqrt ((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

void imprime (tPonto p){
	printf ("Coordenada x: %.2f, Coordenada y: %.2f \n", p.x, p.y);
}

int main(){ 
  tPonto centro = {10.0, 20.5};
  tCirculo c = {centro, 5.0};

  printf("Centro %.2f,%.2f - raio %.2f - Area: %.2f\n", c.p.x, c.p.y, c.raio, calcularArea(c));
  return 0;
}

