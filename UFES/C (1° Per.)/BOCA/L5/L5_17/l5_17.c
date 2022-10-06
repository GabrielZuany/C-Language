#include <stdio.h>

typedef struct{
    char palavra[500];
}tPalavra;

int main(){

    int i = 0, cont = 0;
    tPalavra texto[500];

    while(scanf("%[a-zA-Z]", texto[i].palavra)==1){/*le tudo enquanto for letra e armazena*/
        scanf("%*[^a-zA-Z]");/*le tudo que nao for letra e descarta*/
        ++i;
    }

    for(cont=i; cont>=0;--cont){
        printf("%s ", texto[cont].palavra);
    }
    return 0;
}