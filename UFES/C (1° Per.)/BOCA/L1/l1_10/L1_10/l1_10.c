#include <stdio.h>

int main(void){

    int num = 0;
    scanf("%i", &num);

    if(num%2==0){
        printf("Par");
    }else printf("Impar");

    return 0;
}
