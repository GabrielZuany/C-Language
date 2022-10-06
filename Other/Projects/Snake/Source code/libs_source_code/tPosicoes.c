#include "../libs_h/tPosicoes.h"

tCobra AtualizaPosicaoCobraAntesMovimento(tCobra JogoCobra, int linha, int coluna){
    JogoCobra.PosicaoCobraAntesMovimentoLinha = linha;
    JogoCobra.PosicaoCobraAntesMovimentoColuna = coluna;
    return JogoCobra;
}

tCobra AtualizaCoordenadaAtualCobra(tCobra JogoCobra, int linha, int coluna){
    JogoCobra.PosicaoAtualCobraLinha = linha;
    JogoCobra.PosicaoAtualCobraColuna = coluna;
    return JogoCobra;
}

tCobra AtualizaUltimoCorpo(tCobra JogoCobra, int linha, int coluna){
    JogoCobra.UltimaPosicaoLinhaCorpo = linha;
    JogoCobra.UltimaPosicaoColunaCorpo = coluna;
    return JogoCobra;
}

int RetornaPosicaoCobraAntesMovimento(tCobra JogoCobra, char id){
    if(id=='L') return JogoCobra.PosicaoCobraAntesMovimentoLinha;
    return JogoCobra.PosicaoCobraAntesMovimentoColuna;
}

int RetornaPosicaoAtualCobra(tCobra JogoCobra, char id){
    if(id == 'L')return JogoCobra.PosicaoAtualCobraLinha;
    return JogoCobra.PosicaoAtualCobraColuna;
}

int RetornaUltimoCorpo(tCobra JogoCobra, char tipo){
    if(tipo == 'L') return JogoCobra.UltimaPosicaoLinhaCorpo;
    return JogoCobra.UltimaPosicaoColunaCorpo;
}