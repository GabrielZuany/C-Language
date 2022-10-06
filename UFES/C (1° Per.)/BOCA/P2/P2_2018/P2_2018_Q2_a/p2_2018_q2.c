#include <stdio.h>

int EhIgual(int a, int b){
    if(a==b){
        return 1;
    }else return 0;
}

int MaiorDigito(int num){
    int digito = 0, MaiorDigito = 0, i = 0;

    for(i=0; i<10; i++){

        digito = num%10;
        num = num/10;

        if(digito>MaiorDigito){
            MaiorDigito = digito;
        }
    }

    return MaiorDigito;

}

int main(void){

    int num1 = 0, num2 = 0, MaiorDigito_n1 = 0, MaiorDigito_n2 = 0, count = 0;

    while(scanf("(%i,%i)", &num1, &num2)==2){

        MaiorDigito_n1 = MaiorDigito(num1);
        MaiorDigito_n2 = MaiorDigito(num2);

        if(EhIgual(MaiorDigito_n1, MaiorDigito_n2)){
            count++;
        }

        MaiorDigito_n1 = 0;
        MaiorDigito_n2 = 0;
    }

    printf("COUNT:%i", count);


    return 0;
}