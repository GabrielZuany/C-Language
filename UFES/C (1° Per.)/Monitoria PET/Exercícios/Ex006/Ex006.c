#include <stdio.h>

int EhValidoCPF();
int EhMaiorIdade();
int EhAprovado();
int EhValido();

int main(){
    int QtdVerificacoes = 0, i = 0;
    scanf("%d", &QtdVerificacoes);
    for(i = 0; i < QtdVerificacoes; i++){
        if(EhValido()){
            printf("%d eh valido!\n", i+1);
        }else{
            printf("%d eh invalido!\n", i+1);
        }
        printf("\n");
    }
    
    return 0;
}

int EhValido(){
    int CPF = 0, Idade = 0, Pontos = 0;
    if(EhValidoCPF()){
        CPF = 1;
    }
    if(EhMaiorIdade()){
        Idade = 1;
    }
    if(EhAprovado()){
        Pontos = 1;
    }
    if(CPF && Idade && Pontos){
        return 1;
    }
    return 0;
}

int EhValidoCPF(){
    int n[10];
    n[0] = NULL;
    int dig1 = 0, dig2 = 0, dig1Valido = 0, dig2Valido = 0;
    int soma = 0, RestoDiv = 0, Validade_1o_dig = 0;
    int i = 0;
    for(i = 1; i <= 9; i++){
        scanf("%1d", &n[i]);
    }
    scanf("%1d", &dig1);
    scanf("%1d", &dig2);
    
    soma = n[1]*10 + n[2]*9 + n[3]*8 + n[4]*7 + n[5]*6 + n[6]*5 + n[7]*4 + n[8]*3 + n[9]*2;
    RestoDiv = soma%11;

    if(RestoDiv<2 && dig1==0 ||(RestoDiv>=2 && dig1==11-RestoDiv)){
        dig1Valido = 1;
    }
    soma = 0;
    soma = n[1]*11 + n[2]*10 + n[3]*9 + n[4]*8 + n[5]*7 + n[6]*6 + n[7]*5 + n[8]*4 + n[9]*3 + dig1*2;
    RestoDiv = soma%11;

    if(RestoDiv<2 && dig2==0 || (RestoDiv>=2 && dig2==11-RestoDiv)){
        dig2Valido = 1;
    }
    if(dig1Valido == 1 && dig2Valido == 1){
        return 1;
    }
    if(dig1Valido==0 || dig2Valido==0){
        printf("CPF INVALIDO!\n");
        return 0;
    }
}

int EhMaiorIdade(){
    int ano = 0;
    scanf("%d", &ano);
    if(2022-ano>=18){
        return 1;
    }
    printf("EH MENOR DE IDADE!\n");
    return 0;
}

int EhAprovado(){
    int ponto = 0;
    scanf("%d", &ponto);
    if(ponto<=3){
        return 1;
    }
    printf("FOI REPROVADO!\n");
    return 0;
}