#include <stdio.h>
#include "tPonto.h"

int main(){
    tPonto p = {0, 0}, p1Reta = {0, 0}, p2Reta = {0, 0};
    int qtd, i;
    float dist_inicio = 0, dist_fim = 0;

    scanf("%d", &qtd);
    for(i=0; i<qtd; i++){
        p = LeCoordenada();
        p1Reta = LeCoordenada();
        p2Reta = LeCoordenada();
        dist_inicio = CalculaDistancia(p, p1Reta);
        dist_fim = CalculaDistancia(p, p2Reta);
        if(dist_inicio == dist_fim){
            printf("EQUIDISTANTE");
        }else if(dist_inicio>dist_fim){
            printf("FIM");
        }else printf("INICIO");
        printf("\n");
    }
    return 0;
}
