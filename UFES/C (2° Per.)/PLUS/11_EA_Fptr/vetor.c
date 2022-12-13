#include "vetor.h"
#define MAX 100

struct vetor{
    void* elementos;
    int qtd_elementos;
    char tipo_vetor;
    double media;
    double desvio;
    double variancia;
};

Vetor *criar(int tam, int tipo){
    Vetor *v = malloc(sizeof(Vetor));
    v->qtd_elementos = tam;
    v->tipo_vetor = tipo;

    if(tipo == 'i'){
        v-> elementos = malloc(sizeof(int)*tam);
    }else if(tipo == 'd'){
        v-> elementos = malloc(sizeof(double)*tam);
    }else if(tipo == 'f'){
        v-> elementos = malloc(sizeof(float)*tam);
    }else exit(0);

    return v;
}

void preencher(Vetor *v){
    int index;
    if(v->tipo_vetor == 'i'){
        for(index = 0; index<(v->qtd_elementos); index++){
            ((int*)v->elementos)[index] = (int)rand( )%MAX;
        }
    }else if(v->tipo_vetor == 'd'){
        for(index = 0; index<(v->qtd_elementos); index++){
            ((double*)v->elementos)[index] = (double)rand( )/RAND_MAX*MAX;
        }
    }else if(v->tipo_vetor == 'f'){
        for(index = 0; index<(v->qtd_elementos); index++){
            ((float*)v->elementos)[index] = (float)rand( )/RAND_MAX*MAX;
        }
    }else exit(0);
}

void imprimir(Vetor *v){
    int index = 0, max = v->qtd_elementos;
    printf("Valores: ");

    if(v->tipo_vetor == 'i'){
        int valor;

        for(index = 0; index<max; index++){
            valor = ((int*)v->elementos)[index];
            printf("%d | ", valor);
        }

    }else if(v->tipo_vetor == 'd'){
        double valor;

        for(index = 0; index<max; index++){
            valor = ((double*)v->elementos)[index];
            printf("%.2f | ", valor);
        }

    }else if(v->tipo_vetor == 'f'){
        float valor;
        for(index = 0; index<max; index++){
            valor = ((float*)v->elementos)[index];
            printf("%.2f | ", valor);
        }
    }else exit(0);
}

double media(Vetor *v){
    double media;

    if(v->tipo_vetor == 'i'){
        media = media_int(v);
    }else if(v->tipo_vetor == 'd'){
        media = media_double(v);
    }else if(v->tipo_vetor == 'f'){
        media = media_float(v);
    }else exit(0);

    v->media = media;
    return media;
}

float media_int(Vetor* v){
    int index = 0, max = v->qtd_elementos;
    float sum = 0;
    for(index; index<max; index++){
        sum += ((int*)v->elementos)[index];
    }
    return (sum/(float)max);
}

float media_float(Vetor* v){
    int index = 0, max = v->qtd_elementos;
    float sum = 0;
    for(index; index<max; index++){
        sum += ((float*)v->elementos)[index];
    }
    return (sum/(float)max);
}

float media_double(Vetor* v){
    int index = 0, max = v->qtd_elementos;
    double sum = 0;
    for(index; index<max; index++){
        sum += ((double*)v->elementos)[index];
    }
    return (sum/(double)max);
}

double variancia(Vetor *v){
    double media;
    int max = v->qtd_elementos, index = 0;
    double sum = 0;

    switch (v->tipo_vetor)
    {
    case 'i':
        media = media_int(v);
        for(index; index<max; index++){
            sum += pow( ( ((int*)v->elementos)[index] - (media) ) , 2);
        }
        break;
    case 'f':
        media = media_float(v);
        for(index; index<max; index++){
            sum += pow( ( ((float*)v->elementos)[index] - (media) ) , 2);
        }
        break;
    case 'd':
        media = media_double(v);
        for(index; index<max; index++){
            sum += pow( ( ((double*)v->elementos)[index] - (media) ) , 2);
        }
        break;
    
    default: exit(0);
        break;
    }

    v->variancia = (media/((double)(max-1)));
    if(max == 1) v->variancia = 0;

    return v->variancia;
}

double desvioPadrao(Vetor *v){
    v->desvio = sqrt(v->variancia);
    return sqrt(v->variancia);
}

double operacao(Vetor* v, fptrCalcula m){
    return m(v);
}

double calculaOp(Vetor*v, char o){

    switch (o)
    {
    case 'm':
        return operacao(v, media);
        break;
    case 'v':
        return operacao(v, variancia);
        break;
    case 'd':
        return operacao(v, desvioPadrao);
    default: exit(0);
        break;
    }
}

void liberar(Vetor *v){
    int index;
    free(v->elementos);
    free(v);
}