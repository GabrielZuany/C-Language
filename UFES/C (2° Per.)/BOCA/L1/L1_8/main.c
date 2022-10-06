#include <stdio.h>
#include "tAnimal.h"

int main(){
    int qtdTipos = 0, i;
    float Valor = 0, qtdRacao = 0;
    tAnimal animal;

    scanf("%d", &qtdTipos);
    for(i=0; i<qtdTipos; i++){
        animal = LeAnimal();
        qtdRacao = QtdRacao(animal);
        Valor += CalcularPreco(qtdRacao, animal);
    }
    printf("Valor total: %.2f reais", Valor);
    
    return 0;
}