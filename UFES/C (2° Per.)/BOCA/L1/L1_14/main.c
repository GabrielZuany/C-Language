#include "tForma.h"
#include <stdio.h>

int main(){
    int qtd, i;
    int C = 0, R = 0, Q = 0;
    float AC = 0, AR = 0, AQ = 0;
    scanf("%d", &qtd);
    tForma formas[qtd];

    for(i=0; i<qtd; i++){
        formas[i] = LeForma();
        if(EhCirculo(formas[i])){
            AC += AreaCirculo(formas[i]);
            C++;
        }else if(EhQuadrado(formas[i])){
            AQ += AreaQuadrado(formas[i]);
            Q++;
        }else if(EhRetangulo(formas[i])){
            AR += AreaRetangulo(formas[i]);
            R++;
        }
    }
    printf("Circulos: %d Area: %.2f\nQuadrados: %d Area: %.2f\nRetangulos: %d Area: %.2f", C, AC, Q, AQ, R, AR);
    return 0;
}