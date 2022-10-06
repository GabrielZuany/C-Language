/*
Declare duas strings com capacidade para 20
caracteres. Leia pela entrada padrão a primeira string.
Em seguida, inverta o conteudo das duas strings.
 Imprima no final o conteúdo das duas strings.
*/

#include <stdio.h>
#include <string.h>

int main(){

    char str1[20], str2[20];

    scanf("%s", str1);
    scanf("%s", str2);

    char strTemp[20];

    strcpy(strTemp, str1);
    strcpy(str1, str2);
    strcpy(str2, strTemp);

    printf("str1 = %s\nstr2 = %s\n", str1, str2);

    return 0;
}