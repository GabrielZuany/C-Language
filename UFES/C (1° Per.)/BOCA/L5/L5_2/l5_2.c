#include <stdio.h>

int EhDecrescente(int nota[], int qtd);
int EhCrescente(int nota[], int qtd);
int EhUnitarioOuIgual(int nota[], int qtd);


int main(void){

    int qtd = 0, i = 0;

    scanf("%i", &qtd);
    int nota[qtd];

    for(i=0; i<qtd; ++i){
        scanf("%i", &nota[i]);
    }

    if(EhCrescente(nota, qtd)){
        printf("CRESCENTE");
    }else if(EhUnitarioOuIgual(nota, qtd)){
        printf("CRESCENTE&DECRESCENTE");
    }else if(EhDecrescente(nota, qtd)){
        printf("DECRESCENTE");
    }else{
        printf("DESORDENADO");
    }

    return 0;
}

//----------FUNÇÕES---------------
int EhCrescente(int nota[], int qtd){
    int i = 0;

    for(i=0; i<qtd; ++i){

        if(nota[i]<=nota[i+1] && nota[qtd-1]>=nota[qtd-2]){

            if(nota[i+1]>qtd){
                break;
            }
            continue;

        }else return 0;
    }

    if(!EhUnitarioOuIgual(nota, qtd)){
       return 1; 
    }else return 0;
    
}

int EhDecrescente(int nota[], int qtd){
    int i = 0;

    for(i=0; i<qtd; ++i){

        if(nota[i]>=nota[i+1 && nota[qtd-1]<=nota[qtd-2]]){

            if(nota[i+1]>qtd){
                break;
            }
            continue;
        }else return 0;

    }
    
    if(!EhUnitarioOuIgual(nota, qtd)){
       return 1; 
    }else return 0;
    
}

int EhUnitarioOuIgual(int nota[], int qtd){
    int i = 0;

    if(qtd==1){
        return 1;
    }

    for(i=0; i<qtd; ++i){

        if(nota[i]==nota[i+1]){

            if(nota[i+1]>qtd){
                break;
            }
            continue;

        }else return 0;
    }

    return 1;
}