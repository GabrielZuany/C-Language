#include <stdio.h>

int verificaNegativo(int n);
int verificaPrimo(int n);

int main(void){

    int num = 0, PrimoNeg = 0, Extremo = 0, i = 0, j = 0;
    int l = 0, c = 0;

    scanf("%i %i", &l, &c);

    if(!(l<=100 && l>=1 && c<=100 &&c>=1)){
        return 0;
    }

    for(i=1;i<=l;++i){

        printf("	");

        for(j = 1; j<=c; ++j){

            scanf("%i", &num);

            Extremo = num;

            if(num<-32000 && num>32000){
                return 0;
            }

            if(verificaNegativo(num) == 1){
                num = num*-1;
                Extremo = -num;
                PrimoNeg = 1;
            }

            if(verificaPrimo(num) == 0){

                do{
                    num++; 
                    if(num>=32000){

                        num = Extremo;
                        goto proximo;
                    }

                }while(verificaPrimo(num)==0);
                
            }

            proximo:

            if(PrimoNeg==1 && num>-31998){

                printf("-%i ", num);

            }else printf("%i ", num);
            
            PrimoNeg = 0;
        }

        printf("\n");

    }

    return 0;
}
//----------FUNÇÕES-----------

int verificaPrimo(int n){
    int i, divisores = 0;

    for(i=1;i<=n;++i){
        if(n%i==0){
            divisores++;
        }
    }
    if(divisores==2){
        return 1;
    }else return 0;
}

int verificaNegativo(int n){

    if(n<0){
        return 1;
    }else return 0;

}