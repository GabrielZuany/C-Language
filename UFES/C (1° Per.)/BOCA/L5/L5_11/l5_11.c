#include<stdio.h>

void PreencheVet(int vet[], int tam){
    int i = 0;
    for(i=0; i<tam; ++i){
        scanf("%i", &vet[i]);
    }
}

void TrocaPosicao(int vet[], int i, int j){
    int aux = 0;
    aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;

}

void OrdenaCrescente(int vet[], int qtd){
    int i = 0, aux = 0, j = 0;

    for(i=0; i<qtd-1; ++i){

        if(vet[i]>vet[i+1]){

            TrocaPosicao(vet, i, i+1);            
            i = -1;//repete desde o inicio, porem com o vetor atualizado
        }

    }
}

void AtribuiVet1eVet2aVet3(int *vet1, int *vet2, int *vet3, int tam1, int tam2, int tam3){
    int i = 0;
    int cont = 0;

    for(i=0; i<tam1; ++i){
        vet3[i] = vet1[i];
    }
    
    for(i=tam1; i<tam3; ++i){
        vet3[i] = vet2[cont];
        cont++;
    }
    
}

void ImprimeDadosDoVetor(int vet3[],int qtd, int vet_1[], int tam1){
    int i = 0, j = 0;

    for(i=0; i<qtd; ++i){

        if(i+1>qtd){
            break;
        }

        if(vet3[i]==vet_1[j]){
            j++;
            printf("A");
            continue;
        }else printf("B");
 
    }
}

int main(void){

    int tam1 = 0, tam2 = 0;

    scanf("%i", &tam1);
    int vet1[tam1];
    PreencheVet(vet1, tam1);


    scanf("%i", &tam2);
    int vet2[tam2];
    PreencheVet(vet2, tam2);
    

    int tam3 = tam1+tam2;
    int vet3[tam3]; 
    AtribuiVet1eVet2aVet3(vet1, vet2, vet3, tam1, tam2, tam3);

    OrdenaCrescente(vet1, tam1);
    OrdenaCrescente(vet2, tam2);
    OrdenaCrescente(vet3, tam3);

    ImprimeDadosDoVetor(vet3, tam3, vet1, tam1);

    return 0;
}