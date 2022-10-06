#include <stdio.h>

typedef struct{
    int hora;
    int min;
    int seg;
}tHorario;

void ImprimeHorario(tHorario horario);

int main(){
    tHorario horario_atual, *horario_seguinte;
    horario_seguinte = &horario_atual;

    ImprimeHorario(horario_atual);
    
    printf("Alterando...\n");
    (*horario_seguinte).hora = 100; // horario_seguinte->hora
    (*horario_seguinte).min = 90; // horario_seguinte->min
    (*horario_seguinte).seg = 80; // horario_seguinte->seg
    ImprimeHorario(horario_atual);

    printf("Alterando...\n");
    horario_seguinte->hora = 200;
    horario_seguinte->min = 300;
    horario_seguinte->seg = 400;
    ImprimeHorario(horario_atual);

    printf("Operando...\n");
    tHorario horario_antes;
    int soma = 30;
    horario_antes.hora = soma + horario_seguinte->hora;  
    horario_antes.min = soma +horario_seguinte->min;
    horario_antes.seg = soma + horario_seguinte->seg;
    ImprimeHorario(horario_antes);

    return 0;
}

void ImprimeHorario(tHorario horario){
    printf("Horario = %d:%d:%d\n", horario.hora, horario.min, horario.seg);
}
