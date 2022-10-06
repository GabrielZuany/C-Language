/*
-------JOGO DA COBRINHA (em modo "debug")-----

    ---Para o funcionamento do jogo, o usuario deve digitar no terminal o executavel (apos compilar o main.c) do jogo juntamente com o caminho do arquivo de mapa. Exemplo: "./jogo /home/minhamaquina/jogo/mapas/mapa_1/"---
    ---O jogo deve ser executado com o terminal---
    ---A cabeça da cobrinha eh respresentada por setas '>', '<', '^' e 'v'.---
    ---O corpo da cobrinha eh respresentada por 'o'---
    ---A comida eh respresentada por '*' e o bonus de dinheiro '$'---
    ---Os tuneis/portais sao respresentados por '@'. Caso o usuario entre em um, saira no outro na mesma direcao com a qual entrou.---
    ---As pareses são respresentadas por '#'. Caso o jogador acerte a parede ou o proprio corpo ele perde o jogo.---
    ---Os comandos validos sao: 'c' (continuar mov), 'a' (mov antiHorario), 'h'(mov horario)---
    ---Caso deseje ver as informacoes geradas apos a ultima jogada no mapa, os aquivos gerados se encontram na pasta "saida", encontrada na pasta mapa_<numero_do_mapa>---
        >Os Arquivos de saida sao: HeatMap.txt, Ranking.txt, Resumo.txt, Inicializacao.txt e Estatisticas.txt---

-->Realizado na disciplina de Prog.I (1o Periodo) da Universidade Federal do Espirito Santo (UFES).
-->Objetivo: Aplicar conhecimentos de modularizacao, criacao e manipulacao de tipos de dados definidos pelo usuario, logica e manipulacao de arquivos.

--Autor do codigo: Gabriel Zuany Duarte Vargas---
---Data: 2022, Agosto---

=============OPERAVEL, POR ENQUANTO, APENAS NO LINUX;==============
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_COBRA 100
#define COBRA '>'
#define COBRA_DIREITA '>'
#define COBRA_CIMA '^'
#define COBRA_BAIXO 'v'
#define COBRA_ESQUERDA '<'
#define MORREU 'X'
#define PAREDE '#'
#define ESPACO_LIVRE ' '
#define COMIDA '*'
#define PONTO_COMIDA 1
#define DINHEIRO '$'
#define GANHA_DINHEIRO 10
#define PORTAL '@'
#define CORPO 'o'
#define MOV_HORARIO 'h'
#define MOV_ANTIHORARIO 'a'
#define MOV_CONTINUA 'c'

/*============================TIPOS============================*/
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

typedef struct {
    FILE *Resumo;
    FILE *Heatmap;
    FILE *Ranking;
    FILE *Estatisticas;
}tArquivos;

typedef struct{
    int PosicaoCobraAntesMovimentoLinha;
    int PosicaoCobraAntesMovimentoColuna;
    int PosicaoAtualCobraLinha;
    int PosicaoAtualCobraColuna;
    int UltimaPosicaoLinhaCorpo;
    int UltimaPosicaoColunaCorpo;
}tCobra;

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
}tJogo;

/*======================DECLARAÇÃO DE FUNÇÕES================*/

//--FUNCOES DE INICIALIZACAO E JOGADA--//
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

//--FUNCOES DE ESTATISTICAS--//
tEstatisticas AumentaComida(tEstatisticas estatisticas);
tEstatisticas AtualizaPontuacao(tEstatisticas estatisticas, char tipo);
tEstatisticas AtualizaAumentouCorpo(tEstatisticas estatisticas, int var);
tEstatisticas AtualizaAumentouDinheiro(tEstatisticas estatisticas, int var);
tEstatisticas ResetaValores(tEstatisticas estatisticas);
tEstatisticas AtualizaQtdMov(tEstatisticas estatisticas, char mov);
tEstatisticas AtualizaNumeroDoMovimento(tEstatisticas estatisticas, int var);
tEstatisticas AtualizaJaMoveuCorpo(tEstatisticas estatisticas, int var);
tEstatisticas ArmazenaMovimento(tEstatisticas estatisticas, char mov);
int RetornaPontuacao(tEstatisticas estatisticas);
int RetornaQtdComida(tEstatisticas estatisticas);
int RetornaQtdDinheiro(tEstatisticas estatisticas);
int RetornaQtdCorpoCobra(tEstatisticas estatisticas);
int RetornaAumentouCorpo(tEstatisticas estatisticas);
int RetornaAumentouDinheiro(tEstatisticas estatisticas);
int RetornaQtdMov(tEstatisticas estatisticas);
int RetornaMovBaixo(tEstatisticas estatisticas);
int RetornaMovCima(tEstatisticas estatisticas);
int RetornaMovDireita(tEstatisticas estatisticas);
int RetornaMovEsquerda(tEstatisticas estatisticas);
int RetornaNumeroDoMovimento(tEstatisticas estatisticas);
int RetornaJaMoveuCorpo(tEstatisticas estatisticas);
char RetornaMovimento(tEstatisticas estatisticas);

//--FUNCOES DE ARQUIVOS--//
FILE *RetornaArquivoAberto(char Caminho[]);
tArquivos AbreArquivos(char CaminhoResumo[], char CaminhoEstatisticas[], char CaminhoHeatMap[], char CaminhoRanking[]);

//--FUNCOES DE POSICAO--//
tCobra AtualizaPosicaoCobraAntesMovimento(tCobra JogoCobra, int linha, int coluna);
tCobra AtualizaCoordenadaAtualCobra(tCobra JogoCobra, int linha, int coluna);
tCobra AtualizaUltimoCorpo(tCobra JogoCobra, int linha, int coluna);
int RetornaPosicaoCobraAntesMovimento(tCobra JogoCobra, char id);
int RetornaPosicaoAtualCobra(tCobra JogoCobra, char id);
int RetornaUltimaPosicaoLinhaCorpo(tCobra JogoCobra, char tipo);

