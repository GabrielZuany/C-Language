#include <stdio.h>

void LeMatriz(int l, int c, int matriz[l][c]);
void ImprimeMatriz(int l, int c, int matriz[l][c]);
void IncrementaMatriz(int i, int j, int matriz[i][j], int l, int c);
int ContaPos(int l, int c, int matriz[l][c]);
void ResetaMatriz(int l, int c, int matriz[l][c]);
void AtualizaMatriz(int l, int c, int matriz[l][c], int matriz_fim[l][c]);

int main(){
    int l = 0, c = 0, horas = 0, i = 0, j = 0, cont = 0, qtd = 0, Acum = 0;
    scanf("%i", &horas);
    scanf("%i %i", &c, &l);
    int matriz[l][c];
    int matrizFinal[l][c];

    ResetaMatriz(l, c, matrizFinal);
    LeMatriz(l, c, matriz);
    cont = ContaPos(l, c, matriz);//quantidade de terra inicialmente
    //ImprimeMatriz(l, c, matriz);

    while (Acum<horas){
        
        qtd = 0;

        for(i=0; i<l; i++){

            for(j=0;j<c;++j){
                if(matriz[i][j]==0 && matriz[i+1][j]==0 && matriz[i-1][j]==0 && matriz[i][j+1]==0 && matriz[i][j-1]==0){   
                    matrizFinal[i][j] = 0;
                    qtd++;
                }
            }

        }
        Acum++;//soma horas
        AtualizaMatriz(l, c, matriz, matrizFinal);
        ResetaMatriz(l, c, matrizFinal);
    }
    
    //printf("\n\n");
    //ImprimeMatriz(l, c, matrizFinal);
    printf("%i %i\n", cont, qtd);
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

void ImprimeMatriz(int l, int c, int matriz[l][c]){
    int i = 0, j = 0;
    for(i=0; i<l; ++i){
        for(j=0 ;j<c; j++){
            printf("%i", matriz[i][j]);
        }
        printf("\n");
    }
}

int ContaPos(int l, int c, int matriz[l][c]){
    int i = 0, j = 0, cont = 0;
    for(i=0; i<l; ++i){
        for(j=0 ;j<c; j++){
            if(matriz[i][j]==0){
                cont++;
            }
        }
    }
    return cont;
}

void ResetaMatriz(int l, int c, int matriz[l][c]){
    int i = 0, j = 0;

    for(i=0;i<l;++i){
        for(j=0;j<c;++j){
            matriz[i][j] = 1;
        }
    }
}

void AtualizaMatriz(int l, int c, int matriz[l][c], int matriz_fim[l][c]){
    int i = 0, j = 0;

    for(i=0;i<l;++i){
        for(j=0;j<c;++j){
            matriz[i][j] = matriz_fim[i][j];
        }
    }
}