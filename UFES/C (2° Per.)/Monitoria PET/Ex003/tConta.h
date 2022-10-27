#ifndef _TCONTA_H_
#define _TCONTA_H_

#include "tUsuario.h"

typedef struct tConta tConta;

tConta** InicializaMemoria(int init);

void ImprimeRelatorio(tConta **conta, int qtd);

void DeletaConta(tConta **conta, int num);

void CriaConta(tUsuario *usuario, tConta *conta);

int Saque(tConta* conta, float valor);

void Deposito(tConta* conta, float valor);

void Transferencia(tConta *dest, tConta *orig, float valor);

void Sair();

tConta* InicializaConta(int num_conta, tUsuario* usuario);

void ImprimeSaldo(tConta *conta);

void FazOperacao(tConta* conta);

#endif