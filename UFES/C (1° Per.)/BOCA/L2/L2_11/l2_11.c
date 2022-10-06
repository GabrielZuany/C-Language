#include <stdio.h>

int main(void){

    int n = 0, m = 0, a = 0, b = 0, c = 0, res = 0;
    scanf("%i %i", &n, &m);
    
    if(n<m && n>=1000 && m<=9999){
        for(n=n+1;n<m;++n){
            a = n/100;/*EX: 3025--->3025/100=30*/
            b = (n-a*100);/*3025-3000=25*/
            c = a + b;/*30+25=55*/
            res = c*c;/*55*55=3025*/
            if(res==n){
                printf("%i\n", n);
            }
        }
    }
    return 0;
}