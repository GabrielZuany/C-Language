#include <stdio.h>

int main(void){

    int n1 = 0, n2 = 0, n3 = 0;
    scanf("%i %i %i", &n1, &n2, &n3);

    if(n1>n2 && n2>n3){
        printf("N3 = %i, N2 = %i, N1 = %i", n3, n2, n1);
    }else if(n3>n2 &&n2>n1){
        printf("N1 = %i, N2 = %i, N3 = %i", n1, n2, n3);
    }else if(n2>n3 && n3>n1){
        printf("N1 = %i, N3 = %i, N2 = %i", n1, n3, n2);
    }else if(n1>n3 && n3>n2){
        printf("N2 = %i, N3 = %i, N1 = %i", n2, n3, n1);
    }else if(n3>n1 && n1>n2){
        printf("N2 = %i, N1 = %i, N3 = %i", n2, n1, n3);
    }else if(n2>n1 && n1>n3){
        printf("N3 = %i, N1 = %i, N2 = %i", n3, n1, n2);
    }

    return 0;
}