#include<stdio.h>

int main(void){

    int min = 0, max = 0, multi = 1, res = 0;

    scanf("%i %i", &min, &max);
    
    while(min<=max){
        for(multi=1;multi<=10;++multi){
          res = min*multi; 
          printf("%i x %i = %i\n", min, multi, res); 
        }
        ++min;
    }
    return 0;
}