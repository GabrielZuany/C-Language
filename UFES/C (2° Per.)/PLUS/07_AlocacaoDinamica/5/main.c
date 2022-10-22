#include <stdio.h>
#include <stdlib.h>
#include "tBoleto.h"

int main(){
    int qtd, i, cod;
    float soma=0, valor;
    scanf("%d", &qtd);

    tBoleto* boletos[qtd];
    tBoleto* caro, *barato;

    for(i=0; i<qtd;i++){
        scanf("%d %f", &cod, &valor);
        boletos[i] = RegistraBoleto(cod, valor, boletos[i]);
    }
    for(i=0;i<qtd;i++){
        if(i==0){
            caro  = boletos[0];
            barato = boletos[0];
        }
        
        caro = MaisCaro(boletos[i], caro);
        barato = MaisBarato(boletos[i], barato);
        soma+=ValorBoleto(boletos[i]);
    
    }
    
    printf("Mais caro: ");
    ImprimirBoleto(caro);
    printf("\nMais barato: ");
    ImprimirBoleto(barato);
    printf("\nSoma: %.2f", soma);

    for(i=0; i<qtd; i++){
       FreeMem(boletos[i]); 
    }

    return 0;
}