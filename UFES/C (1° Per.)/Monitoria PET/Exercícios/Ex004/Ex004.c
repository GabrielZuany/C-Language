#include <stdio.h>

int main(void){

    int qtd = 0, num = 0, i =0, cont = 0;

    scanf("%i", &qtd);
    
    if(qtd>0 && qtd<=10){

        for(cont=1;cont<=qtd;++cont){

            scanf("%i", &num);
            printf("%i ", num);

            for(i=num-1; i>=1; i--){
                num*=i;
            }
            
            printf("%i\n", num);

        }

    }
    
 
    return 0;
}