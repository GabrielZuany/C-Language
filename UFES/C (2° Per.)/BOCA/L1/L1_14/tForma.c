#include "tForma.h"
#include <stdio.h>
#define PI 3.141592

tForma LeForma(){
    tForma f;
    scanf("%f %f %f", &f.base, &f.altura, &f.raio);
    return f;
}

int EhQuadrado(tForma forma){
    if(forma.base == forma.altura && forma.raio <0 && forma.base>0 && forma.altura>0){
        return 1;
    }return 0;
}

int EhRetangulo(tForma forma){
    if(forma.base != forma.altura && forma.raio <0 && forma.base>0 && forma.altura>0){
        return 1;
    }return 0;
}

int EhCirculo(tForma forma){
    if( forma.altura<0 && forma.base <0 && forma.raio>0){
        return 1;
    }return 0;
}

float AreaCirculo(tForma forma){
    return PI*forma.raio*forma.raio;
}

float AreaQuadrado(tForma forma){
    return forma.altura*forma.base;
}

float AreaRetangulo(tForma forma){
    return forma.altura*forma.base;
}