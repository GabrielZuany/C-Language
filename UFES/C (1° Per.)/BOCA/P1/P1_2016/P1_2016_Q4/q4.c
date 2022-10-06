#include <stdio.h>

int main(void){

    int num1 = 0, num2 = 0, num3 = 0, N1 = 0, N2 = 0, N3 = 0;

    scanf("%i", &num1);
    N1 = num1/100;
    if(N1>9){
        num1 = num1/100;
        N1 = num1%10;
    }

    scanf("%i", &num2);
    N2 = num2/100;
    if(N2>9){
        num2 = num2/100;
        N2 = num2%10;
    }

    scanf("%i", &num3);
    N3 = num3/100;
    if(N3>9){
        num3 = num3/100;
        N3 = num3%10;
    }

    if(N1 == 0 && N2 == 0 && N3 == 0){
        printf("Nenhum");
        return 0;
    }

    if(N1==0){
        N1 = N2 + 9;
    }
    if(N2 == 0){
        N2 = N1 + 9;
    }
    if(N3 == 0){
        N3 = N2 + 9;
    }

    if(N1 == N2 && N1<N3){
        printf("N1");
        return 0;
    }
    if(N2 == N3 && N2 < N1){
        printf("N2");
        return 0;
    }
    if(N1 == N2 && N2 == N3){
        printf("N1");
        return 0;
    }
    

    if(((N1<N2 && N2<N3) || (N1<N3 && N3<N2)) && N1!=0){
        printf("N1");
    }else if(((N2<N1 && N1<N3) || (N2<N3 && N3<N1)) && N2!=0 ){
        printf("N2");
    }else printf("N3");

    return 0;
}