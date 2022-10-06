#include "tRetangulo.h"
#include <stdlib.h>

tRetangulo criaRetangulo(tPonto p1, tPonto p2){
  if(p1.x != p2.x && p1.y != p2.y){
    tRetangulo ret;
    ret.p1 = p1;
    ret.p2 = p2;
    return ret;
  }else{
    printf("Retangulo invalido\n");
    exit(1);
  }
  
}
