#ifndef _TTRIANGULO_H_
#define _TTRIANGULO_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct tTriangulo tTriangulo;


/**
 * @brief Aloca a memória necessária para manipular o vetor de ponteiros (a.k.a ponteiro de ponteiro) tipo tTriangulo;
 * 
 * @param qtd tamanho do vetor de ponteiros.
 * @return tTriangulo** o endereço de memória do ponteiro duplo após a alocação de memória.
 */
tTriangulo** InicializaMemoriaTriangulo(int qtd);


/**
 * @brief Cria um ponteiro e aloca a memória necessária registrando os dados passados.
 * 
 * @param raio valor do raio dado pelo usuário.
 * @return tTriangulo* ponteiro para a struct.
 */
tTriangulo* RegistraTriangulo(float base, float altura);


/**
 * @brief Calcula e retorna o cálculo da área do triângulo.
 * 
 * @param circulo ponteiro para a struct tTriangulo triângulo.
 * @return float a área cálculada;
 */
float CalculaAreaTriangulo(tTriangulo* triangulo);


/**
 * @brief Retorna a área do triângulo dado um triângulo[pos];
 * 
 * @param c ponteiro do tipo que eu quero pegar o valor.
 * @return float valor desejado.
 */
float RetornaAreaTrianguloPos(tTriangulo* t);


/**
 * @brief Libera toda a memória alocada relacionada ao tipo tTriangulo.
 * 
 * @param t ponteiro dos ponteiros do tipo tTriangulo.
 * @param qtd numero de elementos do ponteiro de ponteiro (tamanho do array de ponteiros).
 */
void LiberaTriangulo(tTriangulo **t, int qtd);

#endif