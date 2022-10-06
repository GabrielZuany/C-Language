#ifndef _TALUNO_H_
#define  _TALUNO_H_

typedef struct{
    char nome[20];
    int matricula;
    float nota[3];
}tAluno;

tAluno LeAluno();
float CalculaMedia(tAluno aluno);
int Aprovado(tAluno aluno);
void OrdenaAlunos(tAluno *alunos, int tam);
void ImprimeAluno(tAluno aluno);

#endif