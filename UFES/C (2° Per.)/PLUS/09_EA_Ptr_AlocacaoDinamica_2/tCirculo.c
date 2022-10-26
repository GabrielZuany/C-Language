#include "tCirculo.h"
#include<stdlib.h>

#define PI 3.141592

struct tCirculo{
    float raio;
    float area;
};

tCirculo** InicializaMemoriaCirculo(int qtd){
    tCirculo** c;
    c = (tCirculo**)calloc(qtd * sizeof(tCirculo),1);
    return c;
}

float CalculaAreaCirculo(tCirculo* circulo){
    circulo->area = PI*circulo->raio*circulo->raio;
    return circulo->area;
}

tCirculo* RegistraCirculo(float raio){
    tCirculo *c = calloc(sizeof(tCirculo), 1);
    c->raio = raio;
    return c;
}

float RetornaAreaCirculoPos(tCirculo*c){
    return c->area/10000;
}

void LiberaCirculo(tCirculo **c, int qtd){
    int i;
    for(i=0; i<qtd; i++){
        free(c[i]);
    }
    free(c);
}