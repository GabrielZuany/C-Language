#include <stdio.h>
#include "../libs_h/tArquivos.h"

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