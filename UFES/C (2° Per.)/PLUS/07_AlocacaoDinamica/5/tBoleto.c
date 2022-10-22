#include "tBoleto.h"
#include <stdio.h>
#include <stdlib.h>

struct tBoleto{
    int cod;
    float valor;
};

tBoleto* RegistraBoleto(int cod, float valor, tBoleto *boleto){
    boleto=malloc(sizeof(tBoleto));
    boleto->cod = cod;
    boleto->valor = valor;
    return boleto;
}

void FreeMem(tBoleto *boletos){
    free(boletos);
}

void ImprimirBoleto(tBoleto* boleto){
    printf("Cod: %d valor: %.2f", boleto->cod, boleto->valor);
}

tBoleto* MaisCaro(tBoleto* boleto1,tBoleto* boleto2){
    if(boleto1->valor > boleto2->valor){
        return boleto1;
    }
    return boleto2;
}

tBoleto* MaisBarato(tBoleto* boleto1,tBoleto* boleto2){
    if(boleto1->valor < boleto2->valor){
        return boleto1;
    }
    return boleto2;
}

float ValorBoleto(tBoleto* boleto){
    return boleto->valor;
}
