#include <stdio.h>

void ImprimeResposta(int valor[], int qtd, int inicio, int fim){
    int i = 0, cont = 0;

    for(i=0; i<qtd; i++){
        if(valor[i]>=inicio && valor[i]<=fim){
            cont++;
        }
    }

    printf("%i %i", cont, qtd-cont);
}

int main(void){

    int qtd = 0, i = 0, inicio = 0, fim = 0;

    scanf("%i", &qtd);

    int valor[qtd];

    for(i=0; i<qtd; ++i){
        scanf("%i", &valor[i]);
    }

    scanf("%i %i", &inicio, &fim);

    ImprimeResposta(valor, qtd, inicio, fim);

    return 0;
}