#include "tAluno.h"
#include <stdio.h>

int main(){
    int qtd, i, i_maior_media = 0;
    float media_aluno, media_geral = 0;

    scanf("%d", &qtd);
    tAluno alunos[qtd];

    for(i=0; i<qtd; i++){
        alunos[i] = LeAluno();
        media_aluno = Media(alunos[i]);
        alunos[i] = RegistraMedia(media_aluno, alunos[i]);
        alunos[i_maior_media] = MaiorMedia(alunos[i_maior_media], alunos[i]);
        media_geral+=media_aluno;
    }
    printf("Maior media: ");
    ImprimirAluno(alunos[i_maior_media]);
    printf("\n");
    printf("Media geral: %.2f", media_geral/(float)qtd);
    return 0;
}