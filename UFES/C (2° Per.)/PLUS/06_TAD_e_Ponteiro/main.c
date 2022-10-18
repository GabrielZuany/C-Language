#include <stdio.h>
#include "tCirculo.h"

int main(){

    tCirculo *c;
    float raio;
    InicializaDados(c);
    
    scanf("%f", &raio);
    ValidaDados(c, raio);
    CalculaArea(c);
    ImprimeDados(c);

    return 0;
}