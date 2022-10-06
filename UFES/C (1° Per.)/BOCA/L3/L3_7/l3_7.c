#include <stdio.h>

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2);
int area (int x1, int y1, int x2, int y2);

int main(){

    int r1_x1 = 0, r1_y1 = 0, r1_x2 = 0, r1_y2 = 0;
    int r2_x1 = 0, r2_y1 = 0, r2_x2 = 0, r2_y2 = 0;

    int Area_1 = 0, Area_2 = 0, AreaTotal = 0, Diferenca = 0;

    scanf("%i %i %i %i", &r1_x1, &r1_y1, &r1_x2, &r1_y2);
    scanf("%i %i %i %i", &r2_x1, &r2_y1, &r2_x2, &r2_y2);

    if((r1_x1 <= r1_x2) && (r1_x1 <= r2_x1) && (r1_x1 <= r2_x2) &&
        (r1_y1 <= r1_y2) && (r1_y1 <= r2_y1) && (r1_y1 <= r2_y2) &&
        (r2_x2 >= r2_x1) && (r2_x2 >= r1_x1) && (r2_x2 >= r1_x2) &&
        (r2_y2 >= r2_y1) && (r2_y2 >= r1_y1) && (r2_y2 >= r1_y2))
        {

            if(r2_x1<r1_x2 && r2_y1<r1_y2){
            Area_1 = area(r1_x1, r1_y1, r1_x2, r1_y2);
            Area_2 = area(r2_x1, r2_y1, r2_x2, r2_y2);
            Diferenca = (r2_x1-r1_x2)*(r2_y1-r1_y2);

            AreaTotal = area_total(r1_x1, r1_y1, r1_x2, r1_y2,r2_x1, r2_y1, r2_x2, r2_y2);

            printf("RESP:%i", AreaTotal-Diferenca);

            }else{

                Area_1 = area(r1_x1, r1_y1, r1_x2, r1_y2);
                Area_2 = area(r2_x1, r2_y1, r2_x2, r2_y2);

                AreaTotal = area_total(r1_x1, r1_y1, r1_x2, r1_y2,r2_x1, r2_y1, r2_x2, r2_y2);
                
                printf("RESP:%i", AreaTotal);
            }

        }

    return 0;
}
//----------FUNÇÕES-----------
int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2){
    return ((r1_x2 - r1_x1)*(r1_y2-r1_y1) + (r2_x2-r2_x1)*(r2_y2-r2_y1));
}

int area (int x1, int y1, int x2, int y2){
    return (x2-x1)*(y2-y1);
}