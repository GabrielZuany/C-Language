/*Escrever um programa em "C" que solicita as notas das duas provas feitas por
cada um dos alunos de uma turma (as notas tem de estar no intervalo [0 10]) e
imprime para cada um a média das notas.*/
#include<stdio.h>

#define QTD_PROVAS 2

typedef struct{
    float nota[QTD_PROVAS];
    float media;
    int id;
}tAluno;

tAluno LeAluno(tAluno aluno, int id);
void ImprimeAluno(tAluno aluno);

int main(){
    int QtdAlunos = 0;
    printf("DIGITE O NUMERO DE ALUNOS: ");

    scanf("%d", &QtdAlunos);
    tAluno aluno[QtdAlunos];
    int cont = 0, i = 0;

    for(cont = 0; cont<QtdAlunos; ++cont){
        printf("DIGITE AS NOTAS DO ALUNO %d:\n", cont+1);
        aluno[cont] = LeAluno(aluno[cont], cont);
    }

    for(i=0; i<QtdAlunos; ++i){
        ImprimeAluno(aluno[i]);
    }

    return 0;
}

tAluno LeAluno(tAluno aluno, int id){
    int i;
    aluno.media = 0;
    aluno.id = id;

    for(i=0;i<QTD_PROVAS;++i){
        scanf("%f", &aluno.nota[i]);

        if(aluno.nota[i]>10 || aluno.nota[i]<0){
            i--;
            printf("NOTA INVALIDA, INSIRA NOVAMENTE: ");
            continue;
        }

        aluno.media+=aluno.nota[i];
    }
    return aluno;
}

void ImprimeAluno(tAluno aluno){
    printf("ID ALUNO: %d -> N1: %.2f // N2: %.2f // MEDIA: %.2f\n", aluno.id+1, aluno.nota[0], aluno.nota[1], aluno.media/QTD_PROVAS);
}