/*=============================MAIN===========================*/

int main(int argc, char **argv){
    tJogo JOGO;
    char nomeDiretorio[1000]; // nome do diretorio
    FILE *Diretorio = NULL;

    char CaminhoResumo[1000];
    char CaminhoEstatisticas[1000];
    char CaminhoHeatMap[1000];
    char CaminhoRanking[1000];

    //converte o vetor de caracteres em string para usar a biblioteca string.h
    CaminhoResumo[0] = '\0';
    CaminhoEstatisticas[0] = '\0';
    CaminhoHeatMap[0] = '\0';
    CaminhoRanking[0] = '\0';

    Diretorio = fopen(argv[1], "r"); //abre o caminho do diretorio digitado no terminal.

    if (Diretorio == NULL) {
        printf("ERRO: Diretorio de arquivos de configuracao nao foi informado\n");
        return 1;
    }
    sprintf(nomeDiretorio, "%s", argv[1]); //converte o nome do arquivo para string.

    //concatena o nome do diretorio com o do arquivo de saida.
    strcat(CaminhoResumo, nomeDiretorio); 
    strcat(CaminhoResumo, "/saida/resumo.txt");
    strcat(CaminhoEstatisticas, nomeDiretorio);
    strcat(CaminhoEstatisticas, "/saida/estatisticas.txt");
    strcat(CaminhoHeatMap, nomeDiretorio);
    strcat(CaminhoHeatMap, "/saida/heatmap.txt");
    strcat(CaminhoRanking, nomeDiretorio);
    strcat(CaminhoRanking, "/saida/ranking.txt");

    //Abre os arquivos de saida para escrita.
    JOGO.Arquivos = AbreArquivos(CaminhoResumo, CaminhoEstatisticas, CaminhoHeatMap, CaminhoRanking);
    
    JOGO = LeMapa(nomeDiretorio, JOGO);
    JOGO = InicializaValores(JOGO);
    JOGO = RealizaJogada(JOGO);
    ImprimeEstatisticas(JOGO);
    ImprimeHeatMap(JOGO);
    return 0;
}

/*==========================FUNÇÕES=======================================*/

//===========ARQUIVOS==================//

tArquivos AbreArquivos(char CaminhoResumo[], char CaminhoEstatisticas[], char CaminhoHeatMap[], char CaminhoRanking[]){
    tArquivos Arquivos;
    Arquivos.Resumo = RetornaArquivoAberto(CaminhoResumo);
    Arquivos.Estatisticas = RetornaArquivoAberto(CaminhoEstatisticas);
    Arquivos.Heatmap = RetornaArquivoAberto(CaminhoHeatMap);
    Arquivos.Ranking = RetornaArquivoAberto(CaminhoRanking);
    return Arquivos;
}

FILE *RetornaArquivoAberto(char Caminho[]){
    //Recebe o caminho do arquivo e retorna o arquivo aberto.
    FILE *file = NULL;
    file = fopen(Caminho, "w");
    return file;
}

FILE *RetornaHeatMap(tArquivos jogoArquivo){
    return jogoArquivo.Heatmap;
}

FILE *RetornaRanking(tArquivos jogoArquivo){
    return jogoArquivo.Ranking;
}

FILE *RetornaResumo(tArquivos jogoArquivo){
    return jogoArquivo.Resumo;
}

FILE *RetornaEstatisticas(tArquivos jogoArquivo){
    return jogoArquivo.Estatisticas;
}

//==========INICIALIZACAO/LEITURA=====//

tJogo LeMapa(char nomeDiretorio[], tJogo jogo){
    FILE *fmapa, *fInicializacao, *fsaida;
    int i, j;
    char CaminhoArquivosDeEntrada[1000];
    char CaminhoArquivoSaidaInicializacao[1000];

    //--Edicao do nome do caminho do arquivo de mapa--//
    CaminhoArquivosDeEntrada[0] = '\0';
    CaminhoArquivoSaidaInicializacao[0] = '\0';

    strcat(CaminhoArquivosDeEntrada, nomeDiretorio);
    strcat(CaminhoArquivosDeEntrada, "/mapa.txt");
    strcat(CaminhoArquivoSaidaInicializacao, nomeDiretorio);
    strcat(CaminhoArquivoSaidaInicializacao, "/saida/inicializacao.txt");

    //--Abertura dos arquivos para leitura ou escrita--//
    fmapa = fopen(CaminhoArquivosDeEntrada, "r");
    fInicializacao = fopen(CaminhoArquivoSaidaInicializacao, "w");

    //--Edicao dos arquivos--//
    if (fmapa == NULL){
        printf("ERRO: Arquivo mapa.txt nao encontrado em %s", nomeDiretorio); 
        fclose(fInicializacao);
        fclose(fmapa);
        exit(0);
    }

    //--Leitura do mapa--//
    fscanf(fmapa, "%d %d", &jogo.TamanhoLinha, &jogo.TamanhoColuna);
    fscanf(fmapa, "%*c");//pula o caractere '\n'
    for (i = 0; i < jogo.TamanhoLinha; i++){
        for (j = 0; j < jogo.TamanhoColuna; j++) {
            fscanf(fmapa, "%c", &jogo.tabuleiro[i][j]);
            fprintf(fInicializacao, "%c", jogo.tabuleiro[i][j]);
        }
        fscanf(fmapa, "%*c"); //consome o \n
        fprintf(fInicializacao, "\n");
    }

    //--Inicializacao da posicao da cobra--//
    jogo = PosicaoInicial(jogo);
    fprintf(fInicializacao, "A cobra comecara o jogo na linha %d e coluna %d\n", RetornaPosicaoAtualCobra(jogo.Cobra, 'L')+1, RetornaPosicaoAtualCobra(jogo.Cobra, 'C')+1);


    //--Fechamento dos arquivos--//
    fclose(fInicializacao);
    fclose(fmapa);
    return jogo;
}

