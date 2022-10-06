#ifndef _TPONTO_
#define _TPONTO_

typedef struct{
    int x;
    int y;
}tPonto;

tPonto LeCoordenada();
void ImprimeQuadrante(tPonto coordenada);
void ImprimeCoordenadas(tPonto coordenada);
tPonto RetornaSimetrico(tPonto coordenada);
float CalculaDistancia(tPonto p1, tPonto p2);

#endif