#include<stdio.h>

int main(void){
    
    unsigned char c = ' ';

    scanf("%c", &c);
    //printf("%c(%i)", c-32, c-32);
    if(c>=97 && c<=122){
        printf("%c(%i)", c-32, c-32);
    }else if(c>=65 && c<=90){
        printf("A letra deve ser minuscula!");
    }else printf("Nao e letra!");

    return 0;
}