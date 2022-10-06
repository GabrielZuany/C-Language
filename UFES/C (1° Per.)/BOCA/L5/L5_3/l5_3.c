#include <stdio.h>
#include <math.h>

int CalculaDiferenca(int altura[], int qtd){
    int i = 0, dif = 0, MaiorDif = -1, marcador_1 = 0;

    altura[qtd] = altura[qtd-1];

    for(i=0; i<qtd; ++i){
        if(i+1>qtd){
            break;
        }
        dif = fabs(altura[i]-altura[i+1]);

        if(dif>MaiorDif){
            MaiorDif = dif;
        }
    }

    return MaiorDif;
}

void ImprimeMaior(int altura[], int qtd, int MaiorDif){
    int i = 0, dif = 0, control = 0;

    for(i=0; i<qtd-1; ++i){
        if(i+1>qtd){
            break;
        }
        dif =  fabs(altura[i]-altura[i+1]);

        if(dif==MaiorDif){
            printf(" (%i %i)", i, i+1);
            control = 1;
        }
    }

    if(control==0){
        printf("IMPOSSIVEL");
    }
}

int main(void){
    
    int qtd = 0, i = 0, MaiorDif = -1;

    scanf("%i", &qtd);

    int altura[qtd];

    for(i=0; i<qtd; ++i){
        scanf("%i", &altura[i]);
    }

    MaiorDif = CalculaDiferenca(altura, qtd);
    ImprimeMaior(altura, qtd, MaiorDif);

    return 0;
}