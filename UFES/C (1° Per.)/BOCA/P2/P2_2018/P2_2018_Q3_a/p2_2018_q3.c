#include <stdio.h>

double LeNotasECalculaMediaAluno (){

    char C2 = '2';
    int nota = 0, soma = 0, MenorNota = 101, cont = 0;
    float media = 0;

        while(C2!=']'){

            scanf("%i%c", &nota, &C2);

            if(nota<=MenorNota){
                MenorNota = nota;
            }

            soma+=nota;
            cont++;
        }

    soma = soma - MenorNota;
    cont--;

    scanf("%*[^\n]");
    scanf("%*c");

    media = (float)soma/((float)cont);

    if(cont==0){
        media = nota;
    }

    return media;
}


int ContaAlunosAprovadosTurma (){

    char A1 = '.', A2 = '.', Colch = '.';
    int NumeroAlunos = 0, i = 0, aprovados = 0;
    float media = 0;

    scanf("%i", &NumeroAlunos);
    scanf("%*[^\n]");
    scanf("%*c");

    for(i=0; i<NumeroAlunos;++i){

        scanf("%c%c%c", &A1, &A2, &Colch);

        if(Colch=='['){

            media = LeNotasECalculaMediaAluno();

            if(media>=70){
                printf("%c\n", A1);
                aprovados++;
            }

        }

    }
    
    return aprovados;
}

int main(void){

    int NumeroTurmas = 0, i = 0, aprovados = 0, controlador = 0;
    int MaiorQtd = -1, MenorQtd = 999999, MaiorTurma = 0, MenorTurma = 0;

    scanf("%i", &NumeroTurmas);

    for(i=1; i<=NumeroTurmas; ++i){


        printf("TURMA:%i\n", i);

        aprovados = ContaAlunosAprovadosTurma();

        if(aprovados>MaiorQtd){
            MaiorQtd = aprovados;
            MaiorTurma = i;
        }
        if(aprovados<MenorQtd){
            MenorQtd = aprovados;
            MenorTurma = i;
        }

    }

    printf("MAIOR:TURMA %i MENOR:TURMA %i\n", MaiorTurma, MenorTurma);


    return 0;
}