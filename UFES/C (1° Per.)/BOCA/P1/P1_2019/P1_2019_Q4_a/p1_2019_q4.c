#include <stdio.h>

int main(){

    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0;
    int B1 = 0, B2 = 0, B3 = 0, B4 = 0;//blocos de numeros--->B1 = 111. B2 = 222. B3 = 333- B4 = 44
    int dig1 = 0, dig2 = 0, dig1Valido = 0, dig2Valido = 0;
    int soma = 0, RestoDiv = 0, Validade_1o_dig = 0;

    scanf("%i.%i.%i-%i", &B1, &B2, &B3, &B4);
    n1 = B1/100;
    n2 = (B1%100)/10;
    n3 = B1%10;

    n4 = B2/100;
    n5 = (B2%100)/10;
    n6 = B2%10;

    n7 = B3/100;
    n8 = (B3%100)/10;
    n9 = B3%10;

    dig1 = B4/10;
    dig2 = B4%10;
    
    if(n1==n2 && n1==n3 && n1==n4 && n1==n5 && n1==n6 && n1==n1 && n1==n8 && n1==n9 && n1==dig1 && n1==dig2){
        printf("CPF invalido: digitos iguais!");
        return 0;
    }

    soma = n1*10 + n2*9 + n3*8 + n4*7 + n5*6 + n6*5 + n7*4 + n8*3 + n9*2;
    RestoDiv = soma%11;

    if(RestoDiv<2 && dig1==0 ||(RestoDiv>=2 && dig1==11-RestoDiv)){
        dig1Valido = 1;
    }

    if(dig1Valido==0){/*caso o primeiro seja invalido, para verificar se o segundo eh valido, deve-se considerar o promeiro como valido, caso contrario, ele acusará ambos como invalidos, ja q o resultado do segundo depende do primeiro*/
        dig1=0;
        while(Validade_1o_dig==0){

            soma = n1*10 + n2*9 + n3*8 + n4*7 + n5*6 + n6*5 + n7*4 + n8*3 + n9*2;
            RestoDiv = soma%11;
            if(RestoDiv<2 && dig1==0 || (RestoDiv>=2 && dig1==11-RestoDiv)){
                Validade_1o_dig = 1;//variavel que verifica quando o numero eh valido como 1o digito do cpf
                break;
            }
            dig1++;
        }
    }

    soma =  n1*11 + n2*10 + n3*9 + n4*8 + n5*7 + n6*6 + n7*5 + n8*4 + n9*3 + dig1*2;
    RestoDiv = soma%11;

    if(RestoDiv<2 && dig2==0 || (RestoDiv>=2 && dig2==11-RestoDiv)){
        dig2Valido = 1;
    }

    if(dig1Valido == 1 && dig2Valido == 1){
        printf("CPF valido!");
    }else{
        printf("CPF invalido:");
        if(dig1Valido == 0 && dig2Valido == 0){
            printf(" dois digitos!");
        }else if(dig1Valido==0 && dig2Valido == 1){
            printf(" primeiro digito!");
        }else if(dig1Valido==1 && dig2Valido == 0){
            printf(" segundo digito!");
        }
    }
    return 0;
}