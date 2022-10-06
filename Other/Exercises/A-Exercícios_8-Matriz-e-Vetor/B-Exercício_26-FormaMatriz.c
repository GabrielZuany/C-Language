/*
Imprima uma matriz 10x10 em que seus elementos são de forma:
-> 2i + 7j -2, se i<j
-> 3i^2 -1, se i=j
-> 4i^3 +5j^2 + 1, se i>j
*/  
#include <stdio.h>
#include <math.h>

int main(){

    int matriz[10][10];
    int i, j, n = 0;

    for(i=0; i<10; i++){
        for(j=0;j<10;j++){
            
            if(i<j){
                n = 2*i + 7*j -2;
            }else if(i==j){
                n = 3*pow(i, 2) -1;
            }else{
                n = 4*pow(i, 3) + 5*pow(j, 2) + 1;
            }

            matriz[i][j] = n;
        }
    }

    for(i=0; i<10; i++){
        for(j=0;j<10;++j){
            printf("|%d|", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}