#include<stdio.h>
#include<math.h>

int main(void){

    int n = 0, i = 0;
    float res = 0.0, soma = 0.0;

    scanf("%i", &n);
    for(i=1;i<=n;++i){
        soma = soma + (float)6/((pow(i,2)));
    }

    res = sqrt(soma);
    printf("%.6f", res);

    return 0;
}