tJogo PosicaoInicial(tJogo jogo){
    int Linha, Coluna;
    //--Varre o mapa até encontrar uma posicao inicial para a cobra--//
    for (Linha = 0; Linha < jogo.TamanhoLinha; Linha++) {
        for (Coluna = 0; Coluna < jogo.TamanhoColuna; Coluna++){
            if (jogo.tabuleiro[Linha][Coluna] == COBRA_DIREITA){
                jogo.Cobra = AtualizaCoordenadaAtualCobra(jogo.Cobra, Linha, Coluna);
            }
        }
    }
    return jogo;
}

tEstatisticas ArmazenaMovimento(tEstatisticas estatisticas, char mov){
    //--Registra o movimento para o resumo.txt--//
    estatisticas.movimento = mov;
    return estatisticas;
}

tJogo LeMovimentos(tJogo jogo){
    char mov;
    scanf("%c", &mov);
    scanf("%*c");//consome o \n do buffer
    jogo.Estatisticas = ArmazenaMovimento(jogo.Estatisticas, mov);
    return jogo;
}

tJogo InicializaValores(tJogo jogo){
    //--Reseta os valores de estatisticas--//
    jogo.Estatisticas = ResetaValores(jogo.Estatisticas);
    jogo.ContadorCorpo = 0;
    jogo.TemPortal = 0;
    int n = 0;
    int i, j;

    //--Conta a quantidade de itens no mapa--//
    for (i = 0; i < jogo.TamanhoLinha; i++) {
        for (j = 0; j < jogo.TamanhoColuna; j++)  {
            if (jogo.tabuleiro[i][j] == COMIDA){
                jogo.Estatisticas = AumentaComida(jogo.Estatisticas);
            }
            if(jogo.tabuleiro[i][j] == PORTAL){
                jogo.TemPortal = 1;
                jogo.portalLinha[n] = i;
                jogo.portalColuna[n] = j; 
                n++;
            }
        }
    }
    return jogo;
}

char RetornaMovimento(tEstatisticas estatistica){
    return estatistica.movimento;
}

tCobra AtualizaPosicaoCobraAntesMovimento(tCobra JogoCobra, int linha, int coluna){
    JogoCobra.PosicaoCobraAntesMovimentoLinha = linha;
    JogoCobra.PosicaoCobraAntesMovimentoColuna = coluna;
    return JogoCobra;
}

tJogo RealizaJogada(tJogo jogo){
    int i = 0;
    for (i = 0; i < 1000; ++i){
        if (RetornaQtdComida(jogo.Estatisticas) == 0){
            EncerraJogo(1, jogo);//Encerra o jogo com sucesso.
        }
        jogo = LeMovimentos(jogo);
        jogo.Cobra = AtualizaPosicaoCobraAntesMovimento(jogo.Cobra, RetornaPosicaoAtualCobra(jogo.Cobra, 'L'), RetornaPosicaoAtualCobra(jogo.Cobra, 'C'));
        jogo.Estatisticas = AtualizaNumeroDoMovimento(jogo.Estatisticas, i);
        jogo.Estatisticas = AtualizaAumentouCorpo(jogo.Estatisticas, 0);
        jogo.Estatisticas = AtualizaAumentouDinheiro(jogo.Estatisticas, 0);
        jogo = GeraHeatMap(jogo); 

        if (RetornaMovimento(jogo.Estatisticas) == MOV_HORARIO) {
            if(jogo.tabuleiro[RetornaPosicaoAtualCobra(jogo.Cobra, 'L')][RetornaPosicaoAtualCobra(jogo.Cobra, 'C')] == COBRA_DIREITA){
                jogo = MoveParaBaixo(jogo);
            }
            else if (jogo.tabuleiro[RetornaPosicaoAtualCobra(jogo.Cobra, 'L')][RetornaPosicaoAtualCobra(jogo.Cobra, 'C')] == COBRA_ESQUERDA){
                jogo = MoveParaCima(jogo);
            }
            else if (jogo.tabuleiro[RetornaPosicaoAtualCobra(jogo.Cobra, 'L')][RetornaPosicaoAtualCobra(jogo.Cobra, 'C')] == COBRA_CIMA) {
                jogo = MoveParaDireita(jogo);
            }
            else{
                jogo = MoveParaEsquerda(jogo);
            }

        }else if (RetornaMovimento(jogo.Estatisticas) == MOV_ANTIHORARIO) {
            if (jogo.tabuleiro[RetornaPosicaoAtualCobra(jogo.Cobra, 'L')][RetornaPosicaoAtualCobra(jogo.Cobra, 'C')] == COBRA_DIREITA){
                jogo = MoveParaCima(jogo);
            }
            else if (jogo.tabuleiro[RetornaPosicaoAtualCobra(jogo.Cobra, 'L')][RetornaPosicaoAtualCobra(jogo.Cobra, 'C')] == COBRA_ESQUERDA){
                jogo = MoveParaBaixo(jogo);
            }
            else if (jogo.tabuleiro[RetornaPosicaoAtualCobra(jogo.Cobra, 'L')][RetornaPosicaoAtualCobra(jogo.Cobra, 'C')] == COBRA_CIMA) {
                jogo = MoveParaEsquerda(jogo);
            }
            else{
                jogo = MoveParaDireita(jogo);
            }

        }else if (RetornaMovimento(jogo.Estatisticas) == MOV_CONTINUA){
            if (jogo.tabuleiro[RetornaPosicaoAtualCobra(jogo.Cobra, 'L')][RetornaPosicaoAtualCobra(jogo.Cobra, 'C')] == COBRA_DIREITA){
                jogo = MoveParaDireita(jogo);
            }
            else if (jogo.tabuleiro[RetornaPosicaoAtualCobra(jogo.Cobra, 'L')][RetornaPosicaoAtualCobra(jogo.Cobra, 'C')] == COBRA_ESQUERDA){
                jogo = MoveParaEsquerda(jogo);
            }
            else if (jogo.tabuleiro[RetornaPosicaoAtualCobra(jogo.Cobra, 'L')][RetornaPosicaoAtualCobra(jogo.Cobra, 'C')] == COBRA_CIMA){
                jogo = MoveParaCima(jogo);
            }
            else{
                jogo = MoveParaBaixo(jogo);
            }
        }

        if(RetornaJaMoveuCorpo(jogo.Estatisticas) == 0){
            jogo = MoveCorpo(jogo);
        }
        jogo.Estatisticas = AtualizaJaMoveuCorpo(jogo.Estatisticas, 0);//reseta o valor para 0.
        ImprimeJogo(jogo);
        GeraResumo(RetornaAumentouDinheiro(jogo.Estatisticas), RetornaAumentouCorpo(jogo.Estatisticas), jogo);
    }
    return jogo;  
}

