#include <stdio.h>

void ReadVet(int Vet[], int Size);
void PairNumbers(int Vet1[], int Size1, int Vet2[], int Size2);

int main(void){

    int SizeVet1 = 0, SizeVet2 = 0;

    scanf("%d", &SizeVet1);
    int Vet1[SizeVet1];
    ReadVet(Vet1, SizeVet1);

    scanf("%d", &SizeVet2);
    int Vet2[SizeVet2];
    ReadVet(Vet2, SizeVet2);

    printf("PARES:\n");
    PairNumbers(Vet1, SizeVet1, Vet2, SizeVet2);

    return 0;
}

void ReadVet(int Vet[], int Size){
    int i = 0;
    for(i = 0; i < Size; i++){
        scanf("%d", &Vet[i]);
    }
}

void PairNumbers(int Vet1[], int Size1, int Vet2[], int Size2){
    int i = 0, j = 0;
    for(i=0, j = 0; i<Size1; ++i, j++){
        if(j == Size2){
            j = 0;
        }
        printf("%d - %d\n", Vet1[i], Vet2[j]);
    }
}