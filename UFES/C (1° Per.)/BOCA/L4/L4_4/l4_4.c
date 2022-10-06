#include <stdio.h>

typedef struct{
    int x;
    int y;
}tPonto;

tPonto p;

int IdentificaQuadrante(tPonto p);
void ImprimeDados(tPonto p);
void InvertePonto();
void LePonto();

int main(){

    int QtdPontos = 0, i = 0, quadrante = -1;
    scanf("%i", &QtdPontos);

    for(i=0; i<QtdPontos; ++i){

        LePonto();

        quadrante = IdentificaQuadrante(p);
        ImprimeDados(p);
        printf("%i ", quadrante);

        InvertePonto(p);

        quadrante = IdentificaQuadrante(p);
        ImprimeDados(p);
        printf("%i", quadrante);

        printf("\n");
    }

    return 0;
}

void LePonto(){
    scanf("%i %i", &p.x, &p.y);
}

void ImprimeDados(tPonto p){
    printf("(%i,%i) ", p.x, p.y);
}

void InvertePonto(){
    p.x = -p.x;
    p.y = -p.y;
}

int IdentificaQuadrante(tPonto p){
    if(p.x==0 || p.y==0){
        return 0;
    }
    if(p.x>0 && p.y>0){
        return 1;
    }
    if(p.x<0 && p.y>0){
        return 2;
    }
    if(p.x<0 && p.y<0){
        return 3;
    }
    if(p.x>0 && p.y<0){
        return 4;
    }

    return -1;
}