#include <stdio.h>

typedef struct{
    int x1;
    int y1;
    int x2;
    int y2;
}tReta;

tReta r1;

int IdentificaQuadrante1(tReta r1);
int IdentificaQuadrante2(tReta r2);
void LePonto();

int main(void){

    int QtdPontos = 0, i = 0, Q1 = 0, Q2 = 0;

    scanf("%i", &QtdPontos);

    for(i=0; i<QtdPontos; ++i){

        LePonto();

        Q1 = IdentificaQuadrante1(r1);
        Q2 = IdentificaQuadrante2(r1);

        if(Q1 == Q2 && Q1!=0 && Q2!=0){
            printf("MESMO\n");
        }else printf("DIFERENTE\n");

    }

    return 0;
}

void LePonto(){

    scanf("%i %i %i %i", &r1.x1, &r1.y1, &r1.x2, &r1.y2);

}

int IdentificaQuadrante1(tReta r1){
    if(r1.x1==0 || r1.y1==0){
        return 0;
    }
    if(r1.x1>0 && r1.y1>0){
        return 1;
    }
    if(r1.x1<0 && r1.y1>0){
        return 2;
    }
    if(r1.x1<0 && r1.y1<0){
        return 3;
    }
    if(r1.x1>0 && r1.y1<0){
        return 4;
    }

    return -1;
}

int IdentificaQuadrante2(tReta r2){
    if(r2.x2==0 || r2.y2==0){
        return 0;
    }
    if(r2.x2>0 && r2.y2>0){
        return 1;
    }
    if(r2.x2<0 && r2.y2>0){
        return 2;
    }
    if(r2.x2<0 && r2.y2<0){
        return 3;
    }
    if(r2.x2>0 && r2.y2<0){
        return 4;
    }

    return -1;
}