#include <stdio.h>

int EhPar(int n){
    if(n%2 == 0){
        return 1;
    }else return 0;
}

int main(){

    int i = 0, qtd = 0, num = 0, par = 0, impar = 0;

    scanf("%i", &qtd);

    for(i=0; i<qtd; ++i){

        scanf("%i", &num);

        if(EhPar(i)){
            if(EhPar(num)){
                par+=num;
            }
        }else{
            if(!EhPar(num)){
                impar+=num;
            }
        }

    }

    printf("SOMA:%i", par+impar);

    return 0;
}