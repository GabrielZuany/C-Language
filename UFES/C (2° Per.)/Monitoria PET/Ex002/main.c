#include <stdio.h>
#include <stdlib.h>
#include "tUsuario.h"
#include "tConta.h"

int main(){
    char nome[10];
    int cpf = 0;

    scanf("%s", nome);
    scanf("%d", &cpf);

    tUsuario *usuario = RegistraUsuario(nome, cpf);
    tConta *conta = InicializaConta();

    CriaConta(usuario, conta);
    ImprimeConta(conta);

    FazOperacao(conta);

    return 0;
}