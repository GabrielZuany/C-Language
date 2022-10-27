#include "tUsuario.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct tUsuario{
    char nome[10];
    int cpf;
};

tUsuario* RegistraUsuario(char *nome, int cpf){
    tUsuario* u = (tUsuario*)malloc(sizeof(tUsuario));
    RegistraNome(u, nome);
    u->cpf = cpf;
    return u;
}

void ImprimeUsuario(tUsuario* usuario){
    printf("Nome: %s\n", usuario->nome);
    printf("CPF: %d\n", usuario->cpf);
}

void RegistraNome(tUsuario *usuario, char* nome){
    strcpy(usuario->nome, nome);
}