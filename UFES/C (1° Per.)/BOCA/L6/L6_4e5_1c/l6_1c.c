#include <stdio.h>

typedef struct{
    int IdMsg;
    int IdPac;
    int TamMsg;
    char Msg[10];
    int CodErro;
}tPacote;

typedef struct{
    tPacote pct[100];
}tMensagens;

tPacote LePacote();
tMensagens GuardaPct();
void OrdenaMensagens(tMensagens mensagens);
void TrocaPosicao(int i, int j);
int PacoteTransmitidoComSucesso(tPacote pacote);
void ImprimeMensagens(tMensagens mensagens);

int qtd = 0;
tMensagens mensagens;

int main(void){
    mensagens = GuardaPct();
    int cont = qtd;

    while(cont>=0){
        OrdenaMensagens(mensagens);
        cont--;
    }
    ImprimeMensagens(mensagens);
 
    return 0;
}

tPacote LePacote(){
    int i = 0;
    tPacote pacote;

    scanf("%d %d %1d", &pacote.IdMsg, &pacote.IdPac, &pacote.TamMsg);

    pacote.Msg[pacote.TamMsg+1];

    for(i=0;i<10; ++i){
        scanf("%c", &pacote.Msg[i]);
    }
    for(i=pacote.TamMsg;i<10; ++i){
        pacote.Msg[i] = '\0';
    }

    scanf("%d", &pacote.CodErro);

    return pacote;
}

tMensagens GuardaPct(){
    scanf("%d", &qtd);
    int i = 0;

    tMensagens mensagens;
    mensagens.pct[qtd];

    for(i=0;i<qtd;++i){
        mensagens.pct[i] = LePacote();
    }

    return mensagens;
}

void OrdenaMensagens(tMensagens mensagens){
    int i =0, j = 0;

    for(i=0; i<qtd;++i){
        for(j=i+1;j<qtd;++j){

            if(mensagens.pct[i].IdMsg>mensagens.pct[j].IdMsg){
                TrocaPosicao(i, j);
                continue;
            }else if(mensagens.pct[i].IdMsg==mensagens.pct[j].IdMsg){

                if(mensagens.pct[i].IdPac>mensagens.pct[j].IdPac){
                    TrocaPosicao(i, j);
                    continue;
                }else continue;

            }else continue;
        }
    }
}

void TrocaPosicao(int i, int j){
    tPacote aux;
    aux = mensagens.pct[i];
    mensagens.pct[i] = mensagens.pct[j];
    mensagens.pct[j] = aux;
}

int PacoteTransmitidoComSucesso(tPacote pacote){
    int soma = 0, i = 0;
    int somaLetra = 0;
    char tmp;

    for(i=0;i<pacote.TamMsg;++i){
        somaLetra+=pacote.Msg[i];
    }
    
    soma = pacote.IdMsg + pacote.IdPac + pacote.TamMsg + somaLetra;
    
    if(soma==pacote.CodErro){
        return 1;
    }else{
        return 0;
    }
}

void ImprimeMensagens(tMensagens mensagens){
    int i = 0;
    for(i=0;i<qtd;++i){
        if(PacoteTransmitidoComSucesso(mensagens.pct[i])){
            if(mensagens.pct[i].IdMsg!=mensagens.pct[i+1].IdMsg){
                printf("%s\n", mensagens.pct[i].Msg);   
            }else{
               printf("%s", mensagens.pct[i].Msg); 
            }
               
        }else{
            if(mensagens.pct[i].IdMsg!=mensagens.pct[i+1].IdMsg){
                printf("##FALHA##\n");   
            }else{
               printf("##FALHA##"); 
            }
        }
    }
}