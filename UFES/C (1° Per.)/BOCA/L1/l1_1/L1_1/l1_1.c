#include<stdio.h>
#include<math.h>

int main(void){

    int x = 0, y = 0;
    float res = 0.00;

    scanf("%i %i", &x, &y);
    res = sqrt(x) + sqrt(y);
    printf("%.2f", res);

    return 0;
}