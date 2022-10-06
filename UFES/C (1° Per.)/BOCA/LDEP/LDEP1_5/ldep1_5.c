/*
O objetivo desta questão é treinar a capacidade de encontrar
erros e acertar códigos. Para isso, conserte o código dado (arquivo
“codigo_quebrado.c” no zip juntamente com a descrição do problema), para que
ele seja capaz de calcular o mmc e o mdc de dois números positivos fornecidos
pelo usuário.

Entrada: 2 números inteiros positivos.
Saída: MDC e MMC dos dois números, respectivamente.
Exemplo de Entrada:
15 10
13 27
2 2
Exemplo de Saída:
5 30
1 351
*/
#include <stdio.h>

int main(){
	int a, b, den=1, i=0, mdc=0, mmc=0, limMDC, limMMC;

	scanf("%d %d", &a, &b);


	/*Acha limites da busca*/
	if (a < b){ 
		limMDC = a;
		limMMC = b;
	} else {
		limMDC = b;
		limMMC = a;
	}
	
	/*MDC*/
	for(den=1; den <= limMDC; den++){   
		if(!(a%den) && !(b%den)){ 
			mdc = den;
		}
	}
	
	/*MMC*/
	i = limMMC;
	while(1){
		if(i%a==0 && i%b==0){
			mmc = i;
			break;
		}      
			
		i++;                      
	}

	printf("%d %d",mdc, mmc);

	return 0;
}
