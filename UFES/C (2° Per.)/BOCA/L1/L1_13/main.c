#include "tForma.h"
#include <stdio.h>

int main(){
    int qtd, i;
    int C = 0, R = 0, Q = 0;

    scanf("%d", &qtd);
    tForma formas[qtd];

    for(i=0; i<qtd; i++){
        formas[i] = LeForma();
        if(EhCirculo(formas[i])){
            C++;
        }else if(EhQuadrado(formas[i])){
            Q++;
        }else if(EhRetangulo(formas[i])){
            R++;
        }
    }
    printf("Circulos: %d\nQuadrados: %d\nRetangulos: %d", C, Q, R);
    return 0;
}