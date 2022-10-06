#include <stdio.h>

void LeMatriz(int l, int c, int matriz[l][c]);
void VerificaPontos(int linha1, int coluna1, int matriz1[linha1][coluna1], int linha2, int coluna2, int matriz2[linha2][coluna2]);
int CorrespondeTemplate(int linha1, int coluna1, int matriz1[linha1][coluna1], int linha2, int coluna2, int matriz2[linha2][coluna2], int posx, int posy);

int Linha_1 = 0, Coluna_1 = 0, Linha_2 = 0, Coluna_2 = 0;

int main(void){

    scanf("%d %d", &Linha_1, &Coluna_1);
    int matriz_1[Linha_1][Coluna_1];
    LeMatriz(Linha_1, Coluna_1, matriz_1);

    scanf("%d %d", &Linha_2, &Coluna_2);
    int matriz_2[Linha_2][Coluna_2];
    LeMatriz(Linha_2, Coluna_2,matriz_2);
    
    VerificaPontos(Linha_1, Coluna_1, matriz_1, Linha_2, Coluna_2,matriz_2);

    return 0;
}

void LeMatriz(int l, int c, int matriz[l][c]){
    int i = 0, j = 0;
    for(i=0; i<l; ++i){
        for(j=0 ;j<c; j++){
            scanf("%1d", &matriz[i][j]);
        }
    }
}

void VerificaPontos(int linha1, int coluna1, int matriz1[linha1][coluna1], int linha2, int coluna2, int matriz2[linha2][coluna2]){
    int l1=0, c1=0;

    for(l1=0; l1<linha1; ++l1){
        for(c1=0; c1<coluna1; ++c1){
            if(CorrespondeTemplate(linha1, coluna1, matriz1, linha2, coluna2, matriz2, l1, c1)){
                printf("%d,%d\n", c1, l1);
            }
        }
    }
}

int CorrespondeTemplate(int linha1, int coluna1, int matriz1[linha1][coluna1], int linha2, int coluna2, int matriz2[linha2][coluna2], int posx, int posy){
    int l2 = 0, c2 = 0, qtd = 0;
    int l1 = posx, c1 = posy;

    for(l2=0;   l2<Linha_2;       l2++,l1++){
        for(c2=0,c1=posy    ;c2<Coluna_2;       ++c2, c1++){
            if(matriz1[l1][c1]==matriz2[l2][c2]){
                qtd++;  
            }
        }
    }
    if(qtd==Linha_2*Coluna_2){
        return 1;
    }else return 0;

}