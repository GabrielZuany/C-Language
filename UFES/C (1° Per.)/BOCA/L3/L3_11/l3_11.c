#include <stdio.h>

int EhPar (int x);
void PrintaImpares (int N);
void PrintaPares (int N);

int main(void){

    int Tipo = -1, Qtd = 0, NumPar = 2, NumImpar = 1, i = 0;

    scanf("%i %i", &Tipo, &Qtd);

    if(Tipo==0/*PAR*/ && (Qtd>=1 && Qtd<=99999)){

        for(i = 2; i<=Qtd*2; ++i){

            if(EhPar(i)){
                PrintaPares(i);
            }

        }

    }else if(Tipo == 1 /*IMPAR*/ && (Qtd>=1 && Qtd<=99999)){

        for(i = 1; i<=Qtd*2; ++i){
            if(!(EhPar(i))){
                PrintaImpares(i);
            }
        }

    }else return 0;

    return 0;
}

//-----FUNÇÕES---------

int EhPar (int x){
    if( x%2 == 0 ){
        return 1;
    }else return 0;
}

void PrintaPares (int N){
    printf("%i ", N);
}

void PrintaImpares (int N){
    printf("%i ", N);
}