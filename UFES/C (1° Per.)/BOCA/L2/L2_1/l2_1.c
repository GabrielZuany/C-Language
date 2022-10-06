#include <stdio.h>

int main(void){

    int num = 0, lim = 0, resp = 0;
    int i = 0;

    scanf("%i %i", &num, &lim);
    printf("RESP:");

    for(i=num+1;i<lim;i++){
        if(num<lim){
            resp = i%2;{
                if(resp==0){
                    printf("%i ", i);
                }
            }
        }
    }

    return 0;
}