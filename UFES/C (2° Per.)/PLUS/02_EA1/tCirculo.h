#ifndef _TCIRCULO_H_
#define _TCIRCULO_H_
#define PI 3.1415

typedef struct{
    float raio;
}tCirculo;

tCirculo LeCirculo();
float RetornaAreaCirculo(tCirculo circulo);
float RetornaMultaCirculo(float area);

#endif