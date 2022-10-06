#include <stdio.h>

int main(){
	
	int l=0, c=0, i=0, j=0;
	int soma = 0, atual=0, somaTotal = 0;

	scanf("%d %d", &l, &c);

	for (i = 0; i<l; i++){
		for(j = 0; j<c; j++){
			scanf("%d", &atual);
			soma += atual;
		}
		printf("%i\n", soma);
		somaTotal = somaTotal + soma;	
		soma = 0;
	}	
	printf("%d\n", somaTotal);

	return 0;
}
