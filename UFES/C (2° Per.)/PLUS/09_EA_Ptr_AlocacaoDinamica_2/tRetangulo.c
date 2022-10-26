#include "tRetangulo.h"

struct tRetangulo{
    float base;
    float altura;
    float area;
};

tRetangulo** InicializaMemoriaRetangulo(int qtd){
    tRetangulo** r = calloc(qtd * sizeof(tRetangulo), 1);
    return r;
}

float CalculaAreaRetangulo(tRetangulo *retangulo){
    retangulo->area = (retangulo->base*retangulo->altura);
    return retangulo->area;
}

float RetornaAreaRetanguloPos(tRetangulo* r){
    return r->area/10000;
}

tRetangulo* RegistraRetangulo(float base, float altura){
    tRetangulo* r = calloc(sizeof(tRetangulo), 1);
    r->base = base;
    r->altura = altura;
}

void LiberaRetangulo(tRetangulo **r, int qtd){
    int i;
    for(i=0; i<qtd; i++){
        free(r[i]);
    }
    free(r);
}
