#include <stdio.h>

void Calcula(int n1, int n2, char op){

    if(op == '+'){
        
        printf("SOMA:%i", (n1+n2));

    }else if(op=='-'){

        printf("SUB:%i", (n1-n2));

    }else if(op=='*'){

        printf("MULT:%i", (n1*n2));

    }else if(op=='/'){

        if(n1%n2==0){
            printf("DIV:%i", (n1/n2));
        }else printf("DIV:%i, RESTO:%i", (n1/n2), (n1%n2));

    }

}

int main(void){

    int n1 = 0, n2 = 0;
    char op = 'x';

    scanf("%i %c %i", &n1, &op, &n2);

    Calcula(n1, n2, op);


    return 0;
}