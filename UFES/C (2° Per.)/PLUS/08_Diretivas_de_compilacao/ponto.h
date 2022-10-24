#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED
#define DESTE_TIPO int
#define DESTE_FORMATO "%d"

typedef struct tPonto tPonto;

tPonto * CriarPonto(DESTE_TIPO x, DESTE_TIPO y);
void ImprimirPonto(tPonto *p);
void LiberarPonto(tPonto *p);

#endif