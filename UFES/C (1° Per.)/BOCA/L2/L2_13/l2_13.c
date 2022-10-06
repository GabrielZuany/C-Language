#include <stdio.h>

int main(void){

    char c = 'x';
    do{
        scanf("%c", &c);
        if(c>=97 && c<=122){
            c = c-32;
        }
        printf("%c", c);
        if(c=='.'|| c=='?' || c=='!'){
            break;
        }
    }while(1);

    return 0;
}