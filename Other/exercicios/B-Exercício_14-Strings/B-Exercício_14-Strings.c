/*
Leia um texto pela entrada padrão com no máximo 99
caracteres. Em seguida imprima o número de caracteres
digitados.
*/
#include <stdio.h>

int main(){

    char texto[99];
    int i = 0;
    for (i=0; i<99; ++i){
        scanf("%c", &texto[i]);
        if(texto[i] == '\n'){
            printf("O texto digitado tem %d caracteres.\n", i);
            break;
        }
        if(i==98){
            printf("O limite ja foi atingido.\n");
            break;
        }
    }
    return 0;
}