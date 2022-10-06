#include <stdio.h>

int main(void){

    float celsius = 0.0, fahrenheit = 0.0, temp = 0.0;
    char unidade = 'x';
    scanf("%f %c", &temp, &unidade);
    
    if(unidade == 'f'|| unidade == 'F'){
        fahrenheit = (5*(temp-32))/9;
        unidade = 'C';
        printf("%.2f (%c)", fahrenheit, unidade);
    }else if(unidade == 'C'|| unidade == 'c'){
        celsius = (temp*1.8)+32; 
        unidade = 'F';
        printf("%.2f (%c)", celsius, unidade);
    }

    return 0;
}