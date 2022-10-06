/*
Considerando a necessidade de desenvolver uma agenda que contenha nomes, UF e telefones de 5 pessoas, defina a estrutura de resgistro apropriada que, com o uso de subprogramas, seja capaz de, por meio de um menu:
a) acessar cada um dos registros e exibir os dados de cada um deles.
b) exibir os registros de todas as pessoas cadastradas ordenados alfabeticamente (nome).
*/
#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[20];
    char UF[30];
    int tel;
}tAgenda;

tAgenda LeAgenda(tAgenda agenda);
void ImprimeRegistros(tAgenda *agenda, int tam);
void OrdenaRegistros(tAgenda *agenda, int tam);

int main(){
    tAgenda agenda[5];
    int i;

    for(i=0; i<5; ++i){
        //printf("DIGITE O REGISTRO %d (nome, UF, tel)\n", i+1);
        agenda[i] = LeAgenda(agenda[i]);
    }

    int opcao;
    //printf("DIGITE 1 PARA IMPRIMIR OS REGISTROS OU 2 PARA ORDENAR E IMPRIMIR: ");
    scanf("%d", &opcao);

    if(opcao == 1){
        ImprimeRegistros(agenda, 5);
    }else if(opcao == 2){
        OrdenaRegistros(agenda, 5);
        ImprimeRegistros(agenda, 5);
    }else printf("Opcao invalida\n");

    return 0;
}

tAgenda LeAgenda(tAgenda agenda){
    scanf("%s\n%s\n%d", agenda.nome, agenda.UF, &agenda.tel);
    return agenda;
}

void ImprimeRegistros(tAgenda *agenda, int tam){
    int i;
    for(i=0;i<tam;++i){
        printf("REG %d: \nNome: %s\nUF: %s\nTel: %d\n\n", i+1, agenda[i].nome, agenda[i].UF, agenda[i].tel);
    }
}

void OrdenaRegistros(tAgenda *agenda, int tam){
    tAgenda temp;
    int i, j;
    for(i=0; i<tam; ++i){
        for(j=i+1; j<tam; ++j){
            if(strcoll(agenda[i].nome, agenda[j].nome) > 1){
                temp = agenda[i];
                agenda[i] = agenda[j];
                agenda[j] = temp;
            }
        }
    }
}