#include "tAluno.h"
#include <stdio.h>

tAluno RegistraMedia(float media, tAluno aluno){
    aluno.media = media;
    return aluno;
}

float Media(tAluno aluno){
    aluno.media = aluno.nota[0]+aluno.nota[1]+aluno.nota[2];
    return aluno.media/=3;
}

tAluno LeAluno(){
    int i;
    tAluno a;
    scanf("%d", &a.matricula);
    for (i=0;i<3;i++){
        scanf("%f", &a.nota[i]);
    }
    return a;
}

void ImprimirAluno(tAluno aluno){
    printf("mat:%d n1:%.2f n2:%.2f n3:%.2f", aluno.matricula, aluno.nota[0],aluno.nota[1],aluno.nota[2]);
}

tAluno MaiorMedia(tAluno aluno1,tAluno aluno2){
    if(aluno1.media>aluno2.media){
        return aluno1;
    }
    return aluno2;
}