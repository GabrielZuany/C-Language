#include <stdio.h>

int main(void){

    int n1 = 0, n2 = 0;
    char operador = 'x';
    
    scanf("%i %i %c", &n1, &n2, &operador);

    if(operador == '+'){
        printf("RESP:%i", n1+n2);
    }else if(operador == '-'){
        printf("RESP:%i", n1-n2);
    }else if(operador == '*'){
        printf("RESP:%i", n1*n2);
    }else if(operador == '/'){
        printf("RESP:%i", n1/n2);
    }else printf("Invalido");


    return 0;
}