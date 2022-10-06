#include <stdio.h>

int CalculaValorPalavra(char letra);
int EhPrimo(int n);

int main(void){

    char letra = '!';
    int ValorPalavra = 0;

    do{
        
        while(scanf("%c", &letra) == 1 && letra!='\n'){
        
            ValorPalavra += CalculaValorPalavra(letra);

        }

        if(ValorPalavra == 0){
            break;
        }

        if(EhPrimo(ValorPalavra)){

            printf("E primo\n");

        }else{

            while(!EhPrimo(ValorPalavra)){ 
                ValorPalavra++;
            }
            
            printf("Nao e primo %i\n", ValorPalavra); 
            
        }

        ValorPalavra = 0;
        
        
    }while(!feof(stdin));

    return 0;
}
//-------FUNÇÕES-------

int CalculaValorPalavra(char letra){
   if(letra>='a' && letra<='z'){
        letra = letra - 'a' + 1;
    }else if(letra >= 'A' && letra <= 'Z'){
        letra =  letra - 'A' + 1 + 26;
    }
    return letra;
}

int EhPrimo(int n){
    int i = 0, cont = 0;
    for(i = 1; i<= n; ++i){
        if(n%i == 0){
            cont++;
        }
    }

    if(cont == 2){
        return 1;
    }else return 0;
}