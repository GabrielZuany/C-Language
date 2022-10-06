#include <stdio.h>

void LeVetor(int vet[]);
int CompactaVetor(int vet[]);
void ImprimeVetor(int vet[], int qtd);

int main(){
    int vet[15], qtd = 0;
    LeVetor(vet);
    qtd = CompactaVetor(vet);
    ImprimeVetor(vet, qtd);
    return 0;
}

void LeVetor(int vet[]){
    int i;
    for(i=0;i<15;i++){
        scanf("%d",&vet[i]);
    }
}

int CompactaVetor(int vet[]){//compacta o vetor e retorna o tamanho do vetor compactado.
    int i = 0, qtd = 0, pos = 0;
    for(i=0; i<15; i++){
        if(vet[i] != 0){
            qtd++;
        }
    }
    int vetCompacto[qtd];
    for(i=0; i<15; i++){
        if(vet[i] != 0){
            vetCompacto[pos] = vet[i];
            pos++;
        }
    }
    for(i=0; i<pos; i++){
        vet[i] = vetCompacto[i];
    }
    return qtd;
}

void ImprimeVetor(int vet[], int qtd){
    int i;
    printf("V = [");
    for(i=0; i<qtd; i++){
        if(i>0){
            printf(", ");
        }
        printf("%d",vet[i]);
    }
    printf("]\n");
}