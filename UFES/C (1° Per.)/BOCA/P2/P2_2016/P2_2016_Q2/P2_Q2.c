#include <stdio.h>

int MaiorPrimo = 0;//Variavel Global
int Soma = 0;//Variavel Global


void SeparaDigito(int num){

    int digito = 0, i = 1;

        for(i=1;i<50;++i){

            digito = num%10;
            num = num/10;
            EhPrimo(digito); 

        }

}

int EhPrimo(int DigitoNum){
    
    int i = 1, divisores = 0, DigitoPrimo = 0;

    for(i=1;i<=DigitoNum;++i){

        if(DigitoNum%i==0){
            divisores++;
        }

    }
    if(divisores==2){

        DigitoPrimo = DigitoNum;
        return MaiorDigitoPrimo(DigitoPrimo);

    }else return 0;
}

int MaiorDigitoPrimo(int DigitoPrimo){

    if(DigitoPrimo>MaiorPrimo){
        MaiorPrimo = DigitoPrimo;
    }
    return Soma;

}

int main(void){

    int num = 0;

    while(scanf("%i", &num)){

        SeparaDigito(num);

        Soma+=MaiorPrimo;
        MaiorPrimo = 0;
    }

printf("SOMA:%i", Soma);

    return 0;
}