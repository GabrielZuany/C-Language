#ifndef _TCONTA_H_
#define _TCONTA_H_

#include "tUsuario.h"

typedef struct tConta tConta;

/**
 * @brief Registra conta com os dados do usuário;
 * 
 * @param usuario ponteiro da struct a ser escrita.
 * @param conta ponteiro da struct a ser escrita.
 */
void CriaConta(tUsuario *usuario, tConta *conta);

/**
 * @brief Realiza saque caso haja saldo.
 * 
 * @param conta ponteiro para a struct.
 * @param valor valor a ser sacado.
 */
void Saque(tConta* conta, float valor);

/**
 * @brief Realiza depósito na conta.
 * 
 * @param conta ponteiro para a struct.
 * @param valor valor a ser sacado.
 */
void Deposito(tConta* conta, float valor);

/**
 * @brief Encerra o programa.
 * 
 */
void Sair();

/**
 * @brief Inicializa conta com valores genéricos.
 * 
 * @return tConta* ponteiro para a struct.
 */
tConta* InicializaConta();

/**
 * @brief Imprime saldo final após operações.
 * 
 * @param conta ponteiro para a conta.
 */
void ImprimeSaldo(tConta *conta);

/**
 * @brief Imprime dados da conta.
 * 
 * @param conta ponteiro para a struct.
 */
void ImprimeConta(tConta* conta);

/**
 * @brief Realiza as operações enquanto não for digitado o valor 0.
 * 
 * @param conta ponteiro para a struct.
 */
void FazOperacao(tConta* conta);

#endif