#include <stdio.h>

int main(){

    int x = 10;
    long int *ponteiro_x; //*ponteiro_x == 10; ponteiro_x == end mem [quando declarado assim].
    ponteiro_x = &x;
    printf("No endereco de memoria %ld possui o valor %d\n", ponteiro_x, x);
    printf("A variavel <*ponteiro_x> retorna o valor {%d} contido no endereco de memoria \n", *ponteiro_x);
    printf("A variavel <ponteiro_x> retorna o endereco de memoria %ld\n", ponteiro_x);

    int y = 20;
    *ponteiro_x = y;
    printf("x = %d; y = %d\n", x, y);
    return 0;
}