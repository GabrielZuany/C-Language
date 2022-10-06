#ifndef _TPESSOA_H_
#define _TPESSOA_H_

typedef struct {
    char nome;
    float altura;
    float peso;
}tPessoa;

tPessoa LePessoa();
void ImprimirPessoa(tPessoa pessoa);
float CalcularIMC(tPessoa pessoa);
int EhMaisAlta(tPessoa pessoa1,tPessoa pessoa2);
int EhMaisBaixa(tPessoa pessoa1,tPessoa pessoa2);

#endif



/*
#include <stdio.h>
typedef struct {
    char nome;
    float altura;
    float peso;
}tPessoa;

tPessoa LePessoa(){
    tPessoa pessoa;
    scanf("%c,%f,%f", &pessoa.nome, &pessoa.altura, &pessoa.peso);
    return pessoa;
}

void ImprimirPessoa(tPessoa pessoa){
    printf("N:%c A:%.2f P:%.2f ", pessoa.nome, pessoa.altura, pessoa.peso);
}

float CalcularIMC(tPessoa pessoa){
    return (pessoa.peso/(pessoa.altura*pessoa.altura));
}

int EhMaisAlta(tPessoa pessoa1,tPessoa pessoa2){
    if(pessoa1.altura>pessoa2.altura){
        return 1;
    }else return 0;
}

int EhMaisBaixa(tPessoa pessoa1,tPessoa pessoa2){
    if(pessoa1.altura<pessoa2.altura){
        return 1;
    }else return 0;
}*/


