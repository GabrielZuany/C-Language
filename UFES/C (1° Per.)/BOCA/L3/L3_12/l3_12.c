#include <stdio.h>

int somadosdigitos(int n);
void parImpar(int n);
void valorPrimo(int n);

int main(void){ 

    int num = 0, Soma = 0;

    scanf("%i", &num);

    if(num>0){

        do{

            Soma = somadosdigitos(num);

            printf("%i ", Soma);

            parImpar(Soma);
            valorPrimo(Soma);

            num = Soma;

            printf("\n");

        }while(Soma/10!=0);
        
    }

    return 0;
}

//-----FUNÇÕES------,

int somadosdigitos(int n){

    int i = 0, digito = 0, Soma = 0;

    for(i = 0; i<12; ++i){
        digito = n%10;
        n= n/10;
        Soma += digito;
    }

    return Soma;

}

void parImpar(int n){

    if(n%2==0){
        printf("Par ");
    }else printf("Impar ");

}

void valorPrimo(int n){

    int i, divisores = 0;

    for(i=1;i<=n;++i){

        if(n%i==0){
            divisores++;
        }

    }
    if(divisores==2){

        printf("Primo");

    }else printf("Nao e primo");

}