#include <stdio.h>

int main(void){

    int i = 0, par = 0, impar = 0, qtd = 0;
    float num = 0.0, soma = 0.0, media = 0.0;
    int leitura = 1;
    int maiorNum = 0, menorNum = 0;

    scanf("%i", &qtd);

    for(i=0;i<qtd;++i){
        scanf("%f", &num);
        if(num>0){
            if((int)num%2==0){
                par++;
            }else{
                impar++;
            }
            if(leitura==1){
                maiorNum=num;
                menorNum=num;
                leitura=0;
            }
            if(num>maiorNum){
                maiorNum=num;
            }
            if(num<menorNum){
                menorNum=num;
            }
            soma+=num;
        }
            
    }       
    media=soma/qtd;
    
    printf("%i %i %i %i %.6f", maiorNum, menorNum, par, impar, media);

    return 0;
}