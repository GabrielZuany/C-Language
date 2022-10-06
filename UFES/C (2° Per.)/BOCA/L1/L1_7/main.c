#include <stdio.h>
#include "tPonto.h"

int main(){
    tPonto p1Reta = {0, 0}, p2Reta = {0, 0};
    int qtd, i;

    scanf("%d", &qtd);
    for(i=0; i<qtd; i++){
        p1Reta = LeCoordenada();
        p2Reta = LeCoordenada();
        if(RetornaQuadrante(p1Reta) == RetornaQuadrante(p2Reta)){
            printf("MESMO");
        }else{
            printf("DIFERENTE");
        }
        printf("\n");
    }
    return 0;
}
