#include <stdio.h>

int EhFinalDaLista(int buraco){
    if(buraco==-1){
        return 1;
    }else return 0;
}
int EcontraMaiorBuraco(){

    int diametro = 0, MaiorDiametro = -1;

    while(scanf("%i", &diametro)==1 && !EhFinalDaLista(diametro)){

        if(diametro>MaiorDiametro){
            MaiorDiametro = diametro;
        }
    }

    return MaiorDiametro;
}
int ContaEsferasGrandes(int maiorBuraco){

    int esfera = 0, cont = 0;

    while(scanf("%i", &esfera)==1 && !EhFinalDaLista(esfera)){
        if(esfera>=maiorBuraco){
            cont++;
        }
    } 

    return cont;
}

int main(void){

    int MaiorBuraco = -1, cont = 0;
    
    MaiorBuraco = EcontraMaiorBuraco();
    cont =  ContaEsferasGrandes(MaiorBuraco);
       
    printf("QTD:%i\n", cont);
    return 0;
}