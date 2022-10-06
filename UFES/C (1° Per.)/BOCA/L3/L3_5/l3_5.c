#include <stdio.h>

int res = 0;//global

int Propriedade(int num);

int main(void){

    int min = 0, max = 0, num = 0;

    scanf("%i %i", &min, &max);
    
    if(min<max && min>=1000 && max<=9999){

        for(num=min+1; num<max; ++num){

            Propriedade(num);

            if(res==1){
                printf("%i\n", num);
            }
            
        }
    }
    return 0;
}
//-------FUNÇÕES----------

int Propriedade(int num){
    int ab = 0, cd = 0, ef = 0, resultado = 0;

    ab = num/100;
    cd = num%100;
    ef = ab+cd;
    resultado = ef*ef;

    if(resultado==num){
        return res = 1;
    }else return res = 0;

}