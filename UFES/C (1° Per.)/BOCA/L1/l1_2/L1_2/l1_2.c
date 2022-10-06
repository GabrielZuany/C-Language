#include <stdio.h>

int main(void){

    float x = 0.00, y = 0.00;
    float perimetro = 0;

    scanf("%f %f", &x, &y);
    
    perimetro = 2*x + 2*y;
    printf("%.2f", perimetro);

    return 0;
}