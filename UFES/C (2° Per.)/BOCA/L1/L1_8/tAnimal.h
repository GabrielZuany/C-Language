#ifndef _TANIMAL_
#define _TANIMAL_

typedef struct{
    long double peso;
    long double nAnimais;
    long double valorRacao;
    long double prctPeso;
}tAnimal;

tAnimal LeAnimal();
float QtdRacao(tAnimal animal);
float CalcularPreco(float qtdRacao, tAnimal animal);

#endif
