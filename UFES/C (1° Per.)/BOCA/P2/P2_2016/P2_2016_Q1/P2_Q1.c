#include <stdio.h>

int EhPar(int x){
    if (x%2==0){
        return 1;
    }else return 0;
}

int EhImpar(int x){
    if (x%2!=0){
        return 1;
    }else return 0;
}

int main(void){

    int Quantidade = 0, cont = 0, Numero = 0, Par = 0, Impar = 0, controle = 0;

    scanf("%i", &Quantidade);

    for(cont=1; cont<=Quantidade; ++cont){

        scanf("%i", &Numero);
        if(EhPar(Numero) && controle==0){
            controle = 1;
        }
        if(EhImpar(Numero) && controle==0){
            controle = 2;
        }

        if(EhPar(Numero) == 1){
            Par++;
        }
        if(EhImpar(Numero) == 1){
            Impar++;
        }
    }

    if(controle == 1){
        printf("QTD PARES:%i", Par);
    }
    if(controle == 2){
      printf("QTD IMPARES:%i", Impar);  
    }
    
    

    return 0;
}