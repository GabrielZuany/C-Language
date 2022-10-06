#include <stdio.h>
#include <math.h>

int main(void){

    int x1 = 0, x2 = 0, p_x = 0;
    int y1 = 0, y2 = 0, p_y = 0;
    scanf("%i %i %i %i %i %i", &x1, &y1, &x2, &y2, &p_x, &p_y);

    int dist_x = 0, dist_y = 0;
    dist_x = x1 - x2;
    dist_y = y1 - y2;
    
    if(x1>=0 && x2>=0 && y1>=0 && y2>=0 && p_x<0 && p_y<0){
        printf("Fora");
    }else{
        if(p_x<=fabs(dist_x) && p_y<=fabs(dist_y)){
        printf("Dentro");
        }else printf("Fora");
    }
    
    return 0;
}