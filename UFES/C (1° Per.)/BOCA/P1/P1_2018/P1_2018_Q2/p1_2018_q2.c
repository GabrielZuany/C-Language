#include <stdio.h>

int main(void){

    int V1 = 0, V2 = 0, troco_1 = 0, troco_2 = 0;

    scanf("%i %i", &V1, &V2);

    troco_1 = V1/5 + V1%5;
    troco_2 = V2/5 + V2%5;

    if(troco_1==troco_2){
        printf("Iguais!");
    }else if(troco_1>troco_2){
        printf("QTD troco 1 eh maior!");
    }else printf("QTD troco 2 eh maior!");


    return 0;
}