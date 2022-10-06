#include <stdio.h>

int main(void){

    int NumeroDeClientes = 1, i = 0;
    char nome = '\0';
    float valor = 0, bonus = 0;

    scanf("%i", &NumeroDeClientes);

    scanf("%*[^\n]");/*Consumir buffer e \n*/
    scanf("%*c");

    if(NumeroDeClientes>0 && NumeroDeClientes<27){

        for(i=1;i<=NumeroDeClientes;++i){

            scanf("%c %f", &nome, &valor);

            if(valor<500 && valor>=0){

                bonus = valor*0.1;

            }else {

                bonus = valor*0.15;
            }

            scanf("%*[^\n]");/*Consumir buffer e \n*/
            scanf("%*c");
            
            printf("Cliente %c ganhou um bonus de %.3f$!\n", nome, bonus);
        }

    }

    return 0;
}