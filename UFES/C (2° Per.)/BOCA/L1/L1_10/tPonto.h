#ifndef _TPONTO_
#define _TPONTO_

typedef struct {
    int x;
    int y;
}tPonto;

tPonto LePonto();
float Distancia(tPonto p1,tPonto p2);
void ImprimirPonto(tPonto p);
int MaisProximo(float d1,float d2);

#endif