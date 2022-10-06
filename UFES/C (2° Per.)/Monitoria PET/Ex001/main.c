#include <stdio.h>
#include "tAluno.h"

int main(){
    int numero_de_alunos, i;

    scanf("%d", &numero_de_alunos);

    tAluno alunos[numero_de_alunos];
    for(i=0; i<numero_de_alunos; i++){
        alunos[i] = LeAluno();
    }
    printf("Alunos Aprovados:\n");
    OrdenaAlunos(alunos, numero_de_alunos);

    for(i=0; i<numero_de_alunos; i++){
        if(Aprovado(alunos[i])){
            ImprimeAluno(alunos[i]);
        }
    }

    return 0;
}