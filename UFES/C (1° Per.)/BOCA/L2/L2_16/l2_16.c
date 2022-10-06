#include <stdio.h>

int main(void){

    int menorNum = 0, num = 0, i = 0;
    char temp = ' ';
    int controle = 1, posicao_1 = 0, posicao_2 = 0, sequencia = 0;

    do{         
            temp='\0';
            scanf("%i", &num);
            scanf("%c", &temp);
                if(num>=-32000 && num<=32000){
                if(controle==1){
                    menorNum=num;
                    controle = 0;
                }
                if(num<menorNum){
                    menorNum=num;
                }
            }
	}while(temp==' ');

    while(scanf("%i", &num)){
    		if(num>=-32000 && num<=32000){
			    if(menorNum==num){
			        sequencia++;
                    if(sequencia==1){
                    posicao_1=i;
                    sequencia++;
                    }
                    if(sequencia>1){
                    posicao_2=i;
                    }  
                }
		    }  
           ++i; 
    }

    printf("%i ", menorNum);
        if(sequencia==0){
            printf("%i %i\n",i, i);
        }else{
             printf("%i %i", posicao_1, posicao_2);
        }

    return 0;
}