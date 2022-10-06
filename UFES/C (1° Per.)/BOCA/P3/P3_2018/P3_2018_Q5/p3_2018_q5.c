#include <stdio.h>

void CalculateSum(int Vet1[], int Vet2[],int i, int j);

int main(){

    int SumQantity = 0, i = 0, j = 0;
    scanf("%d", &SumQantity);

    while(SumQantity--){
        int Vet1[100];
        int Vet2[100];

        while(scanf("%1d", &Vet1[i])==1 && Vet1[i]!=-1){
            i++;
        }

        while(scanf("%d", &Vet2[j])==1 && Vet2[j]!=-1){
            j++;
        }
        CalculateSum(Vet1, Vet2, i, j);
    }

    return 0;
}

void CalculateSum(int Vet1[], int Vet2[],int i, int j){
    int VetSum[i+j], cont_i = 0, cont_j = 0, cont_sum = 0;
    int Vet1Position = i, Vet2Position = j;
    int BiggerSize = 0;

    if(i>j){
        BiggerSize = i;
    }else if(j>i){
        BiggerSize = j;
    }else{
        BiggerSize = i;
    }

    for(cont_sum = 0; cont_sum<i+j; ++cont_sum){
        VetSum[cont_sum] = 0;
    }
     

    for(cont_sum=0; cont_sum<BiggerSize; cont_sum++){
        printf("%d ", VetSum[cont_sum]);
    }
    printf("\n");
}