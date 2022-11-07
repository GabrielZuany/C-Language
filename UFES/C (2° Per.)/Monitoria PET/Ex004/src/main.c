#include <stdio.h>
#include <stdlib.h>
#include "tUsuario.h"
#include "tConta.h"

int main(int argc, char **argv){
    char nome[10];
    int cpf = 0, num = 0, num_conta = 0, ultimas_transacoes;
    int op = 4, Conta_Destino = 0, Conta_Origem = 0;
    float valor;
    tConta **conta = InicializaMemoria(1);
    FILE* entrada = fopen(argv[1], "r");
    FILE* saida = fopen(argv[2], "w");
    system("mkdir ../output");
    
    do{
        fscanf(entrada, "%d", &op);
        
        switch (op){

        case 1:
            /* saque */
            fscanf(entrada, "%d %f", &Conta_Destino, &valor);
            Saque(conta[Conta_Destino-1], valor);
            break;
        case 2:
            /* deposito */
            fscanf(entrada, "%d %f", &Conta_Destino, &valor);
            Deposito(conta[Conta_Destino-1], valor);
            break;

        case 3:
            /* transferencia */
            fscanf(entrada, "%d %d %f", &Conta_Destino, &Conta_Origem, &valor);
            Transferencia(conta[Conta_Destino-1], conta[Conta_Origem-1], valor);
            break;
        case 4:
            /* cadastro */
            conta = (tConta**)realloc(conta, (num+1)*sizeof(tConta*));
            fscanf(entrada, "%s %d %d", nome, &cpf, &num_conta);
            conta[num] = InicializaConta(num_conta, nome, cpf);
            num++;
            break;
        case 5:
            ImprimeRelatorio(conta, num);
            break;
        case 6:
            /* extrato */
            fscanf(entrada, "%d %d", &num_conta, &ultimas_transacoes);
            ImprimeExtrato(conta[num_conta-1], ultimas_transacoes);
            break;
        }

    }while(op!=0);

    DeletaConta(conta, num);

    fclose(entrada);
    fclose(saida);

    return 0;
}
