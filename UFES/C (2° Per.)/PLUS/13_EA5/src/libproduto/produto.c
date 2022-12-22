
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#define TRUE 1
#define FALSE 0

void produto_le(FILE *file, Produto *produto)
{
    fscanf(file, "%s", produto->nome);
    fscanf(file, "%s", produto->categoria);
    fscanf(file, "%f", &(produto->preco_unitario));
    fscanf(file, "%f", &(produto->custo_unitario));
    fscanf(file, "%d", &(produto->qtd_vendas_ano));
    fscanf(file, "%f", &(produto->pontuacao));
}

void produto_imprime(Produto *produto)
{
    printf("Nome: %s | Categoria: %s | Preco Unit: %.2f | Custo Unit: %.2f | Qtd vendas no ano: %d | Pontuacao: %.2f", produto->nome, produto->categoria, produto->preco_unitario, produto->custo_unitario, produto->qtd_vendas_ano, produto->pontuacao);
     printf(" | Valor Liq: %.2f\n", produto -> lucro_liq);
    printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
}

void ImprimeDados(Produto *produtos, int tamanho_vetor)
{
    int i = 0;
    float valor_bruto_total = 0;
    float valor_liquido_total = 0;
    float custo = 0;
    
    for (i = 0; i < tamanho_vetor; i++)
    {
        valor_bruto_total+= (produtos + i)->qtd_vendas_ano * (produtos + i)->preco_unitario; 

        custo+=(produtos + i)->qtd_vendas_ano * (produtos + i)->custo_unitario;

        (produtos+i) -> lucro_liq = (produtos + i)->qtd_vendas_ano * (produtos + i)->preco_unitario - (produtos + i)->qtd_vendas_ano * (produtos + i)->custo_unitario;

        produto_imprime(produtos+i);
       
    }
    valor_liquido_total = valor_bruto_total-custo;

    Regista_ou_Resgata_Custo(custo, TRUE);
    Regista_ou_Resgata_Bruto(valor_bruto_total, TRUE);
    Regista_ou_Resgata_Liquido(valor_liquido_total, TRUE);
}

int cmp_nome(const void *v1, const void *v2)
{
    Produto *p1 = v1;
    Produto *p2 = v2;
    return strcmp(p1->nome, p2->nome);
}

int cmp_pontuacao(const void *v1, const void *v2)
{
    Produto *p1 = v1;
    Produto *p2 = v2;
    if(p1->pontuacao > p2->pontuacao){
        return 1;
    }return 0;
}

int cmp_preco_venda_uni(const void *v1, const void *v2)
{
    Produto *p1 = v1;
    Produto *p2 = v2;
    if(p1->preco_unitario > p2->preco_unitario){
        return 1;
    }return 0;
}

int cmp_lucro_liq(const void *v1, const void *v2)
{
    Produto *p1 = v1;
    Produto *p2 = v2;
    if(p1->lucro_liq > p2->lucro_liq){
        return 1;
    }return 0;
}

float Regista_ou_Resgata_Custo(float valor, int op){
    static float custo = 0;
    if(op == TRUE){
        custo = valor;
    }
    return custo;
}

float Regista_ou_Resgata_Liquido(float valor, int op){
    static float liq = 0;
    if(op == TRUE){
        liq = valor;
    }
    return liq;
}

float Regista_ou_Resgata_Bruto(float valor, int op){
    static float brt = 0;
    if(op == TRUE){
        brt = valor;
    }
    return brt;
}

int igual(const void *v1, const void *v2)
{
    Produto *p1 = v1;
    Produto *p2 = v2;
    if(strcmp(p1->categoria, p2->categoria) == 0) return 0;
    return 1;
}

void OrdenaPorNome(Produto *produtos, int tamanho_vetor)
{
    qsort(produtos, tamanho_vetor, sizeof(Produto), cmp_nome);
}

void OrdenaPorPontuacao(Produto *produtos, int tamanho_vetor)
{
    qsort(produtos, tamanho_vetor, sizeof(Produto), cmp_pontuacao);
}

void OrdenaPorPrecoVendaUnitario(Produto *produtos, int tamanho_vetor)
{
    qsort(produtos, tamanho_vetor, sizeof(Produto), cmp_preco_venda_uni);
}

void OrdenaPorLucroTotalLiquido(Produto *produtos, int tamanho_vetor)
{
    qsort(produtos, tamanho_vetor, sizeof(Produto), cmp_lucro_liq);
}

void ImprimeItensDaCategoria(Produto *produtos, int tamanho_vetor)
{   
    for(int i = 0; i < tamanho_vetor; i++){
       qsort(produtos, tamanho_vetor, sizeof(Produto), igual); 
    }
    ImprimeDados(produtos, tamanho_vetor);
}

void ImprimeValores(Produto *produtos, int tamanho_vetor)
{
    float custo = Regista_ou_Resgata_Custo(0, FALSE);
    float brt = Regista_ou_Resgata_Bruto(0, FALSE);
    float liq = Regista_ou_Resgata_Liquido(0, FALSE);
    printf("Custos totais de producao: %.2f\nLucro bruto: %.2f\nLucro liquido: %.2f\n-----\n", custo, brt, liq);
}