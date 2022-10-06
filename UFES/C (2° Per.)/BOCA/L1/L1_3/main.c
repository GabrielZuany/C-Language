#include <stdio.h>
#include "tData.h"

int main(){
    tData data;
    int qtd, i;

    scanf("%d", &qtd);
    for(i=0;i<qtd;++i){
        data = LeData();
        ImprimeData(data);
        if(EhBissexto(data)){
            printf(":Bisexto\n");
        }else{
            printf(":Normal\n");
        } 
    }
    return 0;
}