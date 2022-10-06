#ifndef _TPRODUCT_
#define _TPRODUCT_

typedef struct{
    int id;
    float price;
    int inventory;
}tProduct;

tProduct ScanProductData();
int IsP1HigherThanP2(tProduct p1, tProduct p2);
int IsP1LowerThanP2(tProduct p1, tProduct p2);
int ExistsProdInInventory(tProduct p);
void DisplayProd(tProduct p);

#endif