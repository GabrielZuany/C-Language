
#ifndef _DISPATCH_TABLE_
#define _DISPATCH_TABLE_

#include "produto.h"

typedef void (*vetor_produto_fn)(Produto *produtos, int tamanho_vetor);

void dispatch_table_inicializa();

void filtro(char operacao, Produto *produtos, int tamanho_vetor);

#endif