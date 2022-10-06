#include <stdio.h>

void LeMatriz(int l, int c, int matriz[l][c]);
void ResetaMatriz(int l, int c, int matriz[l][c]);

int main(){
    int l = 0, c = 0, i = 0, j = 0, cont = 0, qtd = 0;
    scanf("%d %d", &c, &l);
    int matriz[l][c];
    int matrizFinal[l][c];

    ResetaMatriz(l, c, matrizFinal);
    LeMatriz(l, c, matriz);

    for(i=0; i<l; i++){
        for(j=0;j<c;++j){
            if(matriz[i][j]==0 && (matriz[i-1][j-1]==1 || matriz[i-1][j+1]==1 ||matriz[i+1][j-1]==1 || matriz[i+1][j+1]==1 )){   
                qtd++;
            }
        }
    }
    
    printf("%d\n", qtd);
    return 0;
}

//------FUNÇÕES------
void LeMatriz(int l, int c, int matriz[l][c]){
    int i = 0, j = 0;
    for(i=0; i<l; ++i){
        for(j=0 ;j<c; j++){
            scanf("%1i", &matriz[i][j]);
        }
    }
}

void ResetaMatriz(int l, int c, int matriz[l][c]){
    int i = 0, j = 0;

    for(i=0;i<l;++i){
        for(j=0;j<c;++j){
            matriz[i][j] = 1;
        }
    }
}
