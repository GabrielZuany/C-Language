#include<stdio.h>
 
int NumeroElementos = 0, Elemento = 0, i = 0, controlador = 1, Num = 0;
char caractere = 'x';
int n1 = -32768, n2 = -32768, n3 = -32768, n4 = -32768, n5 = -32768, n6 = -32768, n7 = -32768, n8 = -32768, n9 = -32768;

int main(void){

void funcaoAtribuirValores(int i);
void funcaoPrintValores(int Num);

    scanf("%i", &NumeroElementos);
    if(NumeroElementos>0 && NumeroElementos<10){

        for(i = 1; i<=NumeroElementos;++i){
            scanf("%i", &Elemento);
            funcaoAtribuirValores(i);
        }
        scanf("%*c");/*Limpar Buffer*/
        do{ 
            scanf("%c", &caractere);
            if(caractere=='"' && controlador==1){ /*-----INICIA A LEITURA DA FRASE-----*/
                controlador=0;
                continue;
            }
            if(controlador!=1){
                if(caractere=='"'){           /*------TERMINA A LEITURA DA FRASE ----*/
                break;
                }
                if(caractere=='%'){
                    scanf("%i", &Num);
                    if(Num>=-32767 && Num<=32767){
                        funcaoPrintValores(Num);
                        continue;
                    }
                }
                if(caractere!='\n'){
                    printf("%c", caractere); 
                }
            }
        }while(1);
    }
    return 0;
}


void funcaoAtribuirValores(int i){
    switch (i)
    {
    case 1:
        n1 = Elemento;
        break;
    case 2:
        n2 = Elemento;
        break;
    case 3:
        n3 = Elemento;
        break;
    case 4:
        n4 = Elemento;
        break;
    case 5:
        n5 = Elemento;
        break;
    case 6:
        n6 = Elemento;
        break;
    case 7:
        n7 = Elemento;
        break;
    case 8:
        n8 = Elemento;
        break;
    case 9:
        n9 = Elemento;
        break;
    }
}

void funcaoPrintValores(int Num){
        switch (Num)
        {
        case 1:
            if(n1==-32768){
                goto fim;
            }else printf("%i", n1); 
            break;
        case 2:
            if(n2==-32768){
                goto fim;
            }else printf("%i", n2); 
            break;
        case 3:
            if(n3==-32768){
                goto fim;
            }else printf("%i", n3); 
            break;
        case 4:
            if(n4==-32768){
                goto fim;
            }else printf("%i", n4); 
            break;
        case 5:
            if(n5==-32768){
                goto fim;
            }else printf("%i", n5); 
            break;
        case 6:
            if(n6==-32768){
                goto fim;
            }else printf("%i", n6); 
            break;
        case 7:
            if(n7==-32768){
                goto fim;
            }else printf("%i", n7); 
            break;
        case 8:
            if(n8==-32768){
                goto fim;
            }else printf("%i", n8); 
            break;
        case 9:
            if(n9==-32768){
                goto fim;
            }else printf("%i", n9); 
            break;
        default: fim: printf("ERRO");
            break;
        }
}