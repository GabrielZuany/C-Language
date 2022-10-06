#include <stdio.h>

typedef struct{
    int Ataque;
    int Defesa;
    int Valor;
    int Level;
}tJogador;

tJogador EscreveJogador(tJogador Jogador);
void ImprimeVencedor(tJogador Jogador1, tJogador Jogador2, int bonus);
int ValorJogador(tJogador Jogador, int bonus);

int main(){
    tJogador Jogador1, Jogador2;//lucas, luana
    int instancia, bonus;

    scanf("%d", &instancia);
    while(instancia--){
        scanf("%d", &bonus);
        Jogador1 = EscreveJogador(Jogador1);
        Jogador2 = EscreveJogador(Jogador2);
        ImprimeVencedor(Jogador1, Jogador2, bonus);
    }
    
    return 0;
}

tJogador EscreveJogador(tJogador Jogador){
    scanf("%d %d %d", &Jogador.Ataque, &Jogador.Defesa, &Jogador.Level);
    return Jogador;
}

void ImprimeVencedor(tJogador Jogador1, tJogador Jogador2, int bonus){
    if(ValorJogador(Jogador1, bonus) > ValorJogador(Jogador2, bonus)){
        printf("Lucas!\n");//Jogador1 venceu
    }else if(ValorJogador(Jogador1, bonus) < ValorJogador(Jogador2, bonus)){
        printf("Luana!\n");//Jogador2 venceu
    }else if(ValorJogador(Jogador1, bonus) == ValorJogador(Jogador2, bonus)){
        printf("Empate!\n");//Empate
    }
}

int ValorJogador(tJogador Jogador, int bonus){
    Jogador.Valor = (Jogador.Ataque + Jogador.Defesa)/2;
    if(Jogador.Level%2 == 0){
        Jogador.Valor += bonus;
    }
    return Jogador.Valor;
}