#ifndef _TRETANGULO_H_
#define _TRETANGULO_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct tRetangulo tRetangulo;


/**
 * @brief Retorna a área do retângulo dado um retângulo[pos];
 * 
 * @param c ponteiro do tipo que eu quero pegar o valor.
 * @return float valor desejado.
 */
float RetornaAreaRetanguloPos(tRetangulo* r);


/**
 * @brief Aloca a memória necessária para manipular o vetor de ponteiros (a.k.a ponteiro de ponteiro) tipo tRetangulo;
 * 
 * @param qtd tamanho do vetor de ponteiros.
 * @return tRetangulo** o endereço de memória do ponteiro duplo após a alocação de memória.
 */
tRetangulo** InicializaMemoriaRetangulo(int qtd);


/**
 * @brief Calcula e retorna o cálculo da área do retângulo.
 * 
 * @param circulo ponteiro para a struct tTriangulo retângulo.
 * @return float a área cálculada;
 */
float CalculaAreaRetangulo(tRetangulo *retangulo);


/**
 * @brief Cria um ponteiro e aloca a memória necessária registrando os dados passados.
 * 
 * @param raio valor do raio dado pelo usuário.
 * @return tRetangulo* ponteiro para a struct.
 */
tRetangulo* RegistraRetangulo(float base, float altura);


/**
 * @brief Libera toda a memória alocada relacionada ao tipo tRetangulo.
 * 
 * @param r ponteiro dos ponteiros do tipo tRetangulo.
 * @param qtd numero de elementos do ponteiro de ponteiro (tamanho do array de ponteiros).
 */
void LiberaRetangulo(tRetangulo **r, int qtd);

#endif