#include<stdio.h>
#include<string.h>

typedef struct{
    char palavra[100];
}tPalavra;

int main(void){
    int i = 0, cont = 0, flag = 0;
    tPalavra palavra[50];
    char MaiorPalavra[50];

    while(scanf("%s", palavra[i].palavra)==1){
        i++;
    }
    
    for(cont=0;cont<i;++cont){

        if(strlen(palavra[cont].palavra)>strlen(palavra[cont+1].palavra)){

            printf("%s\n", palavra[cont].palavra);
            if(strlen(palavra[cont].palavra)>strlen(MaiorPalavra)){
                strcpy(MaiorPalavra, palavra[cont].palavra);
            }
            flag++;

        }else if(strlen(palavra[cont].palavra)<strlen(palavra[cont+1].palavra)){

            printf("%s\n", palavra[cont+1].palavra);
            if(strlen(palavra[cont+1].palavra)>strlen(MaiorPalavra)){
                strcpy(MaiorPalavra, palavra[cont+1].palavra);
            }
            flag++;

        }

        cont++;
    }
    if(flag==0){
        printf("MAX:--\n");
    }else{
        printf("MAX:%s\n", MaiorPalavra);
    }

    return 0;
}
