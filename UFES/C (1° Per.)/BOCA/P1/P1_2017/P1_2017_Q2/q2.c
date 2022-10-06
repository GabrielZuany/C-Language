#include <stdio.h>

int main(void){

    int n1 = 0, n2 = 0;

    scanf("%i %i", &n1, &n2);

    if((n1>=1 && n1<=5) && (n2>=1 && n2<=5) && n1!=n2){
        printf("Par de homens");
    }else if((n1>=6 && n1<=10) && (n2>=6 && n2<=10) && n1!=n2){
        printf("Par de mulheres");
    }else if(((n1>=1 && n1<=5) && (n2>=6 && n2<=10)) || ((n1>=6 && n1<=10) && (n2>=1 && n2<=5))){
        printf("Um casal");
    }else if(((n1>=1 && n1<=5) && n1==n2) || (n2>=1 && n2<=5) && n1 == n2){
        printf("Um homem");
    }else if(((n1>=6 && n1<=10) && n1==n2) || (n2>=6 && n2<=10) && n1 == n2){
        printf("Uma mulher");
    }else printf("Invalido");
    

    return 0;
}