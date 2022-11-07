#include "tUsuario.h"

struct tUsuario{
    char nome[10];
    int cpf;
};

tUsuario* RegistraUsuario(char *nome, int cpf){
    tUsuario* u = (tUsuario*)malloc(sizeof(tUsuario));
    strcpy(u->nome, nome);
    u->cpf = cpf;
    return u;
}

void ImprimeUsuario(tUsuario* usuario){
    printf("Nome: %s\n", usuario->nome);
    printf("CPF: %d\n", usuario->cpf);
}

void FILE_ImprimeUsuario(tUsuario* usuario, FILE* arq){
    fprintf(arq, "Nome: %s\n", usuario->nome);
    fprintf(arq, "CPF: %d\n", usuario->cpf);
}
