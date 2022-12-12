#include <stdio.h>
#include <stdlib.h>
#include "tFiguras.h"
typedef void (*funcao_desenha)(void);

int main(){
    funcao_desenha f;
    char op;

    scanf("%c", &op);
    switch (op)
    {
    case 'R':
        f = DesenhaRetangulo;
        break;
    case 'Q':
        f = DesenhaQuadrado;
        break;
    case 'D':
        f = DesenhaDiamante;
        break;
    default:
        break;
    }

    f();
    return 0;
}