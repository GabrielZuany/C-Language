#ifndef _TRETANGULO_H_
#define _TRETANGULO_H_

typedef struct{
    float base;
    float altura;
}tRetangulo;

tRetangulo LeRetangulo();
float RetornaAreaRetangulo(tRetangulo retangulo);
float RetornaMultaRetangulo(float area);

#endif