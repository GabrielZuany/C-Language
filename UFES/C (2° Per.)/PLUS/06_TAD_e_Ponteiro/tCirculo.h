#ifndef  _TCIRCULO_H_
#define _TCIRCULO_H_

typedef struct tCirculo tCirculo;

void InicializaDados(tCirculo *c);
void CalculaArea(tCirculo *c);
void ImprimeDados(tCirculo  *c);
void ValidaDados(tCirculo *c, float raio);

#endif