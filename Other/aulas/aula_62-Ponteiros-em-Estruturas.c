#include <stdio.h>

typedef struct{
    int hora;
    int min;
    int seg;
}tHorario;

void ImprimeAtual(tHorario horario);

int main(){
    tHorario horario_atual, *horario_seguinte;
    horario_seguinte = &horario_atual;

    ImprimeAtual(horario_atual);
    
    printf("Alterando...\n");
    (*horario_seguinte).hora = 100; // horario_seguinte->hora
    (*horario_seguinte).min = 90; // horario_seguinte->min
    (*horario_seguinte).seg = 80; // horario_seguinte->seg
    ImprimeAtual(horario_atual);

    printf("Alterando...\n");
    horario_seguinte->hora = 200;
    horario_seguinte->min = 300;
    horario_seguinte->seg = 400;
    ImprimeAtual(horario_atual);

    return 0;
}

void ImprimeAtual(tHorario horario){
    printf("atual = %d:%d:%d\n", horario.hora, horario.min, horario.seg);
}
