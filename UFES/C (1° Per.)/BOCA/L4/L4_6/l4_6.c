#include <stdio.h>
#include <math.h>

typedef struct{
    int x;
    int y;
}tPonto;

typedef struct{
    int x1;
    int y1;
    int x2;
    int y2;
}tReta;

tPonto p1;
tReta r1;

float CalculaDistanciaInicio(tPonto p1, tReta r1){
    return sqrt( pow((p1.x-r1.x1), 2) + pow((p1.y-r1.y1), 2)  );
}

float CalculaDistanciaFim(tPonto p1, tReta r1){
    return sqrt( pow((p1.x-r1.x2), 2) + pow((p1.y-r1.y2), 2)  );
}

void LePonto(){
    scanf("%i %i %i %i %i %i", &p1.x, &p1.y, &r1.x1, &r1.y1, &r1.x2, &r1.y2);
}

int main(){

    int QtdPontos = 0, i = 0;
    float Inicio = 0, Fim = 0;

    scanf("%i", &QtdPontos);

    for(i=0; i<QtdPontos; ++i){

        LePonto();

        Inicio = CalculaDistanciaInicio(p1, r1);
        Fim = CalculaDistanciaFim(p1, r1);

        if(Inicio==Fim){
            printf("EQUIDISTANTE\n");
        }
        if(Inicio>Fim){
            printf("FIM\n");
        }
        if(Inicio<Fim){
            printf("INICIO\n");
        }

    }

    return 0;
}