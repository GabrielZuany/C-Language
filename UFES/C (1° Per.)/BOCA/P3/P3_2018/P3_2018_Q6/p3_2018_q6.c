#include<stdio.h>

int VerificaFalhas(int i, int  j, int Linha_1, int Coluna_1, int Linha_2, int Coluna_2, int placa[Linha_1][Coluna_1], int template[Linha_2][Coluna_2]);

int main(){
    int Linha_1, Linha_2, Coluna_1, Coluna_2;
    scanf("%d %d", &Linha_1, &Coluna_1);
    int placa[Linha_1][Coluna_1];

    int i = 0, j = 0;

    for(i = 0; i < Linha_1; i++){
        for(j = 0; j < Coluna_1; j++){
            scanf("%1d", &placa[i][j]);
        }
    }

    scanf("%d %d", &Linha_2, &Coluna_2);
    int template[Linha_2][Coluna_2];

    for(i=0; i < Linha_2; i++){
        for(j = 0; j < Coluna_2; j++){
            scanf("%1d", &template[i][j]);
        }
    }
    int cont= 0;
    for(i=0; i < Linha_1; i++){
        for(j = 0; j < Coluna_1; j++){
            if(VerificaFalhas(i, j, Linha_1, Coluna_1, Linha_2, Coluna_2, placa, template) == 1){
                cont++;
            }
        }
    }

    printf("RESP:%d", cont);
    
    return 0;
}

int VerificaFalhas(int i, int j, int Linha_1, int Coluna_1, int Linha_2, int Coluna_2, int placa[Linha_1][Coluna_1], int template[Linha_2][Coluna_2]){
    int I = 0, J = 0;
    int cont = 0;
    for(I = 0; I < Linha_2; I++){
        for(J = 0; J < Coluna_2; J++){
            if(placa[I+i][J+j] == template[I][J] && i+I < Linha_1 && j+J < Coluna_1){
                cont++;
            }
        }
    }
    if(cont==Linha_2*Coluna_2){
        return 1;
    }
    return 0;
}

