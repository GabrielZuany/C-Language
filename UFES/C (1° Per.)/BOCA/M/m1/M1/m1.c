/*
Faça um programa que leia dois números inteiros e imprima os números em ordem
invertida ao recebimento.
● Entrada: dois números separados por espaço.
● Saída: os números da entrada em ordem invertida e separados apenas por uma vírgula.
● Exemplo de Entrada:
11 23
● Exemplo de Saída:
23,11
*/

#include <stdio.h>

int main(){

    int x = 0, y = 0;

    scanf("%i %i", &x, &y);
    printf("%i,%i", y, x);

    return 0;
}