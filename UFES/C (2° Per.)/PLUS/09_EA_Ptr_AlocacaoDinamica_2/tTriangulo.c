#include "tTriangulo.h"

struct tTriangulo{
    float base;
    float altura;
    float area;
};

tTriangulo** InicializaMemoriaTriangulo(int qtd){
    tTriangulo** t = calloc(qtd * sizeof(tTriangulo), 1);
    return t;
}

tTriangulo* RegistraTriangulo(float base, float altura){
    tTriangulo* t = calloc(sizeof(tTriangulo), 1);
    t->altura = altura;
    t->base = base;
}

float CalculaAreaTriangulo(tTriangulo* triangulo){
    triangulo->area = triangulo->base*triangulo->altura;
    return triangulo->area;
}

float RetornaAreaTrianguloPos(tTriangulo* t){
    return t->area/10000;
}

void LiberaTriangulo(tTriangulo **t, int qtd){
    int i;
    for(i=0; i<qtd; i++){
        free(t[i]);
    }
    free(t);
}