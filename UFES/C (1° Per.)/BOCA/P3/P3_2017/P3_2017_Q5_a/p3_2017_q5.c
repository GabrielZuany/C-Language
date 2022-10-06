#include <stdio.h>

void ModifyVet(int Vet[], int VetSize, int Modifier);
void ReadVet(int Vet[], int VetSize);

int main(void){
    int VetSize = 0;

    while(scanf("%d", &VetSize)==1){
        int Vet[VetSize];
        ReadVet(Vet, VetSize);

        int Modifier = 0;
        while(scanf("%d", &Modifier)==1 && Modifier!=-1){
            ModifyVet(Vet, VetSize, Modifier);
        }
    }
    return 0;
}

void ReadVet(int Vet[], int VetSize){
    int i = 0;
    for(i=0; i<VetSize; i++){
        scanf("%d", &Vet[i]);
    }
}

void ModifyVet(int Vet[], int VetSize, int Modifier){
    int i = 0, pos = 0;
    int TempVet[VetSize];

    for(i=0; i<VetSize; i++){

        if(i-Modifier<0){
            TempVet[pos] = Vet[VetSize + i - Modifier];
            pos++;
            continue;
        }

        TempVet[pos] = Vet[i-Modifier];
        pos++;
    }

    for(i=0; i<VetSize; i++){
        Vet[i] = TempVet[i];
    }

    for(i=0; i<VetSize; i++){
        printf("%d ", Vet[i]);
    }
    
    printf("\n");
}