#ifndef _TTERRENO_H_
#define _TTERRENO_H_
#include "tCirculo.h"
#include "tRetangulo.h"
#include "tTriangulo.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tTerreno tTerreno;


/**
 * @brief Aloca a memória necessária para trabalhar com o tipo tTerreno.
 * 
 * @param qtd tamamnho máximo que a struct vai alocar.
 * @return tTerreno* ponteiro para o endereço de memória alocado para o tipo.
 */
tTerreno* InicializaTerreno(int qtd);


/**
 * @brief Registra um terreno com base no valor selecionado pelo usuário.
 * 
 * @param terreno ponteiro para o acesso do tipo na função.
 * @param tipo tipo de terreno a ser cadastrado.
 * @param base valor da base caso o terreno seja retângulo ou triângulo.
 * @param altura valor da altura caso o terreno seja retângulo ou triângulo.
 * @param raio valor do raio caso o terreno seja circular.
 */
void RegistraTerreno(tTerreno* terreno, char tipo, float base, float altura,float raio);


/**
 * @brief Retorna a área total desmatada dos terrenos.
 * 
 * @param terreno ponteiro que contém as informações dos outros terrenos e da soma do desmatamento.
 * @return float a área total desmatada.
 */
float RetornaAreaTotal(tTerreno* terreno);


/**
 * @brief Calcula e retorna o desvio padrão.
 * 
 * @param terreno ponteiro para acessar os dados da struct.
 * @return float valor do desvio padrão.
 */
float RetornaDesvioPadrao(tTerreno* terreno);


/**
 * @brief Calcula e retorna a média do desmatamento.
 * 
 * @param terreno ponteiro para acessar os dados da struct.
 * @return float desmatamento.
 */
float RetornaMediaDesmatamento(tTerreno* terreno);


/**
 * @brief Libera toda a memória alocada relacionada ao tipo tTerreno.
 * 
 * @param terreno ponteiro do tipo tTerreno.
 */
void LiberaMemoria(tTerreno* terreno);

#endif