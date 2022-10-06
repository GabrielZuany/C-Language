#include <stdio.h>

typedef struct{
    int IdMsg;
    int IdPac;
    int TamMsg;
    char *Msg;
    int CodErro;

}tPacote;

tPacote LePacote();
void ImprimePacote(tPacote pacote);
int PacoteTransmitidoComSucesso(tPacote pacote);

int main(void){
    int QtdPac = 0, i = 0, j = 0;
    scanf("%i", &QtdPac);
    tPacote pacote;
    
    while(QtdPac>0){
        pacote = LePacote();
        if(PacoteTransmitidoComSucesso(pacote)){
          ImprimePacote(pacote);   
        }else{
            printf("FALHA!\n");
        }
        QtdPac--;
    }
        
    return 0;
}

tPacote LePacote(){
    int i = 0;
    int IdMsg = 0, IdPac = 0, TamMsg = 0, CodErro = 0;

    scanf("%d %d %1d", &IdMsg, &IdPac, &TamMsg);

    char msg[TamMsg+1];
    for(i=0;i<10; ++i){
        scanf("%c", &msg[i]);
    }
    for(i=TamMsg;i<10; ++i){
        msg[i] = '\0';
    }

    scanf("%d", &CodErro);

    tPacote pacote = {IdMsg, IdPac, TamMsg, msg, CodErro};
    return pacote;
}

void ImprimePacote(tPacote pacote){
    printf("PCT: %i,%i,%i,%s,%i\n", pacote.IdMsg, pacote.IdPac, pacote.TamMsg, pacote.Msg, pacote.CodErro);
}

int PacoteTransmitidoComSucesso(tPacote pacote){
    int soma = 0, i = 0;
    int somaLetra = 0;

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