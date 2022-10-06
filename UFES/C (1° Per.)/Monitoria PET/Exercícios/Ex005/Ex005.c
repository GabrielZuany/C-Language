#include <stdio.h>

#define ESCOVADO 1
#define ARRUMADA 1
#define PREPARADO 1

int EscovarDentes(){
    return ESCOVADO;
}

int ArrumarCama(){
    return ARRUMADA;
}
int PrepararCafe(){
    return PREPARADO;
}

int main(void){

    int opcao = 0, dentes = 0, cama = 0, cafe = 0, bloq1 = 0, bloq2 = 0, bloq3 = 0;


    do{

        scanf("%i", &opcao);

        if(opcao == 1 && bloq1 == 0){

            printf("Escovando os dentes!\n");
            dentes = EscovarDentes();
            bloq1 = 1;
            continue;
            
        }
        
        if((opcao == 1 && bloq1 == 1) || (opcao == 2 && bloq2 == 1) || (opcao == 3 && bloq3 == 1)){

            printf("Isso ja foi feito!\n");

        }
        
        if(opcao == 2 && bloq2 == 0){

            printf("Arrumando a cama!\n");
            cama = ArrumarCama();
            bloq2 = 1;
            continue;

        }
        
        if(opcao == 3 && bloq3 == 0){

            printf("Preparando o cafe!\n");
            cafe = PrepararCafe();
            bloq3 = 1;  
            continue;

        }

        if(opcao == 0 && (dentes==0 || cafe==0 || cama==0)){
            printf("### Ainda ha tarefas pendentes! ###\n");
        }

        if((dentes && cafe && cama) && opcao == 0){
            printf("Saindo de casa!\n");
            break;
        }


    }while(1);



    return 0;
}