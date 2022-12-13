#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int main(int argc, char **argv){
    int tam = 0;
    char tam_str[2] = {'\0', '\0'};
    char tipo[2] = {'\0', '\0'};

    tam =  atoi(argv[1]);
    //sprintf(tam, "%d", argc);
    sprintf(tipo, "%s", argv[2]); 

    Vetor* v = criar(tam, tipo[0]);
    preencher(v);
    imprimir(v);

    double Media = calculaOp(v, 'm');
    printf("\n\n>>> MEDIA = %lf\n", Media);

    double Variancia = calculaOp(v, 'v');
    printf(">>> VARIANCIA INT = %lf\n", Variancia);

    double Desvio =  calculaOp(v, 'd');
    printf(">>> DESVIO = %lf\n", Desvio);

    liberar(v);
    return 0;
}