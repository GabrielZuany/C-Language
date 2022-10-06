#include <stdio.h>
#include <math.h>
 
int main(void){

    float a = 0, b = 0, c = 0, d = 0, y3 = 0;
    int x = 0, e = 0, f = 0, pico = -32767, vale = +32767;
    int maiorPonto = -32000, menorPonto = +32000;
    
    scanf("%f %f %f %f", &a, &b, &c, &d);
    scanf("%i %i", &e, &f);

    for(x=e; x<=f; ++x){

        y3 = a*pow(x,3) + b*pow(x,2) + c*pow(x,1) + d;

        if((y3>a*pow(x+1,3) + b*pow(x+1,2) + c*pow(x+1,1) + d) && (y3>a*pow(x-1,3) + b*pow(x-1,2) + c*pow(x-1,1) + d)){
            maiorPonto=y3;
            pico = x;
        }
        if((y3<a*pow(x+1,3) + b*pow(x+1,2) + c*pow(x+1,1) + d) && (y3<a*pow(x-1,3) + b*pow(x-1,2) + c*pow(x-1,1) + d)){
            menorPonto = y3;
            vale = x;
        }
    }
    if(pico>=e && pico<=f && vale>=e && vale<=f ){
        if(pico<vale){
            printf("Pico em x=%i\nVale em x=%i\n", pico, vale);
        }else printf("Vale em x=%i\nPico em x=%i\n", vale, pico);
        

    }else if (pico>=e && pico<=f && vale==+32767){

        printf("Pico em x=%i\nNao ha vale\n", pico);

    }else if (pico==-32767 && vale>=e && vale<=f){
         
        printf("Vale em x=%i\nNao ha pico\n", vale);

    }else printf("Nao ha pico\nNao ha vale");
    
    

    return 0;
}
