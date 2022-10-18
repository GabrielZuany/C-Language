#include "tCirculo.h"
#include <stdio.h>
#include <stdlib.h>

struct tCirculo{
    float raio;
    float area;
};

void InicializaDados(tCirculo *c){
    c->area = 0;
    c->raio = 0;
}

void ValidaDados(tCirculo *c, float raio){
    if(raio>=0){
        c->raio = raio;
    }else{
        exit(-1);
    }
}

void CalculaArea(tCirculo *c){
    c->area =  3.141592*c->raio*c->raio;
}

void ImprimeDados(tCirculo  *c){
    printf("O circulo de raio %.2f tem %.2f de area\n", c->raio, c->area);
}