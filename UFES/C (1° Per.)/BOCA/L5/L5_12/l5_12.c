#include <stdio.h> 
#include <stdlib.h> 
 
void ConcatenaString(char * str1, char * str2, char * strOut){
    int i = 0, j = i;

    while(str1[i]!='\0'){
        strOut[i] = str1[i];
        i++;
    }
    while(str2[j]!='\0'){
        strOut[i] = str2[j];
        i++;
        j++;
    }
}
 
int main(){ 
    char nome[1000]; 
    char sobrenome[1000]; 
    char nomeCompleto[2000]; 
    int i = 0;
   
    while ( scanf("%s", &sobrenome) == 1 && scanf("%s", &nome) == 1){ 
    ConcatenaString(nome, sobrenome, nomeCompleto); 
    
    printf("%s\n", nomeCompleto); 

        for(i = 0; i<1000; ++i){/*loop para zerar os vetores de caracteres e evitar que existam caracteres nao sobrescritos (i.e Remover loop para vizualizar a saida).*/
            nome[i] = '\0';
            sobrenome[i] = '\0';
            nomeCompleto[i] = '\0';
        }
    } 
  
    return 0;     
} 