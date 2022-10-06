#include <stdio.h>

float FazOperacao(float num1, float num2, char op){

    if(op=='+'){
        return num1+num2;
    }else if(op=='-'){
        return num1-num2;
    }if(op=='*'){
        return num1*num2;
    }if(op=='/'){
        return num1/num2;
    }else return 0;

}


int main(void){

    float num1 = 0, num2 = 0, res = 0, control = 1, MaiorNum = -9999999;
    char op = 'x', letra = 'x';

    while(letra!='.'){

        scanf("%c", &letra);

        if(letra=='('){

            if(control == 1){

                scanf("%f %f %c", &num1, &num2, &op);
                res = FazOperacao(num1, num2, op);
                control = 0;  
            }

            while(scanf("%f %c", &num2, &op) == 2){

               res = FazOperacao(res, num2, op);   

            }

            continue;
        }

        if(letra==')'&& control == 0){

            printf("%.2f", res);

            if(res>MaiorNum){
                MaiorNum = res;
            }

            res = 0;
            control = 1;
            continue;

        }

        printf("%c", letra);   
         
    }

    printf(" MAIOR:%.2f", MaiorNum);    

    return 0;
}
