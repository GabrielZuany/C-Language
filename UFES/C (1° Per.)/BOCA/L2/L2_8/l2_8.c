#include<stdio.h>

int main(void){

    int divisor=0, min=0, max = 0, acumulador = 0;
    scanf("%i %i", &min, &max);
    printf("RESP:");
    min++;/*EXCLUI O N, POIS O PROG CONSIDERA INTERVALOS ABERTOS*/
    for(;min<max; min++){

        acumulador = 0;

        for(divisor=1;divisor<=min;++divisor){
            if(min%divisor==0){
                acumulador++;
            }
        }
        if(acumulador==2){
            printf("%i ", min);
        }
    
    }
    return 0;
}