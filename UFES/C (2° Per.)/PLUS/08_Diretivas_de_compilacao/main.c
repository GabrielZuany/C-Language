#include "ponto.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    tPonto* p;
    p = CriarPonto(4, 5);
    ImprimirPonto(p);
    LiberarPonto(p);

    return 0;
}