#include <stdio.h>

int main(void){

    int a = 0, b = 0, contador = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;

    scanf("%i %i %i %i %i %i %i %i", &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);


    if(a*x1 + b == y1){
        contador++;
    }
    if(a*x2 + b == y2){
        contador++;
    }
    if(a*x3 + b == y3){
        contador++;
    }

    if(contador == 1){
        printf("Um");
    }
    if(contador == 2){
        printf("Dois");
    }
    if(contador == 3){
        printf("Todos");
    }
    if(contador == 0){
        printf("Nenhum");
    }

    return 0;
}