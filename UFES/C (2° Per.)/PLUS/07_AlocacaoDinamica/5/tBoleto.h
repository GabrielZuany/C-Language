#ifndef _TBOLETO_
#define _TBOLETO_

typedef struct tBoleto tBoleto;
void FreeMem(tBoleto *boletos);
void ImprimirBoleto(tBoleto* boleto);
tBoleto* MaisCaro(tBoleto* boleto1,tBoleto* boleto2);
tBoleto* MaisBarato(tBoleto* boleto1,tBoleto* boleto2);
float ValorBoleto(tBoleto* boleto);
tBoleto* RegistraBoleto(int cod, float valor, tBoleto *boleto);
#endif