//============PORTAIS==============//

int EncontraPosPortal(int linha, int coluna, tJogo jogo){
    if(linha == jogo.portalLinha[0] && coluna == jogo.portalColuna[0]){
        return 0;
    }else if(linha == jogo.portalLinha[1] && coluna == jogo.portalColuna[1]){
        return 1;
    } return -1;
}

tCobra AtualizaCoordenadaAtualCobra(tCobra JogoCobra, int linha, int coluna){
    JogoCobra.PosicaoAtualCobraLinha = linha;
    JogoCobra.PosicaoAtualCobraColuna = coluna;
    return JogoCobra;
}

tJogo MovePeloPortal(tJogo jogo, int linhaDestino, int colunaDestino, char mov){
    //--Move a cobra de um portal (tunel) para outro e atualiza a sua posicao--//
    if(mov == 'c'){//se for para cima
        jogo.tabuleiro[linhaDestino][colunaDestino] = COBRA_CIMA;
    }else if(mov == 'b'){//se for para baixo
        jogo.tabuleiro[linhaDestino][colunaDestino] = COBRA_BAIXO;
    }else if(mov == 'e'){//se for para esquerda
        jogo.tabuleiro[linhaDestino][colunaDestino] = COBRA_ESQUERDA;
    }else if(mov == 'd'){//se for para direita
        jogo.tabuleiro[linhaDestino][colunaDestino] = COBRA_DIREITA;
    }
    jogo.Cobra = AtualizaCoordenadaAtualCobra(jogo.Cobra, linhaDestino, colunaDestino);
    return jogo; 
}

tJogo VerificaCondicoesAntesMovPeloPortal(tJogo jogo, int linha, int coluna, int n, char mov){
    //--Caso o portal de destino esteja na borda do mapa--//
    //--linha e coluna sao as coordenadas do portal de destino--//
    if(coluna > jogo.TamanhoColuna-1){
        coluna = 0;
    }else if(coluna < 0 ){
        coluna = jogo.TamanhoColuna-1;
    }else if(linha > jogo.TamanhoLinha-1){
        linha = 0;
    }else if(linha < 0){
        linha = jogo.TamanhoLinha-1;
    }
    
    jogo = TipoDeBonus(linha, coluna, jogo);
    
    if(EhPosicaoValida(linha, coluna, jogo)){
        jogo = MoveCorpo(jogo);
        jogo.Estatisticas = AtualizaJaMoveuCorpo(jogo.Estatisticas, 1);
        jogo = MovePeloPortal(jogo, linha, coluna, mov);

    }else if(EhUltimoCorpo(linha, coluna, jogo)){
        jogo = MoveCorpo(jogo);
        jogo.Estatisticas = AtualizaJaMoveuCorpo(jogo.Estatisticas, 1);
        jogo = MovePeloPortal(jogo,linha, coluna, mov);

    }else  if(EhBorda(linha, coluna, jogo) && linha == 0 && EhPosicaoValida(linha, coluna, jogo)){
        jogo = MovePeloPortal(jogo,linha, coluna, mov);

    }else{
        jogo = MovePeloPortal(jogo, linha, coluna, mov);
        EncerraJogo(0, jogo);
    }
    return jogo;
}

tJogo UsaPortal(int linha, int coluna, char mov, tJogo jogo){
    int n = EncontraPosPortal(linha, coluna, jogo);//n = 0 -> portal 1 //  n = 1 -> portal 2.
    if(n == 0){//inverte o valor de n para transportar a cobra para o outro portal.
        n = 1;
    }else n = 0;

    switch(mov){
        case 'c': //cima
            jogo = VerificaCondicoesAntesMovPeloPortal(jogo, jogo.portalLinha[n]-1, jogo.portalColuna[n], n, mov);
        break;
        case 'b'://baixo
            jogo = VerificaCondicoesAntesMovPeloPortal(jogo, jogo.portalLinha[n]+1, jogo.portalColuna[n], n, mov);
        break;
        case 'e'://esquerda
            jogo = VerificaCondicoesAntesMovPeloPortal(jogo, jogo.portalLinha[n], jogo.portalColuna[n]-1, n, mov);
        break;
        case 'd'://direita
            jogo = VerificaCondicoesAntesMovPeloPortal(jogo, jogo.portalLinha[n], jogo.portalColuna[n]+1, n, mov);
        break;
    }
    return jogo;
}

int EhPortal(int linha , int coluna, tJogo jogo){
    if((linha == jogo.portalLinha[0] && coluna == jogo.portalColuna[0]) || (linha == jogo.portalLinha[1] && coluna == jogo.portalColuna[1])){
        return 1;
    } return 0;
}

//=========MOVIMENTOS=CABECA===============//

