#include<stdio.h>

int main(void){

    char caractere = 'x', SaveChar = ' ';
    int controlador = 1;
    int controlePrint = 1, Cont_Parentese_Aberto = 0, Cont_Parentese_Fechado = 0;

    do{

        scanf("%c", &caractere);

        if(controlePrint==1){
            printf("RESP:");
            controlePrint=0;
        }
        
        if(caractere=='(' && controlador==1){/*----INICIA A LEITURA-------*/

            controlador++;
            Cont_Parentese_Aberto++;
            continue;          /*----IGNORA O PRIMEIRO (  ---*/

        }



        if(caractere == ')' && Cont_Parentese_Aberto == Cont_Parentese_Fechado){

            Cont_Parentese_Fechado++;

            SaveChar = caractere;//guarda o caractere pro caso do seguinte n ser um .
            scanf("%c", &caractere);

            if(caractere == '.'){
                break;
            }else caractere = SaveChar;

        }


        if(caractere == '('){
            Cont_Parentese_Aberto++;
        }

        if(caractere == ')'){
            Cont_Parentese_Fechado++;
        }


        if(caractere == ')' && Cont_Parentese_Aberto == Cont_Parentese_Fechado){
            controlador = 1;
            continue;
        }

        if(caractere == '.' && Cont_Parentese_Aberto==Cont_Parentese_Fechado){
            break;//--PRIMEIRA CONDIÇÃO DE PARADA --
        }
        

        if(controlador>1){/*----INDICA QUE A LEITURA INICIAL COMECOU-----*/
            printf("%c", caractere);
        }

    }while(caractere!='\n');//--SEGUNDA CONDIÇÃO DE PARADA --

    return 0;
}