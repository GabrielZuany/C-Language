#include "tBoleto.h"
#include <stdio.h>

tBoleto LeBoleto(){
    tBoleto boleto;
    scanf("%d %f", &boleto.cod, &boleto.valor);
    return boleto;
}

void ImprimirBoleto(tBoleto boleto){
    printf("Cod: %d valor: %.2f", boleto.cod, boleto.valor);    
}

tBoleto MaisCaro(tBoleto boleto1,tBoleto boleto2){
    if (boleto1.valor>boleto2.valor){
        return boleto1;
    }
    return boleto2;
}

tBoleto MaisBarato(tBoleto boleto1,tBoleto boleto2){
    if (boleto1.valor<boleto2.valor){
        return boleto1;
    }
    return boleto2;
}

float ValorBoleto(tBoleto boleto){
    return boleto.valor;
}