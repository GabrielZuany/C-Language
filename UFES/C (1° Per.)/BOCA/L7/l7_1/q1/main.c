#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    char fileName[30]; //nome do arquivo
    char nome[20], curso[20];int idade; //dados do aluno
    
    FILE *file = NULL; //ponteiro para o arquivo

    sprintf(fileName,"%s", argv[1]);//converte o nome do arquivo para string
    file = fopen(fileName, "r");//abre o arquivo para leitura

    while(!feof(file)){//enquanto nao é o fim do arquivo executa o loop
        fscanf(file, "%[^;];%d;%[^\n]\n", nome, &idade, curso);//le o arquivo e armazena os dados em variaveis
        printf("-> %s tem %d anos e cursa %s\n\n", nome, idade, curso);
    }

    fclose(file);//fecha o arquivo

    return 0;
}
/*
./prog arquivos/exemplo1.txt
*/