#include <stdio.h>

void ImprimeMultiplos(int num, int max);
int EhPrimo(int num);

int main(void){

    int min = 0, res = 0, max = 0, num = 0;

    scanf("%i %i", &min, &max);
    scanf("%*c");
 
    if(min<max){

        for(num=min+1;num<max;++num){

            res = EhPrimo(num);

            if(res==1){
                if(num>0){
                    printf("%i\n", num); 
                    ImprimeMultiplos(num, max);
                }
                     
            }
        }
    }

    return 0;
}
//------------FUNÇÕES---------------------
int EhPrimo(int num){

    int i = 0, cont = 0;

    for(i=1;i<=num;++i){

        if(num%i==0){
            cont++;
        }
    }
    if(cont==2){
        return 1;
    }else return 0;
}

void ImprimeMultiplos(int num, int max){

    int i = num+1, valor = 0; /*, num = 0, max = 0, i = 0*/

    while(i<max){
        if(i%num==0){
            printf("%i ", i);
            valor++;
            }
        ++i;
    }

    if(valor==0){
        printf("*");
    }
    printf("\n");
}
