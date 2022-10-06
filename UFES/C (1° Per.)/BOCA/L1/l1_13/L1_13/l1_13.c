#include <stdio.h>

int main(void){

    int p = 0, i = 0;
    int res = 0;

    scanf("%i %i", &p, &i);
    res = i%p;

    if(res==0){
        printf("RESP:%i", p);
    }else printf("RESP:%i", res);

    return 0;
}