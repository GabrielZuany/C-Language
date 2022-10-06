#ifndef _TCIRCULO_H_
#define _TCIRCULO_H_
#define PI 3.1415

typedef struct{
    float raio;
}tCirculo;

tCirculo CriaCirculo(float raio);
float RetornaAreaCirculo(tCirculo circulo);
float RetornaMultaCirculo(float area);

#endif