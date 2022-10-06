#include <stdio.h>

int main(void){

    int hora = 0, minuto = 0, dia = 0;
    int Incremento_Minutos = 0;
    char PontoPonto = '.', white = '.';

    scanf("%i", &hora);
    scanf("%c", &PontoPonto);
    scanf("%i", &minuto);
    scanf("%c", &white);
    scanf("%i", &Incremento_Minutos);

    if(hora<0 || hora>23 || minuto<0 || minuto>59 || PontoPonto!=':' || white!=' '){
        return 0;
    }

    minuto = minuto + Incremento_Minutos;

    if(minuto>59){

      hora = hora + minuto/60;
      minuto = minuto%60;  

    }
    
    if(hora>23){
        do{
            dia++;
            hora = hora - 24;
        }while(hora>23);
        
    }

    if(dia == 0 && hora!=0 && minuto!=0){

        if(hora>1 && minuto>1){
            printf("(%i horas)(%i minutos)\n", hora, minuto);
        }else if(hora>1 && minuto == 1){
            printf("(%i horas)(%i minuto)\n", hora, minuto);
        }else if(hora == 1 && minuto>1){
            printf("(%i hora)(%i minutos)\n", hora, minuto);
        }else if(hora == 1 && minuto == 1){
            printf("(%i hora)(%i minuto)\n", hora, minuto);
        }

    }else if(dia==0 && hora == 0 && minuto!=0){

        if(minuto>1){
            printf("(%i minutos)\n", minuto);
        }else printf("(%i minuto)\n", minuto);
        

    }else if(dia==0 && minuto == 0 && hora!=0){

        if(hora>1){
           printf("(%i horas)\n",hora); 
        }else printf("(%i hora)\n", hora);
        

    }else if(dia!=0 && hora == 0 && minuto!=0){

        if(dia>1 && minuto>1){
            printf("(%i dias)(%i minutos)\n",dia, minuto);
        }else if(dia>1 && minuto==1){
            printf("(%i dias)(%i minuto)\n",dia, minuto);
        }else if(dia == 1 && minuto>1){
            printf("(%i dia)(%i minutos)\n",dia, minuto);
        }else if(dia == 1 && minuto == 1){
            printf("(%i dia)(%i minuto)\n",dia, minuto);
        }
        

    }else if(dia!=0 && hora!=0 && minuto == 0){

        if(dia>1 && hora>1){
            printf("(%i dias)(%i horas)\n",dia, hora);
        }else if(dia>1 && hora == 1){
            printf("(%i dias)(%i hora)\n",dia, hora);
        }else if(dia == 1 && hora>1){
            printf("(%i dia)(%i horas)\n",dia, hora);
        }else if(dia == 1 && hora == 1){
            printf("(%i dia)(%i hora)\n",dia, hora);
        }


    }else if(dia!=0 && hora==0 && minuto==0){

        if(dia>1){
            printf("(%i dias)\n",dia);
        }else if(dia==1) printf("(%i dia)\n",dia);
        
    }else if(dia!=0 && hora!=0 && minuto!=0){

        if(dia>1 && hora>1 && minuto>1){
            printf("(%i dias)(%i horas)(%i minutos)\n",dia, hora, minuto);
        }else if(dia>1 && hora>1 && minuto==1){
            printf("(%i dias)(%i horas)(%i minuto)\n",dia, hora, minuto);
        }else if(dia>1 && hora == 1 && minuto>1){
            printf("(%i dias)(%i hora)(%i minutos)\n",dia, hora, minuto);
        }else if(dia==1 && hora>1 && minuto>1){
            printf("(%i dia)(%i horas)(%i minutos)\n",dia, hora, minuto);
        }else if(dia==1 && hora==1 && minuto==1){
            printf("(%i dia)(%i hora)(%i minuto)\n",dia, hora, minuto);
        }else if(dia==1 && hora==1 && minuto>1){
            printf("(%i dia)(%i hora)(%i minutos)\n",dia, hora, minuto);
        }else if(dia>1 && hora==1 && minuto==1){
            printf("(%i dias)(%i hora)(%i minuto)\n",dia, hora, minuto);
        }else if(dia==1 && hora>1 && minuto==1){
            printf("(%i dia)(%i horas)(%i minuto)\n",dia, hora, minuto);
        }
        
    }

    return 0;
}