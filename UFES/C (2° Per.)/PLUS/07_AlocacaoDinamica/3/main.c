#include <stdio.h>
#include <stdlib.h>
//Defina e implemente TrocaInterios
int TrocaInteiros(int* a, int* b);

int main(){
    int n1, n2;
    
    while ( scanf("%d %d", &n1, &n2) == 2 ){

        if(TrocaInteiros(&n1, &n2)){
            
            printf("TROCADO: %d %d\n", n1, n2);
        } else {
            printf("ORIGINAL: %d %d\n", n1, n2);
        }
    }

    return 0;
}

int TrocaInteiros(int* a, int* b){
    if(*a > *b){
        int aux = *a;
        *a = *b;
        *b = aux;   
        return 1;
    }
    return 0; 
}