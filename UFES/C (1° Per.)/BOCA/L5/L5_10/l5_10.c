#include<stdio.h>

void TrocaPosicao(int vet[], int i, int j){
    int aux = 0;
    aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;

}

void PreencheVet(int vet[], int tam){
    int i = 0;
    for(i=0; i<tam; ++i){
        scanf("%i", &vet[i]);
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd){
    int i = 0;

    printf("{");
    for(i=0; i<qtd; ++i){

        if(i<qtd-1){
            printf("%i, ", vet[i]);
            continue;
        }else printf("%i", vet[i]);
    
    }
    printf("}");
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


int main(void){

    int tam = 0;
    scanf("%i", &tam);

    int vet[tam];

    PreencheVet(vet, tam);
    OrdenaCrescente(vet, tam);
    ImprimeDadosDoVetor(vet, tam);

    return 0;
}