#include <stdio.h>

int main(void){

    int positivo = 0, negativo = 0, somaNeg = 0, somaPos = 0;
    int num = 0;
    char temp=' ';

        do{
        temp ='a';
        scanf("%i", &num);
        scanf("%c", &temp);
            if(num>-100 && num<100){
                    if(num>0){
                        positivo++;
                        somaPos+=num;
                    }else if(num<0){
                        negativo++;
                        somaNeg+=num;
                    }
            }else break;
        }while(temp==' '||temp=='\n');

        printf("%i %i %i %i",negativo, positivo, somaNeg, somaPos);

    return 0;
}