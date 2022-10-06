/*
Leia duas strings. Se as strings forem iguais escreva
“strings iguais”. Caso contrário, concatene as duas
strings e imprima a string resultante.
*/
#include <stdio.h>
#include <string.h>

int main(){

    char str1[20], str2[20];
    scanf("%s", str1);
    scanf("%s", str2);

    if(strcmp(str1, str2) == 0){
        printf("strings iguais\n");
    }else{
        strcat(str1, str2);
        printf("%s\n", str1);
    }

    return 0;
}