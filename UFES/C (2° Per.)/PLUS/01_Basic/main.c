//Aluno: Gabriel Zuany Duarte Vargas (2o Período, CComp).
//inf16153 - 2022/2

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void ManWord(char *word);
void ResetWord(char *word);

int main(){
    char text[300], word[30];
    int i = 0, WordPos = 0;

        for(i=0; ; i++){//Condicao de parada logo abaixo.

            scanf("%c", &text[i]);
            if(text[i] == '\n'){
                if(WordPos!=0) ManWord(word);//Caso antes do \n haja uma palavra, manipula-la antes de encerrar.
                exit(EXIT_SUCCESS);

            }else if(isalpha(text[i])){ //Enquanto ler letras, adiciona-las em um vetor que ira compor a palavra a ser manipulada.
                word[WordPos] = text[i];
                WordPos++;

            }else{ //Quando ler algo diferente de letra (indicara o fim da palavra).
                if(WordPos!=0){
                    ManWord(word); 
                    ResetWord(word);
                }
                printf("%c", text[i]);
                WordPos = 0;
            }
        }
    return 0;
}


void ManWord(char *word){
    int i = 0, size = 0;
    char firstChar = word[0]; //Armazena a primeira letra da palavra antes de transpor para o fim.

    size = strlen(word);
    word[size] = '\0';

    if(isupper(firstChar)){
        firstChar = tolower(firstChar);
        word[1] = toupper(word[1]);
    }

    for(i=0; i<size; ++i){// "Andar" com as letras da palavra.
        word[i] = word[i+1];
    }
    word[size-1] = firstChar;

    for(i=0; i<strlen(word); ++i){
        printf("%c", word[i]);
    }

    if(size <= 3){
        printf("an");
    }else{
        printf("o");
    }
}

void ResetWord(char *word){
    int i = 0;
    for(i=0; i<30; ++i){
        word[i] = '\0';
    }
}