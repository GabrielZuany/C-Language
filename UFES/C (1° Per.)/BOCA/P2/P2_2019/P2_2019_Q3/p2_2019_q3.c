#include <stdio.h>
#include <ctype.h>

int EhDigito(char c){
    if(c>='0' && c<='9'){
        return 1;
    }else return 0;
}

void ImprimePorExtenso(char digito){
    if(digito>'9'){
        printf("%c", digito);
    }else{
        switch (digito){
        case '0':
            printf("zero");
            break;
        case '1':
            printf("um");
            break;
        case '2':
            printf("dois");
            break;
        case '3':
            printf("tres");
            break;
        case '4':
            printf("quatro");
            break;
        case '5':
            printf("cinco");
            break;
        case '6':
            printf("seis");
            break;
        case '7':
            printf("sete");
            break;
        case '8':
            printf("oito");
            break;
        case '9':
            printf("nove");
            break;
        
        default:printf("%c", digito);
            break;
        }
    }
}
   
int main(void){

    char delimitador = '1';
    scanf("%c", &delimitador);
    int i = 0;
    char letra[100], temp;

    for(i=0;i<100;++i){
        letra[i] = '\0';
    }
    i=0;
    while(scanf("%c", &letra[i])==1 && letra[i]!=delimitador){
        i++;
    }
    i=0;

    while(letra[i]!=delimitador){

        if(EhDigito(letra[i]) && !EhDigito(letra[i+1]) && !EhDigito(letra[i-1])){
            ImprimePorExtenso(letra[i]);
        }else{
            printf("%c", letra[i]);
        }
        ++i;

    }

    return 0;
}
