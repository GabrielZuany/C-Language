
#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <stdio.h>

typedef struct
{
    char nome[64];
    char categoria[64];
    float preco_unitario;
    float custo_unitario;
    int qtd_vendas_ano;
    float pontuacao;
    float lucro_liq;
} Produto;

void produto_le(FILE *file, Produto *produto);
void produto_imprime(Produto *produto);

// TODO: funcoes de comparacao de produtos para utilizacao no qsort
void ImprimeDados(Produto* produtos, int tamanho_vetor);
void OrdenaPorNome(Produto* produtos, int tamanho_vetor);
void OrdenaPorPontuacao(Produto* produtos, int tamanho_vetor);
void OrdenaPorPrecoVendaUnitario(Produto* produtos, int tamanho_vetor);
void OrdenaPorLucroTotalLiquido(Produto* produtos, int tamanho_vetor);
void ImprimeItensDaCategoria(Produto* produtos, int tamanho_vetor);
void ImprimeValores(Produto* produtos, int tamanho_vetor);
int igual(const void *v1, const void *v2);
int cmp_nome(const void *v1, const void *v2);
int cmp_pontuacao(const void *v1, const void *v2);
int cmp_lucro_liq(const void *v1, const void *v2);
int cmp_preco_venda_uni(const void *v1, const void *v2);
float Regista_ou_Resgata_Custo(float valor, int op);
float Regista_ou_Resgata_Liquido(float valor, int op);
float Regista_ou_Resgata_Bruto(float valor, int op);

#endif