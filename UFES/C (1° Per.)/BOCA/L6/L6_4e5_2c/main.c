#include <stdio.h>

typedef struct{
    int id;
    int matriz[6][6];
}tCartela;

tCartela LeCartela();
void ImprimeCartela(tCartela cartela);
int tam = 0;

int main(){

    tCartela cartela; 

    cartela = LeCartela(); 

    ImprimeCartela(cartela); 

    return 0; 
} 
  
tCartela LeCartela(){
    tCartela cartela;
    scanf("%d %d", &cartela.id, &tam);
    cartela.matriz[tam][tam];
    
    int i = 0, j = 0, linha = tam, coluna = tam;
    for(i=0;i<coluna; i++){
        for(j=0;j<linha;++j){
            scanf("%d", &cartela.matriz[j][i]);
        }
    }
    return cartela;
}

void ImprimeCartela(tCartela cartela){
    int i = 0, j = 0;

    printf("ID:%d\n", cartela.id);
    for(i=0;i<tam;++i){
        for(j=0;j<tam;++j){
            printf("%03d", cartela.matriz[i][j]);
            if(j+1!=tam){
                printf("|");
            }
        }
        printf("\n");
    }
}