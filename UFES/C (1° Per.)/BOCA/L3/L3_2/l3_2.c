#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main(void){

    float num1 = 0, num2 = 0, res = 0, controlador = 0;
    char operador = 'x';
        do{
        scanf("%f %f %c", &num1, &num2, &operador);

            switch (operador)
            {
            case '+':
                res = Soma(num1, num2);
                break;
            case '-':
                res = Subtracao(num1, num2);
                break;
            case '*':
                res = Multiplicacao(num1, num2);
                break;
            case '/':
                res = Divisao(num1, num2);
                break;
            default:
                break;
            }
        controlador++;/*LOOP executado apenas 1 vez!*/
        
    }while(controlador==0);

    while(scanf("%f %c",&num2, &operador)==2){
        switch (operador)
            {
            case '+':
                res = Soma(res, num2);
                break;
            case '-':
                res = Subtracao(res, num2);
                break;
            case '*':
                res = Multiplicacao(res, num2);
                break;
            case '/':
                res = Divisao(res, num2);
                break;
            default:
                break;
            }
    }

    printf("%.2f", res);
    
    return 0;
}
//-----------FUNÇÕES--------------
float Soma(float x, float y){
    return x + y;
}
float Subtracao(float x, float y){
    return x - y;
}
float Divisao(float x, float y){
    return x / y;
}
float Multiplicacao(float x, float y){
    return x * y;
}
