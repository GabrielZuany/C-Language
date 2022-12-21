#ifndef TGEOMETRICA_H
#define TGEOMETRICA_H

#include "tPonto.h"
#include "tCirculo.h"
#include "tRetangulo.h"
#include "tQuadrado.h"
#include "tTriangulo.h"

typedef float (*fptrArea)(void *);

float area(fptrArea forma, void *x);

/* Dado um caracter - retorna a função de area */
fptrArea selecionaFuncao(char code);
/* Utiliza a função anterior para selecionar a função que vai calcular a área */
float  calcularArea(char code, void *x);

/**  NAO IMPLEMENTAR HOJE ***/

/* Inicializa uma tabela de disperção - necessário criar este array antes */
void inicializaTabelaFuncoes();

/* Obtem a função da tabela de disperção e  retorna o resultado desta função */
float calcularAreaTabela(char code, void *x);



#endif