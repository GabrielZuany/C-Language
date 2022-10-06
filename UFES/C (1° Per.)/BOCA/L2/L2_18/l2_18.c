#include <stdio.h>

int  gMaiorNum = 0, gControlador = 1, i = 0, j=0, gPosLinha = 0, gPosColuna = 0;

void PosicaoMatriz(int num){
    if(gControlador==1){
        gMaiorNum=num;
        gControlador=0;
    }
    if(num>gMaiorNum){
        gMaiorNum=num;
        gPosLinha=i;
        gPosColuna=j;
    }
}

int main(void){

    int linha = 0, coluna = 0, num = 0;

    scanf("%i %i", &linha, &coluna);

    if((linha>=1 && linha<=100)&&(coluna>=1 &&coluna<=100)){

        for(i=0;i<linha;++i){

            for(j=0;j<coluna;++j){
                scanf("%i", &num);
                if(num>=-32767&&num<=32767){
                    PosicaoMatriz(num);
                }else goto fim;
            }
        }
        printf("%i (%i, %i)", gMaiorNum, gPosLinha+1, gPosColuna+1);
    }

    fim:
    return 0;
}