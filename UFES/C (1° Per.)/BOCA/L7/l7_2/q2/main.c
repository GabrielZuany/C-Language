#include <stdio.h>
#include <string.h>

void ConverteEmMinusculo(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int main(int argc, char **argv){

    char cod1[4], cod2[4];
    char fileName[30]; //nome do arquivo

    FILE *file = NULL; //ponteiro para o arquivo
    FILE *fileC;
    sprintf(fileName, "%s", argv[1]);//converte o nome do arquivo para string

    while(!feof(file)){
        fscanf(file, "%[a-zA-Z0-9] %[a-zA-Z0-9]", cod1, cod2);//le o arquivo e armazena os dados em variaveis
        if(strlen(cod1) != strlen(cod2)){
            //fscanf(fileC, "INVALIDO\n");
            printf("INVALIDO\n");
            continue;
        }

        ConverteEmMinusculo(cod1);
        ConverteEmMinusculo(cod2);

        if(strcoll(cod1, cod2) == 0){
            //fscanf(fileC, "IGUAIS\n");
            printf("IGUAIS\n");
        }else{
            //fscanf(fileC, "DIFERENTES\n");
            printf("DIFERENTES\n");
        }
    }

    fclose(file);//fecha o arquivo
    fclose(fileC);

    return 0;
}