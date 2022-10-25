#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "conta.h"

struct conta{
    Usuario* usuario;
    int agencia;
    int nConta;
    float saldo;
};

Conta* CriaConta(Usuario* usuario, int agencia, int nConta){
    Conta* conta = (Conta*)malloc(sizeof(Conta));

    conta->usuario = usuario;
    conta->agencia = agencia;
    conta->nConta = nConta;
    conta->saldo = 0;

    return conta;
}

Usuario* RecuperaUsuario(Conta* conta){
    return conta->usuario;
}

int RecuperaAgencia(Conta* conta){
    return conta->agencia;
}

int RecuperaNConta(Conta* conta){
    return conta->nConta;
}

float RecuperaSaldo(Conta* conta){
    return conta->saldo;
}

float Saque(Conta* conta,float valor){
    if(conta->saldo >= valor){
        conta->saldo -= valor;
        printf("\nSaque realizado no valor de %.2f\n", valor);
        return valor;
        
    }
    printf("\nSaldo insuficiente!\n");
    return 0;
}

void Deposito(Conta* conta,float valor){
    conta->saldo += valor;
    printf("\nDeposito realizado no valor de %.2f\n", valor);
}

void DestroiConta(Conta* conta){
    free(conta);
}

void InterfaceConta(Conta* c){
    printf("Usuário: %s\n",RecuperaNomeUsuario(RecuperaUsuario(c)));
    printf("Conta: %d\n",RecuperaNConta(c));
    printf("Agência: %d\n",RecuperaAgencia(c));
}
