#include <stdio.h>

int main(void){

    int opcao = 0, n = 0;
    unsigned char letra = '^';
    int controle = 0;

    scanf("%i", &opcao);
    scanf("%i", &n);
    switch (opcao)
    {
    case 1:
        while(n>=26){
        n=n%26;
        }
        while(letra!='.'){
            scanf("%c", &letra);
            if(letra>=97 &&letra<=122){
                letra =letra+n;    
            }
            while(letra>122){
                letra=letra-26;
            }
            printf("%c", letra);
        }
        break;
    case 2:
        while(n>=26){
        n=n%26;
        }
        while(letra!='.'){
            scanf("%c", &letra);
            if(letra>=97 && letra<=122){
                letra = letra-n; 
                if(letra<97){
                    letra=123-(97-letra);
                }   
            }
            printf("%c", letra);
        }
        break;

    default:printf("Operacao invalida.");
        break;
    }

    return 0;
}