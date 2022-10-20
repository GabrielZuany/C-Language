#include "tUsuario.h"
#include <string.h>
#include <stdio.h>

struct tUsuario{
    char nome[10];
    int cpf;
};

tUsuario* RegistraUsuario(char *nome, int cpf){
    tUsuario  *u;
    RegistraNome(u, nome);
    u->cpf = cpf;
    ImprimeUsuario(u);
    return u;
}

void ImprimeUsuario(tUsuario* usuario){
    printf("Usuário: %s\n", usuario->nome);
    //printf("CPF: %d\n", usuario->cpf);
}

void RegistraNome(tUsuario *usuario, char* nome){
    strcpy(usuario->nome, nome);
}
