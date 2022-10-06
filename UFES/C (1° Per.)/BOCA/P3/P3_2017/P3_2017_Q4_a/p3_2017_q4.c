#include <stdio.h>
#include <ctype.h>

int EhVogal(char c);
int ContaVogal(char str[]);
int ContaConsoante(char str[]);
void ImprimeConsoante(char str[]);
void ImprimeVogal(char str[]);

int main(void) {
    char palavra[100];
    int vog = 0, cons = 0;

    while(scanf("%s", palavra) == 1){

        vog = ContaVogal(palavra);
        cons = ContaConsoante(palavra);
        if(cons>vog){
            ImprimeConsoante(palavra);
        }
        else if(vog>cons){
            ImprimeVogal(palavra);
        }
        else{
            printf("%s", palavra);
        }
        printf("\n");
    }
    return 0;
}

int EhVogal(char c){
    if(c == 'a' || c == 'A'|| c == 'e' || c == 'E'|| c == 'i' || c == 'I'|| c == 'o' || c == 'O'|| c =='u' || c == 'U'){
        return 1;
    }
    return 0;
}

int ContaVogal(char str[]){
    int qtd = 0, i = 0;
    for (i = 0; str[i]; i++) {
        if (EhVogal(str[i])) {
            qtd++;
        }
    }
    return qtd;
}

int ContaConsoante(char str[]){
    int qtd = 0, i = 0;
    for (i = 0; str[i]; i++) {
        if (!EhVogal(str[i]) && isalpha(str[i])) {
            qtd++;
        }
    }
    return qtd;
}

void ImprimeVogal(char str[]){
    int i;
    for (i = 0; str[i]; i++) {
        if (EhVogal(str[i])) {
            printf("%c", str[i]);
        }
    }
}

void ImprimeConsoante(char str[]){
    int i;
    for (i = 0; str[i]; i++) {
        if (!EhVogal(str[i]) && isalpha(str[i])) {
            printf("%c", str[i]);
        }
    }
}