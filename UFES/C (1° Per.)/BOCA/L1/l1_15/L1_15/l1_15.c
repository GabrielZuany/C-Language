#include <stdio.h>

int main(void){

    int num = 0, opcao = 0, temp = 0;
    scanf("%i %i", &num, &opcao);

    switch (opcao)
    {
    case 1:
        temp = num%2;
        if(temp==0){
            printf("PAR");
        }else printf ("IMPAR");
        break;

    case 2:
        num = num/10;
        temp = num%2;
        if(temp==0){
            printf("PAR");
        }else printf("IMPAR");
        break;

    case 3:
        num = num/100;
        temp = num%2;
        if(temp==0){
            printf("PAR");
        }else printf("IMPAR");
        break;

    default:("");
        break;
    }

    return 0;
}