/*
Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura deve conter o numero de matricula do aluno, seu nome, e as notas de 3 provas. Leia 5 alunos e em seguida exiba os alunos ordenados de acordo com a maior media.
*/
#include <stdio.h>
#include <string.h>

typedef struct{
    int matricula;
    char nome[50];
    float nota[3];
    float media;
}tAluno;

tAluno LeAluno(tAluno aluno);
void ImprimeAluno(tAluno aluno);
void OrdenaAlunos(tAluno *aluno, int qtd);

int main(){
    tAluno aluno[5];
    int i;

    for(i=0; i<5; ++i){
        aluno[i] = LeAluno(aluno[i]);
    }

    OrdenaAlunos(aluno, 5);

    for(i=0; i<5; ++i){
        ImprimeAluno(aluno[i]);
    }


    return 0;
}

tAluno LeAluno(tAluno aluno){
    int i, j = 0;
    aluno.media = 0;
    aluno.nome[0] = '\0';

    scanf("%d", &aluno.matricula);
    scanf("%*c");//consome o \n

    while(scanf("%[^\n]", aluno.nome) == 1);
    scanf("%*c");

    for(j=0; j<3; j++){
        scanf("%f", &aluno.nota[j]);
        aluno.media+=aluno.nota[j];
    }

    aluno.media/=3;

    return aluno;
}

void OrdenaAlunos(tAluno *aluno, int qtd){
    int i, j;
    tAluno aux;

    for(i=0; i<5; ++i){
        for(j=i+1; j<5; ++j){
            if(aluno[i].media < aluno[j].media){
                aux = aluno[i];
                aluno[i] = aluno[j];
                aluno[j] = aux;
            }
        }
    }

}


void ImprimeAluno(tAluno aluno){
    int i;
    printf("\nNOME: %s\nMATRICULA: %d\nMEDIA: %.2f\n", aluno.nome, aluno.matricula, aluno.media);
}
