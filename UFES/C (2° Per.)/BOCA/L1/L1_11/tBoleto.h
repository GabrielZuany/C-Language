#ifndef _TBOLETO_
#define _TBOLETO_

typedef struct{
    int cod;
    float valor;
}tBoleto;

tBoleto LeBoleto();
void ImprimirBoleto(tBoleto boleto);
tBoleto MaisCaro(tBoleto boleto1,tBoleto boleto2);
tBoleto MaisBarato(tBoleto boleto1,tBoleto boleto2);
float ValorBoleto(tBoleto boleto);

#endif