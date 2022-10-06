#include <stdio.h>
#include <stdlib.h>

int main(void){

    int num = 1, n =  0, maiorNum = 0;
    float soma = 0;
    int leitura = 1;

    while(num>0){
        scanf("%i", &num);
        /*ESTRUTURA PARA ATRIBUIR NUM A MAIORNUM---->EXECUTADO 1x*/
        if(leitura==1){
            maiorNum=num;
            leitura=0;
        }
        if(num>maiorNum){
            maiorNum=num;
        }
        soma+=num;
        ++n;//numero de vezes que o loop foi executado
        if(num!=0)printf("%i %.6f\n",maiorNum, soma/(n));
        
    }

    return 0;
}