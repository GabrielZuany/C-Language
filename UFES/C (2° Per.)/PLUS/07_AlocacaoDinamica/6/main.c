#include <stdio.h>
#include <stdlib.h>

void LeDadosParaVetor(int *vet, int tam);
void OrdeneCrescente(int *vet, int tam);
void ImprimeDadosDoVetor(int *vet, int tam);

int main(int argc, char * argv[]){
        
    int casos;
    scanf("%d", &casos);

    while(casos){

        int tam;
        scanf("%d", &tam);
        int vet[tam];

        LeDadosParaVetor(vet, tam);
        OrdeneCrescente(vet, tam);
        ImprimeDadosDoVetor(vet, tam);
        casos--;
    }

    return 0;
}

void LeDadosParaVetor(int *vet, int tam){
    int i;
    for(i=0;i<tam;i++){
        scanf("%d", (vet+i));
    }
}

void OrdeneCrescente(int *vet, int tam){
    int aux, i, j;

    for(i=0; i<tam; i++){
        for(j=i+1;j<tam;j++){
            if(*(vet+i) > *(vet+j)){
                aux = *(vet+i);
                *(vet+i) = *(vet+j);
                *(vet+j) = aux;
            }
        }
    }

}

void ImprimeDadosDoVetor(int *vet, int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("%d ", *(vet+i));
    }
    printf("\n");
}