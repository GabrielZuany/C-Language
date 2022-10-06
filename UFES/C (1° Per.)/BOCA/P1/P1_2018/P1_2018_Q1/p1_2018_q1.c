#include <stdio.h>

int main(void){

    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    scanf("%i %i %i %i", &x1, &y1, &x2, &y2);

    if(x1<x2)/*Prim ponto no canto esquerdo*/{

        if(y1<y2)/*Primeiro ponto no canto inferior esq*/{
            printf("(%i,%i)(%i,%i)(%i,%i)(%i,%i)\n", x1,y2, x1,y1, x2,y1, x2,y2);
        }
        if(y1>y2)/*Primeiro ponto no canto sup esquerdo*/{
            printf("(%i,%i)(%i,%i)(%i,%i)(%i,%i)\n", x1,y1, x1,y2, x2,y2, x2,y1);
        }

    }

    if(x1>x2){

        if(y1>y2)/*Primeiro ponto no canto sup direito*/{
            printf("(%i,%i)(%i,%i)(%i,%i)(%i,%i)\n",x2,y1, x2,y2, x1,y2, x1,y1);
        }
        if(y2>y1)/*Primeiro ponto no canto inf direito*/{
            printf("(%i,%i)(%i,%i)(%i,%i)(%i,%i)\n", x2,y2, x2,y1, x1,y1, x1,y2);
        }

    }

    return 0;
}