#include <stdio.h>

int EhPalindromo(int num);

int main(){
    int num = 0;

    while(scanf("%i", &num)==1){

        if(EhPalindromo(num)){
            printf("S\n");
        }else printf("N\n");

    }

    return 0;
}
//----------FUNÇÕES-------------------
int EhPalindromo(int num){

    int saveNum = 0, resultado = 0, dig = 0;

    saveNum = num;

    while (num > 0){
        resultado = resultado * 10;

        dig = num % 10;
        num = num / 10;

        resultado = resultado + dig;
    }

    if (resultado==saveNum){
        return 1;
    }else return 0;
}
