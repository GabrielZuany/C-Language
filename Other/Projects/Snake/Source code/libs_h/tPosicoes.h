#ifndef _TPOSICOES_H_
#define _TPOSICOES_H_

//--Definição de tipo de dados--//
typedef struct{
    int PosicaoCobraAntesMovimentoLinha;
    int PosicaoCobraAntesMovimentoColuna;
    int PosicaoAtualCobraLinha;
    int PosicaoAtualCobraColuna;
    int UltimaPosicaoLinhaCorpo;
    int UltimaPosicaoColunaCorpo;
}tCobra;

tCobra AtualizaPosicaoCobraAntesMovimento(tCobra JogoCobra, int linha, int coluna);
tCobra AtualizaCoordenadaAtualCobra(tCobra JogoCobra, int linha, int coluna);
tCobra AtualizaUltimoCorpo(tCobra JogoCobra, int linha, int coluna);
int RetornaPosicaoCobraAntesMovimento(tCobra JogoCobra, char id);
int RetornaPosicaoAtualCobra(tCobra JogoCobra, char id);
int RetornaUltimoCorpo(tCobra JogoCobra, char tipo);

#endif