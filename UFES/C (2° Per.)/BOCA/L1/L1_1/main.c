#include <stdio.h>
#include "tProduct.h"

int main(){
    int prod_quantity, i, higher, lower;
    int higer_id, lower_id;
    scanf("%d", &prod_quantity);
    tProduct products[prod_quantity];

    for (i=0; i<prod_quantity; i++){
        products[i] = ScanProductData();
    }
    for (i=0; i<prod_quantity; i++){
        if(i==0){
            higer_id = 0;
            lower_id = 0;
        }
        if(IsP1HigherThanP2(products[i], products[i+1])){
            higer_id = i;
        }
        if(IsP1LowerThanP2(products[i], products[i+1])){
            lower_id = i;
        }
        if(ExistsProdInInventory(products[i])){
            printf("FALTA:");
            DisplayProd(products[i]);
        }
    }
    printf("MAIOR:");
    DisplayProd(products[higer_id]);
    printf("MENOR:");
    DisplayProd(products[lower_id]);
    return 0;
}
