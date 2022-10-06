#ifndef _TMAINSNAKE_H_
#define _TMAINSNAKE_H_
#include <stdio.h>
#include "tArquivos.h"
#include "tPosicoes.h"
#include "tEstatisticas.h"
#define TAM_MAX_COBRA 100
#define MORREU 'X'
#define PAREDE '#'
#define ESPACO_LIVRE ' '
#define PORTAL '@'
#define CORPO 'o'
#define MOV_HORARIO 'h'
#define MOV_ANTIHORARIO 'a'
#define MOV_CONTINUA 'c'
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

//--Definição de tipo de dados--//
typedef struct{
    tCobra Cobra;
    tArquivos Arquivos;
    tEstatisticas Estatisticas;
    //--MAPEAMENTO DO CORPO--//
    int CoordenadaLinhaCorpo[100];
    int CoordenadaColunaCorpo[100];
    int ContadorCorpo;
    //--REFERENTE AO MAPA--//
    int TamanhoLinha;
    int TamanhoColuna;
    char tabuleiro[100][100];
    int TemPortal;
    int portalLinha[2];
    int portalColuna[2];
    int HeatMap[100][100];
    int velocidade;
    char movAnterior;
}tJogo;

//--Funções da lib--//
tJogo LeMapa(char nomeDiretorio[], tJogo jogo);
tJogo LeMovimentos(tJogo jogo);
tJogo PosicaoInicial(tJogo jogo);
tJogo InicializaValores(tJogo jogo);
tJogo RealizaJogada(tJogo jogo);
tJogo TeletransportaCobrinha(char mov, tJogo jogo);
tJogo UsaPortal(int linha, int coluna, char mov, tJogo jogo);
tJogo TipoDeBonus(int linha, int coluna, tJogo jogo);
tJogo AtualizaPosicaoCobra(tJogo jogo, char mov);
tJogo MoveParaCima(tJogo jogo);
tJogo MoveParaBaixo(tJogo jogo);
tJogo MoveParaDireita(tJogo jogo);
tJogo MoveParaEsquerda(tJogo jogo);
tJogo MoveCorpo(tJogo jogo);
tJogo AtualizaCoordenadasCorpo(tJogo jogo);
tJogo AtualizaDinheiro(tJogo jogo);
tJogo AtualizaComida(tJogo jogo);
tJogo GeraHeatMap(tJogo jogo);
tJogo ColocaComida(tJogo jogo);
void ImprimeJogo(tJogo jogo);
void MataCobrinha(tJogo jogo);
void EncerraJogo(int validador, tJogo jogo);
void GeraResumo(int AumentouDinheiro, int AumentouCorpo, tJogo jogo);
void ImprimeEstatisticas(tJogo jogo);
void ImprimeHeatMap(tJogo jogo);
void GeraRanking(tJogo jogo);
int EhPortal(int linha , int coluna, tJogo jogo);
int EncontraPosPortal(int linha, int coluna, tJogo jogo);
int EhPosicaoValida(int linha, int coluna, tJogo jogo);
int EhBorda(int linha, int coluna, tJogo jogo);
int VerificaBonus(int linha, int coluna, tJogo jogo);
int EhUltimoCorpo(int linha, int coluna, tJogo jogo);

#endif