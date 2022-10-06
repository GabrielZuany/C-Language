#include<stdio.h>

int main(void){
    float nota_1 = 0.0, nota_2 = 0.0;
    float resultado = 0.0;

    scanf("%f %f", &nota_1, &nota_2);
    resultado = (nota_1+nota_2)/2;
    
    if(resultado>=7){
        printf("%.1f - Aprovado", resultado);
    }else if(resultado<5){
        printf("%.1f - Reprovado", resultado);
    }else printf("%.1f - De Recuperacao", resultado);

    return 0;
}