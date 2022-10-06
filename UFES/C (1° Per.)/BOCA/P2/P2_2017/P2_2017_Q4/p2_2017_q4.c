#include <stdio.h>

int EhLetra(char c){
    if((c>='a' && c<='z') || (c>='A' && c<='Z')){
        return 1;
    }else return 0;
}
int EhVogal(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
        return 1;
    }else return 0;

}
int ReconheceSimbolo(char c){
    int num = 0;
    char caractere = 'x';

    if(c=='*'){

        scanf("%i%c", &num, &caractere);

        if(caractere=='*' && (num>=1 && num<=3)){
            return num;//O TIPO DE MARCADOR *1* *2* ou *3*
        }else{
            while(caractere!='*'){
                scanf("%c", &caractere);
            }
            return -1;//ERRO
        }

    }else{
        
        while(caractere!='*'){
            scanf("%c", &caractere);
        }
        return 0;
    }

    

}

int main(void){

    char letra = '!';
    int L = 0, V = 0, C = 0, id = 0;

    while(letra!='.'){

        scanf("%c", &letra);

        if(EhLetra(letra)){

            printf("%c", letra);
            L++;
            if(EhVogal(letra)){
                V++;
            }else{
                C++;
            }

            continue;
        }

        if(letra=='*'){
            id = ReconheceSimbolo(letra);

            if(id == 1){
                printf("*L:%i V:%i C:%i*", L, V, C);
                V = 0;
                C = 0;
                L = 0;
            }else if(id == 2){
                printf("*V:%i*", V);
                V = 0;  
            }else if(id == 3){
                printf("*C:%i*", C);
                C = 0;
            }else if(id == -1){
                printf("*ERRO*");
            }
        }
        
    }

    printf(".");


    return 0;
}