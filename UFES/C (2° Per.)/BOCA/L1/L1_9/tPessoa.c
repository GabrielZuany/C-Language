#include "tPessoa.h"
#include <stdio.h>

tPessoa LePessoa(){
    tPessoa pessoa;
    scanf("%c,%f,%f", &pessoa.nome, &pessoa.altura, &pessoa.peso);
    scanf("%*c");
    return pessoa;
}

void ImprimirPessoa(tPessoa pessoa){
    printf("N:%c A:%.2f P:%.2f ", pessoa.nome, pessoa.altura, pessoa.peso);
}

float CalcularIMC(tPessoa pessoa){
    return (pessoa.peso/(pessoa.altura*pessoa.altura));
}

int EhMaisAlta(tPessoa pessoa1,tPessoa pessoa2){
    static float maior = 0;
    if(pessoa1.altura>pessoa2.altura && pessoa1.altura>maior){
        maior = pessoa1.altura;
        return 1;
    }else return 0;
}

int EhMaisBaixa(tPessoa pessoa1,tPessoa pessoa2){
    static float menor = 10;
    if(pessoa1.altura<pessoa2.altura && pessoa1.peso<menor){
        menor = pessoa1.peso;
        return 1;
    }else return 0;
}