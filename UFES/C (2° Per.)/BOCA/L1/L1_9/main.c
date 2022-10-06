
#include <stdio.h>
#include "tPessoa.h"
int main(){
    int qtd, i;
    int i_mais_alto = 0, i_mais_baixo = 0;
    float imc = 0;
    scanf("%d", &qtd);
    scanf("%*c");

    tPessoa pessoas[qtd];

    for(i=0;i<qtd;++i){
        pessoas[i] = LePessoa();
    }
    for(i=0;i<qtd;++i){
        if(EhMaisAlta(pessoas[i], pessoas[i+1])){
            i_mais_alto = i;
        }
        if(EhMaisBaixa(pessoas[i], pessoas[i+1])){
            i_mais_baixo = i;
        }
    }
    imc = CalcularIMC(pessoas[i_mais_alto]);
    printf("Alta: ");
    ImprimirPessoa(pessoas[i_mais_alto]);
    printf("I:%.2f\n", imc);

    imc = CalcularIMC(pessoas[i_mais_baixo]);
    printf("Baixa: ");
    ImprimirPessoa(pessoas[i_mais_baixo]);
    printf("I:%.2f", imc);

    return 0;
}