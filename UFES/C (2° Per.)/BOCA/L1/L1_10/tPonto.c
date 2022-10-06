#include "tPonto.h"
#include <stdio.h>
#include <math.h>

tPonto LePonto(){
    tPonto p;
    scanf("%d %d", &p.x, &p.y);
    return p;
}

float Distancia(tPonto p1,tPonto p2){
    return sqrt(pow((p1.x-p2.x), 2)+pow((p1.y-p2.y), 2));
}

void ImprimirPonto(tPonto p){
    printf("(%d,%d)", p.x, p.y);
}

int MaisProximo(float d,float menor){
    if(d<menor) return 1;
    return 0;
}