#include <stdio.h>

int gRazao = 0;

void PreencheVet(int vet[], int tam){
    int i = 0;
    for(i=0; i<tam; ++i){
        scanf("%i", &vet[i]);
    }
}

int EhPA(int vet[], int tam){
    int i = 0;

    gRazao = vet[0]-vet[1];

    for(i=0; i<tam-1; ++i){

        if(i+1>tam){
            break;
        }

        if(vet[i]-vet[i+1]!=gRazao){
            return 0;
        }

    }

    return 1;
}

int main(void){

    int tam = 0;
    scanf("%i", &tam);

    int vet[tam];
    PreencheVet(vet, tam);

    if(tam>1 && EhPA(vet, tam)){
        printf("RESP:%i", gRazao*-1);
    }else printf("NAO");

    return 0;
}