#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usuario.h"

struct usuario{
    char* nome;
    int cpf;
};

Usuario* CriaUsuario(char* nome, int cpf){
    Usuario* usuario = (Usuario*)malloc(sizeof(Usuario));

    usuario->nome = strdup(nome);
    usuario->cpf = cpf;

    return usuario;
}

char* RecuperaNomeUsuario(Usuario* usuario){
    return usuario->nome;
}

int RecuperaCpfUsuario(Usuario* usuario){
    return usuario->cpf;
}

void DestroiUsuario(Usuario* usuario){
    free(usuario->nome);
    free(usuario);
}