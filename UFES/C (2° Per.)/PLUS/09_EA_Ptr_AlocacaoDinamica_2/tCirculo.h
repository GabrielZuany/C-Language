#ifndef _TCIRCULO_H_
#define _TCIRCULO_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct tCirculo tCirculo;


/**
 * @brief Aloca a memória necessária para manipular o vetor de ponteiros (a.k.a ponteiro de ponteiro) tipo tCirculo;
 * 
 * @param qtd tamanho do vetor de ponteiros.
 * @return tCirculo** o endereço de memória do ponteiro duplo após a alocação de memória.
 */
tCirculo** InicializaMemoriaCirculo(int qtd);


/**
 * @brief Calcula e retorna o cálculo da área do círculo.
 * 
 * @param circulo ponteiro para a struct tCirculo circulo.
 * @return float a área cálculada;
 */
float CalculaAreaCirculo(tCirculo* circulo);


/**
 * @brief Cria um ponteiro e aloca a memória necessária registrando os dados passados.
 * 
 * @param raio valor do raio dado pelo usuário.
 * @return tCirculo* ponteiro para a struct.
 */
tCirculo* RegistraCirculo(float raio);


/**
 * @brief Retorna a área do círculo dado um círculo[pos];
 * 
 * @param c ponteiro do tipo que eu quero pegar o valor.
 * @return float valor desejado.
 */
float RetornaAreaCirculoPos(tCirculo*c);


/**
 * @brief Libera toda a memória alocada relacionada ao tipo tCirculo.
 * 
 * @param c ponteiro dos ponteiros do tipo tCirculo.
 * @param qtd numero de elementos do ponteiro de ponteiro (tamanho do array de ponteiros).
 */
void LiberaCirculo(tCirculo **c, int qtd);

#endif