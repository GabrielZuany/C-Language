#include <stdio.h>
#include <stdlib.h>
#include "tUsuario.h"
#include "tConta.h"

int main(){
    char nome[10];
    int cpf = 0, num = 0, num_conta;
    int op = 4, Conta_Destino, Conta_Origem;
    float valor;
    tUsuario *usuario;
    tConta **conta = InicializaMemoria(1);

    do{
        scanf("%d", &op);
        
        switch (op){

        case 1:
            /* saque */
            scanf("%d %f", &Conta_Destino, &valor);
            Saque(conta[Conta_Destino-1], valor);
            break;
        case 2:
            /* deposito */
            scanf("%d %f", &Conta_Destino, &valor);
            Deposito(conta[Conta_Destino-1], valor);
            break;

        case 3:
            /* transferencia */
            scanf("%d %d %f", &Conta_Destino, &Conta_Origem, &valor);
            Transferencia(conta[Conta_Destino-1], conta[Conta_Origem-1], valor);
            break;
        case 4:
            /* cadastro */
            conta = (tConta**)realloc(conta, (num+1)*sizeof(tConta**));
            scanf("%s %d %d", nome, &cpf, &num_conta);
            usuario = RegistraUsuario(nome, cpf);
            conta[num] = InicializaConta(num_conta, usuario);
            num++;
            break;
        case 5:
            ImprimeRelatorio(conta, num);
            break;

        }

    }while(op!=0);

    DeletaConta(conta, num);

    return 0;
}
