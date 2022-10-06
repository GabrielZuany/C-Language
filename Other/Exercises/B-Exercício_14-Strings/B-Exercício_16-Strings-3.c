/*
Leia 5 strings e depois imprima cada uma delas;
Depois de ler as 5 strings, leia mais uma string e
verifique se ela está no vetor.
*/
#include <stdio.h>
#include <string.h>

int main(){

    char texto[5][20];
    char palavra[20];
    int i, flag = 0;

    printf("INSIRA 5 PALAVRAS: \n");
    for(i=0;i<5; i++){
        scanf("%s", texto[i]);
    }
    printf("INSIRA A PALAVRA QUE DESEJA ENCONTRAR: ");
    scanf("%s", palavra);

    for(i=0;i<5; i++){
        if(strcmp(palavra, texto[i]) == 0){
            printf("PALAVRA [%s] ENCONTRADA NA POS %d\n", palavra, i+1);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("PALAVRA NAO ENCONTRADA\n");
    }


    return 0;
}