tJogo AtualizaPosicaoCobra(tJogo jogo, char mov){
    //--Atualiza e move (nessa ordem) a posicao da cabeca da cobra--//
    int PosicaoAtualCobraLinha = RetornaPosicaoAtualCobra(jogo.Cobra, 'L');
    int PosicaoAtualCobraColuna = RetornaPosicaoAtualCobra(jogo.Cobra, 'C');
    if(mov == 'c'){
        jogo.tabuleiro[--PosicaoAtualCobraLinha][PosicaoAtualCobraColuna] = COBRA_CIMA;
    }else if(mov == 'b'){
        jogo.tabuleiro[++PosicaoAtualCobraLinha][PosicaoAtualCobraColuna] = COBRA_BAIXO;
    }else if(mov == 'e'){
        jogo.tabuleiro[PosicaoAtualCobraLinha][--PosicaoAtualCobraColuna] = COBRA_ESQUERDA;
    }else jogo.tabuleiro[PosicaoAtualCobraLinha][++PosicaoAtualCobraColuna] = COBRA_DIREITA;

    jogo.Cobra = AtualizaCoordenadaAtualCobra(jogo.Cobra, PosicaoAtualCobraLinha, PosicaoAtualCobraColuna);
    return jogo;
}

tJogo TipoDeBonus(int linha, int coluna, tJogo jogo){
    int Tipo_De_Bonus = VerificaBonus(linha, coluna, jogo);
    //--Bonus = 1 -> bonus de Dinheiro--//
    //--Bonus = 2 -> bonus de Comida--//
    if(Tipo_De_Bonus == 1){
        jogo.Estatisticas = AtualizaPontuacao(jogo.Estatisticas, DINHEIRO);
    }else if(Tipo_De_Bonus == 2){
        jogo.Estatisticas = AtualizaPontuacao(jogo.Estatisticas, COMIDA);
    }
    return jogo;
}

int VaiTeleportarCobra(tJogo jogo, int linha, int coluna, char mov){
    //--Verifica se a posicao atual eh BORDA VALIDA de acordo com o movimento dado--//
    if(mov == 'c'){//cima
        if(EhBorda(linha, coluna, jogo) && linha == 0) return 1;
    }else if(mov == 'b'){//baixo
        if(EhBorda(linha, coluna, jogo) && linha == jogo.TamanhoLinha-1) return 1;
    }else if(mov == 'e'){//esquerda
        if(EhBorda(linha, coluna, jogo) && coluna == 0) return 1;
    }else if(EhBorda(linha, coluna, jogo) && coluna == jogo.TamanhoColuna-1) return 1; 
    return 0;
}

int RetornaPosicaoCobraAntesMovimento(tCobra JogoCobra, char id){
    if(id=='L') return JogoCobra.PosicaoCobraAntesMovimentoLinha;
    return JogoCobra.PosicaoCobraAntesMovimentoColuna;
}

int RetornaPosicaoAtualCobra(tCobra JogoCobra, char id){
    if(id == 'L')return JogoCobra.PosicaoAtualCobraLinha;
    return JogoCobra.PosicaoAtualCobraColuna;
}

tJogo MOVIMENTA_COBRINHA(tJogo jogo, int linha, int coluna, char mov){
    int linhaDestino, colunaDestino;//Usado caso vá teleportar.
    if(mov == 'c'){
        linhaDestino = jogo.TamanhoLinha-1;
        colunaDestino =RetornaPosicaoAtualCobra(jogo.Cobra, 'C');
    }else if(mov == 'b'){
        linhaDestino = 0;
        colunaDestino = RetornaPosicaoAtualCobra(jogo.Cobra, 'C');
    }else if(mov == 'e'){
        linhaDestino = RetornaPosicaoAtualCobra(jogo.Cobra, 'L');
        colunaDestino = jogo.TamanhoColuna-1;
    }else{
        linhaDestino = RetornaPosicaoAtualCobra(jogo.Cobra, 'L');
        colunaDestino = 0;
    }

    jogo = TipoDeBonus(linha, coluna, jogo);//Verifica se eh bonus e atualiza pontuacao.

    if(jogo.TemPortal == 1 && EhPortal(linha, coluna, jogo)){
        jogo = UsaPortal(linha, coluna, mov, jogo);
 
    }else if(EhPosicaoValida(linha, coluna, jogo)){//Vertifica a proxima celula .
        jogo = AtualizaPosicaoCobra(jogo, mov);

    }else  if(EhUltimoCorpo(linha, coluna, jogo)){//Caso particular -> PROX CELULA == ULTIMO CORPO.
        jogo = MoveCorpo(jogo);
        jogo.Estatisticas = AtualizaJaMoveuCorpo(jogo.Estatisticas, 1);//Corpo ja mexido.
        jogo = AtualizaPosicaoCobra(jogo, mov);

    }else  if(VaiTeleportarCobra(jogo, RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L'), RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C'), mov)){//Verifica se vai teleportar.
        
        if(EhPosicaoValida(linhaDestino, colunaDestino, jogo)){//Verifica as coordenadas de destino.

            if(jogo.TemPortal == 1 && EhPortal(linhaDestino, colunaDestino, jogo)){
                jogo = UsaPortal(linhaDestino, colunaDestino, mov, jogo);

            }else {
                jogo = TipoDeBonus(linhaDestino,colunaDestino, jogo);//Verifica bonus e atualiza pontuacao
                jogo = TeletransportaCobrinha(mov, jogo); 
            }
            
        }else{
            jogo = TeletransportaCobrinha(mov, jogo);
            EncerraJogo(0, jogo);
        }

    }else{//Caso proxima celula seja invalida em todas as situações.
        jogo.tabuleiro[RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L')][RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C')] = ESPACO_LIVRE;
        jogo = AtualizaPosicaoCobra(jogo, mov);
        EncerraJogo(0, jogo);
    }
    return jogo;
}

tJogo MoveParaCima(tJogo jogo){
    //--Atualiza estatisticas e passa parametros para a funcao de movimento--//
    jogo.Estatisticas = AtualizaQtdMov(jogo.Estatisticas, 'c');
    jogo = MOVIMENTA_COBRINHA(jogo, RetornaPosicaoAtualCobra(jogo.Cobra, 'L')-1, RetornaPosicaoAtualCobra(jogo.Cobra, 'C'), 'c');
    return jogo;
}

