#include <stdio.h>

int EhFim(char c1, char c2, char c3){
    if(c1=='F' && c2=='I' && c3=='M'){
        return 1;
    }else return 0;
}

int QtdDebitoPlaca(int presc){

    int Debito = 0, Ano = 0, Soma = 0;

    while(scanf("(%i:%i)", &Debito, &Ano) == 2){

        if(Ano<=presc){
            Soma+=Debito;
        }

    }
    scanf("%*[^\n]");
    scanf("%*c");

    return Soma;
}

int MaiorDebitoCidade(){
    char c1 = '.', c2 = '.', c3 = '.', Maior_c1 = '.', Maior_c2 = '.', Maior_c3 = '.';
    int MaiorDeb = 0, Prescrito = 0, Debito = 0;

    scanf("%i", &Prescrito);
    scanf("%*[^\n]");
    scanf("%*c");

    while(scanf("%c%c%c", &c1, &c2, &c3)==3 && !EhFim(c1, c2, c3)){

        Debito = QtdDebitoPlaca(Prescrito);

        if(Debito>MaiorDeb){
            MaiorDeb = Debito;
            Maior_c1 = c1;
            Maior_c2 = c2;
            Maior_c3 = c3;
        }

        Debito = 0;
    }

    if(MaiorDeb>0){
        printf("PLACA:%c%c%c DEBITO:%i\n", Maior_c1, Maior_c2, Maior_c3, MaiorDeb);
        return MaiorDeb;
    }else{
        printf("SEM DEBITO!\n");
        return 0;
    }
}

int main(void){

    int NumeroDeCidades = 0, Prescrito = 0;
    int SomaTotal = 0, MaiorDeb = 0;
    int i = 0;
    char c1 = '.', c2 = '.', c3 = '.', Maior_c1 = '.', Maior_c2 = '.', Maior_c3 = '.';

    scanf("%i", &NumeroDeCidades);

    for(i=0; i<NumeroDeCidades; ++i){

        SomaTotal+=MaiorDebitoCidade();

    }
    
    printf("SOMA:%i\n", SomaTotal);   
       
    return 0;
} 