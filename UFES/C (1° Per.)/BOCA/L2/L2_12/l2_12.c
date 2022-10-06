#include <stdio.h>

int main(void){

    char c;
    int controlador = 1;
    do{
        scanf("%c", &c);
        if(controlador==1){
            printf("RESP:");
            controlador=0;
        }
        if(c==' '){
            c='_';
        }printf("%c", c);
        if(c=='.'|| c=='?' || c=='!'){
            break;
            
        }
    }while(1);

    return 0;
}