#include <stdio.h>
#include <math.h>

float CalculaDesvioPadrao(int nota[], int qtd, float media){
    int i = 1;
    float desvio = 0, somatorio = 0;

    for(i=0; i<qtd; ++i){
        somatorio += pow(((float)nota[i]-media), 2);
    }
    desvio = sqrt(somatorio/(float)qtd);

    return desvio;
}

int QtdAcimaDaMedia(int nota[], int qtd, float media){
    int i = 0, AcMed = 0;

    for(i=0; i<qtd; ++i){
        if(nota[i]>media){
            AcMed++;
        }
    }
    return AcMed;
}

int MaiorNota(int nota[], int qtd){

    int i = 0, Maior = -1;
    for(i=0; i<qtd; ++i){
        if(nota[i]>Maior){
            Maior = nota[i];
        }
    }
    return Maior;
}

int MenorNota(int nota[], int qtd){

    int i = 0, Menor = 101;
    for(i=0; i<qtd; ++i){
        if(nota[i]<Menor){
            Menor = nota[i];
        }
    }
    return Menor;
}

int main(){

    int qtd = 0, i = 0, soma = 0, Maior = -1, Menor = 101, Reprov = 0, AcMed = 0;
    float media = 0, desvio = 0;

    scanf("%i ", &qtd);
    int nota[qtd];

    for(i=0; i<qtd; ++i){

        scanf("%i ", &nota[i]);
        if(nota[i]<70){
            Reprov++;
        }
        soma = soma + nota[i];
    }

    media = (float)soma/(float)qtd;
    Menor = MenorNota(nota, qtd);
    Maior = MaiorNota(nota, qtd);
    AcMed = QtdAcimaDaMedia(nota, qtd, media);
    desvio = CalculaDesvioPadrao(nota, qtd, media);

    printf("MENOR:%i, MAIOR:%i, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%i, REPROV:%i", Menor, Maior, media, desvio, AcMed, Reprov);

    return 0;
}