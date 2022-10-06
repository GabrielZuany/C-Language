#include <stdio.h> 
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
void TrocaPosicao(tCandidato candidato[], int i, int j);
int VerificaNota(tCandidato candidato[], int i, int j);
int VerificaIdade(tCandidato candidato[], int i, int j);
int VerificaCodigo(tCandidato candidato[], int i, int j);

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

//---------------------FUNÇÕES-----------------------

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
   int i = 0, j = 0;

    for(i=0;i<qtd;++i){
        for(j=i+1;j<qtd;j++){

            if(VerificaNota(candidato, i, j) == 0/*nota i<j*/){
                TrocaPosicao(candidato, i, j);
                continue;


            }else if(VerificaNota(candidato, i, j) == 1/*nota i=j*/){

                if(VerificaIdade(candidato, i, j) == 0/*idade i>j*/){
                    TrocaPosicao(candidato, i, j);
                    continue;

                }else if(VerificaIdade(candidato, i, j) == 1/*idade i=j*/){


                    if(VerificaCodigo(candidato, i, j) == 0/*cod i>j*/){
                        TrocaPosicao(candidato, i, j);
                        continue;
                    }else if(VerificaCodigo(candidato, i, j) == 1/*cod i=j*/){
                        continue;
                    }


                }else if(VerificaIdade(candidato, i, j) == -1){
                    continue;
                }

            }else if(VerificaNota(candidato, i, j) == -1){
                continue;
            }
        }
    }
}

int VerificaNota(tCandidato candidato[], int i, int j){
    if(candidato[i].nota<candidato[j].nota){
        return 0;
    }else if(candidato[i].nota==candidato[j].nota){
        return 1;
    }else{
      return -1;  
    }
    
}

int VerificaIdade(tCandidato candidato[], int i, int j){
    if(candidato[i].idade>candidato[j].idade){
        return 0;
    }else if(candidato[i].idade==candidato[j].idade){
        return 1;
    }else{
        return -1;
    }
}

int VerificaCodigo(tCandidato candidato[], int i, int j){
    if(candidato[i].codigo>candidato[j].codigo){
        return 0;
    }else if(candidato[i].codigo==candidato[j].codigo){
        return 1;
    }else{
        return -1;
    }
}

void TrocaPosicao(tCandidato candidato[], int i, int j){
    tCandidato aux;
    aux = candidato[i];
    candidato[i] = candidato[j];
    candidato[j] = aux;
}