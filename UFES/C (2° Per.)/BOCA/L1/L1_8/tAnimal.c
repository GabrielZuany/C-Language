#include <stdio.h>
#include "tAnimal.h"

tAnimal LeAnimal(){
    long double qtdAnimais, prct, peso, valorKg;
    scanf("%Le %Le %Le %Le", &qtdAnimais, &prct, &peso, &valorKg);
    tAnimal animal = {peso, qtdAnimais, valorKg, prct};
    return animal;
}

float QtdRacao(tAnimal animal){
    long double qtd = 0;
    qtd = animal.peso*(animal.prctPeso/100);
    return qtd;
}

float CalcularPreco(float qtdRacao, tAnimal animal){
    long double precoTotal = 0;
    precoTotal = qtdRacao*animal.nAnimais*animal.valorRacao;
    return precoTotal;
}