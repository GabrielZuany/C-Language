#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "conta.h"

int main(){
    char nome[50];
    int cpf;
    scanf("%s %d", nome, &cpf);
    
    Usuario* u = CriaUsuario(nome,cpf);
    Conta* c = CriaConta(u, 1234,12345);

    InterfaceConta(c); 
    
    int i;
    do{
        scanf("%d",&i);
        if(i==0)       
            break;
        else {
            float valor;
            scanf("%f",&valor);

            if(i==2) Deposito(c,valor);
            else Saque(c,valor);         
        }
    }while(i!=0);
    
    printf("\nSaldo: %.2f\n",RecuperaSaldo(c));   

    DestroiConta(c);
    DestroiUsuario(u);
    
    return 0;
}

