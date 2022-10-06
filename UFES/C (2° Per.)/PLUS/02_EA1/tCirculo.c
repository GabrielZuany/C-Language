#include "tCirculo.h"
#include <stdio.h>

tCirculo LeCirculo(){
    tCirculo circulo;
    scanf("%f", &circulo.raio);
    return circulo;
}

float RetornaAreaCirculo(tCirculo circulo){
    return PI*circulo.raio*circulo.raio;
}

float RetornaMultaCirculo(float area){
    return area*0.6;
}