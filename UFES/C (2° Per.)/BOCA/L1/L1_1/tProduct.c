#include <stdio.h>
#include "tProduct.h"

tProduct ScanProductData(){
    tProduct p;
    scanf("%d;%f;%d", &p.id, &p.price, &p.inventory);
    scanf("%*c");
    return p;
}

int IsP1HigherThanP2(tProduct p1, tProduct p2){//true or false
    static float H = -1;
    if(p1.price>=p2.price && p1.price>H){
        H = p1.price;
        return 1;
    }
    return 0;
}
int IsP1LowerThanP2(tProduct p1, tProduct p2){//true or false
    static float L = 121575219;
    if (p1.price<=p2.price && p1.price<L){
        L = p1.price;
        return 1;
    }return 0;
}
int ExistsProdInInventory(tProduct p){
    if (p.inventory==0){
        return 1;
    }return 0;
}

void DisplayProd(tProduct p){
    printf("COD %d, PRE %.2f, QTD %d\n", p.id, p.price, p.inventory);
}