#ifndef _TALUNO_
#define _TALUNO_

typedef struct{
    int matricula;
    char nome[10];
    float nota[3];
    float media;
}tAluno;

tAluno RegistraMedia(float media, tAluno aluno);
float Media(tAluno aluno);
tAluno LeAluno();
void ImprimirAluno(tAluno aluno);
tAluno MaiorMedia(tAluno aluno1,tAluno aluno2);

#endif