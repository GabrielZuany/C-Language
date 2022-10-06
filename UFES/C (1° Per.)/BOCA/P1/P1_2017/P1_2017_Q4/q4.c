#include <stdio.h>

int main(void){

    int H1 = 0, M1 = 0, S1 = 0, H2 = 0, M2 = 0, S2 = 0;
    int soma = 0;

    scanf("%i %i %i %i %i %i", &H1, &M1, &S1, &H2, &M2, &S2);

    if(H1==H2 && M1==M2 && S1==S2){
        printf("IGUAIS");
        return 0;
    }

    if(H1 > H2 || (H1==H2 && M1>M2) || (H1==H2 && M1==M2 && S1>S2)){

        soma = H1+M1+S1; 

    }else soma = H2 + M2 + S2;


    if(soma>=0 && soma<10){
        printf("RESP:0");
        return 0;
    }
    if(soma>9 && soma<100){
        printf("RESP:%i", soma/10);
        return 0;
    }
    if(soma>100 && soma<1000){
        soma = soma/10;
        printf("RESP:%i", soma%10);
        return 0;
    }

    return 0;
}