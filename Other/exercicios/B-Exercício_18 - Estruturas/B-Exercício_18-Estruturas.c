/*
Escreva um trecho de codigo para fazer a criação dos novos tipos de dados conforme
solicitado abaixo:
• Horario: composto de hora, minutos e segundos.
• Data: composto de dia, mes e ano.
• Compromisso: composto de uma data, horario e texto que descreve o compromisso.
*/
#include <stdio.h>

typedef struct{
    int hora;
    int min;
    int seg;
}tHorario;

typedef struct{
    int dia;
    int mes;
    int ano;
}tData;

typedef struct{
    tHorario horario;
    tData data;
    char frase[100]; // max = 20 palavras
}tCompromisso;

tCompromisso LeCompromisso(tCompromisso compromisso);
tHorario LeHorario(tHorario horario);
tData LeData(tData data);
void ImprimeCompromisso(tCompromisso compromisso);
int RetornaDia(tData data);
int RetornaMes(tData data);
int RetornaAno(tData data);
int RetornaHora(tHorario horario);
int RetornaMin(tHorario horario);
int RetornaSeg(tHorario horario);

int main(){
    int qtd = 0, i = 0;
    scanf("%d", &qtd);
    tCompromisso compromisso[qtd];

    while(i<qtd){
        compromisso[i] = LeCompromisso(compromisso[i]);
        i++;
    }

    i = 0;
    while(i<qtd){
        ImprimeCompromisso(compromisso[i]); 
        i++;
    }
    return 0;
}

tCompromisso LeCompromisso(tCompromisso compromisso){
    compromisso.horario = LeHorario(compromisso.horario);
    compromisso.data = LeData(compromisso.data);

    while(scanf("%[^\n]", compromisso.frase) == 1);
    scanf("%*c");

    return compromisso;
}

tHorario LeHorario(tHorario horario){
    scanf("%d:%d:%d", &horario.hora, &horario.min, &horario.seg);
    scanf("%*[^\n]");
    scanf("%*c");
    return horario;
}

tData LeData(tData data){
    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
    scanf("%*[^\n]");
    scanf("%*c");
    return data;
}

void ImprimeCompromisso(tCompromisso compromisso){
    int dia = RetornaDia(compromisso.data);
    int mes = RetornaMes(compromisso.data);
    int ano = RetornaAno(compromisso.data);
    int hora = RetornaHora(compromisso.horario);
    int min = RetornaMin(compromisso.horario);
    int seg = RetornaSeg(compromisso.horario);
    printf("\nDATA: %d/%d/%d\nHORARIO: %d:%d:%d\nCompromisso: ", dia, mes, ano, hora, min, seg);
    printf("%s\n", compromisso.frase);
}

int RetornaDia(tData data){
    return data.dia;
}

int RetornaMes(tData data){
    return data.mes;
}

int RetornaAno(tData data){
    return data.ano;
}

int RetornaHora(tHorario horario){
    return horario.hora;
}

int RetornaMin(tHorario horario){
    return horario.min;
}

int RetornaSeg(tHorario horario){
    return horario.seg;
}