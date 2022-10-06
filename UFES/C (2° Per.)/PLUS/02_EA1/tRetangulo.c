#include "tRetangulo.h"
#include <stdio.h>

tRetangulo LeRetangulo(){
    tRetangulo retangulo;
    scanf("%f %f", &retangulo.base, &retangulo.altura);
    return retangulo;
}

float RetornaAreaRetangulo(tRetangulo retangulo){
    return retangulo.base*retangulo.altura;
}

float RetornaMultaRetangulo(float area){
    return area*0.8;
}