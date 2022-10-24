#include "ponto.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct tPonto{
    DESTE_TIPO x;
    DESTE_TIPO y;
};

tPonto * CriarPonto(DESTE_TIPO x, DESTE_TIPO y){
    tPonto* p = (tPonto*)malloc(sizeof(tPonto*));
    p->x = x;
    p->y = y;
    return p;
}

void ImprimirPonto(tPonto *p){
    char formato[2] = {'\0', '\0'};
    strcat(formato, DESTE_FORMATO);
    printf("x = ");
    printf(formato, p->x);
    printf("\ny = ");
    printf(formato, p->y);
}

void LiberarPonto(tPonto *p){
    free(p);
}
