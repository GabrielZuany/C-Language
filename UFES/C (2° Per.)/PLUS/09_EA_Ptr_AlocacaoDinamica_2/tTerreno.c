#include "tTerreno.h"
#include <math.h>
#include <stdio.h>

struct tTerreno{
    tCirculo** circulos;
    tRetangulo** retangulos;
    tTriangulo** triangulos;
    int qtd_circ;
    int qtd_ret;
    int qtd_tri;
    float areaTotal;
    float dp;
};

tTerreno* InicializaTerreno(int qtd){
    tTerreno* t = (tTerreno*)calloc(sizeof(tTerreno),1);
    t->qtd_circ = 0;
    t->qtd_ret = 0;
    t->qtd_tri = 0;
    t->areaTotal = 0;
    t->dp = 0;
    t->circulos = InicializaMemoriaCirculo(qtd);
    t->retangulos = InicializaMemoriaRetangulo(qtd);
    t->triangulos = InicializaMemoriaTriangulo(qtd);
    
    return t;
}

void RegistraTerreno(tTerreno* terreno, char tipo, float base, float altura,float raio){
    if(tipo=='C'){
        terreno->circulos[terreno->qtd_circ] = RegistraCirculo(raio);
        terreno->areaTotal += CalculaAreaCirculo(terreno->circulos[terreno->qtd_circ]);
        terreno->qtd_circ++;

    }else if(tipo=='R'){
         terreno->retangulos[terreno->qtd_ret] = RegistraRetangulo(base, altura);
        terreno->areaTotal+= CalculaAreaRetangulo(terreno->retangulos[terreno->qtd_ret]);
        terreno->qtd_ret++;

    }else{
        terreno->triangulos[terreno->qtd_tri] = RegistraTriangulo(base, altura);
        terreno->areaTotal+= CalculaAreaTriangulo(terreno->triangulos[terreno->qtd_tri]);
        terreno->qtd_tri++;
    }
}

float RetornaAreaTotal(tTerreno* terreno){
    return terreno->areaTotal;
}

float RetornaMediaDesmatamento(tTerreno* terreno){
    float qtd = terreno->qtd_circ + terreno->qtd_ret + terreno->qtd_tri;
    float desm = (terreno->areaTotal) / qtd;
    return desm/10000;
}

float RetornaDesvioPadrao(tTerreno* terreno){
    float media = RetornaMediaDesmatamento(terreno);
    float soma = 0, dp = 0, qtd = terreno->qtd_circ+terreno->qtd_ret+terreno->qtd_tri;
    int i;

    for(i=0; i<terreno->qtd_circ; i++){
        soma+= pow((media-RetornaAreaCirculoPos(terreno->circulos[i])), 2);
    }

    for(i=0; i<terreno->qtd_ret; i++){
        soma+= pow((media-RetornaAreaRetanguloPos(terreno->retangulos[i])), 2);
    }

    for(i=0; i<terreno->qtd_tri; i++){
        soma+= pow((media-RetornaAreaTrianguloPos(terreno->triangulos[i])), 2);
    }

    dp = sqrt(soma/qtd);

    return dp;
}

void LiberaMemoria(tTerreno* terreno){
    LiberaCirculo(terreno->circulos, terreno->qtd_circ);
    LiberaRetangulo(terreno->retangulos, terreno->qtd_ret);
    LiberaTriangulo(terreno->triangulos, terreno->qtd_tri);

    free(terreno);
}