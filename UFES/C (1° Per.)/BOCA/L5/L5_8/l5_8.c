#include <stdio.h>

void TrocaParEImpar(int vet[], int qtd){
    int i = 0, aux = 0;

    for(i=0;i<qtd-1;++i){

        if(i+1>qtd){
            break;
        }

        if(i%2==0){
            aux = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = aux;
        }

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

    TrocaParEImpar(vet, tam);
    ImprimeDadosDoVetor(vet, tam);

    return 0;
}