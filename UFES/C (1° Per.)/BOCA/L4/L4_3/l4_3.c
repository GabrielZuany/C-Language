#include <stdio.h>

typedef struct{
    int dia;
    int mes;
    int ano;

}tData;

tData d1;

int EhBisexto(tData d1){
    if ( !(d1.ano%400) ){
        return 1;
    }
    if ( !(d1.ano%100) ){
        return 0;
    }
    if ( !(d1.ano%4) ){
        return 1;
    }
    return 0;
}

void ValidaD1(tData d){
    if(d1.mes>=12){
        d1.mes = 12;
    }
    if(d1.mes<=0){
        d1.mes = 1;
    }

    if((d1.mes==4 || d1.mes==6 || d1.mes==9 || d1.mes==11) && d1.dia>30 ){
        d1.dia = 30;
    }
    if((d1.mes==1 || d1.mes==3 || d1.mes==5 || d1.mes==7 || d1.mes==10 || d1.mes==12) && d1.dia>31){
        d1.dia = 31;
    }
    if(d1.mes==2 && EhBisexto(d1) && d1.dia>29){
        d1.dia = 29;
    }
    if(d1.mes==2 && !EhBisexto(d1) && d1.dia>28){
        d1.dia = 28;
    }
}

void ImprimeData(){
    if(EhBisexto(d1)){
        printf("'%02i/%02i/%04i':Bisexto\n", d1.dia, d1.mes, d1.ano);
    }else printf("'%02i/%02i/%04i':Normal\n", d1.dia, d1.mes, d1.ano);
}

tData LeData(){
    scanf("%i %i %i", &d1.dia, &d1.mes, &d1.ano);
}

int main(void){

    int QtdDatas = 0, i = 0;

    scanf("%i", &QtdDatas);

    for(i=0; i<QtdDatas; ++i){
        LeData();
        ValidaD1(d1);
        ImprimeData();
    }

    return 0;
}