tJogo MoveParaBaixo(tJogo jogo){
    //--Atualiza estatisticas e passa parametros para a funcao de movimento--//
    jogo.Estatisticas = AtualizaQtdMov(jogo.Estatisticas, 'b');
    jogo = MOVIMENTA_COBRINHA(jogo,RetornaPosicaoAtualCobra(jogo.Cobra, 'L')+1, RetornaPosicaoAtualCobra(jogo.Cobra, 'C'), 'b');
    return jogo;
}

tJogo MoveParaEsquerda(tJogo jogo){
    //--Atualiza estatisticas e passa parametros para a funcao de movimento--//
    jogo.Estatisticas = AtualizaQtdMov(jogo.Estatisticas, 'e');
    jogo = MOVIMENTA_COBRINHA(jogo, RetornaPosicaoAtualCobra(jogo.Cobra, 'L'), RetornaPosicaoAtualCobra(jogo.Cobra, 'C')-1, 'e');
    return jogo;
}

tJogo MoveParaDireita(tJogo jogo){
    //--Atualiza estatisticas e passa parametros para a funcao de movimento--//
    jogo.Estatisticas = AtualizaQtdMov(jogo.Estatisticas, 'd');
    jogo = MOVIMENTA_COBRINHA(jogo, RetornaPosicaoAtualCobra(jogo.Cobra, 'L'), RetornaPosicaoAtualCobra(jogo.Cobra, 'C')+1, 'd');
   return jogo;  
}

tJogo TeletransportaCobrinha(char mov, tJogo jogo){
    //--Teleporta a cobra para outra extremidade do mapa de acordo com o movimento dado--//
    int PosicaoAtualCobraLinha = RetornaPosicaoAtualCobra(jogo.Cobra, 'L');
    int PosicaoAtualCobraColuna = RetornaPosicaoAtualCobra(jogo.Cobra, 'C');
    if(mov == 'c'){
        jogo.tabuleiro[0][PosicaoAtualCobraColuna] = ESPACO_LIVRE;
        jogo.tabuleiro[jogo.TamanhoLinha - 1][PosicaoAtualCobraColuna] = COBRA_CIMA;
        jogo.Cobra = AtualizaCoordenadaAtualCobra(jogo.Cobra, jogo.TamanhoLinha-1, PosicaoAtualCobraColuna);
    }else if(mov == 'b'){
        jogo.tabuleiro[PosicaoAtualCobraLinha][PosicaoAtualCobraColuna] = ESPACO_LIVRE;
        jogo.tabuleiro[0][PosicaoAtualCobraColuna] = COBRA_BAIXO;
        jogo.Cobra = AtualizaCoordenadaAtualCobra(jogo.Cobra, 0, PosicaoAtualCobraColuna);
    }else if(mov == 'e'){
        jogo.tabuleiro[PosicaoAtualCobraLinha][PosicaoAtualCobraColuna] = ESPACO_LIVRE;
        jogo.tabuleiro[PosicaoAtualCobraLinha][jogo.TamanhoColuna - 1] = COBRA_ESQUERDA;
        jogo.Cobra = AtualizaCoordenadaAtualCobra(jogo.Cobra, PosicaoAtualCobraLinha, jogo.TamanhoColuna-1);
    }else if(mov == 'd'){
        jogo.tabuleiro[PosicaoAtualCobraLinha][PosicaoAtualCobraColuna] = ESPACO_LIVRE;
        jogo.tabuleiro[PosicaoAtualCobraLinha][0] = COBRA_DIREITA;
        jogo.Cobra = AtualizaCoordenadaAtualCobra(jogo.Cobra, PosicaoAtualCobraLinha, 0);
    }
    return jogo;
}

//================CORPO===================//

tCobra AtualizaUltimoCorpo(tCobra JogoCobra, int linha, int coluna){
    JogoCobra.UltimaPosicaoLinhaCorpo = linha;
    JogoCobra.UltimaPosicaoColunaCorpo = coluna;
    return JogoCobra;
}

int RetornaUltimoCorpo(tCobra JogoCobra, char tipo){
    if(tipo == 'L') return JogoCobra.UltimaPosicaoLinhaCorpo;
    return JogoCobra.UltimaPosicaoColunaCorpo;
}

tJogo MoveCorpo(tJogo jogo){  
    /*
    A)QtdCorpo = 1 e Comeu comida:
    --> Mantém o corpo na mesma posição e coloca 'o' na posição anterior à cabeça.
    */
    if(RetornaQtdCorpoCobra(jogo.Estatisticas)==1 && RetornaAumentouCorpo(jogo.Estatisticas) == 1){
        jogo.tabuleiro[RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L')][RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C')] = CORPO; 

        jogo.Cobra = AtualizaUltimoCorpo(jogo.Cobra, RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L'), RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C'));
        
        jogo.CoordenadaLinhaCorpo[jogo.ContadorCorpo] = RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L');
        jogo.CoordenadaColunaCorpo[jogo.ContadorCorpo] = RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C');
    }

    /*
    B)QtdCorpo = 1 e Nao Comeu comida:
    --> Célula do corpo = espaço vazio; célula atual da cabeça = corpo;
    */
    else if(RetornaQtdCorpoCobra(jogo.Estatisticas)==1 && RetornaAumentouCorpo(jogo.Estatisticas) ==  0){
        jogo.CoordenadaLinhaCorpo[jogo.ContadorCorpo] = RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L');
        jogo.CoordenadaColunaCorpo[jogo.ContadorCorpo] = RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C');

        jogo.tabuleiro[RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L')][RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C')] = CORPO;

        jogo.tabuleiro[RetornaUltimoCorpo(jogo.Cobra, 'L')][RetornaUltimoCorpo(jogo.Cobra, 'C')] = ESPACO_LIVRE;
        //Atualiza a posição do último corpo.
        jogo.Cobra = AtualizaUltimoCorpo(jogo.Cobra, RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L'), RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C'));
    }

    /*
    C)QtdCorpo>1 e Comeu comida:
    --> Mantém o corpo no mesmo lugar; coloca 'o' na célula anterior à cabeça (vazia);
    --> Registra coordenada do corpo inserido;
    */
    else if(RetornaQtdCorpoCobra(jogo.Estatisticas)>1 && RetornaAumentouCorpo(jogo.Estatisticas) == 1){
        jogo.tabuleiro[RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L')][RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C')] = CORPO; 
        jogo.ContadorCorpo++;
        jogo.CoordenadaLinhaCorpo[jogo.ContadorCorpo] = RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L');
        jogo.CoordenadaColunaCorpo[jogo.ContadorCorpo] = RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C');
    }
    
    /*
    D)QtdCorpo>1 e Nao comeu comida;
    --> Move Corpo e atualiza a posição do último corpo.
    */
    else if(RetornaQtdCorpoCobra(jogo.Estatisticas)>1 && RetornaAumentouCorpo(jogo.Estatisticas) == 0){
        jogo = AtualizaCoordenadasCorpo(jogo);
    }   
    
    /*
    E)QtdCorpo = 0; -> Célula anterior à cabeça = vazio;
    */
    if(RetornaQtdCorpoCobra(jogo.Estatisticas) == 0){
        jogo.tabuleiro[RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L')][RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C')] = ESPACO_LIVRE;
    }
    return jogo;
}

