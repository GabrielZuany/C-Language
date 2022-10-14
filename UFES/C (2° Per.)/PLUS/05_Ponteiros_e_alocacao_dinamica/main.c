#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int PosicaoDoMaior(int *vet, int max);
void *meurealloc(int *vet, unsigned int size);

int main(){
    int i = 0, pos = 0, tamanhoTotal = 0, inicial = 5;
    int *vet  = malloc(sizeof(int)*inicial);

    while(scanf("%d", &vet[i])== 1){
        i++;
        if(i%5==0){// a cada 5 valores inseridos amplia em +5 (40 bytes) o numero de posicoes totais do vetor.
            tamanhoTotal+=5;
            vet = (int *)meurealloc(vet, tamanhoTotal*sizeof(int));
        }    
    }

    printf("PosMaior: %d\n", PosicaoDoMaior(vet, tamanhoTotal));
    free(vet);
    
    return 0;
}

void *meurealloc(int *vet, unsigned int size){
    int *VetorAmpliado = malloc(sizeof(int)*size);
    VetorAmpliado = memmove(VetorAmpliado, vet, size);//move para o VetorAmpliado o conteudo do vet que tem size bytes.
    free(vet); 
    return VetorAmpliado;
}

int PosicaoDoMaior(int *vet, int max){
    int maior, pos, count = 0, i;

    for(i=0; i<max; i++){
        if(i==0){ // setar o valor da posicao 0 como o maior;
            maior = vet[0];
            pos = 0;
            continue;
        }
        if(*(vet+i) > maior){ //busca o maior.
            maior = *(vet+i);
            pos =  i;
        }
    }

    for(i=0; i<max; i++){
        if(*(vet+i) == maior){ // retornar a posicao 0 caso haja 2 valores maximos iguais.
            count++;
        }
        if(count == 2){
            return 0;
        }
     }
    return pos;
}
