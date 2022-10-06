#ifndef _TFORMA_
#define _TFORMA_

typedef struct{
    float base;
    float altura;
    float raio;
}tForma;

tForma LeForma();
int EhQuadrado(tForma forma);
int EhRetangulo(tForma forma);
int EhCirculo(tForma forma);
float AreaCirculo(tForma forma);
float AreaQuadrado(tForma forma);
float AreaRetangulo(tForma forma);

#endif