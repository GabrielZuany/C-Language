#include <stdio.h>

int main(void){

    int n1 = 0, n2 = 0, n3 = 0;

    scanf("%i %i %i", &n1, &n2, &n3);

    if(n1<n2 && n2<n3){
        printf("CRESCENTE");
    }else if(n3<n2 && n2<n1){
        printf("DECRESCENTE");
    }else printf("TUDO DOIDO");



    return 0;
}