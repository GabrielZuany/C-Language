/*
Calcule em qual Octante tridimensional se encontra determinado ponto dado por coordenadas x y z;
*/

#include <stdio.h>

int main(void){

    float x = 0, y = 0, z = 0;

    scanf("%f %f %f", &x, &y, &z);

    if(x==0 && y==0 && z==0){
        printf("Origem");
    }else if(x>0 && y>0 && z>0){
        printf("1o Octante");
    }else if(x<0 && y>0 && z>0){
        printf("2o Octante");
    }else if(x<0 && y<0 &&z>0){
        printf("3o Octante");
    }else if(x>0 && y<0 && z>0){
        printf("4o Otcante");
    }else if(x>0 && y>0 && z<0){
        printf("5o Octante");
    }else if(x<0 && y>0 && z<0){
        printf("6o Octante");
    }else if(x<0 && y<0 && z<0){
        printf("7o Octante");
    }else{
        printf("8o Octante");
    }

    return 0;
}