tJogo AtualizaCoordenadasCorpo(tJogo jogo){
    int i;

    //Coordenada corpo[0] = Coordenada corpo[1] .... de 0 a n-1
    for(i=0; i<RetornaQtdCorpoCobra(jogo.Estatisticas); i++){
        jogo.CoordenadaLinhaCorpo[i] = jogo.CoordenadaLinhaCorpo[i+1];
        jogo.CoordenadaColunaCorpo[i] = jogo.CoordenadaColunaCorpo[i+1];
    }

    //Coordenada do corpo [n-1] = Coordenada da célula anterior à cabeça.
    jogo.CoordenadaLinhaCorpo[RetornaQtdCorpoCobra(jogo.Estatisticas)-1] = RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L');
    jogo.CoordenadaColunaCorpo[RetornaQtdCorpoCobra(jogo.Estatisticas)-1] = RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C');

    //Limpa célula onde estava o último corpo.
    jogo.tabuleiro[RetornaUltimoCorpo(jogo.Cobra, 'L')][RetornaUltimoCorpo(jogo.Cobra, 'C')] = ESPACO_LIVRE;

    //Coloca 'o' na posição anterior à cabeça.
    jogo.tabuleiro[RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L')][RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C')] = CORPO;

    //Atualiza coordenada do último corpo.
    jogo.Cobra = AtualizaUltimoCorpo(jogo.Cobra, jogo.CoordenadaLinhaCorpo[0], jogo.CoordenadaColunaCorpo[0]);

    return jogo;
}

//================VALORES===================//

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
    estatisticas.QtdComida = 0;
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

//================VERIFICACAO=================//

int EhBorda(int linha, int coluna, tJogo jogo){
    if(linha == 0 || coluna == 0 || linha == jogo.TamanhoLinha -1  || coluna == jogo.TamanhoColuna-1 ){
        return 1;
    }
    return 0;
}

int VerificaBonus(int linha, int coluna, tJogo jogo){
    //--Verifica se na posicao seguinte existe um bonus--//
    if(jogo.tabuleiro[linha][coluna] == DINHEIRO){
        return 1;
    }else if(jogo.tabuleiro[linha][coluna] == COMIDA){
        return 2;
    }return 0;
}

int EhPosicaoValida(int linha, int coluna, tJogo jogo){
    //--Verifica se a posicao seguinte esta dentro do tamanho do mapa e se eh celula valida--//
    if((jogo.tabuleiro[linha][coluna] != PAREDE && jogo.tabuleiro[linha][coluna] != CORPO && linha<jogo.TamanhoLinha && coluna<jogo.TamanhoColuna && linha>=0 && coluna>=0)){
        return 1;
    } return 0;
}

int EhUltimoCorpo(int linha, int coluna, tJogo jogo){
    if(linha == jogo.CoordenadaLinhaCorpo[0] && coluna == jogo.CoordenadaColunaCorpo[0]){
        return 1;
    }
    return 0;
}

//=============PRINT/FIM=====================//

