#include <stdio.h>

void EncontraNum(int valor[], int qtd, int NumProc){
    int i = 0, found = 0;

    for(i=0; i<qtd; ++i){

        if(valor[i]==NumProc){
            printf("RESP:%i", i);
            found = 1;
            break;
        }
    }

    if(found==0){
        printf("RESP:%i", qtd);
    }
}

int main(){

    int qtd = 0, i = 0, NumProc = 0;

    scanf("%i", &NumProc);
    scanf("%i", &qtd);
    int valor[qtd];

    for(i=0; i<qtd; ++i){
        scanf("%i", &valor[i]);
    }

    EncontraNum(valor, qtd, NumProc);

    return 0;
}