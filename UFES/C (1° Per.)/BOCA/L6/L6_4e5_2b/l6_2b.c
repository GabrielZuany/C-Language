#include <stdio.h>

typedef struct{
    int id;
    int matriz[6][6];
}tCartela;

typedef struct{
    tCartela cartelas[10];
}tPartida;

tPartida LeCartelasPartida();
void ImprimeInvCartelasPartida(tPartida partida);
int tam = 0, qtd = 0;

int main(){ 
    tPartida partida; 

    partida = LeCartelasPartida(); 

    ImprimeInvCartelasPartida(partida); 

    return 0; 
    } 
  
tPartida LeCartelasPartida(){
    scanf("%d", &qtd);
    tPartida partida;
    tCartela cartela[qtd];

    int cont = 0;
    for(cont=qtd-1;cont>=0;--cont){

        scanf("%d %d", &partida.cartelas[cont].id, &tam);

        partida.cartelas[cont].matriz[tam][tam];

        int i = 0, j = 0, linha = tam, coluna = tam;

        for(i=0;i<coluna; i++){
            for(j=0;j<linha;++j){
                scanf("%d", &partida.cartelas[cont].matriz[j][i]);
            }
        } 

    }

    
    return partida;
}

void ImprimeInvCartelasPartida(tPartida partida){
    int cont = 0;
    int i = 0, j = 0;

    for(cont=0; cont<qtd;++cont){

        printf("ID:%d\n", partida.cartelas[cont].id);
        for(i=0;i<tam;++i){

            for(j=0;j<tam;++j){
                printf("%03d", partida.cartelas[cont].matriz[i][j]);
                if(j+1!=tam){
                    printf("|");
                }
            }
            
            printf("\n");
        }
    }
}