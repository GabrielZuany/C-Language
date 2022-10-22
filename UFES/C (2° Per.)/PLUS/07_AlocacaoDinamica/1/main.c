#include <stdio.h>

int main(){
    char caractere = 'x';
    int num = 1;
    float floatnum = 5.4;

    char* p_caractere = &caractere;
    int* p_intnum = &num;
    float* p_floatnum = &floatnum;

    printf("ANTES:\nCaractere: %c; Numero inteiro: %i; Numero float:%.2f\n\n", *p_caractere, *p_intnum, *p_floatnum);

    *p_intnum+=1;
    *p_floatnum+=6.7;
    *p_caractere = 'y';

    printf("DEPOIS:\nCaractere: %c; Numero inteiro: %i; Numero float:%.2f\n", *p_caractere, *p_intnum, *p_floatnum);

    return 0;
}