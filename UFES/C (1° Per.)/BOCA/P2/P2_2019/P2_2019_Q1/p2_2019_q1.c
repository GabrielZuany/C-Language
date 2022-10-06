#include <stdio.h>

int main(void){

    int ValorTipo_1 = 0, ValorTipo_2 = 0, ValorTipo_3 = 0;
    int NumeroFolhas = 0, T1 = 0, T2 = 0, T3 = 0, tipo = 0;
    int i = 0, Soma = 0;

    scanf("%i %i %i", &ValorTipo_1, &ValorTipo_2, &ValorTipo_3);
    scanf("%i", &NumeroFolhas);

    for(i=1; i<=NumeroFolhas; ++i){

        scanf("%i", &tipo);

        if(tipo==1){
            T1++;
        }else if(tipo==2){
            T2++;
        }else if(tipo==3){
            T3++;
        }
        
    }
    
    Soma = T1*ValorTipo_1 + T2*ValorTipo_2 + T3*ValorTipo_3;
    printf("CUSTO:%i\n", Soma);

    return 0;
}