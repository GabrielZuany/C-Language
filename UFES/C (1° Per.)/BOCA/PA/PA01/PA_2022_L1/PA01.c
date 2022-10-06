#include <stdio.h>

void IntercalaDigito(int num1, int num2){

    int d1_n1 = 0, d2_n1 = 0, d3_n1= 0, d4_n1 = 0, d1_n2 = 0, d2_n2 = 0, d3_n2= 0, d4_n2 = 0;

    d1_n1 = num1%10;
    num1/=10;
    d1_n2 = num2%10;
    num2/=10;

    d2_n1 = num1%10;
    num1/=10;
    d2_n2 = num2%10;
    num2/=10;

    d3_n1 = num1%10;
    num1/=10;
    d3_n2 = num2%10;
    num2/=10;

    d4_n1 = num1%10;
    num1/=10;
    d4_n2 = num2%10;
    num2/=10;

    if(d4_n2!=0){
        printf("(%i%i%i%i%i%i%i%i)", d4_n2, d4_n1, d3_n2, d3_n1, d2_n2, d2_n1, d1_n2, d1_n1);
    }else if(d4_n2==0 && d4_n1 != 0){
        printf("(%i%i%i%i%i%i%i)", d4_n1, d3_n2, d3_n1, d2_n2, d2_n1, d1_n2, d1_n1);
    }else if(d4_n1==0 && d3_n2 != 0){
        printf("(%i%i%i%i%i%i)", d3_n2, d3_n1, d2_n2, d2_n1, d1_n2, d1_n1);
    }else if(d3_n2==0 && d3_n1 != 0){
        printf("(%i%i%i%i%i)", d3_n1, d2_n2, d2_n1, d1_n2, d1_n1);
    }else if(d3_n1==0 && d2_n2 != 0){
        printf("(%i%i%i%i)", d2_n2, d2_n1, d1_n2, d1_n1);
    }else if(d2_n2==0 && d2_n1 != 0){
        printf("(%i%i%i)", d2_n1, d1_n2, d1_n1);
    }else if(d2_n1==0 && d1_n2 != 0){
        printf("(%i%i)", d1_n2, d1_n1);
    }else if(d1_n2==0 && d1_n1 != 0){
        printf("(%i)", d1_n1);
    }
    
}

int main(void){

    int num1 = 0, num2 = 0;
    char c1 = '.';

    scanf("(%c,%i,%i)", &c1, &num1, &num2);

    if((c1>='a' && c1<='z') || (c1>='A' && c1<='Z')){
        IntercalaDigito(num1, num2);
    }else{
        IntercalaDigito(num2, num1);
    }
    printf("\n");
    
    return 0;
}