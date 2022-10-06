#include <stdio.h>
#include "tCirculo.h"
#include "tRetangulo.h"
#include "tTriangulo.h"

int main(){
    int qtd, i;
    float multa = 0, area = 0;
    char fig;
    tCirculo circulo;
    tRetangulo retangulo;
    tTriangulo triangulo;

    scanf("%d", &qtd);
    scanf("%*c");
    for(i=0; i<qtd; i++){
        scanf("%c", &fig);
      
        if(fig == 'C'){
            circulo = LeCirculo();
            area = RetornaAreaCirculo(circulo);
            multa = RetornaMultaCirculo(area);
            printf("Preço = %.2f\n", multa);
          
        }else if(fig == 'R'){
            retangulo = LeRetangulo();
            area = RetornaAreaRetangulo(retangulo);
            multa = RetornaMultaRetangulo(area);
            printf("Preço = %.2f\n", multa);
          
        }else if(fig == 'T'){
            triangulo = LeTriangulo();
            area = RetornaAreaTriangulo(triangulo);
            multa = RetornaMultaTriangulo(area);
            printf("Preço = %.2f\n", multa);
        }
        scanf("%*c");
    }
  
    return 0;
}