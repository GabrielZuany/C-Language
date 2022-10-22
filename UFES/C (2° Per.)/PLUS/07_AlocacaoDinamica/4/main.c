#include <stdio.h>
#include <stdlib.h>

void CreateArray(int* arr, int size, int value);
void PrintArray(int* arr, int size);

int main(){
    int size;
    int value;

    scanf("%d", &size);
    scanf("%d", &value);
    int arr [size];

    CreateArray(arr, size, value);
    PrintArray(arr, size);

    //free(arr);
    return 0;
}

void CreateArray(int* arr, int size, int value){
    int i;
    for(i=0; i<size;  i++){
        *(arr+i) = value;
    }
}

void PrintArray(int* arr, int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d  ", *(arr+i));
    }
}