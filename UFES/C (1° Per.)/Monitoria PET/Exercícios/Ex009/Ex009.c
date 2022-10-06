#include <stdio.h>

void LeMatriz(char Matriz[][10], int NumeroDeAlunos);
void LeGabarito(char gabarito[10]);
void ImprimeQtdAcertos(int i, char Matriz[][10], char gabarito[10]);

int main(){
    int NumeroDeAlunos, i;

    scanf("%d", &NumeroDeAlunos);
    scanf("%*c");

    char Matriz[NumeroDeAlunos][10], gabarito[10];

    LeMatriz(Matriz, NumeroDeAlunos);
    LeGabarito(gabarito);
    for(i=0; i<NumeroDeAlunos; i++){
        ImprimeQtdAcertos(i, Matriz, gabarito);
    }
    return 0;
}

void LeMatriz(char Matriz[][10], int NumeroDeAlunos){
    int i, j;
    for(i=0; i<NumeroDeAlunos; i++){
        for(j=0; j<10; j++){
            scanf("%c", &Matriz[i][j]);
            scanf("%*c");
        }
    }
    
}

void LeGabarito(char gabarito[10]){
    int i;
    for(i=0; i<10; i++){
        scanf("%c", &gabarito[i]);
        scanf("%*c");
    }
}

void ImprimeQtdAcertos(int i, char Matriz[][10], char gabarito[10]){
    int j, acertos=0;
    for(j=0; j<10; j++){
        if(Matriz[i][j] == gabarito[j]){
            acertos++;
        }
    }
    printf("Aluno %d: %d acertos\n",i+1, acertos);
}