#include "usuario.h"

typedef struct conta Conta;

Conta* CriaConta(Usuario* usuario,int agencia, int nConta);

Usuario* RecuperaUsuario(Conta* conta);

int RecuperaAgencia(Conta* conta);

int RecuperaNConta(Conta* conta);

float RecuperaSaldo(Conta* conta);

float Saque(Conta* conta,float valor);

void Deposito(Conta* conta,float valor);

void DestroiConta(Conta* conta);

void InterfaceConta(Conta* c);