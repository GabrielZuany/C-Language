#include <stdio.h>

int main(void){

    int divisor=0, min=0, max = 0, acumulador = 0, i = 1, valor = 0;
    scanf("%i %i", &min, &max);
    min++;/*EXCLUI O N, POIS O PROG CONSIDERA INTERVALOS ABERTOS*/

    for(;min<max; min++){
        acumulador = 0;
        valor = 0;

        for(divisor=1;divisor<=min;++divisor){
            if(min%divisor==0){
                acumulador++;
            }
        }
        if(acumulador==2){
                printf("%i\n", min);
                i=min+1;
                    while(i<max){
                        if(i%min==0){
                            printf("%i ", i);
                            valor++;
                        }
                    ++i;
                }
                if(valor==0){
                    printf("*");
                }
                printf("\n");   
        }
    }
    return 0;
}