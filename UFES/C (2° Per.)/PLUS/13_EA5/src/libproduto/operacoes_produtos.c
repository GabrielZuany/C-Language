#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include "operacoes_produtos.h"

static vetor_produto_fn dispatch_table[256];

// TODO: definicao das funcoes da tabela

void dispatch_table_inicializa()
{
    // apenas para sabermos quais funcoes nao foram definidas ainda
    for (int i = 0; i < 256; i++)
        dispatch_table[i] = NULL;

    // TODO: adicionar funcoes...
    dispatch_table['i'] = ImprimeDados;
    dispatch_table['n'] = OrdenaPorNome;
    dispatch_table['p'] = OrdenaPorPontuacao;
    dispatch_table['v'] = OrdenaPorPrecoVendaUnitario;
    dispatch_table['l'] = OrdenaPorLucroTotalLiquido;
    dispatch_table['f'] = ImprimeItensDaCategoria;
    dispatch_table['s'] = ImprimeValores;
}

static void dispatch_table_executa(char operacao, Produto *produtos, int tamanho_vetor)
{
    int idx = (int)operacao;

    if (dispatch_table[idx] != NULL)
        dispatch_table[idx](produtos, tamanho_vetor);
    else
        printf(">> ERRO: A funcao '%c' nao foi definida ainda.\n", operacao);
}


void filtro(char operacao, Produto *produtos, int tamanho_vetor)
{
    dispatch_table_executa(operacao, produtos, tamanho_vetor);
}