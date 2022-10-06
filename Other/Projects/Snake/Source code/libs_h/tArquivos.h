#ifndef _TARQUIVOS_H_
#define _TARQUIVOS_H_

#define COBRA '>'
#define COBRA_DIREITA '>'
#define COBRA_CIMA '^'
#define COBRA_BAIXO 'v'
#define COBRA_ESQUERDA '<'

//--Definição de tipo de dados--//
typedef struct {
    FILE *Resumo;
    FILE *Heatmap;
    FILE *Ranking;
    FILE *Estatisticas;
}tArquivos;

FILE *RetornaArquivoAberto(char Caminho[]);
tArquivos AbreArquivos(char CaminhoResumo[], char CaminhoEstatisticas[], char CaminhoHeatMap[], char CaminhoRanking[]);
tArquivos AbreArquivos(char CaminhoResumo[], char CaminhoEstatisticas[], char CaminhoHeatMap[], char CaminhoRanking[]);
FILE *RetornaArquivoAberto(char Caminho[]);
FILE *RetornaHeatMap(tArquivos jogoArquivo);
FILE *RetornaRanking(tArquivos jogoArquivo);
FILE *RetornaResumo(tArquivos jogoArquivo);
FILE *RetornaEstatisticas(tArquivos jogoArquivo);

#endif