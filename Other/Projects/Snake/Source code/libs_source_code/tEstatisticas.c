#include "../libs_h/tEstatisticas.h"

tEstatisticas ArmazenaMovimento(tEstatisticas estatisticas, char mov){
    //--Registra o movimento para o resumo.txt--//
    estatisticas.movimento = mov;
    return estatisticas;
}

tEstatisticas AtualizaPontuacao(tEstatisticas estatisticas, char tipo){
    //--Atualiza a pontuação de acordo com o bonus encontrado--//
    if(tipo == COMIDA){
        estatisticas.Pontos += PONTO_COMIDA;
        estatisticas.QtdComida--;
        estatisticas.QtdCorpoCobra++;
        estatisticas.AumentouCorpo = 1;
    }else{
        estatisticas.Pontos += GANHA_DINHEIRO;
        estatisticas.QtdDinheiro++;
        estatisticas.AumentouDinheiro = 1;
    }
    return estatisticas;
}

tEstatisticas AumentaComida(tEstatisticas estatisticas){
    estatisticas.QtdComida++;
    return estatisticas;
}

tEstatisticas AtualizaAumentouCorpo(tEstatisticas estatisticas, int BIN){
    estatisticas.AumentouCorpo = BIN;
    return estatisticas;
}

tEstatisticas AtualizaAumentouDinheiro(tEstatisticas estatisticas, int BIN){
    estatisticas.AumentouDinheiro = BIN;
    return estatisticas;
}

tEstatisticas ResetaValores(tEstatisticas estatisticas){
    estatisticas.Pontos = 0;
    estatisticas.QtdComida = 1000000;
    estatisticas.QtdDinheiro = 0;
    estatisticas.QtdCorpoCobra = 0;
    estatisticas.AumentouCorpo = 0;
    estatisticas.AumentouDinheiro = 0;
    estatisticas.QtdMov = 0;
    estatisticas.MovBaixo = 0;
    estatisticas.MovCima = 0;
    estatisticas.MovEsquerda = 0;
    estatisticas.MovDireita = 0;
    estatisticas.NumeroDoMovimento = 1;
    estatisticas.JaMoveuCorpo = 0;
    return estatisticas;
}

tEstatisticas AtualizaQtdMov(tEstatisticas estatisticas, char mov){
    //--Atualiza estatisticas--//
    if(mov == 'c'){
        estatisticas.MovCima++;
    }else if(mov == 'b'){
        estatisticas.MovBaixo++;
    }else if(mov == 'e'){
        estatisticas.MovEsquerda++;
    }else if(mov == 'd'){
        estatisticas.MovDireita++;
    }
    estatisticas.QtdMov++;
    return estatisticas;
}

tEstatisticas AtualizaNumeroDoMovimento(tEstatisticas estatisticas, int var){
    //--Numero do movimento eh usado em resumo.txt--//
    estatisticas.NumeroDoMovimento = var+1;
    return estatisticas;
}

tEstatisticas AtualizaJaMoveuCorpo(tEstatisticas estatisticas, int BIN){
    estatisticas.JaMoveuCorpo = BIN;
    return estatisticas;
}

int RetornaQtdComida(tEstatisticas estatisticas){
    return estatisticas.QtdComida;
}

int RetornaQtdDinheiro(tEstatisticas estatisticas){
    return estatisticas.QtdDinheiro;
}

int RetornaPontuacao(tEstatisticas estatisticas){
    return estatisticas.Pontos;
}

int RetornaQtdCorpoCobra(tEstatisticas estatisticas){
    return estatisticas.QtdCorpoCobra;
}

int RetornaAumentouCorpo(tEstatisticas estatisticas){
    return estatisticas.AumentouCorpo;
}

int RetornaAumentouDinheiro(tEstatisticas estatisticas){
    return estatisticas.AumentouDinheiro;
}

int RetornaQtdMov(tEstatisticas estatisticas){
    return estatisticas.QtdMov;
}

int RetornaMovBaixo(tEstatisticas estatisticas){
    return estatisticas.MovBaixo;
}

int RetornaMovCima(tEstatisticas estatisticas){
    return estatisticas.MovCima;
}

int RetornaMovEsquerda(tEstatisticas estatisticas){
    return estatisticas.MovEsquerda;
}

int RetornaMovDireita(tEstatisticas estatisticas){
    return estatisticas.MovDireita;
}

int RetornaNumeroDoMovimento(tEstatisticas estatisticas){
    return estatisticas.NumeroDoMovimento;
}

int RetornaJaMoveuCorpo(tEstatisticas estatisticas){
    return estatisticas.JaMoveuCorpo;
}

char RetornaMovimento(tEstatisticas estatistica){
    return estatistica.movimento;
}
