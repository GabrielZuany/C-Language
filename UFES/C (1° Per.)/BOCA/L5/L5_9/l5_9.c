#include <stdio.h>

void ImprimeDadosDoVetor(int vet[], int qtd){
    int i = 0;

    printf("{");
    for(i=qtd-1; i>=0; --i){

        if(i>0){
            printf("%i, ", vet[i]);
            continue;
        }else printf("%i", vet[i]);
    
    }
    printf("}");
}

void PreencheVet(int vet[], int tam){
    int i = 0;
    for(i=0; i<tam; ++i){
        scanf("%i", &vet[i]);
    }
}

int main(void){

    int tam = 0;
    scanf("%i", &tam);

    int vet[tam];

    PreencheVet(vet, tam);
    ImprimeDadosDoVetor(vet, tam);

    return 0;
}