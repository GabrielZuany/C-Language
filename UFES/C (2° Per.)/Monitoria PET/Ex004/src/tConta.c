#include "tConta.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tConta{
    tUsuario *usuario;
    int conta;
    float saldo;
    float* transacoes;
    int num_transacoes;
};

tConta** InicializaMemoria(int init){
    tConta** c = (tConta**)calloc(sizeof(tConta*), init);
    return c;
}

void ImprimeConta(tConta* conta, FILE* out){
    fprintf(out, "Conta: %d\n", conta->conta);
    fprintf(out, "Saldo: R$ %.2f\n", conta->saldo);
    FILE_ImprimeUsuario(conta->usuario, out);
    fprintf(out, "\n");
}

void ImprimeExtrato(tConta* conta, int ultimas_transacoes){
    //Cria cada arquivo de acordo com um indice sequencial.
    static int indice = 1;
    char indice_arquivo[2];
    indice_arquivo[0] = indice+'0';
    indice_arquivo[1] = '\0';
    indice++;

    //Cria um comando para ser automaticamente executado pelo terminal criando os arquivos necessarios.
    char command[50];
    InicializaStr(command);
    strcat(command, "touch ../output/");
    strcat(command, indice_arquivo);
    strcat(command, ".txt");
    system(command);

    // Cria caminho do arquivo que será escrito.
    char filepath[50];
    InicializaStr(filepath);
    strcat(filepath, "../output/");
    strcat(filepath, indice_arquivo);
    strcat(filepath, ".txt");    
    FILE* out = fopen(filepath, "w");


    // Imprime cada dado no respectivo arquivo.

    fprintf(out, "===| Imprimindo Extrato |===\n");
    fprintf(out, "Conta: %d\nSaldo: R$ %.2f\n", conta->conta, conta->saldo);

    FILE_ImprimeUsuario(conta->usuario, out);

    fprintf(out, "\nUltimas %d transações\n",ultimas_transacoes);

    int cont = 1;
    while(cont <= ultimas_transacoes){
        fprintf(out, "%.2f\n", conta->transacoes[conta->num_transacoes - cont]);
        cont++;
    }
    fclose(out);
}

void InicializaStr(char* str){
    int i;
    for(i=0; i<50; i++){
        str[i] = '\0';
    }
}

tConta* InicializaConta(int num_conta, char*nome, int cpf){
    tConta* conta = (tConta*)calloc(sizeof(tConta), 1);
    conta->transacoes = (float*)calloc(sizeof(float), 30);
    conta->usuario = RegistraUsuario(nome, cpf);
    conta->conta  = num_conta;
    conta->num_transacoes = 0;
    conta->saldo = 0.0;
    return conta;
}

int Saque(tConta* conta, float valor){
    conta->transacoes[conta->num_transacoes] = -valor;
    conta->num_transacoes++;
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
    conta->transacoes[conta->num_transacoes] = valor;
    conta->num_transacoes++;
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
    system("touch ../output/relatorio.txt");
    FILE* out = fopen("../output/relatorio.txt", "w");

    fprintf(out, "===| Imprimindo Relatorio |===\n");
    for(int i=0; i<qtd; i++){
      ImprimeConta(conta[i], out);
    }
    fclose(out);
}

void DeletaConta(tConta **conta, int num){
    int i;
    for(i=0; i<num; i++){
        free(conta[i]->usuario);
        free(conta[i]->transacoes);
        free(conta[i]);
    }
    free(conta);
}
