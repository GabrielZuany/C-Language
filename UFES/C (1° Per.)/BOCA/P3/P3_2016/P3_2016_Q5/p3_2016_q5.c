#include <stdio.h>
#include <string.h>

int VerificaSeEstaContida(char *str1, char *str2);
void TransformaMinuscula(char *str1, char *str2);

int main(void){
    int qtd = 0, i = 0;
    char str1[400], str2[400];

    scanf("%d", &qtd);
    scanf("%*[^\n]");
    scanf("%*c");

    while(qtd--){
        while(scanf("%c", &str1[i])==1){
            if(str1[i]==' '){
                str1[i] = '\0';
                break;
            }
            i++;
        }
        i = 0;

        while(scanf("%c", &str2[i])==1){
            if(str2[i]=='\n'){
                str2[i] = '\0';
                break;
            }
            i++;
        }
        i = 0;

        TransformaMinuscula(str1, str2);

        if(VerificaSeEstaContida(str1, str2)){
            printf("PODE!\n");
        }else{
            printf("NAO PODE!\n");
        } 
    }
    return 0;
}

void TransformaMinuscula(char *str1, char *str2){
    int i = 0;
    while(str1[i]!='\0'){
        if(str1[i]>='A' && str1[i]<='Z'){
            str1[i]=str1[i]+32;
        }
        i++;
    }
    i=0;
    while(str2[i]!='\0'){
        if(str2[i]>='A' && str2[i]<='Z'){
            str2[i]=str2[i]+32;
        }
        i++;
    }
}

int VerificaSeEstaContida(char *str1, char *str2){
    int cont = 0;
    if(strlen(str2)<strlen(str1)){
        return 0;
    }

    int i = 0, j = 0;
    for(i=0; i<strlen(str1);++i){
        for(j=0;j<strlen(str2); j++){
            if((str1[i]==str2[j]) && i<=j){
                cont++;
                break;
            }
        }
    }
    if(cont==strlen(str1)){
        return 1;
    }

    return 0;
}