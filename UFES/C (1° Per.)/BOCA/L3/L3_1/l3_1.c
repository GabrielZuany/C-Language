#include <stdio.h>

float Soma(float num1, float num2);
float Subtracao(float num1, float num2);
float Divisao(float num1, float num2);
float Multiplicacao(float num1, float num2);

int main(){
    float num1, num2;
        while ( scanf("%f %f", &num1, &num2) == 2 ){
            float result;
            result = Soma(num1, num2);
            printf("%.2f", result);
            result = Subtracao(num1, num2);
            printf(" %.2f", result);
            result = Divisao(num1, num2);
            printf(" %.2f", result);
            result = Multiplicacao(num1, num2);
            printf(" %.2f\n", result);
        }
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