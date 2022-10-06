#include <stdio.h>

int main(void){

    int i=0, n=0, cont = 0;
    scanf("%i", &n);
    for(i=1;i<=n;++i){
        if(n%i==0){
            cont++;
        }
    }
    if(cont==2){
        printf("Primo");
    }else printf("Nao primo");

    return 0;
}