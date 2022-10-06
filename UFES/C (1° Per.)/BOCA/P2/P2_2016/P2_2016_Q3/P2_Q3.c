#include <stdio.h>

int gMaiorNum = 0;

int EhProduto(char prd){

    if(prd>='A' && prd<='Z'){
        return 1;
    }else return 0;

}

int AcabaramOsProdutos(char prd){

    if(prd == '0'){
        return 1;
    }else return 0;

}

int QtdDoProdutoMaisComprado(){

    int QtdDoProdutoMaisComprado = 0, QtdProduto = 0;
    char Produto = 'A', temp = 'A';

    while( !(AcabaramOsProdutos(Produto)) ){

        scanf("%c",&Produto);

        if(Produto!=temp){//VERIFICA A MUDANÇA DE TIPO DE PRODUTO
            temp=Produto;
            QtdProduto = 0;
        }

        if(EhProduto(Produto)){
            QtdProduto++;
        }
        if(QtdProduto>QtdDoProdutoMaisComprado){//COMPARÇÃO ENTRE QTD DO PRODUTO ATUAL E PRODUTO MAIS VENDIDO ATE O MOMENTO
            QtdDoProdutoMaisComprado = QtdProduto;
        }
    }

    return QtdDoProdutoMaisComprado;
}


int main(void){

    int cliente = 0, MaisGuloso = 0, res = 0;

    while(cliente!=-1){

        scanf("%i", &cliente);

        if(cliente==-1){
            break;
        }

        scanf("%*c");//CONSUMIR BUFFER

        res = QtdDoProdutoMaisComprado();

        if(res>gMaiorNum){
            MaisGuloso = cliente;
            gMaiorNum = res;
        }

    }

    printf("CLIENT:%i QTD:%i", MaisGuloso, gMaiorNum);


    return 0;
}