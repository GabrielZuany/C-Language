#include <stdio.h>
#include "tCirculo.h"
#include "tRetangulo.h"
#include "tTriangulo.h"

int main(){
    int qtd, i;
    float multa = 0, area = 0, raio,  base, altura;
    char fig;
    tCirculo circulo;
    tRetangulo retangulo;
    tTriangulo triangulo;

    scanf("%d", &qtd);
    scanf("%*c");
    for(i=0; i<qtd; i++){
        scanf("%c", &fig);
      
        if(fig == 'C'){
            scanf("%f", &raio);
            circulo = CriaCirculo(raio);
            area = RetornaAreaCirculo(circulo);
            multa = RetornaMultaCirculo(area);
            printf("Preço = %.2f\n", multa);
          
        }else if(fig == 'R'){
            scanf("%f %f", &base, &altura);
            retangulo = CriaRetangulo(base, altura);
            area = RetornaAreaRetangulo(retangulo);
            multa = RetornaMultaRetangulo(area);
            printf("Preço = %.2f\n", multa);
          
        }else if(fig == 'T'){
            scanf("%f %f", &base, &altura);
            triangulo = CriaTriangulo(base, altura);
            area = RetornaAreaTriangulo(triangulo);
            multa = RetornaMultaTriangulo(area);
            printf("Preço = %.2f\n", multa);
        }
        scanf("%*c");
    }
  
    return 0;
}