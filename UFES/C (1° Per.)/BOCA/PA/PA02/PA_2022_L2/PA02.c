#include <stdio.h>

int main(void){

    int i = 0, j = 0, topo = 0, meio = 0, QTD_= 0, cont = 0;

    scanf("%i %i", &topo, &meio);

    if(meio>topo){

    
        QTD_ = meio-topo;

        while(topo<meio){

            for(cont = 1; cont<=QTD_/2; ++cont){
                printf("_");
            }

            for(i=0;i<topo;++i){
                printf("$");
            }

            for(cont = 1; cont<=QTD_/2; ++cont){
                printf("_");
            }

            printf("\n");

            QTD_-=2;
            topo+=2;
        }
            
        QTD_ = 0;

        while(meio>0){

            if(QTD_!=0){

            for(cont=0; cont<QTD_/2; ++cont){
                    printf("_");
                }

            }

            for(i=meio;i>=1;--i){

                printf("$");

            }

            if(QTD_!=0){

            for(cont=0; cont<QTD_/2; ++cont){
                    printf("_");
                }

            }

            
            printf("\n");

            QTD_+=2;
            meio-=2;

        }

    }
            
    return 0;
}