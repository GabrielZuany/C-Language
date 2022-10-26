#include <stdio.h>
#include <stdlib.h>
#include "tTerreno.h"

int main(){
    char tipo;
    int qtd, i;
    float base, altura, raio;

    scanf("%d", &qtd);
    scanf("%*c");
    tTerreno *terrenos = NULL;
    terrenos = InicializaTerreno(qtd);
    
    for(i=0; i<qtd; i++){
        scanf("%c", &tipo);

       if(tipo == 'C'){
            scanf("%f", &raio);
            RegistraTerreno(terrenos, 'C', 0, 0, raio);
        }else if(tipo == 'R'){
            scanf("%f %f", &base, &altura);
            RegistraTerreno(terrenos, 'R', base, altura, 0);
        }else{
            scanf("%f %f", &base, &altura);
            RegistraTerreno(terrenos, 'T', base, altura, 0);
        }
        scanf("%*c");
    }

    printf("MEDIA DESMATAMENTO: %.3f\nDESVIO PADRAO: %.3f\n", RetornaMediaDesmatamento(terrenos), RetornaDesvioPadrao(terrenos));
    
    LiberaMemoria(terrenos);

    return 0;
}