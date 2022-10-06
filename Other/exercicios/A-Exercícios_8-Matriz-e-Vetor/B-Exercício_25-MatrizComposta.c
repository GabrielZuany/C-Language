/*
Dadas duas matrizes A(4x4) e B(4x4), construa uma matriz C(3x3) que seja formada da seguinte maneira:
Primeiro elemento da matriz C = primeiro elemento de posicao impar da matriz A
Segundo elemento da matriz C = primeiro elemento de posicao par da matriz B
Terceiro elemento da matriz C = segundo elemento de posicao impar da matriz A
Quarto elemento da matriz C = segundo elemento de posicao par da matriz B

A[4][4] = { 1, 2,  3,  4, 
            5, 6,  7,  8,
            9, 10, 11, 12, 
           13, 14, 15, 16};

B[4][4] = {17 ,18, 19, 20, 
           21, 22, 23, 24, 
           25, 26, 27, 28, 
           29, 30, 31, 32};

C[3][3] =   1 | 18 | 3 | 
            20|  5 | 22| 
            7 | 24 | 9 |

...
*/  
#include <stdio.h>

int main(){

    int A[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int B[4][4] = {17 ,18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};
    int C[3][3];

    int i, j, n = 0, k = 0, printei_K = 0, printei_N = 0;

    int Vet_A[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int Vet_B[16] = {17 ,18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};

    for(i=0; i<3; ++i){
        for(j = 0; j<3; j++){

            if(j%2==0 && printei_K == 0 || (printei_N == 1)){
                C[i][j] = Vet_A[2*k];
                k++;
                printei_K = 1;
                printei_N = 0;
            }else{
                C[i][j] = Vet_B[(2*n)+1];
                n++;
                printei_K = 0;
                printei_N = 1;
            }
        }
        if(i%2!=0){
           printei_K = 0; 
        }
    }

    for(i=0;i<3; ++i){
        for(j=0;j<3;j++){
            printf("%d | ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}