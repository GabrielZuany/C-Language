/*
Dado um texto qualquer (max 500 palavras, e somente letras):
A) ordene as palavras de acordo com o seu tamanho. Caso tenham tamanho igual, ordene pela ordem da que apareceu primeiro.
B) imprima ele com a ordem das palavras invertidas;
*/
//=-=-=-=-=-=-=-=-=REDIRECIONE VIA TERMINAL O ARQUIVO 'in.txt'-=-=-=-=-=-=-=-=-=

#include <stdio.h>
#include <string.h>

int main(){

    int i = 0, cont = 0, j = 0;
    char texto[500][15];//texto com no max 500 palavras e cada palavra com max de 10 char.

    while(scanf("%[a-zA-Z]", texto[i]) == 1){/*le tudo enquanto for letra e armazena*/
        scanf("%*[^a-zA-Z]");/*le tudo que nao for letra e descarta*/
        ++i;
    }

    printf("TEXTO INVERTIDO:\n");
    for(cont=i; cont>=0;--cont){
        printf("%s ", texto[cont]);
    }

    printf("\nTEXTO ORDENADO POR TAMANHO:\n");
    j=0;
    while(j<15){
        for(cont = 0; cont<i; ++cont){
            if(strlen(texto[cont]) == j){
                printf("%s ", texto[cont]);
            } 
        }   
        j++;
    }
    
    return 0;
}