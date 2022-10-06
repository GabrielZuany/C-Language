#include <stdio.h>
#include <math.h>

int VerificapH(float pH);
int verificaGotaChuvaAcida(float pH);
float porcentagem(float total, float valor);

int main(void){

    int Area = 0, DensidadeGota = 0, Tempo = 0;
    float pH = 0;
    int contador = 0;
    int GotasAcidas = 0, GotasBasicas = 0, GotasNeutras = 0;
    float ChuvaAcida = 0, GotasTotais = 0, pH_MaisAcido = 14, pH_MaisBasico = 0, pH_MaisNeutro = 0, Percentual = 0, Diferenca_pH = 0;

    scanf("%i %i %i", &Area, &DensidadeGota, &Tempo);

    if((Area>=0 && Area<=50) && (DensidadeGota>=0 && DensidadeGota<=50) && (Tempo>=0 && Tempo<=12)){

        for(contador = 1; contador <= (Area*DensidadeGota*Tempo); ++contador){

            scanf("%f", &pH);

            if(!(pH>=0 && pH<=14)){
                continue;
            }

            Diferenca_pH = fabs(pH-7);

            if(pH<pH_MaisAcido){
                pH_MaisAcido = pH;
            }
            if(pH>pH_MaisBasico){
                pH_MaisBasico = pH;
            }
            if(pH>6 && pH<8 && Diferenca_pH < pH-pH_MaisNeutro){
                pH_MaisNeutro = pH;
            }

            if(VerificapH(pH) == 0){
                GotasNeutras++;
            }else if(VerificapH(pH) == 1){
                GotasAcidas++;
            }else if(VerificapH(pH) == 2){
                GotasBasicas++;
            }

            if(verificaGotaChuvaAcida(pH) == 1){
                ChuvaAcida++;
            }

            GotasTotais++;

        }

        if(GotasTotais == 0){
            
            printf("Nenhuma gota foi avaliada");

        }else{

            Percentual = porcentagem(GotasTotais, ChuvaAcida);

            printf("%i %i %i %.2f %.2f %.2f\n", GotasAcidas, GotasBasicas, GotasNeutras, pH_MaisAcido, pH_MaisBasico, pH_MaisNeutro);

            if(Percentual>=75){

                printf("Chuva Acida %.2f%% %.2f%%", Percentual, 100-Percentual);

            }else if(Percentual>=50 && Percentual<75){

                printf("Chuva com indicios de chuva acida %.2f%% %.2f%%", Percentual, 100-Percentual);

            }else printf("Chuva Normal %.2f%% %.2f%%", Percentual, 100-Percentual);

        }
    }

    return 0;
}

//----------FUNÇÕES-------------

int VerificapH(float pH){

    if(pH==7){//neutro
        return 0;
    }else if(pH<7){//acido
        return 1;
    }else if(pH>7){//basico
        return 2;
    }

}

int verificaGotaChuvaAcida(float pH){
    if(pH<5.7){
        return 1;
    }else return 0;
}

float porcentagem(float total, float valor){
    return (valor/total)*100;
}