#include <stdio.h>

//----GLOBAIS---------
int L1 = 0, C1 = 0, L2 = 0, C2 = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
int pos_l = 0, pos_c = 0, soma = 0;
//--------------------

//----FUNÇÕES---------
void ResetaMatriz(int l, int c, int matriz[l][c]);
void LeMatriz(int l, int c, int matriz[l][c]);
void ImprimeMatriz(int l, int c, int matriz[l][c]);
void ResetaParametros();
void MultiplicaMatriz(int l1, int c1, int l2, int c2, int matriz_1[l1][c1], int matriz_2[l2][c2], int matriz_resultado[l1][c2]);
//--------------------

int main(){

    int  pares = 0, cont = 0, i = 0, j = 0;
    scanf("%i", &pares);

    for(cont = 0; cont<pares; ++cont){

        scanf("%i %i", &C1, &L1);//tamanho da matriz 1
        int matriz_1[L1][C1];
        LeMatriz(L1, C1, matriz_1);

        scanf("%i %i", &C2, &L2);//tamanho da matriz 2
        int matriz_2[L2][C2];
        LeMatriz(L2, C2, matriz_2);
        
        int matriz_resultado[L1][C2];
        ResetaMatriz(L1, C2,matriz_resultado);

        MultiplicaMatriz(L1, C1, L2, C2, matriz_1, matriz_2, matriz_resultado);

        ImprimeMatriz(L1, C2, matriz_resultado);
        ResetaParametros();

        printf("\n");
    }
    return 0;
}
//------------------FUNÇÕES----------------

void LeMatriz(int l, int c, int matriz[l][c]){
    int i = 0, j = 0;
    for(i=0;i<l;i++){
        for(j=0;j<c;++j){
            scanf("%i", &matriz[i][j]);
        }
    }
}

void ResetaMatriz(int l, int c, int matriz[l][c]){
    int i = 0, j = 0;

    for(i=0;i<l;++i){
        for(j=0;j<c;++j){
            matriz[i][j] = 0;
        }
    }
}

void ResetaParametros(){
    x1 = 0, x2 = 0, y1 = 0, y2 = 0, pos_l = 0, pos_c = 0, soma = 0;
}

void ImprimeMatriz(int l, int c, int matriz[l][c]){
    int i = 0, j = 0;

    if(L2==C1){
        for(i=0; i<L1;++i){
            for(j=0;j<C2;++j){
                printf("%i ", matriz[i][j]);
            }
            printf("\n");
        } 
    }else{
        printf("IMPOSSIVEL\n");
    }
}

void MultiplicaMatriz(int l1, int c1, int l2, int c2, int matriz_1[l1][c1], int matriz_2[l2][c2], int matriz_resultado[l1][c2]){
    while(x1<L1 && y2<C2){
        y1 = 0;
        while(x2<L2){
            soma += matriz_1[x1][y1]*matriz_2[x2][y2];
            y1++;
            x2++;
        }
        
        
        if(pos_c<C2){
            if(pos_l>0 && pos_c+1<C2){
                pos_c++;
            }
            matriz_resultado[pos_l][pos_c] = soma;
            soma = 0;
            ++pos_c;
        }else{
            pos_c = 0;
            pos_l++;
            matriz_resultado[pos_l][pos_c] = soma;
            soma = 0;
        }

        x2 = 0;
        y2++;

        if(y2==C2){
            y2 = 0;
            x1++;
        }
    }
}