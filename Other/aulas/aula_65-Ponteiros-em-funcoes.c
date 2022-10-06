#include <stdio.h>

void TesteVariavel(int x);
void TestePonteiro(int *pX);

int main(){
    int x = 1;
    int *pX = &x;

    TesteVariavel(x);
    printf("TesteVariavel(int x) não altera o valor da variavel {%d}\n", x);//ocorre uma copia da variavel para a funcao.

    TestePonteiro(pX);
    printf("TestePonteiro(int *pX) altera o valor da variavel {%d}\n", x);//altera diretamente o valor da variavel na memoria.

    return 0;
}

void TesteVariavel(int x){
    ++x;
}

void TestePonteiro(int *pX){
    ++*pX;
}