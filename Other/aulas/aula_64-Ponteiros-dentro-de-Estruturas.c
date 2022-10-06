#include <stdio.h>

typedef struct{
    int *pHora;
    int *pMin;
    int *pSeg;
}tHorario;

void ImprimeHorario(tHorario horario);

int main(){

    tHorario horario_atual;
    int hora = 100, min = 100, seg = 100;

    horario_atual.pHora = &hora;
    horario_atual.pMin = &min;
    horario_atual.pSeg = &seg;

    ImprimeHorario(horario_atual);

    return 0;
}

void ImprimeHorario(tHorario horario){
    printf("Horario = %d:%d:%d\n", *horario.pHora, *horario.pHora, *horario.pSeg);
}