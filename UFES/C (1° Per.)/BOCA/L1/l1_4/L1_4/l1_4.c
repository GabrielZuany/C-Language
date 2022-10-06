#include<stdio.h>
#include <math.h>
#define PI 3.141592

int main(void){

    float raio_1 = 0.0, raio_2 = 0.0;
    float area_1 = 0.0;

    scanf("%f", &raio_1);
    area_1 = PI*raio_1*raio_1;
    raio_2 = sqrt(area_1/PI*2);

    printf("%.2f %.2f", area_1, raio_2/2);
    return 0;
}