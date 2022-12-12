#include "tFiguras.h"
#include <math.h>
#define BASE 10
#define ALTURA 5


void DesenhaRetangulo(){
    Desenha(BASE, ALTURA);    
}


void DesenhaDiamante(){
    int largura = 9, altura = 9;
    int i, j, cont = 1, space = largura;
    
    for(j=0; j<(altura/2)+1;j++){
        for(i = 0; i< (space-cont)/2; i++){
            printf(" ");
        }
        for(i=0; i<cont; i++){
            printf("*");
        }
        for(i = 0; i< (space-cont)/2; i++){
            printf(" ");
        }
        printf("\n");
        cont += 2; 
    }
    
    cont -=4;

    for(j=0; j<(altura/2);j++){
        for(i = 0; i< fabs(space-cont)/2; i++){
            printf(" ");
        }
        for(i=0; i<cont; i++){
            printf("*");
        }
        for(i = 0; i< fabs(space-cont)/2; i++){
            printf(" ");
        }
        printf("\n");
        cont -= 2; 
    }
}

void DesenhaQuadrado(){
    Desenha(BASE, BASE);
}

void Desenha(int base, int altura){
    int i = 0, j = 0;
    for(j=0; j<altura; j++){
        
        for(i=0; i<base*2; i++){
            if((i%2==0 && (j==0 || j == altura-1)) || (!(j==0 || j == altura-1) && (i==0 || i == (base*2)-2))){
                printf("*");
            }else{
                printf(" ");
            }
        }
    printf("\n");
    }
}