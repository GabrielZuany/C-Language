#include <stdio.h> 
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
int VerificaSeFoiImpresso(tCandidato Printed[], int position, int qtd);

int main(){ 
    int qtdCand, i = 0, j = 0, flag = 0, cont = 0, pos = 0, marcador = 0;
    scanf("%d", &qtdCand); 
    tCandidato candidatos[qtdCand], Printed[qtdCand]; 

    for(i = 0; i < qtdCand; i++){ 
        candidatos[i] = LeCandidato(); 
    }

    for(i=0;i<qtdCand; i++){
        flag = i;//guarda i
        for(j=i+1; j<qtdCand;j++){

            if(strcmp(candidatos[i].sobrenome, candidatos[j].sobrenome)==0){
                cont++;//qtd de sobrenomes iguais-1
                if(cont<2){
                    Printed[pos] = candidatos[i];//adiciona num vetor so os que tiverem sobrenomes iguais
                    pos++;
                    Printed[pos] = candidatos[j];
                    pos++;
                }else{
                    Printed[pos] = candidatos[j];
                    pos++;
                    marcador = 1;//desconta o numero de repetições caso haja + que 2 sobrenomes iguais
                }
                i=j;//compara a parir do primeiro encontrado(primeiro encontrado torna-se a referencia)
            }
        }
        i = flag;//i = i antes do for(){<codigo>}
        cont=0;//zera parametro
    }

    if(marcador==1){
        pos-=2;
    }

    for(i=0;i<pos; ++i){
        if(VerificaSeFoiImpresso(Printed, i, pos)){
            ImprimeCandidato(Printed[i]);
        }else{
            continue;
        }
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
    scanf("%*[^\n]\n"); 
    return candidato; 
} 

void ImprimeCandidato(tCandidato candidato){
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n", candidato.codigo, candidato.nome, candidato.sobrenome, candidato.nota, candidato.idade);
} 

int VerificaSeFoiImpresso(tCandidato Printed[], int position, int qtd){
    int i = 0, j = 0;

    for(j=position-1, i = 0;   j>=0, i<position;      --j, ++i){
        if(Printed[position].codigo==Printed[i].codigo || Printed[position].codigo==Printed[j].codigo){
            return 0;
        }
    }
    return 1;
}