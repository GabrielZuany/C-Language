#include "tAluno.h"
#include <stdio.h>

tAluno LeAluno(){
    tAluno aluno;
    int i;
    scanf("%s %d", aluno.nome, &aluno.matricula);
    for(i=0; i<3; i++){
        scanf("%f", &aluno.nota[i]);
    }
    return aluno;
}

float CalculaMedia(tAluno aluno){
    float soma = 0;
    int i = 0;
    for(i=0; i<3; i++){
        soma+=aluno.nota[i];
    }
    return soma/3;
}

int Aprovado(tAluno aluno){
    float Media = CalculaMedia(aluno);
    if(Media>=7){
        return 1;
    }return 0;
}

void OrdenaAlunos(tAluno *alunos, int tam){
    int i, j;
    tAluno aux;
    for(i=0; i<tam-1; i++){
        for(j=i+1; j<tam; ++j){
           if(alunos[i].matricula > alunos[j].matricula){
                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }
}

void ImprimeAluno(tAluno aluno){
    printf("%s\n", aluno.nome);
}