#include <stdio.h>
#include "tPonto.h"

int main(){
    tPonto coordenada;
    int qtd;
    scanf("%d", &qtd);
    while(qtd--){
        coordenada = LeCoordenada();
        ImprimeCoordenadas(coordenada);
        ImprimeQuadrante(coordenada);
        coordenada = RetornaSimetrico(coordenada);
        ImprimeCoordenadas(coordenada);
        ImprimeQuadrante(coordenada);
        printf("\n");
    }

    return 0;
}
