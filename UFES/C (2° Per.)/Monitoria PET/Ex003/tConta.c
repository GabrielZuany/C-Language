#include "tConta.h"
#include <stdlib.h>
#include <stdio.h>

struct tConta{
    tUsuario *usuario;
    int conta;
    float saldo;
};

tConta** InicializaMemoria(int init){
    tConta** c = calloc(sizeof(tConta), init);
    return c;
}

void ImprimeConta(tConta* conta){
    printf("Conta: %d\n", conta->conta);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    ImprimeUsuario(conta->usuario);
    printf("\n");
}

tConta* InicializaConta(int num_conta, tUsuario* usuario){
    tConta* conta = malloc(sizeof(tConta));
    conta->usuario = usuario;
    conta->conta  = num_conta;
    conta->saldo = 0.0;
    return conta;
}

int Saque(tConta* conta, float valor){
    if(conta->saldo - valor >= 0){
        conta->saldo -= valor;
        //printf("Saque realizado no valor de %.2f\n", valor);
        return 1;
    }else{
        //printf("Saldo insuficiente!\n");
    }
    return 0;
}

void Deposito(tConta* conta, float valor){
    conta->saldo+=valor;
    //printf("Deposito realizado no valor de %.2f\n", valor);
}

void Transferencia(tConta *orig, tConta *dest, float valor){
    if(Saque(orig, valor)){
        Deposito(dest, valor);
        //printf("Transferencia realizada\n");
    }else{
        //printf("Não foi possivel realizar a transferencia\n");
    }
}

void ImprimeSaldo(tConta *conta){
    printf("Saldo: %.2f\n", conta->saldo);
}

void ImprimeRelatorio(tConta **conta, int qtd){
    printf("===| Imprimindo Relatorio |===\n");
    for(int i=0; i<qtd; i++){
      ImprimeConta(conta[i]);
    }
}

void DeletaConta(tConta **conta, int num){
    int i;
    for(i=0; i<num; i++){
        free(conta[i]->usuario);
        free(conta[i]);
    }
    free(conta);
}