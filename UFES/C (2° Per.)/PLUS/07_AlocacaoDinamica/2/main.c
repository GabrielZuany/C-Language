#include <stdio.h>

int main(){
    int* x;
    int* y;

    if(x>y){
        printf("X(%p) maior que Y(%p)\n", x, y);
    }else{
        printf("X(%p) menor que Y(%p)\n", x, y);
    }

    return 0;
}