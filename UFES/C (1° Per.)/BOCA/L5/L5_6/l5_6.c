#include <stdio.h>

void PreencheVet(int vet[], int tam){
    int i = 0;
    for(i=0; i<tam; ++i){
        scanf("%i", &vet[i]);
    }
}

int EstaContidoAemB(int vetA[], int vetB[], int tam1, int tam2){
    int i = 0, j = 0, cont_a = 0;

    for(i=0; i<tam1; ++i){

        for(j=0; j<tam2; ++j){
            if(vetA[i]==vetB[j]){
                cont_a++;
                break;
            }
        }
    }

    if(cont_a==tam1){
        return 1;//todos contidos
    }else if(cont_a>0 && cont_a<tam1){
        return 0;//alguns contidos
    }else if(cont_a==0){
        return -1;//nenhum contido
    }
}

int main(void){

    int tam1 = 0, tam2 = 0, resposta = -2;

    scanf("%i", &tam1);
    int vet1[tam1];
    PreencheVet(vet1, tam1);

    scanf("%i", &tam2);
    int vet2[tam2];
    PreencheVet(vet2, tam2);

    if(tam1==0 || tam2==0){
        printf("NENHUM");
        return 0;
    }
    
    resposta = EstaContidoAemB(vet1, vet2, tam1, tam2);

    if(resposta==1){
        printf("TODOS");
    }else if(resposta==0){
        printf("PARCIAL");
    }else if(resposta==-1){
        printf("NENHUM");
    }

    return 0;
}