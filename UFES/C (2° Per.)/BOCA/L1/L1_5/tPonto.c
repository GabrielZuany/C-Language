#include <stdio.h>
#include <math.h>
#include "tPonto.h"

tPonto LeCoordenada(){
    int x, y;
    scanf("%d %d", &x, &y);
    tPonto coord = {x, y};
    return coord;
}

void ImprimeQuadrante(tPonto coordenada){
    int x = coordenada.x, y = coordenada.y;
    if(x==0||y==0){
        printf("0 ");
    }else if(x > 0){
        if(y>0){
          printf("1 ");  
        }else{
            printf("4 ");
        }
    }else if(x<0 ){
        if(y>0){
         printf("2 ");   
        }else{
            printf("3 ");
        }
    }
}

void ImprimeCoordenadas(tPonto coordenada){
    printf("(%d,%d) ", coordenada.x, coordenada.y); 
}

tPonto RetornaSimetrico(tPonto coordenada){
    coordenada.x*=-1;
    coordenada.y*=-1;
    return coordenada;
}

float CalculaDistancia(tPonto p1, tPonto p2){
    float d =  sqrt((pow((p1.x - p2.x), 2) + pow((p1.y-p2.y), 2)));
    return d;
}
