#include <stdio.h>

int main(){

    int x = 10;
    float y = 4.25;
    char z = 'a';

    int *pX;
    pX = &x; //*(&x) => o valor pX = endereco de memoria de x

    float *pY = &y; 
    char *pZ = &z;

    printf("Endereco {%ld} => Valor {%d}\n", pX, *pX);
    printf("Endereco {%ld} => Valor {%f}\n", pY, *pY);
    printf("Endereco {%ld} => Valor {%c}\n", pZ, *pZ);

    float soma = *pX + *pY;
    printf("SOMA = %f\n", soma);

    return 0;
}