void ImprimeJogo(tJogo jogo){
    int i, j;
    printf("\nEstado do jogo apos o movimento '%c':\n", RetornaMovimento(jogo.Estatisticas));
    for (i = 0; i < jogo.TamanhoLinha; i++){
        for (j = 0; j < jogo.TamanhoColuna; j++){
            printf("%c", jogo.tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("Pontuacao: %d\n", RetornaPontuacao(jogo.Estatisticas));
}

void MataCobrinha(tJogo jogo){
    //--Coloca X em todas as posicoes do corpo da cobra--//
    int i, j;
    for(i=0;i<jogo.TamanhoLinha;i++){
        for(j=0;j<jogo.TamanhoColuna;j++){
            if(jogo.tabuleiro[i][j] == COBRA_CIMA || jogo.tabuleiro[i][j] == COBRA_BAIXO || jogo.tabuleiro[i][j] == COBRA_ESQUERDA || jogo.tabuleiro[i][j] == COBRA_DIREITA || jogo.tabuleiro[i][j] == CORPO){
                jogo.tabuleiro[i][j] = MORREU;
            }
        }
    }
    ImprimeJogo(jogo);
}

void EncerraJogo(int validador, tJogo jogo){
    //validador = 0 -> jogo encerrado porque a cobra morreu.
    //validador = 1 -> jogo encerrado porque o jogo acabou com sucesso.

    //--De acordo com o validador, atualiza os dados necessarios e encerra o jogo--//
    FILE *RESUMO = RetornaResumo(jogo.Arquivos);
    if(validador == 1){
        printf("Voce venceu!\nPontuacao final: %d\n", RetornaPontuacao(jogo.Estatisticas));
        jogo = GeraHeatMap(jogo); 
        ImprimeEstatisticas(jogo);
        ImprimeHeatMap(jogo);
        fclose(RESUMO);
        exit(EXIT_SUCCESS);
    }else{
        int TipoDeBonus = VerificaBonus(RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'L'), RetornaPosicaoCobraAntesMovimento(jogo.Cobra, 'C'), jogo);
        jogo = GeraHeatMap(jogo); 
        jogo = MoveCorpo(jogo);
        MataCobrinha(jogo);

        if(TipoDeBonus == 1){
            jogo.Estatisticas = AtualizaPontuacao(jogo.Estatisticas, DINHEIRO);
        }else if(TipoDeBonus == 2){
            jogo.Estatisticas = AtualizaPontuacao(jogo.Estatisticas, COMIDA);
        }

        fprintf(RESUMO, "Movimento %d (%c) resultou no fim de jogo por conta de colisao\n" ,RetornaNumeroDoMovimento(jogo.Estatisticas), RetornaMovimento(jogo.Estatisticas));
        printf("Game over!\nPontuacao final: %d\n", RetornaPontuacao(jogo.Estatisticas));

        ImprimeEstatisticas(jogo);
        ImprimeHeatMap(jogo);
        fclose(RESUMO);
        exit(EXIT_SUCCESS);
    }
}

//---------------------------------ARQUIVOS----------------------------------------------//

void GeraResumo(int AumentouDinheiro, int AumentouCorpo, tJogo jogo){
    FILE *RESUMO = RetornaResumo(jogo.Arquivos);
    int NumeroDoMovimento = RetornaNumeroDoMovimento(jogo.Estatisticas);
    char mov = RetornaMovimento(jogo.Estatisticas);
    int QtdCorpo = RetornaQtdCorpoCobra(jogo.Estatisticas);
    
    //--Atualiza o resumo do jogo a cada movimento--//
    if(RetornaQtdComida(jogo.Estatisticas) == 0){
        fprintf(RESUMO, "Movimento %d (%c) fez a cobra crescer para o tamanho %d, terminando o jogo\n" ,NumeroDoMovimento, mov, QtdCorpo+1);
    }else if(AumentouCorpo){
        fprintf(RESUMO, "Movimento %d (%c) fez a cobra crescer para o tamanho %d\n" ,NumeroDoMovimento, mov, QtdCorpo+1);
    }else if(AumentouDinheiro){
        fprintf(RESUMO, "Movimento %d (%c) gerou dinheiro\n" ,NumeroDoMovimento, mov);
    } 
}

void ImprimeEstatisticas(tJogo jogo){
    int QtdMovSemPontuar = RetornaQtdMov(jogo.Estatisticas) - RetornaQtdCorpoCobra(jogo.Estatisticas) - RetornaQtdDinheiro(jogo.Estatisticas);
    FILE *ESTATISTICAS = RetornaEstatisticas(jogo.Arquivos);
 
    fprintf(ESTATISTICAS, "Numero de movimentos: %d\nNumero de movimentos sem pontuar: %d\nNumero de movimentos para baixo: %d\nNumero de movimentos para cima: %d\nNumero de movimentos para esquerda: %d\nNumero de movimentos para direita: %d\n", RetornaQtdMov(jogo.Estatisticas), QtdMovSemPontuar, RetornaMovBaixo(jogo.Estatisticas), RetornaMovCima(jogo.Estatisticas), RetornaMovEsquerda(jogo.Estatisticas), RetornaMovDireita(jogo.Estatisticas));

    fclose(ESTATISTICAS);
}

tJogo GeraHeatMap(tJogo jogo){
    //--Gera a matriz das dimensoes do mapa com o num de vezes que a cobra passou pela posicao--//
    int i, j;
    for(i=0;i<jogo.TamanhoLinha;i++){
        for(j=0;j<jogo.TamanhoColuna;j++){
            if(jogo.tabuleiro[i][j] == COBRA_CIMA || jogo.tabuleiro[i][j] == COBRA_BAIXO || jogo.tabuleiro[i][j] == COBRA_ESQUERDA || jogo.tabuleiro[i][j] == COBRA_DIREITA){
                jogo.HeatMap[i][j]++;
            }
        }
    }
    return jogo;
}

void ImprimeHeatMap(tJogo jogo){
    //--Imprime o heatmap no arquivo de saida heatmap.txt--//
    int i, j;
    FILE *HEATMAP = RetornaHeatMap(jogo.Arquivos);

    for(i=0;i<jogo.TamanhoLinha;i++){
        for(j=0;j<jogo.TamanhoColuna;j++){
            fprintf(HEATMAP, "%d", jogo.HeatMap[i][j]);
            if(j != jogo.TamanhoColuna-1){
                fprintf(HEATMAP, " ");
            }
        }
        fprintf(HEATMAP, "\n");
    }
    GeraRanking(jogo);
    fclose(HEATMAP);
}

void GeraRanking(tJogo jogo){
    int i, j, MaiorHeatMap = 0;
    FILE *RANKING = RetornaRanking(jogo.Arquivos);

    //--Varre o heatmap e encontra o maior valor--//
    for(i=0;i<jogo.TamanhoLinha;i++){
        for(j=0;j<jogo.TamanhoColuna;j++){
            if(jogo.HeatMap[i][j] > MaiorHeatMap){
                MaiorHeatMap = jogo.HeatMap[i][j];
            }
        }
    }
    //--Imprime cada posicao do heatmap com o numero de vezes que a cobra passou pela posicao--//
    while(MaiorHeatMap>0){
        for(i=0;i<jogo.TamanhoLinha;i++){
            for(j=0;j<jogo.TamanhoColuna;j++){
                if(jogo.HeatMap[i][j] == MaiorHeatMap){
                    fprintf(RANKING, "(%d, %d) - %d\n", i, j, jogo.HeatMap[i][j]);
                }
            }
        }  
        MaiorHeatMap--;
    }    
    fclose(RANKING);
}
