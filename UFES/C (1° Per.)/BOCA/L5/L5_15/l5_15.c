#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
typedef struct{ 
 int codigo; 
 char sobrenome[21]; 
 char nome[21]; 
 int nota; 
 int idade; 
} tCandidato; 
 
tCandidato LeCandidato(); 
void ImprimeCandidato(tCandidato candidato); 
void OrdenaCrescente(tCandidato * candidato, int qtd); 
int main(){ 
    int qtdCand, i = 0, j; 

    scanf("%d", &qtdCand); 
    tCandidato candidatos[qtdCand], Ordenados[qtdCand]; 

    for(i = 0; i < qtdCand; i++){ 
        candidatos[i] = LeCandidato(); 
    } 

    OrdenaCrescente(candidatos, qtdCand);

    for(i = 0; i < qtdCand; i++){
        ImprimeCandidato(candidatos[i]); 
    } 
  
    return 0;     
} 
 
tCandidato LeCandidato(){ 
    tCandidato candidato; 
    scanf("%*[^{]"); 
    scanf("%*[{ ]"); 
    scanf("%d", &candidato.codigo); 
    scanf("%*[, ]"); 
    scanf("%[^,],", candidato.sobrenome); 
    scanf("%*[ ]"); 
    scanf("%[^,],", candidato.nome); 
    scanf("%d", &candidato.nota);  
    scanf("%*[, ]");  
    scanf("%d", &candidato.idade);  
    scanf("%*[^\n]\n");  return candidato; 
}

void ImprimeCandidato(tCandidato candidato){
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",candidato.codigo, candidato.nome,candidato.sobrenome, candidato.nota, candidato.idade);
}

void OrdenaCrescente(tCandidato * candidato, int qtd){
    int i = 0, j = 0, result_nome = 0, result_sobrenome = 0;
    tCandidato aux;

    for(i=0;i<qtd;++i){
        
        for(j=i+1;j<qtd;++j){

            result_nome = strcoll(candidato[i].nome, candidato[j].nome);
            result_sobrenome = strcoll(candidato[i].sobrenome, candidato[j].sobrenome);

            if(result_nome<0/*i<j*/){
                continue;
            }else if(result_nome>0/*i>j*/){
                aux = candidato[i];
                candidato[i] = candidato[j];
                candidato[j] = aux;
            }else{

                if(result_sobrenome<0/*i<j*/){
                    continue;
                }else{
                    aux = candidato[i];
                    candidato[i] = candidato[j];
                    candidato[j] = aux;
                }
            }
        }
    }
}