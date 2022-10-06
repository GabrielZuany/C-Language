#include <stdio.h>

int main(void){

    int Modo = 0, Chave = 0;
    unsigned char letra = ' ', Codigo = ' ';

    scanf("%i %i ", &Modo, &Chave);

    if(Modo==1 || Modo == 2){

        while(Chave>=26){
            Chave = Chave%26;
        }

        do{
            scanf("%c", &letra);

            if(EhLetra(letra) == 0 || Chave<0){
                printf("%c", letra);
                continue;
            }

            if(Modo == 1){

                Codigo = Codifica(letra, Chave);

            }else if(Modo == 2){

                Codigo = Decodifica(letra, Chave);

            }

            printf("%c", Codigo);

        }while(letra!='.');

    }else printf("Operacao invalida.");

    return 0;
}
//---------------FUNÇÕES----------------

int EhLetra (unsigned char c){
    if(c>='A' && c<='Z' || c>='a' && c<='z'){
        return 1;
    }else return 0;
}

int EhLetraMaiuscula (unsigned char c){
    if(c>='A' && c<='Z'){
        return 1;
    }else return 0;
}

int EhLetraMinuscula (unsigned char c){
    if(c>='a' && c<='z'){
        return 1;
    }else return 0;
}

unsigned char Codifica(unsigned char letra, int n){
    if(EhLetraMaiuscula(letra) == 1){

        letra = letra+(2*n);

        if(letra>'Z'){
           while(letra>'Z'){
                letra = letra - 26;
            } 
        }
        if(letra<'A'){
            while(letra<'A'){
                letra = letra+26;
            }
        }
        return letra;

    }else if(EhLetraMinuscula(letra) == 1){

        letra = letra + n;
        if(letra>'z'){
           while(letra>'z'){
                letra = letra - 26;
            } 
        }
        if(letra<'a'){
            while(letra<'a'){
                letra = letra+26;
            }
        }
        return letra;

    }else return ' ';
}

unsigned char Decodifica (unsigned char letra, int n){
    if(EhLetraMaiuscula(letra) == 1){
        letra = letra-(2*n);

        if(letra <'A'){
            while(letra < 'A'){
               letra = ('Z' + 1) - ('A' - letra - n); 
            }
        } 
        if(letra > 'Z'){
            while(letra > 'Z'){
                letra = ('A' + 1) + ('Z' - letra); 
            }
        }

        return letra;

    }else if(EhLetraMinuscula(letra) == 1){
        letra = letra - n;

        if(letra <'a'){
            while(letra < 'a'){
                letra =('z'+ 1)-('a' - letra);
            }
        } 

        if(letra>'z'){
            while (letra>'z'){
               letra = ('a' + 1) + ('z' - letra); 
            }
        }
        
        return letra;

    }else return ' ';

}