#include "tRetangulo.h"
#include <stdio.h>
#include <stdlib.h>

tRetangulo CriaRetangulo(float base, float altura){
    tRetangulo retangulo;
    if(base>=0 && altura>=0){
        retangulo.base = base;
        retangulo.altura = altura;
        return retangulo;
    }
    printf("Algum dos valores digitados para o retangulo nao eh valido!\n");
    exit(0);
}

float RetornaAreaRetangulo(tRetangulo retangulo){
    return retangulo.base*retangulo.altura;
}

float RetornaMultaRetangulo(float area){
    return area*0.8;
}