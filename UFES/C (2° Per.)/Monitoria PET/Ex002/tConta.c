#include "tConta.h"
#include <stdlib.h>
#include <stdio.h>

struct tConta{
    tUsuario *usuario;
    int agencia;
    int conta;
    float saldo;
};

void ImprimeConta(tConta* conta){
    printf("Conta: %d\nAgência: %d\n\n", conta->conta, conta->agencia);
}

tConta* InicializaConta(){
    tConta* conta = (tConta*)malloc(sizeof(tConta));
    conta->conta  = 12345;
    conta->agencia = 1234;
    conta->saldo = 0.0;
    return conta;
}

void CriaConta(tUsuario *usuario, tConta *conta){
    conta->usuario = usuario;
}

void Saque(tConta* conta, float valor){
    if(conta->saldo - valor >= 0){
        conta->saldo -= valor;
        printf("Saque realizado no valor de %.2f\n\n", valor);
    }else{
        printf("Saldo insuficiente!\n\n");
    }
}

void Deposito(tConta* conta, float valor){
    conta->saldo+=valor;
    printf("Deposito realizado no valor de %.2f\n\n", valor);
}

void Sair(){
    exit(1);
}

void ImprimeSaldo(tConta *conta){
    printf("Saldo: %.2f\n", conta->saldo);
}

void FazOperacao(tConta* conta){
    int op = 1;
    float valor=0;
    while(op!=0){
        scanf("%d", &op);

        if(op==1){
            scanf("%f", &valor);
            Saque(conta, valor);
        }else if(op==2){
            scanf("%f", &valor);
            Deposito(conta, valor);
        }else{
            ImprimeSaldo(conta);
            return;
        }
    }
}