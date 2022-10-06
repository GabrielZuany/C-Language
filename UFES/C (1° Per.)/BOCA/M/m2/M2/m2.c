/*Faca um programa que receba um número real (com no máximo 2 casas decimais),
imprima a parte inteira e a parte real da seguinte forma: INTEIRO:#, REAL:0.##

Entrada: um número real.
● Saída: a parte inteira e a parte real do dígito da entrada separadas pela formatação do enunciado.
● Exemplo de Entrada:
2.57
● Exemplo de Saída:
INTEIRO:2,REAL:0.57
*/

#include <stdio.h>

int main(){

    float x = 0.00;
    int y = 0;
    scanf("%f", &x);
    y = x;
    printf("INTEIRO:%i,REAL:%.2f", y, x-y);

    return 0;
}