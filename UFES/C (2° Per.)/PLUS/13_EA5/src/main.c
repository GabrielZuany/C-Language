#include <stdio.h>
#include <stdlib.h>
#include "libproduto/produto.h"
#include "libproduto/operacoes_produtos.h"

Produto *le_vetor_produtos(const char *caminho_arquivo, int *qtd_produtos)
{
    // TODO: alocar vetor de produtos e ler os dados do arquivo
    FILE *f = fopen(caminho_arquivo, "r");
    fscanf(f, "%d", qtd_produtos);
    fscanf(f, "%*c");

    Produto *p = malloc(sizeof(Produto) * *(qtd_produtos));
    int i;
    for(i=0; i< *qtd_produtos; i++){
        produto_le(f, (p+i));
    }

    return p;
}

int main(int argc, char *argv[])
{ 
    
    if (argc < 2)
    {
        printf("Usar ./main  nome_arquivo_produto.txt\n");
        exit(1);
    }
    
    int qtd_produtos;
    Produto *produtos = le_vetor_produtos(argv[1], &qtd_produtos);

    dispatch_table_inicializa();
    // ordena os produtos por nome e exibe a lista na tela
    printf("\nProdutos ordenados por nome:\n");
    filtro('n', produtos, qtd_produtos);
    filtro('i', produtos, qtd_produtos);

    // ordena os produtos por pontuacao e exibe a lista na tela
    printf("\nProdutos ordenados por pontuacao:\n");
    filtro('p', produtos, qtd_produtos);
    filtro('i', produtos, qtd_produtos);

    // ordena os produtos por preço de venda unitário e exibe a lista na tela
    printf("\nProdutos ordenados por preco de venda:\n");
    filtro('v', produtos, qtd_produtos);
    filtro('i', produtos, qtd_produtos);

    // ordena os produtos por lucro total liquido e exibe a lista na tela
    printf("\nProdutos ordenados por lucro total liquido:\n");
    filtro('l', produtos, qtd_produtos);
    filtro('i', produtos, qtd_produtos);

    // solicita que o usuario digite uma categoria e mostra a lista de produtos daquela categoria na tela
    printf("\nProdutos por categoria:\n");
    filtro('f', produtos, qtd_produtos);

    // exibe na tela o relatorio contendo as somas de custos e lucros (brutos e liquidos) de todos os produtos.
    printf("\nRelatório de valores totais considerando todos os produtos:\n");
    filtro('s', produtos, qtd_produtos);

    free(produtos);
    return 0;
}