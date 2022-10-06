#include <stdio.h>
//VERIFICAR SE UM NUM É PRIMO
int primo(int n){
    int i, divisores = 0;

    for(i=1;i<=n;++i){
        if(n%i==0)
        /*n==7-->n%1, n%2...n%7*/
        {
            divisores++;
        }
    }
    if(divisores==2){
        return 1;
    }else return 0;
}

int main(void){

    int valorDig = 0, NumPrimo = 0, n=0;

    scanf("%i", &valorDig);
    
    for(n=0;n<=valorDig;++n){
        NumPrimo = primo(n);
        if(NumPrimo==1){
            printf("%i ", n);
        }
    }

    return 0;
}