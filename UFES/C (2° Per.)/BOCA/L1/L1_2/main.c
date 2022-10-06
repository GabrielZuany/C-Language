#include <stdio.h>
#include <stdlib.h>
#include "tData.h"

int main(){
    tData data, dataIni, dataFim;

    dataIni = LeData();
    dataFim = LeData();
    
    for(data = dataIni; !EhIgual(data, dataFim); data = AvancaParaDiaSeguinte(data)){
        ImprimeData(data);
        printf("\n");
    }
    
    return 0;
}
