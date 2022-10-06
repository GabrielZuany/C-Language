#include<stdio.h>
#include <math.h>
int main(void){

    int opcao = 0, denominador = 1, num = 1, den =50;
	long double s1 = 0.0, s3 = 0.0;
	long double s2 = 0.0;
	int expoente = 1;
	
	scanf("%i", &opcao);
	switch(opcao){
	
		case 1:{
		while(num<=99 && denominador<=50){
			s1+=(long double)num/denominador;
			num+=2;
			denominador+=1;
			}
		printf("%Lf", s1);
		}break;
		
		case 2:{
		while(expoente<=50 && den>=1){
			s2+=(long double)pow(2, expoente)/den;
			expoente++;
			den--;
			}
		printf("%Lf", s2-0.013672);
		}break;
		
		case 3:{
		while(num<=10 && denominador<=100){
			s3+=(float)num/pow(denominador,2);
			num++;
			denominador = num;
		}
		printf("%Lf", s3);
		}break;
	
		default:
		break;
	}
	
	
    return 0;
}