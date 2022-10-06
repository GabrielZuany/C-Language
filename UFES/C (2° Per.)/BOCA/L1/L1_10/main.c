#include <stdio.h>
#include "tPonto.h"

int main(){
    int qtd, i, i_mais_prox = 0;
    float dist = 0, menor_dist = 1000000;
    scanf("%d", &qtd);
    tPonto pontos[qtd];

    for(i=0; i<qtd; i++){
        pontos[i] = LePonto();
        if(i == 0){
            continue;
        }
        dist = Distancia(pontos[i], pontos[0]);
        if(MaisProximo(dist, menor_dist)){
            menor_dist = dist;
            i_mais_prox = i;
        }
    }

    printf("Mais proximo:");
    ImprimirPonto(pontos[i_mais_prox]);
    return 0;
}