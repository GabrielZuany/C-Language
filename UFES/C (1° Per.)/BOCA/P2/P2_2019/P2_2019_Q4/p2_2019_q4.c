#include <stdio.h>

int EhLetraMaiuscula(char c);
int EhNumero(char c);
int EhLetraMinuscula(char c);
int AnalisaSenha();

int main(void){

    int GrupoMaisForte = 0, GrupoMaisFraco = 0, GrupoMaisInvalido = 0, MaiorQtdForte = -1, MaiorQtdFraco = -1, MaiorQtdInvalido = -1, forte = 0, fraco = 0, invalido = 0, Qtd_grupos = 0, i = 0, usuario = 0;
    char senha = '.';

    scanf("%i", &Qtd_grupos);
    scanf("%*[^\n]");
    scanf("%*c");
    
    for(i=1; i<=Qtd_grupos; ++i){

        printf("GRUPO %i\n", i);

        while(scanf("%i", &usuario)==1){

            if(usuario==-1){
                break;
            }

            senha = AnalisaSenha();

            if(senha == 0){
                printf("INVALIDA\n");
                invalido++;
            }else if(senha == 1){
                printf("FRACA\n");
                fraco++;
            }else if(senha == 2){
                printf("FORTE\n");
                forte++;
            }

            if(forte>MaiorQtdForte){
                MaiorQtdForte = forte;
                GrupoMaisForte = i;
            }
            if(fraco>MaiorQtdFraco){
                MaiorQtdFraco = fraco;
                GrupoMaisFraco = i;
            }
            if(invalido>MaiorQtdInvalido){
                MaiorQtdInvalido = invalido;
                GrupoMaisInvalido = i;
            }
        }
        forte = 0;
        fraco = 0;
        invalido = 0;

        printf("\n");
    }

    printf("FORTES: GRUPO(%i) QTD(%i)\nFRACAS: GRUPO(%i) QTD(%i)\nINVALIDAS: GRUPO(%i) QTD(%i)\n", GrupoMaisForte, MaiorQtdForte, GrupoMaisFraco, MaiorQtdFraco, GrupoMaisInvalido, MaiorQtdInvalido);

    return 0;
}

//--------------------FUNÇÕES-----------------------
int EhLetraMaiuscula(char c){
    if(c>='A' && c<='Z'){
        return 1;
    }else return 0;
}

int EhNumero(char c){
    if(c>='0' && c<='9'){
        return 1;
    }else return 0;
}

int EhLetraMinuscula(char c){
    if(c>='a' && c<='z'){
        return 1;
    }else return 0;
}

int AnalisaSenha(){

    int Maiuscula = 0, Minuscula = 0, Num = 0, Alfanum = 0, qtdChar = 0;
    char senha = '.';

    while(1){
        scanf("%c", &senha);
        if(senha=='('){
            continue;
        }
        if(senha==')'){
            break;
        }
        if(EhLetraMaiuscula(senha)){
            Maiuscula = 1;
        }
        if(EhLetraMinuscula(senha)){
            Minuscula = 1;
        }
        if(EhNumero(senha)){
            Num = 1;
        }
        if(!EhLetraMaiuscula(senha) && !EhLetraMinuscula(senha) && !EhNumero(senha)){
            Alfanum = 1;
        } 
        qtdChar++;
    }

    scanf("%*[^\n]");
    scanf("%*c");

    if(qtdChar<6){
        return 0;
    }
    if(qtdChar>=6 && Maiuscula==1 && Minuscula==1 && Num==1 && Alfanum==1){
        return 2;
    }else if(qtdChar>=6 && (Maiuscula==0 || Minuscula==0 || Num==0 || Alfanum==0)){
        return 1;
    }else return -1;
}