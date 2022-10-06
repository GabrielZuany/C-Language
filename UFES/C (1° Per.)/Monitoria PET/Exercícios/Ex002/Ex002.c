#include <stdio.h>

int main(){
    int l = 0, c = 0, i = 0, j = 0;
    printf("Movimentos de uma Torre no xadrez!\nDigite a linha em que a Torre se encontra:");
    scanf("%i", &l);
    printf("Digite a coluna em que a Torre se encontra:");
    scanf("%i", &c);
    l = l-1;
    c = c-1;

    if(l>=0 && l<=7 && c>=0 && c<=7){
        
        printf("    1  2  3  4  5  6  7  8\n");
        printf("    ----------------------\n");
        for(i=0;i<8;++i){
            printf("%i |", i+1);
            if(c!=7){
                for(j=0;j<7;++j){
                    if(j==c){
                        printf(" x ");
                    }
                    if(i==l){
                        printf(" x ");
                    }
                    else{
                        printf(" - ");
                    }
                }
            printf("\n");
            }

            if(c==7){
                for(j=0;j<8;++j){
                    if(j==c){
                        printf(" x ");
                        break;
                    }
                    if(i==l){
                        printf(" x ");
                    }
                    else{
                        printf(" - ");
                    }
                }
            printf("\n");
            }      
        }
    }
    return 0;
}