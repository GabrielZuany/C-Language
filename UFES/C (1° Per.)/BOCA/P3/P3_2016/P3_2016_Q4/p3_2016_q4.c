#include <stdio.h>

typedef struct{
    int vetor[10];
}tVetor;

tVetor LeVetor();
void ComparaValores(tVetor vetor, tVetor vetFin);
int QtdListas = 0, TamVet = 0;

int main(void){
    int i = 0, cont = 0, temp = 0;
    scanf("%d", &QtdListas);

    tVetor vetor[QtdListas], vetFin[QtdListas];

    for(i=0;i<QtdListas;++i){
        vetor[i] = LeVetor();
        vetFin[i] = vetor[i];
        ComparaValores(vetor[i], vetFin[i]);
        printf("\n");
    }
    return 0;
}

tVetor LeVetor(){
    int i = 0;
    scanf("%d", &TamVet);
    tVetor vet;

    for(i=0;i<TamVet;++i){
        scanf("%d", &vet.vetor[i]);
    }
    return vet;
}

void ComparaValores(tVetor vet, tVetor vetFin){
    int cont = 0, i = 0, j = 0;
    for(i=0;i<TamVet;++i){
        for(j=0;j<TamVet;++j){
            if(vet.vetor[i]<vetFin.vetor[j]){
                cont++;
            }
        }
        printf("%d ", cont);
        cont = 0;
    }
}