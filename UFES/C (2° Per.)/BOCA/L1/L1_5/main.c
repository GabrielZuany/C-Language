#include <stdio.h>
#include "tPonto.h"

int main(){
    tPonto p1 = {0, 0}, p2 = {0, 0};
    int qtd, i;
    float dist = 0;

    scanf("%d", &qtd);
    for(i=0; i<qtd; i++){
        if(i==0){
            p1 = LeCoordenada();
            printf("-\n");
            continue;
        }
        p2 = LeCoordenada();
        dist = CalculaDistancia(p1, p2);
        p1 = p2;
        printf("%.2f\n", dist);
    }
    return 0;
}
