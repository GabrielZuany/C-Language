#include <stdio.h>
#include <math.h>

typedef struct{
    int x;
    int y;
}tPonto;

tPonto p1, p2;

float CalculaDistanciaP1P2(tPonto p1, tPonto p2){
    return sqrt( pow((p1.x-p2.x), 2) + pow((p1.y-p2.y), 2)  );
}

void LePonto(){
    scanf("%i %i", &p1.x, &p1.y);
}

int main(){

    int QtdPontos = 0, i = 0;
    float dist = 0;

    scanf("%i", &QtdPontos);

    for(i=0; i<QtdPontos; ++i){

        LePonto();

        if(i==0){
            printf("-\n");
            p2 = p1;
            continue;
        }

        dist = CalculaDistanciaP1P2(p1, p2);

        p2 = p1;
        printf("%.2f\n", dist);
    }

    return 0;
}