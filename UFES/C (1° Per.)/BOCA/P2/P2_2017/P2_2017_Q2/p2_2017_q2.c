#include <stdio.h>
  
int EhIgual(int a, int b){

    if(a==b){
        return 1;
    }else return 0;

}

int InverteNum(int num){
 
    int saveNum = 0, resultado = 0, dig = 0;

    saveNum = num;
      
    while (num > 0){
        resultado = resultado * 10;
        dig = num % 10;
        num = num / 10;

        resultado = resultado + dig;
    } 

    if (EhIgual(saveNum, resultado)){
        return 1;
    }else{
        return 0;
    }
}


int main(){ 

   int num = 0, cont = 0;

    while(scanf("%d", &num)==1){

        if(num<0){
            num*=-1;
        }
        if(InverteNum(num)){
            cont++;
        }

    }
    printf("COUNT:%d", cont);
    return 0;
}

