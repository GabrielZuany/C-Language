#include "tBoleto.h"
#include <stdio.h>

int main(){
    int qtd, i;
    float soma = 0;
    scanf("%d", &qtd);
    tBoleto boletos[qtd], maior, menor;

    for(i=0; i<qtd;i++){
        boletos[i] = LeBoleto();
        soma+=ValorBoleto(boletos[i]);
    }
    for(i=0; i<qtd;i++){
        if(i==0){
            maior = MaisCaro(boletos[i], boletos[i+1]);
            menor = MaisBarato(boletos[i], boletos[i+1]);       
        }else{
            maior = MaisCaro(boletos[i], maior);
            menor = MaisBarato(boletos[i],menor); 
        }
    }

    printf("Mais caro: ");
    ImprimirBoleto(maior);
    printf("\n");
    printf("Mais barato: ");
    ImprimirBoleto(menor);
    printf("\n");
    printf("Soma: %.2f", soma);

    return 0;
}