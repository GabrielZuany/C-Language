#include <stdio.h>

typedef struct{
    int codigo;
    float preco;
    int QtdEstoque;
}tProduto;

tProduto p1 = {0, 0.0, 0};
tProduto MaiorP = {0, 0.0, 0};
tProduto MenorP = {0, 10000000000000.0, 0};


tProduto LeProduto(){

    scanf("%i;%f;%i", &p1.codigo, &p1.preco, &p1.QtdEstoque);

}
int EhProduto1MaiorQ2(tProduto p1, tProduto p2){
    if(p1.preco>MaiorP.preco){
        return 1;
    }else return 0;
}
int EhProduto1MenorQ2(tProduto p1, tProduto p2){
    if(p1.preco<MenorP.preco){
        return 1;
    }else return 0;
}

int TemProdutoEmEstoque(tProduto p){
    if(p.QtdEstoque>0){
        return 1;
    }else return 0;
}

void ImprimeProduto(tProduto p){
    if(!TemProdutoEmEstoque(p)){
        printf("FALTA:COD %d, PRE %.2f, QTD 0\n", p.codigo, p.preco);
    }
}

void ImprimeFim(){

    printf("MAIOR:COD %d, PRE %.2f, QTD %d\n",MaiorP.codigo, MaiorP.preco, MaiorP.QtdEstoque);
    printf("MENOR:COD %d, PRE %.2f, QTD %d\n",  MenorP.codigo, MenorP.preco, MenorP.QtdEstoque);

}

int main(void){

    int i = 0, loop = 0;
    scanf("%i", &loop);

    for(i=0; i<loop; ++i){
        LeProduto();

        if(EhProduto1MaiorQ2(p1, MaiorP)){
            MaiorP = p1;
        }
        if(EhProduto1MenorQ2(p1, MenorP)){
            MenorP = p1;
        }
        ImprimeProduto(p1);
    }
    ImprimeFim();

    return 0;
}