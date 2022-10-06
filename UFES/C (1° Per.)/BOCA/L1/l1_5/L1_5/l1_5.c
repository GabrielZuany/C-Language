#include<stdio.h>

int main(void){

    int x =0, y = 0;

    scanf("%i %i", &x, &y);
    
    if(x>y){
        printf("N1 = %i", x);
    }else if(x<y){
        printf("N2 = %i", y);
    }else printf("N1 = N2");

    return 0;
}