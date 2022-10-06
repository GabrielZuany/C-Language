#ifndef _TESTATISTICAS_H_
#define _TESTATISTICAS_H_
#define COMIDA '*'
#define PONTO_COMIDA 1
#define DINHEIRO '$'
#define GANHA_DINHEIRO 10

//--Definição de tipo de dados--//
typedef struct {
    int Pontos;
    int QtdComida;
    int QtdDinheiro;
    int AumentouDinheiro;
    int AumentouCorpo;
    int QtdCorpoCobra;
    int QtdMov;
    int MovBaixo;
    int MovCima;
    int MovDireita;
    int MovEsquerda;
    int NumeroDoMovimento;
    int JaMoveuCorpo;
    char movimento;
}tEstatisticas;

tEstatisticas ArmazenaMovimento(tEstatisticas estatisticas, char mov);
tEstatisticas AtualizaPontuacao(tEstatisticas estatisticas, char tipo);
tEstatisticas AumentaComida(tEstatisticas estatisticas);
tEstatisticas AtualizaAumentouCorpo(tEstatisticas estatisticas, int BIN);
tEstatisticas AtualizaAumentouDinheiro(tEstatisticas estatisticas, int BIN);
tEstatisticas ResetaValores(tEstatisticas estatisticas);
tEstatisticas AtualizaQtdMov(tEstatisticas estatisticas, char mov);
tEstatisticas AtualizaNumeroDoMovimento(tEstatisticas estatisticas, int var);
tEstatisticas AtualizaJaMoveuCorpo(tEstatisticas estatisticas, int BIN);
int RetornaQtdComida(tEstatisticas estatisticas);
int RetornaQtdDinheiro(tEstatisticas estatisticas);
int RetornaPontuacao(tEstatisticas estatisticas);
int RetornaQtdCorpoCobra(tEstatisticas estatisticas);
int RetornaAumentouCorpo(tEstatisticas estatisticas);
int RetornaAumentouDinheiro(tEstatisticas estatisticas);
int RetornaQtdMov(tEstatisticas estatisticas);
int RetornaMovBaixo(tEstatisticas estatisticas);
int RetornaMovCima(tEstatisticas estatisticas);
int RetornaMovEsquerda(tEstatisticas estatisticas);
int RetornaMovDireita(tEstatisticas estatisticas);
int RetornaNumeroDoMovimento(tEstatisticas estatisticas);
int RetornaJaMoveuCorpo(tEstatisticas estatisticas);
char RetornaMovimento(tEstatisticas estatistica);

#endif