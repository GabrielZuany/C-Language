#include "tCirculo.h"
#include <stdio.h>
#include <stdlib.h>

tCirculo CriaCirculo(float raio){
    tCirculo circulo;
    if(raio>=0){
        circulo.raio = raio;
    }else{
        printf("Valor de raio invalido!\n");
        exit(0);
    }
    return circulo;
}

float RetornaAreaCirculo(tCirculo circulo){
    return PI*circulo.raio*circulo.raio;
}

float RetornaMultaCirculo(float area){
    return area*0.6;
}