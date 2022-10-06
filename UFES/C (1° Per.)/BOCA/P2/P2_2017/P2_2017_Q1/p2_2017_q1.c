#include <stdio.h>

int main(void){

    int i = 1, pos = 0, controlador = 1, Qtd = 0, num = 0, MenorNum = 9999999;

    scanf("%i", &Qtd);

    for(i=1; i<=Qtd; ++i){

        scanf("%i", &num);

        if(controlador == 1){
            MenorNum = num+1;
            controlador = 0;
        }

        if(num<MenorNum){
            MenorNum = num;
            pos = i;
        }

    }

    if(pos!=0){
        printf("POS:%i", pos);
    }
        

    return 0;
}